/*************************************************************************
	> File Name: Ep46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 20时47分31秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 100000
#define swap(a, b) {\
    __typeof(a)__temp = a;\
    a = b;\
    b = __temp;\
}

int prime[max + 5] = {0};
int old[max + 5] = {0};

void quick_sort(int *a, int l,int r) {
    while (l < r) {
        int64_t x = l, y = r, z = a[(l + r) >> 2];
        do {
            while (a[x] < z) x++;
            while (a[y] > z) y--;
            if (x <= y) {
                swap(a[x], a[y]);
                ++x, --y;
            }
        } while(x <= y);
        //quick_sort(a, x, r);
        r = y;
    }
    return ;
}

void init() {
    for (int i = 2; i * i <= max; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= max; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) continue;
        if (i & 1) old[++old[0]] = i;
    }
    for (int i = 2; i <= max ; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    quick_sort(old, 1, old[0]);
    return ;
}

int is_gedebahe(int64_t x) {
    for (int i = 2; i <= prime[0]; i++) {
        if (prime[i] > x) continue;
        int64_t temp = (x - prime[i]) >> 1;
        for (int j = 0; j < max; j++) {
            if (temp < j * j) break;
            if (temp > j * j) continue;
            if (temp == j * j) {
                //printf("%d %d %d", temp, j, prime[i]);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    init();
    int64_t sum = max;
    //printf("%d\n", old[0]);
     is_gedebahe(5777);
    for (int i = 1; i <= old[0]; i++) {
       // printf("%d\n", old[i]);
        //printf("%d\n", is_gedebahe(old[i]));
       if(is_gedebahe(old[i])) continue;
        if(old[i] < sum) {
            sum = old[i];
            break;
        }
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
