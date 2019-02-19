/*************************************************************************
	> File Name: Ep26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月26日 星期三 20时13分31秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define max_n 1000

int dnum[max_n + 5];

int get_len(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    while (y && dnum[y] == 0) {
        dnum[y] = n;//y是余数
        y = y * 10 % d;//当y再次出现n++就是第二次出现位数while条件dnum不成立
        n++;//n记录余数第几位出现
    }
    return y ? n - dnum[y] : 0;
}

int main() {
    int max_len = 0, ans = 0;
    for (int d= 2; d < max_n; d++) {
        int temp_len = get_len(d);
        if (temp_len > max_len) {
            max_len = temp_len;
            ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
