#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN_OF_RULE 128
#define LEN_OF_ORDER 1024

int main() {
  char *rule = malloc(LEN_OF_RULE * sizeof(*rule));
  scanf("%s", rule);

  char *rst = malloc(LEN_OF_ORDER * sizeof(*rst));
  bool legal = true;
  int index = 0;
  int situation = 0;
  char wp = 0;

  char *name = malloc(LEN_OF_ORDER * sizeof(name));
  scanf("%s", name);
  strcpy(rst, name);
  index += (int) strlen(name);
  *(rst + index) = '\n';
  index += 1;

  char *ord = malloc(LEN_OF_ORDER);
  while (scanf("%s", ord) != EOF) {
	if (*ord == '-') {
	  const char *position_of_p = strchr(rule, *(ord + 1));
	  // the parameter cannot be found in the rule
	  if (position_of_p == NULL) {
		wp = *(ord + 1);
		situation = 2;
		legal = false;
		break;
	  }
	  // the parameter has no value
	  if (*(position_of_p + 1) != ':') {
		strncpy(rst + index, ord + 1, 1);
		strncpy(rst + index + 1, "\n", 1);
		index += 2;
	  }
		// the parameter has value
	  else {
		char *value = malloc(LEN_OF_ORDER * sizeof(value));
		scanf("%s", value);
		if (strlen(value) >= 1) {
		  strncpy(rst + index, ord + 1, 1);
		  strncpy(rst + index + 1, "=", 1);
		  strcpy(rst + index + 2, value);
		  strncpy(rst + index + 2 + strlen(value), "\n", 1);
		  index += (3 + (int) strlen(value));
		}
		  // it requires a value
		else {
		  wp = *(ord + 1);
		  situation = 1;
		  legal = false;
		  free(value);
		  break;
		}
		free(value);
	  }
	}
  }

  if (!legal && situation == 1) {
	printf("%s: option requires an argument -- '%c'", name, wp);
  }
  if (!legal && situation == 2) {
	printf("%s: invalid option -- '%c'", name, wp);
  }
  if (legal) {
	for (int i = 0; i < index; i++) {
	  printf("%c", *(rst + i));
	}
  }

  free(rule);
  free(name);
  free(ord);
  free(rst);

  return 0;
}