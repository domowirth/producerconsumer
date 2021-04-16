#include "producer.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

cProducer::cProducer(queue_t* queue) {
	this->queue = queue;
}

void cProducer::produce(queue_t* queue, void* item) {
    ::pthread_mutex_lock(&queue->mutex);
    while (queue->occupied >= Q_SIZE) {
        ::pthread_cond_wait(&queue->less, &queue->mutex);
    }
    assert(queue->occupied < Q_SIZE);
    queue->items[queue->nextin++] = item;
    queue->nextin %= Q_SIZE;
    queue->occupied++;
    ::pthread_cond_signal(&queue->more);
    ::pthread_mutex_unlock(&queue->mutex);
}

