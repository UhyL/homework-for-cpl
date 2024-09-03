//
// Created by 27756 on 2022/10/29.
//
/*#include <stdio.h>
#include <stdbool.h>
int main() {
    char NextStr;
    bool gotI = false;
    bool gotIN = false;
    int count = 0;

    do {
        scanf("%c", &NextStr);
        switch (NextStr) {
            case 'i': {
                gotI = true;
                gotIN = false;
                break;
            }
            case 'n':{
              if (gotIN) {
                  gotIN = false;
              }
              if (gotI) {
                  gotIN = true;
              }
              gotI =false;
                break;
            }
            case 't':{
                if(gotIN) {
                    count++;
                }
                gotI = false;
                gotIN = false;
                break;
            }

            default:{
                gotI = false;
                gotIN = false;
            }
        }

    } while (NextStr != '\n');

    printf("%d", count);

    return 0;

}*/


#include <stdio.h>

int main() {
    int s0, i, n, t, o,put_out = 0;
    scanf("%d%d%d%d%d", &s0, &i, &n, &t, &o);

    if(s0 == 0) {
        if(o == i) {
            put_out = 1;
        } else {
            put_out = 0;
        }
    }

    if(s0 == 1) {
        if (o == i) {
            put_out = 1;
        } else if(o==n) {
            put_out = 2;
        } else {
            put_out = 0;
        }
    }

    if(s0 == 2) {
        if ( o== i) {
            put_out = 1;
        } else if (o==t) {
            put_out = 3;
        } else {
            put_out = 0;
        }
    }

    if(s0==3) {
        if(o==i){
            put_out = 1;
        } else {
            put_out = 0;
        }
    }

    printf("%d", put_out);

    return 0;
}

