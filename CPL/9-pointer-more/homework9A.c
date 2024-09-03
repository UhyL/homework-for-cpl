//
// Created by 27756 on 2022/11/26.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 4096

int Judge = 0;
int step = 0;
char *a = "const";
char *b = "char";
char *c = "int";
char *d = "float";
char *e = "double";
char *f = "long";
char *g = "static";
char *h = "struct";
char *i = "void";
char *j = "enum";
char *k = "extern";
char *l = "return";
char *m = "break";
char *n = "typedef";
char *o = "union";
char *p = "goto";

void process(char *str1, char *str2);

void print(char *str2, int step);

int main() {

  char *str1 = malloc(len * sizeof(*str1));
  char *str2 = malloc(len * sizeof(*str2));

  while (scanf("%s", str1) != EOF) {
	char *position = strchr(str1, ';');
	if (position == NULL) {
	  process(str1, str2);
	} else {
	  int len1 = strlen(str1);

	  char *dest2 = malloc(len1 * sizeof(*dest2));
	  char *dest1 = malloc(len1 * sizeof(*dest1));

	  if (*str1 == ';') {
		*(str2 + step) = 6;
		step++;
	  } else {
		for (int i = 0; i < position - str1; ++i) {
		  *(dest1 + i) = *(str1 + i);
		}

		*(dest1 + (position - str1)) = '\0';

		process(dest1, str2);

		*(str2 + step) = 6;
		step++;
		if (len1 == (position - str1 + 1));
		else {
		  for (int i = 0, j = (position - str1 + 1); j < len1; ++i, ++j) {
			*(dest2 + i) = *(str1 + j);
		  }
		  *(dest2 + len1 - (position - str1) - 1) = '\0';

		  process(dest2, str2);
		}
	  }
	}
	if (Judge) {

	  free(str1);
	  free(str2);
	  return 0;
	}
  }

  print(str2, step);

  free(str1);
  free(str2);

  return 0;
}

void process(char *str1, char *str2) {
  if ((*str1 >= 48) && (*str1 <= 57)) {
	*(str2 + step) = 2;
	for (int i = 1; *(str1 + i) != '\0'; ++i) {
	  if ((*(str1 + i) == '.') && (*(str2 + step) == 2)) {
		*(str2 + step) = 3;
	  } else if (!((*(str1 + i) >= 48) && (*(str1 + i) <= 57))) {
		printf("Compile Error");
		Judge = 1;
		return;
	  }
	}
  } else if ((*str1 == '+') || (*str1 == '-') || (*str1 == '*') || (*str1 == '/') ||
	  (*str1 == '=') || (*str1 == '!') || (*str1 == '<') || (*str1 == '>')) {
	*(str2 + step) = 4;
	if (*(str1 + 1) != '\0') {
	  if ((*str1 == '=') && (*(str1 + 1) == '=') && (*(str1 + 2) == '\0'));
	  else if ((*str1 == '>') && (*(str1 + 1) == '=') && (*(str1 + 2) == '\0'));
	  else if ((*str1 == '<') && (*(str1 + 1) == '=') && (*(str1 + 2) == '\0'));
	  else if ((*str1 == '!') && (*(str1 + 1) == '=') && (*(str1 + 2) == '\0'));
	  else {
		printf("Compile Error");
		Judge = 1;
		return;
	  }
	}
  } else if (*str1 == '.') {
	for (int i = 1; *(str1 + i) != '\0'; ++i) {
	  *(str2 + step) = 3;
	  if ((*(str1 + i) >= 48) && (*(str1 + i) <= 57));
	  else {
		printf("Compile Error");
		Judge = 1;
		return;
	  }
	}
  } else if ((*str1 == 'c') || (*str1 == 'i') || (*str1 == 'f') || (*str1 == 'd') || (*str1 == 'l') ||
	  (*str1 == 's') || (*str1 == 'v') || (*str1 == 'e') || (*str1 == 'r') || (*str1 == 'b') || (*str1 == 't') ||
	  (*str1 == 'u') || (*str1 == 'g')) {
	*(str2 + step) = 5;
	if (*str1 == 'c') {
	  if ((!strcmp(a, str1)) || (!strcmp(b, str1))) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'i') {
	  if (!strcmp(c, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'f') {
	  if (!strcmp(d, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'd') {
	  if (!strcmp(e, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'l') {
	  if (!strcmp(f, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 's') {
	  if ((!strcmp(g, str1)) || (!strcmp(h, str1))) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'v') {
	  if (!strcmp(i, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'e') {
	  if ((!strcmp(j, str1)) || (!strcmp(k, str1))) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'r') {
	  if (!strcmp(l, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'b') {
	  if (!strcmp(m, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 't') {
	  if (!strcmp(n, str1)) {
		*(str2 + step) = 1;
	  }
	} else if (*str1 == 'u') {
	  if (!strcmp(o, str1)) {
		*(str2 + step) = 1;
	  }
	} else {
	  if (!strcmp(p, str1)) {
		*(str2 + step) = 1;
	  }
	}
  } else if ((*str1 == '_') || ((*str1 >= 65) && (*str1 <= 90)) || ((*str1 >= 97) && (*str1 <= 122))) {
	*(str2 + step) = 5;
	for (int i = 1; *(str1 + i) != '\0'; ++i) {
	  if ((*(str1 + i) == '_') || ((*(str1 + i) >= 65) && (*(str1 + i) <= 90))
		  || ((*(str1 + i) >= 97) && (*(str1 + i) <= 122)) || ((*(str1 + i) >= 48) && (*(str1 + i) <= 57)));
	  else {
		printf("Compile Error");
		Judge = 1;
		return;
	  }
	}
  } else {
	printf("Compile Error");
	Judge = 1;
	return;
  }

  step++;

}

void print(char *str2, int step) {
  for (int i = 0; i < step; ++i) {
	switch (*(str2 + i)) {
	  case 1:printf("reserved ");
		break;
	  case 2:printf("integer ");
		break;
	  case 3:printf("float ");
		break;
	  case 4:printf("operator ");
		break;
	  case 5:printf("variable ");
		break;
	  case 6:printf("\n");
		break;
	}

  }
  return;
}
