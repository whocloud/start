/*************************************************************************
	> File Name: ls.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月22日 星期二 00时00分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
 
 int main(int argc,char* argv[])
 //int main()
 {
    DIR *dp;
    struct dirent *dirp;
    dp=opendir(".");
    if(argc!=2)
    {
        printf("Big Warning:We need two parameters.Another is the dir.\n");
        return 0;
    }
    if((dp=opendir(argv[2]))==NULL)
    {
        printf("It is a super awkward!The dir wrong!\n");   
        exit(0);
        return 0;
    }
    while((dirp=readdir(dp))!=NULL)
    {
        printf("%s  ",dirp->d_name);
    }
    puts("");
    closedir(dp);
    return 0;
}
