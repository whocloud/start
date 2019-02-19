/*************************************************************************
	> File Name: Ep13-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 19时59分20秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int ans[100] = {0};
        ans[0] = ans[1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int i = 1; i <= ans[0]; i++) {
                ans[i] *= n;
            }
            for (int i = 1; i <= ans[0]; i++) {
                if (ans[i] < 10) continue;
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
                ans[0] += (i == ans[0]);
            }

        }
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
    }    
    printf("\n");
    return 0;
}
