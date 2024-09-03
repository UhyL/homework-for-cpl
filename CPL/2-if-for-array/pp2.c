//
// Created by 27756 on 2022/10/10.
//
#include <stdio.h>
#include <math.h>

int main() {
    int xA, yA, xB, yB, xC, yC;
    int min = 0;
    int n = 0;
    char way[10000] = "w";
    scanf("%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC);
    int x = fabs(xA - xB);
    int y = fabs(yA - yB);
    min = x + y;
    if (((((xA == xB) && (xB == xC)) && ((yA < yC && yC< yB) || (yB < yC && yC < yA))) ||
         (((yA == yB) && (yB == yC)) && ((xA < xC && xC < xB) || (xB < xC && xC < xA)))) == 1) {
        if (yA == yB && yB == yC) {
            way[0] = 'D';
            way[x + 1] = 'U';
            for (int i = 1; x > 0; ++i) {
                if (xA > xB) {
                    way[i] = 'L';
                } else {
                    way[i] = 'R';
                }
                x--;
            }
        } else {
            way[0] = 'R';
            way[y + 1] = 'L';
            for (int i = 1; y > 0; ++i) {
                if (yA > yB) {
                    way[i] = 'D';
                } else {
                    way[i] = 'U';
                }
                y--;
            }
        }
        min = min + 2;
    } else if ((((yA == yC) || (yB == yC)) && ((xA < xC && xC < xB) || (xB < xC && xC < xA))) == 1) {
        for (int i = 0; y > 1; ++i) {
            if (yA > yB) {
                way[i] = 'D';
            } else {
                way[i] = 'U';
            }
            y--;
            n++;
        }
        for (int i = n; x > 0; ++i) {
            if (xA > xB) {
                way[i] = 'L';
            } else {
                way[i] = 'R';
            }
            x--;
        }
        if (yA > yB) {
            way[min - 1] = 'D';
        } else {
            way[min - 1] = 'U';
        }
    } else if ((((xA == xC) || (xB == xC)) && ((yA < yC && yC < yB) || (yB < yC && yC < yA))) == 1) {
        for (int i = 0; x > 1; ++i) {
            if (xA > xB) {
                way[i] = 'L';
            } else {
                way[i] = 'R';
            }
            n++;
            x--;
        }
        for (int i = n; y > 0; ++i) {
            if (yA > yB) {
                way[i] = 'D';
            } else {
                way[i] = 'U';
            }
            y--;
        }
        if (xA > xB) {
            way[min - 1] = 'L';
        } else {
            way[min - 1] = 'R';
        }
    } else if ((((xA == xC) || (xB == xC)) && ((yA == yC) || (yB == yC))) == 1) {
        if ((((xC == (xA + x)) || ((xC == (xA - x))))) == 1) {
            for (int i = 0; y > 0; ++i) {
                if (yA > yB) {
                    way[i] = 'D';
                } else {
                    way[i] = 'U';
                }
                n++;
                y--;
            }
            for (int i = n; x > 0; ++i) {
                if (xA > xB) {
                    way[i] = 'L';
                } else {
                    way[i] = 'R';
                }
                x--;
            }
        } else {
            for (int i = 0; x > 0; ++i) {
                if (xA > xB) {
                    way[i] = 'L';
                } else {
                    way[i] = 'R';
                }
                n++;
                x--;
            }
            for (int i = n; y > 0; ++i) {
                if (yA > yB) {
                    way[i] = 'D';
                } else {
                    way[i] = 'U';
                }
                y--;
            }
        }
    } else {
        for (int i = 0; x > 0; ++i) {
            if (xA > xB) {
                way[i] = 'L';
            } else {
                way[i] = 'R';
            }
            n++;
            x--;
        }
        for (int i = n; y > 0; ++i) {
            if (yA > yB) {
                way[i] = 'D';
            } else {
                way[i] = 'U';
            }
            y--;
        }
    }

    printf("%d\n%s", min, way);

    return 0;
}