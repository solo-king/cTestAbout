#include<stdio.h>
#include <unistd.h>


int main(int argc, char**argv)
{
	
	int tmp_opt;
	while((tmp_opt =getopt(argc, argv, "ibc:")) != -1){
		printf("%c\n", tmp_opt);
	}
	printf("opt is end!!\n");
	return 0;
}
