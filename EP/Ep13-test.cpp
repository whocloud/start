/*************************************************************************
	> File Name: Ep13-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 23时29分51秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char num[55];
int ans[55] = {0};

void init() {
    while (~scanf("%s",num)) {
        int len = strlen(num);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; num[i]; i++) {
            ans[len - i] += num[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (ans[0] == i) ans[0]++;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    return 0;
}
