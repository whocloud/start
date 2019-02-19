/*************************************************************************
	> File Name: Ep13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 18时57分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    char read_num[55];
    int ans[55] = {0};
    while (scanf("%s", read_num) != EOF) {
        int len = strlen(read_num);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; read_num[i]; i++) {
            ans[len - i] += read_num[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            //if (i == ans[0]) ans[0]++;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
