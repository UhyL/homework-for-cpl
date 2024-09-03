//
// Created by 27756 on 2022/10/21.
//
#include <stdio.h>

int  main() {
    char board[51][51] ={""};
    int vis[51][51] = {0};
    int ans = 0;
    int num = 0;

    int n, m, X0, Y0, x, y;
    scanf("%d%d%d%d", &n, &m, &X0, &Y0);
    getchar();
    x = X0;
    y = Y0;
    vis[x][y] =1;

    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &board[i][j]);
            if(board[i][j] == '#') {
                ans++;
            }
        }
        getchar();
    }
    num = ans;

    printf("%d\n", ans);
    printf("%d %d\n", x, y);

    while (num > 1) {
        int vertors[4][2] = {{0,  1},{0,  -1},{1,  0},{-1, 0}};
        for (int i = 0; i < 4; ++i) {
            int newX = x + vertors[i][0];
            int newY = y + vertors[i][1];
            if ((board[newX][newY] == '#') && (vis[newX][newY] == 0)) {
                x = newX;
                y = newY;
                vis[newX][newY] = 1;
                printf("%d %d\n", newX, newY);
            }
        }
        num--;
    }

    return 0;
}