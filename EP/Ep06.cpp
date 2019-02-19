/*************************************************************************
	> File Name: Ep06.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月09日 星期三 20时13分21秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= 100; i++) {
        sum1 += pow(i, 2);
    }
    for (int i = 1; i <= 100; i++) {
        sum2 += i;
    }
    sum1 = pow(sum2, 2) - sum1;
    printf("%d\n", sum1);
    return 0;
}
