#include <iostream>
#include <vector>
#include "LinkedList.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include <fstream>
#include <sstream>
using std::cout;
using std::string;
LinkedList<int> lista;
Stack<int> pilha;
Queue<int> fila;

void alterFila(string comando, string valor)
{
    if (comando=="size")
    {
        cout << "Tamanho da fila: "<<fila.size()<<std::endl;
    }

    if (comando == "pushBack")
    {
        int ele = stoi(valor);
        cout << "Iserindo elemento na fila: " << ele << std::endl;
        fila.pushBack(ele);
    }

    if (comando == "popFront")
    {
        cout << "Removendo primeiro elemento da fila: " << std::endl;
        fila.popFront();
    }

    if (comando == "front")
    {
        cout << "Primeiro elemento da fila: " << fila.front() << std::endl;
    }

    if (comando == "back")
    {
        cout << "Ultimo elemento da fila: " << fila.back() << std::endl;
    }
}

void alterarPilha(string comando, string valor)
{
    if (comando=="size")
    {
        cout << "Tamanho da Pilha: "<<pilha.size()<<std::endl;
    }

    if (comando == "push")
    {
        int ele = stoi(valor);
        cout << "Inserindo elemento na pilha: " << ele << std::endl;
        pilha.push(ele);
    }
    if (comando == "top")
    {
        cout << "Elemento do topo da pilha: " << pilha.top() << std::endl;
    }
    if (comando == "pop")
    {
        cout << "Removendo elemento da pilha" << std::endl;
        pilha.pop();
    }
}

void alterarLista(string comando, string valor)
{
    if (comando == "insert")
    {
        int ele = stoi(valor);
        cout << "Inserindo na lista: " << ele << std::endl;
        lista.insert(ele);
    }

    if (comando == "insertAtBack")
    {
        int ele = stoi(valor);
        cout << "Inserindo no final da lista: " << ele << std::endl;
        lista.insertAtBack(ele);
    }

    if (comando == "insertAt")
    {
        std::stringstream ss;
        ss<<valor<<' '<<valor;
        size_t pos;
        int ele;
        ss>>ele>>pos;
        cout << "Inserindo: " << ele <<" na posição "<<pos<<" da lista."<<std::endl;
        lista.insertAt(ele, pos);
    }
    
    if (comando=="insertAtFront")
    {
        int ele = stoi(valor);
        cout << "Inserindo no inicio da lista: " << ele << std::endl;
        lista.insertAtFront(ele);
    }

    if (comando=="removeAt")
    {
        int ele = stoi(valor);
        cout << "Removendo da lista no indice: " << ele << std::endl;
        lista.removeAt(ele);
    }

    if (comando=="removeAtBack")
    {
        cout << "Removendo do final da lista." <<std::endl;
        lista.removeAtBack();
    }

    if (comando=="removeAtFront")
    {
        cout << "Removendo do inicio da lista." <<std::endl;
        lista.removeAtFront();
    }
    
    if (comando=="size")
    {
        cout << "Tamanho da lista: "<<lista.size()<<std::endl;
    }

    if (comando=="print")
    {
        cout<<"Imprimindo a lista: "<<std::endl;
        //lista.print();
    }
         
    if (comando=="search")
    {   
        int ele=stoi(valor);
        size_t pos=lista.search(ele);
        if(pos==0)
        {
            cout<<"Elemento não encontrado"<<std::endl;
        }else
        {
            cout<<"O elemento procurado está na posição: "<<pos<<std::endl;
        }
        
    }
        
    
}

void executar(string nome)
{
    std::ifstream file;
    std::string str, estrutura, comando, valor;
    file.open(nome);
    while (std::getline(file, str))
    {
        std::stringstream ss;
        ss << str << ' ' << str << ' ' << str;
        ss >> estrutura >> comando >> valor;
        if (estrutura == "queue")
        {
            alterFila(comando, valor);
        }

        if (estrutura == "stack")
        {
            alterarPilha(comando, valor);
        }

        if (estrutura == "list")
        {
            alterarLista(comando, valor);
        }
    }
    file.close();
}
int main(int argc, char const *argv[])
{
    string nome(argv[1]);
    executar(nome);
    return 0;
}