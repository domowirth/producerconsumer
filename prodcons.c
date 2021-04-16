#include "prodcons.h"
#include <assert.h>

// see https://docs.oracle.com/cd/E19455-01/806-5257/sync-31/index.html

void produce(queue_t* queue, void* item) {
    pthread_mutex_lock(&queue->mutex);
   
    while (queue->occupied >= Q_SIZE) {
        pthread_cond_wait(&queue->less, &queue->mutex);
    }

    assert(queue->occupied < Q_SIZE);

    queue->items[queue->nextin++] = item;

    queue->nextin %= Q_SIZE;
    queue->occupied++;

    /* now: either b->occupied < BSIZE and b->nextin is the index
       of the next empty slot in the buffer, or
       b->occupied == BSIZE and b->nextin is the index of the
       next (occupied) slot that will be emptied by a consumer
       (such as b->nextin == b->nextout) */

    pthread_cond_signal(&queue->more);

    pthread_mutex_unlock(&queue->mutex);
}

void* consume(queue_t* queue) {
    void* item;
    pthread_mutex_lock(&queue->mutex);
    while(queue->occupied <= 0) {
        pthread_cond_wait(&queue->more, &queue->mutex);
    }

    assert(queue->occupied > 0);

    item = queue->items[queue->nextout++];
    queue->nextout %= Q_SIZE;
    queue->occupied--;

    /* now: either b->occupied > 0 and b->nextout is the index
       of the next occupied slot in the buffer, or
       b->occupied == 0 and b->nextout is the index of the next
       (empty) slot that will be filled by a producer (such as
       b->nextout == b->nextin) */

    pthread_cond_signal(&queue->less);
    pthread_mutex_unlock(&queue->mutex);

    return item;
}
