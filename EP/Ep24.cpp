/*************************************************************************
	> File Name: Ep24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月26日 星期三 18时43分07秒
 ************************************************************************/
#include<stdio.h>
#define max 10

int jnum[max] = {0};
int dnum[max] = {0};

void init() {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < max; i++) {
        dnum[i] = 1;//记录该数字是否变动过不变为1变为0
        jnum[i] = i * jnum[i - 1];//是几的阶乘
    }
    return ;
}

int get_num(int n, int k) {
    int ind = (k / jnum[n]) + 1, i = -1;
    //这是错误的
    //int ind = (k / jnum[n]), i = 0;//记录次数该第几位变动
    while (ind > 0) {//如0123 k= 9，ind=2 第一次i=0ind=1第二次i=1ind=0
        i++;//dnum【1】为0 1就是变动的输出它因为它是最前头的
        ind -= dnum[i];//当第一次ind=1时i=0时结束所以0位置不变并输出
    }//由于已输出的元素dnum为0所以ind减操作时ind不变相当于跳过这个位置
    dnum[i] = 0;
    return i;
}

int main() {
    init ();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1;i >= 0; i--) {
        int num = get_num(i, k);//传入变动一次最大的位数和代变动次数
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
