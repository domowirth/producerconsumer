#include "stringconsumer.h"

#include <string>
#include <iostream>

using namespace std;

cStringConsumer::cStringConsumer(queue_t* queue) : cConsumer(queue) {
}

void cStringConsumer::run() {
	for(;;) {
		sleep(2);
		//cout<<"consuming...\n";
		string* s = (string*) this->consume(queue);
		cout<<"consumed:  "<<s->c_str()<<".\n";
		delete s;
	}
}

