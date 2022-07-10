#include "semaphore.h"
#include "thread.h"
#include "traits.h"

__BEGIN_API    

//wait
void Semaphore::p() {
    //begin_atomic();
    if (fdec(license_num) < 1) {
        db<Semaphore>(TRC) << "P() - Número de licenças: " << license_num << "\n";
        sleep();
    }
    //begin_atomic();
    /// if(fdec(_value) < 1) {
        //sleep
    //} else {
        //end_atomic();
    //}


}

// post
void Semaphore::v() {
    if(finc(license_num) < 0) {
        db<Semaphore>(TRC) << "V() - Número de licenças: " << license_num << "\n";
        wakeup();
    }
    /* 
    being_atomic();
    if(finc(_value)) < 0) {
        wakeup(); //implicit end_atomic;
    else
        end_atomic();
    }
    
    */

}

void Semaphore::sleep() {
    Thread::sleep(&this->_wait);
}

void Semaphore::wakeup() {
    Thread::wakeup(&this->_wait);
}

void Semaphore::wakeup_all() {
    Thread::wakeup_all(&this->_wait);
}

Semaphore::Semaphore(int v){
    this->license_num = v;
}

Semaphore::~Semaphore() {
    db<Semaphore>(TRC) << "Semáforo sendo destruído\n";
    Thread::wakeup_all(&this->_wait);
}


// void Thread::reschedule() {
//     yield();
// }
__END_API