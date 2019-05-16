/*
描述:
    作为socket service
    将从socket client中读取到的数据打印出来
*/
/*
基础调用:
    int socket(int domain, int type, int protocol);
        type:
            SOCK_STREAM
                1.applications are unaware of message boundaries.
                2.可能需要多次调用才能接收完数据
    int shutdown(int sockfd, int how);
        功能描述:
            关闭一路socket io
        参数:
            how:SHUT_RD SHUT_WD SHUT_WR
    close()
        1.只有在最后所有活动的引用关闭后，才会释放socket资源(close will deallocate the network endpoint only when the last active reference is closed)
        2.
    int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict len);
        功能:
    大小端字节转换:
        uint32_t htonl(uint32_t hostint32);
            Returns: 32-bit integer in network byte order
        uint16_t htons(uint16_t hostint16);
            Returns: 16-bit integer in network byte order
        uint32_t ntohl(uint32_t netint32);
            Returns: 32-bit integer in host byte order
        uint16_t ntohs(uint16_t netint16);
            Returns: 16-bit integer in host byte order
    socket返回的fd限制:
        1.lseek doesn’t work with sockets
    地址:
        The machine’s network address helps us identify the computer on the network we wish to
        contact, and the service, represented by a port number, helps us identify the particular
        process on the computer.
        通用的地址格式：    
            struct sockaddr {
                sa_family_t sa_family; //address family
                char sa_data[];//variable-length address 
                ...
            };
        linux实现:
            struct sockaddr {
                sa_family_t sa_family; // address family
                char sa_data[14]; //variable-length address
            };
    大小端:(大端:低内存放置高有效字节   小端:低内存放置底有效字节)
        1.The TCP/IP protocol suite uses big-endian byte order
        2.
    转化地址为可读:
        const char *inet_ntop(int domain, const void *restrict addr,char *restrict str, socklen_t size);
            Returns: pointer to address string on success, NULL on error
        int inet_pton(int domain, const char *restrict str,void *restrict addr);
            Returns: 1 on success, 0 if the format is invalid, or −1 on error
*/
#include <stdio.h>

int main(int argc, char**argv)
{
    int socketFd = socket();
    if(socketFd < 0){
        goto openSocketErr;
    }


openSocketErr:
    close(socketFd);
    return 0;
}
