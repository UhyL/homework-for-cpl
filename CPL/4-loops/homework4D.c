//
// Created by 27756 on 2022/10/21.
//
#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    int count = 0;
    int numA = 0, numB = 0;
    char old_string[1000] = {""};
    char new_string[1000] = {""};


    scanf("%d", &n);
    getchar();
    scanf("%s", old_string);
    count = strlen(old_string);
    strncpy(new_string, old_string, count);

    while (n > 0) {
        for (int i = 0; i < count; ++i) {
            if (old_string[i] == 46) {
                for (int j = i + 1; j < i + 4; ++j) {
                    if (old_string[j] == 65) {
                        numA++;
                    } else if (old_string[j] == 66) {
                        numB++;
                    }
                }
                for (int j = i - 1; j > i - 4; --j) {
                    if (old_string[j] == 65) {
                        numA++;
                    } else if (old_string[j] == 66) {
                        numB++;
                    }
                }
                if ((numA == 0) && (numB <= 4) && (numB >= 2)) {
                    new_string[i] = 66;
                } else if ((numB == 0) && (numA <= 4) && (numA >= 2)) {
                    new_string[i] = 65;
                }
            } else if (old_string[i] == 65) {
                for (int j = i + 1; j < i + 4; ++j) {
                    if (old_string[j] == 66) {
                        new_string[i] = 46;
                        break;
                    } else if (old_string[j] == 65) {
                        numA++;
                    }
                }
                for (int j = i - 1; j > i - 4; --j) {
                    if (old_string[j] == 66) {
                        new_string[i] = 46;
                        break;
                    } else if (old_string[j] == 65) {
                        numA++;
                    }
                }
                if ((numA >= 5) || (numA <= 1)) {
                    new_string[i] = 46;
                }
            } else {
                for (int j = i + 1; j < i + 4; ++j) {
                    if (old_string[j] == 65) {
                        new_string[i] = 46;
                        break;
                    } else if (old_string[j] == 66) {
                        numB++;
                    }
                }
                for (int j = i - 1; j > i - 4; --j) {
                    if (old_string[j] == 65) {
                        new_string[i] = 46;
                        break;
                    } else if (old_string[j] == 66) {
                        numB++;
                    }
                }
                if ((numB >= 5) || (numB <= 1)) {
                    new_string[i] = 46;
                }
            }
            numA = 0;
            numB = 0;
        }
        n--;

        strncpy(old_string, new_string, count);
    }

    for (int i = 0; i < count; ++i) {
        printf("%c", old_string[i]);
    }

    return 0;
}