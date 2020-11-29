#pragma once
#include <iostream>
#include <cstdio>

template <typename T>
class Queue
{
public:
    Queue()
    {
    }
    ~Queue()
    {
        clear();
    }
    Queue(const Queue<T> &outro)
    {
        clone(outro);
    }

    Queue &operator=(const Queue<T> outro)
    {
        if (outro == this)
        {
            return *this;
        }

        clear();
        clone(outro);
        return *this;
    }

    void clear()
    {
        if (nodeCount == 0)
        {
            return;
        }

        Node *current = first;

        while (current != nullptr)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }

        nodeCount = 0;
        first = nullptr;
    }

    void pushBack(T value)
    {
        if (first!=nullptr)
        {
            Node* other = new Node();
            other->value = value;
            last->next = other;
            last=other;
            ++nodeCount;
            
        }else
        {
            first=new Node();
            first->value=value;
            last=first;
            ++nodeCount;
        }
        
        
    }

    void popFront()
    {
        first = first->next;
        nodeCount--;
    }

    T front()
    {
        return first->value;
    }

    T back()
    {
        return last->value;
    }

    size_t size() { return nodeCount; }

private:
    struct Node
    {
        T value;
        Node *next;
    };

    Node *first = nullptr;
    Node *last = nullptr;
    size_t nodeCount = 0;
};
