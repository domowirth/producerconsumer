#include "thread.h"
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <cstring>
#include <cstdlib>
 
cThreadException::cThreadException( const string &sMessage, bool isSysMsg) throw() :message(sMessage) {
    if (isSysMsg) {
        message.append(": ");
        message.append(strerror(errno));
    }
}
 
cThreadException::~cThreadException() throw () {
 
}
 
cThread::cThread() {
 
}
 
cThread::~cThread() {
 
}
 
void cThread::start() throw(cThreadException) {
   createThread();
}
 
void cThread::join() throw(cThreadException) {
    int rc = ::pthread_join(threadId, NULL);
    if ( rc != 0 ) {        
        throw cThreadException("Error in thread join.... (pthread_join())", true);
    }  
}
 
void* cThread::threadFunc( void* ptr ) {
    cThread* pThis = static_cast<cThread*>(ptr);
    pThis->run();
    ::pthread_exit(0); 
}
 
void cThread::createThread() throw(cThreadException) {
    int rc = ::pthread_create (&threadId, NULL, threadFunc, this);
    if ( rc != 0 ) {        
        throw cThreadException("Error in thread creation... (pthread_create())", true);
    }  
}