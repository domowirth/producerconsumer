#pragma once

#include "consumer.h"

class cStringConsumer: public cConsumer {
	


	public:
		cStringConsumer(queue_t* queue);
		void run();
};