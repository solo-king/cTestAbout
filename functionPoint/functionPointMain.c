#include<stdio.h>

typedef int (*pAdd)(int , int);
typedef int (add)(int , int);



static int ganyeAdd( int a, int b )
{
    return a+b;
}

int main( int argc, char**argv)
{

    pAdd myAdd = &ganyeAdd;
    add *myAdd1 = ganyeAdd;

    int sum1 = myAdd(3, 5);
    int sum2 = ganyeAdd(3, 6);
    int sum3 = (*myAdd1)(3, 7);
    printf("sum1=%d, sum2=%d, sum3=%d\n", sum1, sum2, sum3);
    return 0;
}