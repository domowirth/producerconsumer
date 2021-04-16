#include "stringproducer.h"

#include <string>
#include <iostream>

using namespace std;

cStringProducer::cStringProducer(queue_t* queue) : cProducer(queue) {
}

void cStringProducer::run() {
	int i = 0;
	for(;;) {
		sleep(1);
		//cout<<"producing...\n";
		string* s = new string("item ");
		s->append(to_string(i));
		this->produce(queue, s);
		//cout<<"produced.  \n";
		i++;
		i %=26;
	}
}

