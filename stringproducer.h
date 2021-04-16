#pragma once

#include "producer.h"

class cStringProducer: public cProducer {
	
	public:
		cStringProducer(queue_t* queue);
		void run();
};