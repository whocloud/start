/*************************************************************************
	> File Name: EP02-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时46分08秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000
int main(){
    int fib[3], n = 2,ans = 0;
    fib[0] = fib[1] = 1;
    while (fib[(n - 1) % 3] <= MAX_N){
        if((fib[(n -1) % 3] &1) == 0) {
            ans += fib[(n - 1) % 3];
        }
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        n += 1;
    }
    printf("%d\n",ans);
    return 0;
}


