/*************************************************************************
	> File Name: Ep27.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月22日 星期二 11时54分03秒
 ************************************************************************/

#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<inttypes.h>

#define MAX_N 1000
#define MAX_M 2500
#define R_M_TEST_ROUND 30

int prime[MAX_M + 5] = {0};

int32_t gcd(int32_t a,int32_t b) {
    if(!b) return a;
    return gcd(b, a % b);
}

//快速幂代码
int quickPow(int a, int b) {
    int ans = 1, temp = a;
    while(b) {
        if (b & 1) ans = ans * temp;
        temp = temp * temp;
        b >>= 1;
    }
    return ans;
}
//a ^ (p - 1) % p == 1其中p为素数 a是p到p - 1中任意值
bool R_M_TEST(int32_t x) {
    if (x <= 1) return false;
    int64_t a, m, ans;
    for (int32_t i = 0; i < R_M_TEST_ROUND; i++) {
        a = (rand() % (x - 1)) + 1;
        ans = 1;
        m = x - 1;
        while(m) {
            if(m % 2) ans = (ans * a) % x;
            a = (a * a) % x;
            m /= 2;
        }
        if(ans != 1) return false;
    }
    return true;
}

int32_t HowManyPrime(int32_t a, int32_t b) {
    int32_t i = 0;
    while(R_M_TEST(i * i + a * i + b)) i++;
    return i;
}

int main() {
    srand(time(0));
    prime[1] = INT_MAX;
    for(int32_t i = 2; i <= MAX_M; i++)
    if(!prime[i])
    for(int32_t j = i; j <= MAX_M; j += i)
    if(!prime[j]) prime[j] = i;
    int32_t maxNum = 40, tempNum, result = 0;
    for(int32_t a = 1 - MAX_N; a < MAX_N; a++)
    for(int32_t b = (a < 0 ? -a + 1 : 2); b < MAX_N; b++) {
        if(prime[b] != b) continue;
        if(prime[b + a + 1] != b + a + 1) continue;
        if(a > 0 && b > 0 && prime[gcd(a, b)] <= maxNum) continue;
        tempNum = HowManyPrime(a, b);
        if(tempNum > maxNum) {
            result = a * b;
            maxNum = tempNum;
        }
    }
    printf("%d\n", result);
    return 0;
}
