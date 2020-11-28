#pragma once
#include <iostream>
#include <cstdio>

template <typename T>
class stack
{
private:
    struct Node
    {
        T value;
        Node *prev;
    };
    Node *frist = nullptr;
    size_t tam;

public:
    stack();
    ~stack();

    size_t size() { return tam; }

    void push(T value)
    {
        if (frist != nullptr)
        {
            Node *last = frist;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            Node *outro = new Node();
            outro->value = value;
            last->next = outro;
            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            ++nodeCount;
        }
    }
};