#pragma once
#include <iostream>
#include <cstdio>

template <typename T>
class LinkedList
{
public:
    LinkedList()
    {
    }
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
        if (first != nullptr)
        {
            Node *current = last;

            Node *other = new Node();
            other->value = value;
            current->next = other;
            other->prev = current;
            last = other;

            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            first->prev = nullptr;
            last = first;
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
        return 0;
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

    void removeAt(size_t index)
    {
        if (index >= nodeCount)
        {
            std::cout << "Posição digitada inválida" << std::endl;
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
        nodeCount--;
    }

    void insertAt(T value, size_t position)
    {
        if (position >= nodeCount)
        {
            std::cout << "Posição digitada inválida" << std::endl;
            return;
        }

        Node *current = first;
        Node *temp = new Node();
        size_t currentIndex = 0;

        while (currentIndex < position-1)
        {
            temp = current;
            current = current->next;
            currentIndex++;
        }

        Node *outro = new Node();
        outro->value = value;
        outro->prev = temp;
        outro->next = current;
        temp->next = outro;
        current->prev = outro;

        ++nodeCount;
    }

    void insertAtFront(T value)
    {
        if (first != nullptr)
        {
            Node *current = first;

            Node *other = new Node();
            other->value = value;
            current->prev = other;
            other->next = current;
            first = other;

            ++nodeCount;
        }
        else
        {
            first = new Node();
            first->value = value;
            first->prev = nullptr;
            last = first;
            ++nodeCount;
        }
    }

    void insertAtBack(T value)
    {
        if (first != nullptr)
        {
            if (nodeCount == 1)
            {
                Node *current = first;
                Node *other = new Node();
                other->value = value;
                current->next = other;
                other->prev = current;
                last = other;

                ++nodeCount;
            }
            else
            {
                Node *current = last;
                Node *other = new Node();
                other->value = value;
                current->next = other;
                other->prev = current;
                last = other;

                ++nodeCount;
            }
        }
        else
        {
            first = new Node();
            first->value = value;
            first->prev = last;
            ++nodeCount;
        }
    }

    void removeAtFront()
    {
        first = first->next;
        first->prev = nullptr;
        nodeCount--;
    }

    void removeAtBack()
    {
        last = last->prev;
        last->next = nullptr;
        nodeCount--;
    }

    size_t size() { return nodeCount; }

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
            Node *current = outro.first;
            while (current != nullptr)
            {
                insert(current->value);
                current = current->next;
            }
        }
    }

    Node *first = nullptr;
    Node *last = nullptr;
    size_t nodeCount = 0;
};
