/*************************************************************************
	> File Name: EP214.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 20时07分54秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000
#define keep_range 1000000
int keep[keep_range + 5] = {0};
int get_length(int64_t x) {
    if (x == 1) return 1;
    //int n = 1;
    //while (x != 1) {
    //    if (x & 1) x = 3 * x + 1;
    //    else x >>= 1;
    //    n++;
    //}
    //return n;
    if (x <= keep_range && keep[x]) return keep[x];
    int temp = 0;
    if (x & 1) temp = get_length(3 * x + 1) + 1;
    else temp = get_length(x >> 1) + 1;
    if (x <= keep_range) keep[x] = temp;
    return temp;
}

int main () {
    int ans, ans_len = 1;
    for (int i = 1; i < max; i++) {
        int temp_len = get_length(i);
        if (temp_len > ans_len) {
            ans = i;
            ans_len = temp_len;
        }
    }
    printf("%d(%d)\n", ans, ans_len);
    return 0;
}
