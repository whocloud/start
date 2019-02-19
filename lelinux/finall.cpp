/*************************************************************************
	> File Name: cd-ls-test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 19时27分28秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void info_print();
void my_ls_l(char *cur_dir);
void my_ls(char *);
void my_cd(char *);
char * my_pwd();
char parsecmd(char *);
char sbuf[512] = {0};
char sbuf1[512] = {0};
char buffer[512];
char b = 'F';
char cmd[1024] = {0};

#define MAXSIZE 100

int main(int argc, char **argv, char **environ)
{
    while(1) {
        info_print();
        //printf("%s$", getcwd(NULL, NULL));
        fgets(cmd, 1000, stdin);
        cmd[strlen(cmd) - 1] = 0;
        b = parsecmd(cmd);
        switch(b) {
            case 1:
                //chdir(&cmd[3]);
                my_cd(&cmd[3]);
              break;
            case 2:{
                my_ls(my_pwd());
              break;}
            case 3:{
                my_ls_l(my_pwd());
              break;
            }
            case 0:
            printf("Bad command, try again! All aviable commands are:\ncd ls ls -l");
            break;
        }
        memset(cmd, 0, 1024);
    }
}

void my_ls(char *cur_dir)
{
    DIR *dir;
    struct dirent *link;
    struct stat buf;
    dir = opendir(cur_dir);
    while ((link = readdir(dir)) != NULL)
    {
        if (lstat(link -> d_name, &buf) == -1)
        {
            perror("lstat");
            continue;
        }
        if (strcmp(link -> d_name, ".") == 0 || strcmp(link -> d_name, "..") == 0)
        {
            continue;       
        }
        sprintf(sbuf1, "%s", link -> d_name);
        printf("%s\n", sbuf1);
    }
}


void my_ls_l(char *cur_dir)
{
    DIR *dir;
    struct dirent *link;
    struct stat buf;
    struct tm *p;
    char file_type[11] = {0};
    char t_buffer[128] = {0};
    dir = opendir(cur_dir);
    while ((link = readdir(dir)) != NULL)
    {
        if (lstat(link -> d_name, &buf) == -1)
        {
            perror("lstat");
            continue;
        }
       if (strcmp(link -> d_name, ".") == 0 || strcmp(link -> d_name, "..") == 0)
        {
            continue;       
        }
        strcpy(file_type, "----------");
        switch (buf.st_mode & S_IFMT) //S_IFMT      0170000     文件类型的位遮罩
          //st_mode是用特征位来表示文件类型的.判断文件类型时，用对文件的st_mode的值与上面给出的值相与，再比较。
        {
            case S_IFSOCK :  //S_IFSOCK    0140000     socket
                file_type[0] = 's';  //  s表示该文件是存放socket信息的，一般是给 process 之前用来进行 network socket 存取沟通使用的档案；
                break;
            case S_IFLNK :  //S_IFLNK     0120000     符号链接(symbolic link)
                file_type[0] = 'l';  // l表示连接文件；
                break;
            case S_IFBLK :  //S_IFBLK     0060000     区块装置(block device)
                file_type[0] = 'b';  // b表示为装置(device)文件中可供存储的接口设备；
                break;
            case S_IFDIR :  //S_IFDIR     0040000     目录
                file_type[0] = 'd';  // d表示目录；
                break;
            case S_IFCHR :  //S_IFCHR     0020000     字符装置(character device)
                file_type[0] = 'c';  // c表示为装置文件中的串行端口设备（如键盘，鼠标）；
                break;
            case S_IFIFO :  //S_IFIFO     0010000     先进先出(fifo)
                file_type[0] = 'f';
                break;
            default :
                break;
        }
        if (buf.st_mode & S_IRUSR) // 00400       文件所有者具可读取权限
        {
            file_type[1] = 'r';
        }
        if (buf.st_mode & S_IWUSR)  // 00200       文件所有者具可写入权限
        {
            file_type[2] = 'w';    
        }
        if (buf.st_mode & S_IXUSR)  //  00100       文件所有者具可执行权限
        {
            file_type[3] = 'x';
        }
        if (buf.st_mode & S_IRGRP)  //  00040       用户组具可读取权限
        {
            file_type[4] = 'r';    
        }
        if (buf.st_mode & S_IWGRP)  //00020       用户组具可写入权限
        {
            file_type[5] = 'w';
        }
        if (buf.st_mode & S_IXGRP)  //00010       用户组具可执行权限
        {
            file_type[6] = 'x';        
        }
        if (buf.st_mode & S_IROTH)  //00004       其他用户具可读取权限
        {
            file_type[7] = 'r';  //只读
        }
        if (buf.st_mode & S_IWOTH)  //  00002       其他用户具可写入权限
        {
            file_type[8] = 'w'; //只写         
        }
        if (buf.st_mode & S_IXOTH)  //  00001       其他用户具可执行权限
        {
            file_type[9] = 'x';    //可执行              
        }
        p = gmtime((time_t *)&(buf.st_mtim));  //获取当前时间和日期,time_t 结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果由结构tm 返回。
        strftime(t_buffer, 128, "%b %e %H:%M", p); //把YYYY-MM-DD HH:MM:SS格式的日期字符串转换成其它形式的字符串。
        sprintf(sbuf, "%s  %3d %-8d %-8d %8lu %s %s", file_type, (int)buf.st_nlink, buf.st_uid, buf.st_gid, (long)buf.st_size, t_buffer, link -> d_name);
        printf("%s\n", sbuf);
    }
}

void my_cd(char *m)
{
    chdir(m);
    //printf("%s\n",getcwd(NULL, NULL));
}

char * my_pwd()
{
    memset(buffer, 0, sizeof(buffer));
    getcwd(buffer, sizeof(buffer));
    //printf("%s\n", buffer);
    return buffer;
}

char parsecmd(char *s) {
    if(!strncasecmp(s, "cd", 2)) return 1;
    if(!strncasecmp(s, "ls -l", 5)) return 3;
    if(!strncasecmp(s, "ls", 2)) return 2;
    else return 0;
}

void info_print() {
    char buf[MAXSIZE], *username, hostname[MAXSIZE], pwd[MAXSIZE], ch;
    bzero(buf, MAXSIZE);
    bzero(pwd, MAXSIZE);
    bzero(hostname, MAXSIZE);
    if((username = getenv("USER")) == NULL) {
        printf("Error: get username failure!\n");
        exit(-1);
    }
    if(getcwd(pwd, MAXSIZE) == NULL) {
        perror("getcwd");
        exit(-1);
    }
    if(gethostname(hostname, MAXSIZE) == -1) {
        perror("gethostname");
        exit(-1);
    }
    if(strcmp(username,"root") == 0) {
        ch = '#';
    } else {
        ch = '$';
    }
    sprintf(buf, "%s@%s:%s%c ", username, hostname, pwd, ch);
    fprintf(stdout, "%s", buf);
}
