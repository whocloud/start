/*************************************************************************
	> File Name: Ep09.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 16时47分34秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 1000

int main() {
    for (int i = 1; i < max; i++) {
        for (int j = i + 1; j < max; j++) {
            if(pow(i, 2) + pow(j, 2) == pow(max - i - j, 2)){
                printf("%d\n", i * j * (max - i - j));
                break;
            }
        }
    }
    return 0;
}
