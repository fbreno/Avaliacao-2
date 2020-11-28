#include <iostream>
#include <vector>
#include "LinkedList.hpp"

int main(int argc, char const *argv[])
{
    LinkedList<int> lista;
    lista.insertAtBack(1);
    lista.insertAtFront(3);
    lista.insertAtBack(4);
    lista.insertAtBack(84);
    //lista.insertAt(2,1);
    lista.print();
    std::cout<<"Numero de nodes: "<<lista.getNodeCount()<<std::endl;
return 0;
}