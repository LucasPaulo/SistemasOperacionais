#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

int buffer[BUFFER_SIZE];

pthread_t ptid,ctid;
pthread_attr_t attr;

void *producer(void *param);
void *consumer(void *param);

int counter;
  int main(){
    init();
    pthread_create(&ptid, &attr, producer, NULL);
    pthread_create(&ctid, &attr, consumer, NULL);
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);

    return 0;
}

  void init(){

   pthread_mutex_init(&mutex, NULL);
   pthread_attr_init(&attr);
   sem_init(&full, 0, 0);
   sem_init(&empty, 0, BUFFER_SIZE);
   counter = 0;
   for(int j=0; j<BUFFER_SIZE; j++){
        buffer[j] = 0;
  }
}

void *producer(void *param){
int item;
  while(1){
   item=item+1;
   sem_wait(&empty);
   pthread_mutex_lock(&mutex);

   if(insert_item(item)){
    perror("Producer error.");
    return 1;
}
  else
  {
  printf("Producer produced %d\n", item);
}
   pthread_mutex_unlock(&mutex);
   sem_post(&full);
  }
}

 void *consumer(void *param){
  int item;
   while(1){
   sleep(5);
     sem_wait(&full);
     pthread_mutex_lock(&mutex);
     if(remove_item(item)){
     perror("COnsumer error.");
}
 else
{
   printf("Consumer consumed %d\n", item);
}
   pthread_mutex_unlock(&mutex);
   sem_post(&empty);
 }
}
   int insert_item(int item){
  if(counter < BUFFER_SIZE){
    buffer[counter] = item;
    counter ++;
    return 0;
}
   else
    return -1;
}

   int remove_item(int item){
      if(counter > 0){
      item = buffer[(counter -1)];
      counter--;
      return ;
}
   else
     return -1;
}

