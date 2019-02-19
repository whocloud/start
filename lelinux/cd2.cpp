/*************************************************************************
	> File Name: cd2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月21日 星期一 23时12分01秒
 ************************************************************************/
#include<iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>

char parsecmd(char *);
/************关于本文档********************************************
 * *filename:用C语言编写一个Linux下的简单shell程序
 * *purpose:展示了C语言如何进行系统调用执行logout cd ls pwd pid rm mkdir mv cp等命令
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言编程
 * *date time:2006-07-16 15:00:00
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL。
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * *********************************************************************/
int main(int argc, char ** argv)
{
    char cmd[1024];
    char tmp[101];
    char b = 'F';
    char * p;
    while(1) {
        memset(cmd, 0, 1024);
        system("pwd");/*显示提示信息*/
        fgets(cmd, 1000, stdin);/*接受用户输入，命令最长1000个字符*/
        cmd[strlen(cmd) - 1] = 0;/*去掉输入的回车符*/
        b = parsecmd(cmd);/*分析取得用户命令字*/
        if(b=='T') break;/*如果是logout就退出程序*/
        switch(b){
            case 1:/*切换工作目录*/
            if(chdir(cmd + 3) != 0) {
                printf("chdir(%s) error!%s\n", cmd + 3, strerror(errno));           
            }
            printf("I'm working in '%s' now\n", getcwd(tmp, 100));
            break;
            case 2:/*ls命令*/
            case 7:/*cp命令*/
            case 8:/*pwd命令*/
            system(cmd);
            break;
            case 3:/*pid命令*/
            printf("%d\n", getpid());
            break;
            case 4:/*rm命令*/
            remove(cmd + 3);
            break;
            case 5:/*mkdir命令*/
            mkdir(cmd + 6, 0755);
            break;
            case 6:/*mv命令*/
            p = strchr(cmd + 3, ' ');
            *p = 0;
            rename(cmd + 3, p + 1);
            break;
            case 0:/*不能识别的命令*/
            printf("Bad command, try again! All aviable commands are:\nlogout cd ls pwd pid rm mkdir mv cp\n", getpid());
            break;       
        }     
    }
}

 char parsecmd(char * s)
 {
    if(!strcasecmp(s, "logout")) return 'T';
    else if(!strncasecmp(s, "cd", 2)) return 1;
    else if(!strncasecmp(s, "ls", 2)) return 2;
    else if(!strncasecmp(s, "pwd", 3)) return 8;
    else if(!strncasecmp(s, "pid", 3)) return 3;
    else if(!strncasecmp(s, "rm", 2)) return 4;
    else if(!strncasecmp(s, "mkdir", 5)) return 5;
    else if(!strncasecmp(s, "mv", 2)) return 6;
    else if(!strncasecmp(s, "cp", 2)) return 7;
    else return 0;
}
