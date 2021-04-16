#include "stringproducer.h"
#include "stringconsumer.h"

int main(int argc, char const *argv[])
{
	queue_t queue;
    queue.occupied=0;
    queue.nextin=0;
    queue.nextout=0;

	cStringProducer* t1 = new cStringProducer(&queue);
	t1->start();

	cStringProducer* t2 = new cStringProducer(&queue);
	//t2->start();

	cStringProducer* t3 = new cStringProducer(&queue);
	//t3->start();

	cStringConsumer* t0 = new cStringConsumer(&queue);
	t0->start();

	while(1) {
		//loop
		sleep(1);
	}

	return 0;
}
