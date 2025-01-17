#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int wantp=0;
int wantq=0;

void *p(void *a)
{
	while(1)
	{
		printf("        p in non-critical section\n");
		sleep(1);
		
		while(wantq != 0);
		
		wantp = 1;
		printf("        p in critical section\n");
		wantp = 0;
		
	}
}

void *q(void *a)
{
	while(1)
	{
		printf("        q in non-critical section\n");
		sleep(1);
		
		while(wantp != 0);
		
		wantq = 1;
		printf("        q in critical section\n");
		wantq = 0;
		
	}
}

int main()
{
	pthread_t x,y;
	
	pthread_create(&x, NULL, p, NULL);
	pthread_create(&y, NULL, q, NULL);
	pthread_join(x, NULL);
	pthread_join(y, NULL);
}
