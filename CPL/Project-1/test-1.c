#include "ramfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* modify this file freely */

typedef enum type{
    FILE_NODE,
    DIR_NODE,
    ERROR,
}Type;

typedef struct node{
    Type type;
    char *name;

    struct node **dirents; //if it's a dir sub_dirs; address of address
    int num_of_subs;

    void *content;//if it's a file content
    int size_of_file;
}Node;

typedef struct fd{
    off_t offset;
    int flags;
    Node *file;
    bool used;// origin file
}Fd;

typedef struct processed_char{
    bool is_there_gang_at_beginning;//前面是否有/
    bool is_there_gang_at_end;//后面是否有/
    char *first_name;//第一个名字的长度
    int num_of_names;//名字的长度
    int origin_path_len;//最初始的长度
}Processed_char;

void process_path(Processed_char *des,char *path, char what_you_want_replace);
char *search_name(char *processed_path_first_address,int which_name,int origin_path_len);
Node *path_seek(Processed_char *path,const Node *Root);
bool is_name_legal(Node *present_file,Processed_char *path);
bool is_repetitive_name(Node *father_path, char *present_name);
bool easy_is_name_legal(Node *present_file,Processed_char *path);

#define fd_size 4096
Node root;
Node error;
Fd fds[fd_size];
Fd *fd_of_error;



int ropen(const char *pathname, int flags) {
    //get executable path
    char *path = malloc((strlen(pathname)+1)* sizeof(char));
    Processed_char *processed_path = malloc(sizeof(Processed_char));

    strcpy(path,pathname);//path中包含 pathname中的所有内容
    //get now_file

    process_path(processed_path,path, '/');
    Processed_char *temp_process_path = malloc(sizeof(Processed_char));
    *temp_process_path = *processed_path;
    Node *now_file = path_seek(temp_process_path, &root);
    *temp_process_path = *processed_path;
    //get father file
    temp_process_path->num_of_names--;
    Node *father_dir = path_seek(temp_process_path, &root);

    //check legal
    if(!is_name_legal(now_file,processed_path) || father_dir->type==ERROR) goto False;
    //if(father_dir->type==ERROR)goto False;
    //never created and flags contain create
    if(now_file->type ==ERROR && (flags & O_CREAT) == O_CREAT){
        now_file = malloc(sizeof(Node));
        now_file->type = FILE_NODE;
    }
    //still not found
    if(now_file->type==ERROR) goto False;
    //find idle fd
    int index_fd = -1;
    for(int i = 0;i<fd_size;i++){
        if(fds[i].used==false){
            index_fd = i;
            break;
        }
    }
    //bind fd
    Fd *now_fd = &fds[index_fd];
    now_fd->used=true;
    fds[index_fd].file = now_file;
    //return DIR
    if(now_file->type==DIR_NODE) goto Redir;


    //now all FILE
    fds[index_fd].offset=0;
    fds[index_fd].flags=flags;
    //create a file
    if((flags & O_CREAT) == O_CREAT){
        char *present_name = search_name(processed_path->first_name,processed_path->num_of_names,processed_path->origin_path_len);
        char *name = malloc(sizeof(char)*(strlen(present_name)+1));
        strcpy(name,present_name);
        if(!is_repetitive_name(father_dir,present_name)){
            //renew father_dir
            father_dir->dirents = realloc(father_dir->dirents,(father_dir->num_of_subs+1) * sizeof(Node*));
            father_dir->dirents[father_dir->num_of_subs] = now_file;
            father_dir->num_of_subs++;
            //init now_file
            now_file->name = name;
            now_file->content = NULL;
            now_file->num_of_subs=0;
            now_file->size_of_file=0;
        }
    }
    //APPEND
    if((now_fd->flags & O_APPEND) == O_APPEND){
        now_fd->offset= now_file->size_of_file;
    }
    //TRUNC
    if((flags & O_TRUNC) == O_TRUNC){
        if((flags & O_WRONLY) == O_WRONLY || (flags & O_RDWR) == O_RDWR){
            free(now_file->content);
            now_file->content=NULL;
            now_file->size_of_file=0;
        }
    }

    if(flags == (O_RDWR | O_WRONLY)){
        now_fd->flags = O_WRONLY;
    }




    free(path);
    free(processed_path);
    free(temp_process_path);
    return index_fd;

    False:
    free(path);
    free(processed_path);
    free(temp_process_path);
    return -1;

    Redir:
    free(path);
    free(processed_path);
    free(temp_process_path);
    return index_fd;
}

int rclose(int fd) {
    if(fd<0|| fds[fd].used==false) return -1;
    //Fd *now_fd = &fds[fd];
//    now_fd->offset=0;
//    now_fd->flags=0;
    fds[fd].used=false;
//    now_fd->file=NULL;
    return 0;
}

ssize_t rwrite(int fd, const void *buf, size_t count) {
    if(fd<0) return -1;
    Fd *now_fd = &fds[fd];
    Node *now_file = now_fd->file;
    //not FILE_NODE
    if(now_fd->used==false) return -1;
    if(now_file->type!=FILE_NODE) return -1;
    //NOT write able
    int flags = now_fd->flags;
    if( !( (flags & O_WRONLY)==O_WRONLY || (flags & O_RDWR) == O_RDWR ) ) return -1;
    //write
    int want_to_write = now_fd->offset + count +1;
    int could_write =now_file->size_of_file;
    if(want_to_write > could_write){
        //enlarge
        now_file->content= realloc(now_file->content, sizeof(char)*(now_fd->offset + count + 1));
        memset(&now_file->content[now_file->size_of_file],'\0',now_fd->offset + count - now_file->size_of_file);
        for(int i = now_file->size_of_file;i<now_fd->offset + count;i++){
            memset(&now_file->content[i],'\0',1);
        }
        now_file->size_of_file = now_fd->offset + count;
    }
    memcpy(now_file->content + now_fd->offset * sizeof(char), buf, count);
    now_fd->offset = now_fd->offset + count;
    return count;
}

ssize_t rread(int fd, void *buf, size_t count) {
    if(fd<0) return -1;
    Fd *now_fd = &fds[fd];
    Node *now_file = now_fd->file;
    //not FILE_NODE
    if(now_fd->used==false) return -1;
    if(now_file->type!=FILE_NODE) return -1;
    if(now_file->content == NULL) return -1;
    //NOT read able
    int flags = now_fd->flags;
    if(!( (flags == O_CREAT) || (flags & O_RDWR) == O_RDWR || (flags == O_APPEND) || (flags == O_TRUNC) || (flags == O_RDONLY) )) return -1;
    //read
    int len = 0;
    for(int i = now_fd->offset; i < now_fd->offset + count && i < now_file->size_of_file; i++){
        len++;
    }

    memcpy(buf, &now_file->content[now_fd->offset], len);
    now_fd->offset += len;
    return len;
}

off_t rseek(int fd, off_t offset, int whence) {
    if(fd<0) return -1;
    Fd *now_fd = &fds[fd];
    Node *now_file = now_fd->file;
    //not FILE_NODE
    if(now_fd->used==false) return -1;
    if(now_file->type!=FILE_NODE) return -1;
    off_t origin_offset = now_fd->offset;

    switch (whence) {
        case SEEK_SET:now_fd->offset = offset;
            break;
        case SEEK_CUR: now_fd->offset = now_fd->offset + offset;
            break;
        case SEEK_END:now_fd->offset = now_fd->file->size_of_file + offset ;
            break;
        default:return -1;
    }
    //minus offset
    if(now_fd->offset < 0){
        now_fd->offset = origin_offset;
        return -1;
    }

    return now_fd->offset;
}

int rmkdir(const char *pathname) {
    char *path = malloc((strlen(pathname)+1)*sizeof(char));
    strcpy(path,pathname);
    Processed_char *processchar = malloc(sizeof(Processed_char));
    process_path(processchar, path, '/');
    char *present_name = search_name(processchar->first_name, processchar->num_of_names, processchar->origin_path_len);
    //is name legal
    if(!is_name_legal(NULL, processchar)) return -1;
    //search father path
    processchar->num_of_names--;
    Node *father_path = path_seek(processchar, &root);
    if(father_path->type==ERROR || father_path->type==FILE_NODE) goto False;
    //is repetitive name
    for(int i = 0;i<father_path->num_of_subs;i++){
        if(!strcmp(present_name,father_path->dirents[i]->name)) goto False;
    }

    //mk dir
    father_path->dirents = realloc(father_path->dirents,(father_path->num_of_subs+1)* sizeof(Node*));
    Node *new_dir = malloc(sizeof(Node));
    father_path->dirents[father_path->num_of_subs] =new_dir;
    father_path->num_of_subs++;
    //init new_dir
    new_dir->dirents=NULL;
    new_dir->type=DIR_NODE;
    new_dir->num_of_subs=0;
    char *name = malloc((strlen(present_name)+1) * sizeof(char));
    strcpy(name,present_name);
    new_dir->name=name;

    free(path);
    free(processchar);
    return 0;//success

    False:
    free(path);
    free(processchar);
    return -1;
	}

int rrmdir(const char *pathname) {
    char *path = malloc(sizeof(char) * (strlen(pathname)+1) );
    strcpy(path,pathname);
    Processed_char *temp = malloc(sizeof(Processed_char));
    process_path(temp,path, '/');
    //search the path
    Processed_char *temp_path = malloc(sizeof(Processed_char));
    *temp_path = *temp;
    Node *delete_the_dir = path_seek(temp_path,&root);

    //is name legal
    //if(!is_name_legal(delete_the_dir,temp)) goto False;
    //remove fail
    if(delete_the_dir->type!=DIR_NODE || delete_the_dir->num_of_subs!=0 || !strcmp(delete_the_dir->name,root.name)){
        goto False;
    }
    //find father dir
    *temp_path = *temp;
    temp_path->num_of_names--;
    Node *father_dir = path_seek(temp_path,&root);
    free(temp_path);
    if(father_dir->type!=DIR_NODE) goto False;
    //rm dir;
    for(int i = 0;i<father_dir->num_of_subs;i++){
        if(!strcmp(father_dir->dirents[i]->name,delete_the_dir->name)){
            for(int j = i;j<father_dir->num_of_subs-1;j++){
                father_dir->dirents[j] = father_dir->dirents[j+1];
            }
            father_dir->dirents[father_dir->num_of_subs-1]=NULL;
            if(father_dir->num_of_subs>=2){
                father_dir->dirents = realloc(father_dir->dirents,(father_dir->num_of_subs-1) * sizeof(Fd*));
            }else{
                father_dir->dirents=NULL;
            }

            father_dir->num_of_subs--;

            free(temp);
            free(path);
            free(delete_the_dir->name);
            free(delete_the_dir->dirents);
            free(delete_the_dir);
            return 0;
        }
    }

    False:
    free(path);
    free(temp);
    return -1;
}

int runlink(const char *pathname) {
    char *path = malloc((strlen(pathname)+1)*sizeof(char));
    Processed_char *temp = malloc(sizeof(Processed_char));

    strcpy(path,pathname);
    process_path(temp,path, '/');
    //search the path
    Processed_char *temp_path = malloc(sizeof(Processed_char));
    *temp_path=*temp;
    Node *delete_the_file = path_seek(temp_path,&root);
    //is name legal
    if(!is_name_legal(delete_the_file,temp)) goto False;
    //not a file
    if(delete_the_file->type!=FILE_NODE) goto False;
    //find father dir
    *temp_path=*temp;
    temp_path->num_of_names--;
    Node *father_dir = path_seek(temp_path,&root);
    free(temp_path);
    if(father_dir->type!=DIR_NODE) goto False;
    //rm file
    for(int i = 0;i<father_dir->num_of_subs;i++){
        if(!strcmp(father_dir->dirents[i]->name,delete_the_file->name)){
            //father_dir->dirents[i]=NULL;
            for(int j = i;j<father_dir->num_of_subs-1;j++){
                father_dir->dirents[j] = father_dir->dirents[j+1];
            }
            father_dir->dirents[father_dir->num_of_subs-1]=NULL;
            if(father_dir->num_of_subs>=2){
                father_dir->dirents = realloc(father_dir->dirents,(father_dir->num_of_subs-1) * sizeof(Fd*));
            }else{
                father_dir->dirents = NULL;
            }
            father_dir->num_of_subs--;

            free(delete_the_file->name);
            free(delete_the_file->content);
            //free(delete_the_file);
            free(temp);
            free(path);
            return 0;
        }
    }

    False:
    free(temp);
    free(path);
    return -1;
}

void init_ramfs() {
    root.type = DIR_NODE;
    root.name = malloc(5* sizeof(char));
    char name[]="root";
    strcpy(root.name,name);

    root.dirents = NULL; //Node address of address
    root.num_of_subs = 0;

    error.type=ERROR;
    error.name="error";
    fd_of_error = malloc(sizeof(Fd));
    fd_of_error->file=&error;

}


void process_path(Processed_char *des,char *path, char what_you_want_replace){
    int len = strlen(path);
    des->origin_path_len = len;
    des->first_name=NULL;
    des->num_of_names=0;
    des->is_there_gang_at_end = false;
    des->is_there_gang_at_beginning = false;

    for(int i = 1;path[i]!=0;i++){
        if(path[i-1]==what_you_want_replace && path[i]!=what_you_want_replace){
            des->num_of_names++;
        }
    }

    if(path[0] == what_you_want_replace){
        des->is_there_gang_at_beginning=true;
    }
    if(path[len-1] == what_you_want_replace){
        des->is_there_gang_at_end=true;
    }

    for(int i = 0;i<len;i++){
        if(path[i]==what_you_want_replace){
            path[i]=0;
        }
    }

    for(int i = 0;i<len;i++){
        if(path[i]!=0){
            des->first_name = &path[i];
            break;
        }
    }
}

char *search_name(char *processed_path_first_address,int which_name,int origin_path_len){
    which_name--;
    if(which_name==0){
        return processed_path_first_address;
    }

    for(int i = 1;i<origin_path_len;i++){
        if(processed_path_first_address[i-1]==0 && processed_path_first_address[i]!=0){
            which_name--;
        }
        if(which_name==0){
            return &processed_path_first_address[i];
        }
    }
    return NULL;
}

Node *path_seek(Processed_char *path,const Node *Root){
    if(path->num_of_names==0){
        return &root;
    }
    for(int i = 0;i<Root->num_of_subs;i++){
        if(Root->dirents[i]==NULL) continue;
        if(!strcmp(Root->dirents[i]->name,path->first_name)){//find it

            if(path->num_of_names == 1){//last one
                return Root->dirents[i];
            }else{//not last one
                path->num_of_names=path->num_of_names-1;
                path->first_name = search_name(path->first_name, 2, path->origin_path_len);
                return path_seek(path, Root->dirents[i]);
            }

        }
    }
    return &error;
}

bool is_name_legal(Node *present_file,Processed_char *path){
    char *temp_name = malloc(sizeof(char ) * (path->origin_path_len+1));
    for(int i = 1;i<=path->num_of_names;i++){
        memcpy(temp_name, search_name(path->first_name,i,path->origin_path_len),path->origin_path_len);
        int len = strlen(temp_name);
        if(len>32){
            goto False;
        }
        for(int j = 0;j<len;j++){
            if(!(temp_name[j]=='.' || (temp_name[j]>='0' && temp_name[j]<='9')
                || (temp_name[j]>='A' && temp_name[j]<='Z') || (temp_name[j]>='a' && temp_name[j]<='z'))){
                goto False;
            }
        }
    }
    if(present_file == NULL) goto True;
    if( (present_file->type==FILE_NODE && path->is_there_gang_at_end) || !path->is_there_gang_at_beginning) goto False;

    True:
    free(temp_name);
    return true;

    False:
    free(temp_name);
    return false;
}

bool is_repetitive_name(Node *father_path, char *present_name) {
    for (int i = 0; i < father_path->num_of_subs; i++) {
        if (!strcmp(present_name, father_path->dirents[i]->name)) return true;
    }
    return false;
}