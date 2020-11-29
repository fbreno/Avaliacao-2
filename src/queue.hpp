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

    void print()
    {
        if (size() == 0)
        {
            return;
        }

        Node *current = first;

        do
        {
            std::cout << current->value << std::endl;
            current = current->next;
        } while (current != nullptr);
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
        if (first != nullptr)
        {
            Node *current = last;

            Node *other = new Node();
            other->value = value;
            current->next = other;
            last = other;

            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            first->next = last;
            ++nodeCount;
        }
    }

    void popFront()
    {
        first = first->next;
        nodeCount--;
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
