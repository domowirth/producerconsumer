#pragma once

#include "prodcons.h"
#include "thread.h"

class cProducer: public cThread {
	
	private:

	protected:
		queue_t* queue;
		void produce(queue_t* queue, void* item);

	public:
		cProducer(queue_t* queue);
};
