#ifndef __producerconsumer_h__
#define __producerconsumer_h__

#include "thread.h"

#define Q_SIZE 10

typedef struct {
    void* items[Q_SIZE];
    int occupied;
    int nextin;
    int nextout;
    pthread_mutex_t mutex;
    pthread_cond_t more;
    pthread_cond_t less;
} queue_t;

void produce(queue_t *queue, void* item);
void* consume(queue_t *queue);

#endif