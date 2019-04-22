#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t lock;

int buffer=0;

void *thread(void* arg) 
{ 
    int count = 0;
    while(1)
    {
        pthread_mutex_lock(&lock);
        
        printf("Thread ID:%lu\nProcess ID:%d\nRecent buffer value :%d\n\n",pthread_self(),getpid(),buffer);

        if(buffer<24)
        {
            buffer++;
            count++;
        }
        
        pthread_mutex_unlock(&lock);

        if(buffer==24)
            break;
        sleep(1);
        
    }

return (int*)count;
} 




void main() 
{ 
 
    buffer=0;

	pthread_t thread1,thread2,thread3;

    pthread_create(&thread1, NULL, thread,void*(NULL));
    pthread_create(&thread2, NULL, thread, void*(NULL));
    pthread_create(&thread3, NULL, thread, void*(NULL));

    void *result;
	
    pthread_join(thread1, &result); 
    printf("\nThread No %d and updated the buffer %d times.",1,result);
	
    pthread_join(thread2, &result);
    printf("\nThread No %d and updated the buffer %d times.",2,result); 
	
    pthread_join(thread3, &result);
    printf("\nThread No %d and updated the buffer %d times.\n",3,result); 

	
} 