#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/*
功能:
    1.监听文件变化./selectFd1 ./selectFd2
    2.使用select机制监听这两个管道的read端
*/
#define SELECT_FD1  "./selectFd1"
#define SELECT_FD2  "./selectFd2"


static void readFdDataAndPrint(int fd);

int main(int argc, char**argv)
{
    int fd1 = 0;
    int fd2 = 0;

    fd_set fdset;
    fd_set fdset1;

    fd1 = open(SELECT_FD1, O_RDWR|O_CREAT, 0664);
    if(fd1 < 0){
        printf("fd1=%d\n", fd1);
        return -1;
    }

    fd2 = open(SELECT_FD2, O_CREAT|O_RDWR, 0664);

    if(fd2 < 0){
        printf("fd2=%d\n", fd2);
        return -1;
    }

    /* 初始化一个fd记录串 */
    FD_ZERO(&fdset);
    FD_ZERO(&fdset1);
    /* 添加文件句柄至fdset */
    FD_SET(fd1, &fdset1);
    FD_SET(fd2, &fdset1);
    
    for(;;){
        int selectRet = 0;
        fdset = fdset1;
        selectRet = select(fd2+1, &fdset, NULL, NULL, NULL);
        
        if(selectRet < 0){
            printf("select error!!,selectRet = %d\n", selectRet);
            continue;
        }
        
        if(FD_ISSET(fd1, &fdset)){
            //printf("fd1 have date,read it!!");
            readFdDataAndPrint(fd1);
        }
        if(FD_ISSET(fd2, &fdset)){
            //printf("fd2 have date,read it!!");
            readFdDataAndPrint(fd1);
        } 
    }

    return 0;
}


static void readFdDataAndPrint(int fd){
    
    char readBuffer[64] ={'\0'};
    int readSize = read(fd, readBuffer, 64);
    if(readSize > 0){
        printf("readBuffer=%s, readSize=%d\n", readBuffer, readSize);
    }
    
}