#include<stdio.h>
#include<signal.h>
#include<pthread.h>
#include<unistd.h>
#include <errno.h>




static void *while_pet_watchdog (void *arg)
{
	
	while(1){
		printf("%s,%d\n",__func__, __LINE__);				
		sleep(1);
	}
	printf("thread exit!!!");
		
}

int main()
{
	int ret = -1;
	pthread_t thread1;
	if((ret = pthread_create(&thread1, NULL,while_pet_watchdog, NULL) )== 0){
		printf("while_pet_watchdog thread create succeed!!\n");
	}else{
		printf("while_pet_watchdog thread create error!!,ret=%d",ret);
	}	
	sleep(5);
	ret = pthread_kill(thread1, 0);
	if(ret == ESRCH){
		printf("thread is not exist,start it!!\n");
		if((ret = pthread_create(&thread1, NULL,while_pet_watchdog, NULL) )== 0){
			printf("while_pet_watchdog thread create succeed!!\n");
		}else{
			printf("while_pet_watchdog thread create error!!,ret=%d",ret);
		}	
		
	}else if(ret == EINVAL){
		printf("sig is inval\n");
	}else{
		printf("thread_kill ret = %d,thread1 is exist.stop it\n", ret);
		pthread_cancel(thread1);
		printf("thread1 = %ld\n", thread1);
		sleep(3);
	}
	ret = pthread_kill(thread1, 0);
	if(ret == ESRCH){
		printf("thread is not exist,start it again!!\n");
		if((ret = pthread_create(&thread1, NULL,while_pet_watchdog, NULL) )== 0){
			printf("while_pet_watchdog thread create succeed!!\n");
		}else{
			printf("while_pet_watchdog thread create error!!,ret=%d",ret);
		}	
	}
	while(1);
}
