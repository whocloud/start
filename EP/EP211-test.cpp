/*************************************************************************
	> File Name: EP211-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 17时39分27秒
 ************************************************************************/

#include<stdio.h>
int dir[4][2] = {
    1, 0,
    1, 1,
    0, 1,
    1, -1
};

int main() {
    int a[30][30] = {0};
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int p = 1;
                for (int step = 0; step < 4; step++) {
                    int xx = i + step * dir[k][0];
                    int yy = j + step * dir[k][1];
                    p *= a[xx][yy];
                }
                if (p > ans) ans = p;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
