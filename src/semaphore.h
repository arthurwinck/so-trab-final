#ifndef semaphore_h
#define semaphore_h

#include "cpu.h"
#include "thread.h"
#include "traits.h"
#include "debug.h"
#include "list.h"

__BEGIN_API

class Semaphore
{
public:

    typedef Ordered_List<Thread> Wait_Queue;
    

    Semaphore(int v = 1);
    ~Semaphore();

    void p();
    void v();
private:
    // Atomic operations
    int finc(volatile int & number) {return CPU::finc(number);}
    int fdec(volatile int & number) {return CPU::fdec(number);}

    // Thread operations
    void sleep();
    void wakeup();
    void wakeup_all();

private:
    //DECLARAÇÃO DOS ATRIBUTOS DO SEMÁFORO
    volatile int license_num;
    //Queue Queue
    Ordered_List<Thread> _wait;


};

__END_API

#endif

