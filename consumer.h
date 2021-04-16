#pragma once
#include "prodcons.h"
#include "thread.h"

class cConsumer: public cThread {
	
	private:

	protected:
		queue_t* queue;
		void* consume(queue_t* queue);

	public:
		cConsumer(queue_t* queue);
};
