/*
大小端定义:
    大端:
        低字节存储高有效位
    小端:
        低字节存储底有效位
*/
#include<stdio.h>
//宏定义方式却别大小端
static union { char c[4]; unsigned long l; }endian_test = { { 'l', '?', '?', 'b' } };
#define ENDIANNESS ((char)endian_test.l)

union main
{
    unsigned short int value;
    unsigned char byte[2];
};

/*
    return 0 小端
    return 1 大端
    return -1 错误
*/
static int isBigEndianWithUnion()
{
    union main  a;
    a.value = 0x1234;
    printf("a.byte[0]=0x%x, &a.byte[0]=0x%x, &a.byte[1]=0x%x\n", a.byte[0], &a.byte[0], &a.byte[1]);
    if(a.byte[0]== 0x34){
        return 0;
    }else if(a.byte[0] == 0x12){
        return 1;
    }else{
        return -1;
    }
}

void main(void)
{
    #if 1
    //int res = isBigEndian();
    int res = isBigEndianWithUnion();
    if(0 == res){

        printf("little endian!!!\n");
    }else if(1 == res){
        
        printf("is big endian!!\n");
    }else{

        printf("error!!\n");
    }
    #endif
}
