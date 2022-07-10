#include "cpu.h"
#include <iostream>
#include "ucontext.h"

__BEGIN_API

void CPU::Context::save()
{
    //adicionar implementação
    getcontext(&this->_context);
    //utiliza o método getcontext para salvar o contexto atual do objeto apontado por _context
}

void CPU::Context::load()
{
    //adicionar implementação
    setcontext(&this->_context);
    //restaura o contexto salvo apontado pelo _context
}

int CPU::finc(volatile int & number) {
    int value = 1;
    asm("lock xadd %0, %1;" : "=r" (value) : "m" (number), "0" (value) : "memory");
    return value;
}

int CPU::fdec(volatile int & number) {
    int value = -1;
    asm("lock xadd %0, %1;" : "=r" (value) : "m" (number), "0" (value) : "memory");
    return value;
}


CPU::Context::~Context()
{
    //adicionar implementação
    //chamado quando o contexto é deletado no final de main
    //Update para a destruição da stack
    if (this->_stack) {
        delete this->_stack;
    }
}

__END_API
