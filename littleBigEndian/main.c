#include<stdio.h>

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
static int isBigEndian()
{
    int STR=0X1234;
    unsigned char str1 = (unsigned char)STR;
    printf("str1 =0x%x\n", str1);
    if(str1 == 0x34){
        return 0;
    }else if(str1 == 0x12){
        return 1;
    }else{
        return -1;
    }
}

/*
    return 0 小端
    return 1 大端
    return -1 错误
*/
static int isBigEndianWithUnion()
{
    union main  a;
    a.value = 0x1234;
    unsigned char str1 = a.byte[0];
    printf("str1 =0x%x\n", str1);
    if(str1 == 0x34){
        return 0;
    }else if(str1 == 0x12){
        return 1;
    }else{
        return -1;
    }
}

void main(void)
{
    //int res = isBigEndian();
    int res = isBigEndianWithUnion();
    if(0 == res){

        printf("little endian!!!\n");
    }else if(1 == res){
        
        printf("is big endian!!\n");
    }else{

        printf("error!!\n");
    }
    
}