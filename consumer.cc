#include "consumer.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

cConsumer::cConsumer(queue_t* queue) {
	this->queue = queue;
}

void* cConsumer::consume(queue_t* queue) {
    void* item;
    ::pthread_mutex_lock(&queue->mutex);
    while(queue->occupied <= 0) {
        ::pthread_cond_wait(&queue->more, &queue->mutex);
    }
    assert(queue->occupied > 0);
    item = queue->items[queue->nextout++];
    queue->nextout %= Q_SIZE;
    queue->occupied--;
    ::pthread_cond_signal(&queue->less);
    ::pthread_mutex_unlock(&queue->mutex);

    return item;
}

