#ifndef __cthread_h__
#define __cthread_h__
extern "C" {   
  #include <pthread.h>
}
#include <string>
 
using namespace std;
 
/**
 *   Signals a problem with the thread handling.
 */
 
class cThreadException: public exception {

public:
   /**
   *   Construct a SocketException with a explanatory message.
   *   @param message explanatory message
   *   @param isSysMsg true if system message (from strerror(errno))
   *   should be postfixed to the user provided message
   */
    cThreadException(const string &message, bool isSysMsg = false) throw();
 
 
    /** 
    *   Destructor.
    *   Virtual to allow for subclassing.
    */
    virtual ~cThreadException() throw ();
 
    /** 
    *   Returns a pointer to the (constant) error description.
    *   @return A pointer to a \c const \c char*. The underlying memory
    *   is in posession of the \c Exception object. Callers \a must
    *   not attempt to free the memory.
    */
    virtual const char* what() const throw () {  
      return message.c_str(); 
    }
 
protected:
    /** 
    *   Error message.
    */
    string message;
};
 
 
/** 
*  Abstract class for Thread management 
*/
class cThread {

 public:
      
     /**
      *   Default Constructor for thread
      */
    cThread();
      
    /**
    *   virtual destructor  
    */
    virtual ~cThread();
      
    /**
    *   Thread functionality Pure virtual function  , it will be re implemented in derived classes  
    */
    virtual void run() = 0;
      
    /**
    *   Function to start thread. 
    */
    void start() throw(cThreadException);
     
    /**
    *   Function to join thread. 
    */
    void join() throw(cThreadException);

 private:
     
     /**
     *   private Function to create thread. 
     */
     void createThread() throw(cThreadException);
 
     /**
     *   Call back Function Passing to pthread create API
     */
     static void* threadFunc(void* ptr);
 
     /**
     *   Internal pthread ID.. 
     */
     pthread_t threadId;
};
#endif
