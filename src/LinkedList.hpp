#pragma once
#include <iostream>
#include <cstdio>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node *prev;
        Node *next;
    };
    void clone(const LinkedList &outro)
    {
        if (outro.nodeCount == 0)
        {
            return;
        }
        else
        {
            Node *current = outro.frist;
            while (current != nullptr)
            {
                insert(current->value);
                current = current->next;
            }
        }
    }
    Node *frist = nullptr;
    Node *last = nullptr;
    size_t nodeCount = 0;

public:
    LinkedList();
    ~LinkedList()
    {
        clear();
    }
    LinkedList(const LinkedList<T> &outro)
    {
        clone(outro);
    }

    LinkedList &operator=(const LinkedList<T> outro)
    {
        if (outro == this)
        {
            return *this;
        }

        clear();
        clone(outro);
        return *this;
    }

    void insert(T value)
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

    T &operator[](size_t index)
    {
        if (index >= nodeCount)
        {
        }

        Node *current = first;
        size_t currentIndex = 0;

        while (currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }

        return current->value;
    }

    size_t search(T value)
    {
        Node *current = first;
        size_t index = 0;

        while (current != nullptr)
        {
            current = current->next;
            ++index;
            if (current == value)
            {
                return index;
            }
        }
    }

    void clear()
    {
        if (nodecount == 0)
        {
            return;
        }

        Node *current = frist;

        while (curret != nullptr)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }

        nodeCount = 0;
        frist = nullptr;
    }

    void removeAt(size_t index)
    {
        if (index >= nodeCount)
        {
            //erro
        }

        Node *current = first;
        Node *tempPrev = nullptr;
        size_t currentIndex = 0;

        while (currentIndex < index)
        {
            tempPrev = current;
            current = current->next;
            currentIndex++;
        }
        Node *tmpNext = current->next;
        tempPrev->next = current->next;
        tmpNext->prev = current->prev;
        delete current;
    }

    void insertAt(T value, size_t position)
    {
        if (position >= nodeCount)
        {
            //erro
        }

        Node *current = first;
        Node *temp = nullptr;
        size_t currentIndex = 0;

        while (currentIndex < position)
        {
            temp = current;
            current = current->next;
            currentIndex++;
        }

        Node *outro = new Node();
        outro->value = value;
        temp->next = outro;
        current->prev = outro;
        ++nodeCount;
    }

    void insertAtFront(T value)
    {
        Node *temp = frist;
        frist->value = value;
        frist->next = temp;
        temp->prev = frist;
    }

    void insertAtBack(T value)
    {
        Node *temp = last;
        last->value = value;
        temp->next = last;
        last->prev = temp;
    }

    void removeAtFront()
    {
        frist = frist->next;
        frist->prev = nullptr;
    }

    void removeAtBack()
    {
        last = last->prev;
        last->next = nullptr;
    }

    size_t size() { return nodeCount; }
};
