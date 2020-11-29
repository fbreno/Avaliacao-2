#include <iostream>
#include <vector>
#include "LinkedList.hpp"
#include "stack.hpp"
#include "queue.hpp"

int main(int argc, char const *argv[])
{
    Queue<int> lista;
    lista.pushBack(10);
    lista.pushBack(140);
    lista.popFront();
    std::cout<<lista.front()<<std::endl;
    std::cout<<lista.back()<<std::endl;
    std::cout<<"Numero de nodes: "<<lista.size()<<std::endl;
return 0;
}