#pragma once
#include <iostream>
#include <cstdio>

template <typename T>
class Stack
{
public:
    Stack()
    {
    }
    ~Stack()
    {
        clear();
    }

    void clear()
    {
        if (nodeCount == 0)
        {
            return;
        }

        Node *current = topo;

        while (current != nullptr)
        {
            Node *temp = current->prev;
            delete current;
            current = temp;
        }

        nodeCount = 0;
        topo = nullptr;
    }

    void push(T value)
    {
        if (topo != nullptr)
        {
            Node *current = topo;

            Node *other = new Node();
            other->value = value;
            other->prev = current;
            topo = other;

            ++nodeCount;
        }
        else
        {
            topo = new Node();
            topo->value = value;
            topo->prev = nullptr;
            ++nodeCount;
        }
    }

    T top()
    {
        return topo->value;
    }

    void pop()
    {
        topo = topo->prev;
        nodeCount--;
    }

    size_t size() { return nodeCount; }

private:
    struct Node
    {
        T value;
        Node *prev;
    };
    Node *topo = nullptr;
    size_t nodeCount = 0;
};