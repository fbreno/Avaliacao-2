#include <iostream>
#include <vector>
#include "LinkedList.hpp"
#include "stack.hpp"
#include "queue.hpp"

int main(int argc, char const *argv[])
{
    LinkedList<int> lista;
    lista.insert(1);
    lista.insert(3);
    lista.insertAtFront(4);
    lista.insert(8);
    lista.insertAt(2,2);
    lista.print();
    std::cout<<"Numero de nodes: "<<lista.size()<<std::endl;
return 0;
}