
#include<stdio.h>
#include <stddef.h>

struct test{
	
	int age;
	char* name;
};

int main(int argc, char **args){

	printf("%ld\n", offsetof(struct test, age));
	printf("%ld\n", offsetof(struct test, name));
	return 0;

}
