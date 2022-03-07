#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>

namespace Algo {

template <typename T>
struct Node {
    Node(const T &d) : data(d) {}
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
struct DoublyNode {
    DoublyNode(const T &d) : data(d) {}
    T data;
    DoublyNode<T> *next = nullptr;
    DoublyNode<T> *prev = nullptr;
};

template <typename T>
class LinkedList {
public:

    void push(const T &val) {
        Node<T> *node = new Node<T>(val);
        if(m_root)
            node->next = m_root;
        m_root = node;
        m_count++;
    }
    void append(const T &val) {
        Node<T> *node = new Node<T>(val);
        if(!m_root) {
            m_root = node;
            m_count++;
            return;
        }
        Node<T> *last = m_root;
        while(last->next != nullptr)
            last = last->next;
        last->next = node;
        m_count++;
    }
    void insert(Node<T> *prev, const T &val) {
        if(!prev)
            return;
        Node<T> *node = new Node<T>(val);
        node->next = prev->next;
        prev->next = node;
        m_count++;
    }
    void removeAfter(Node<T> *prev) {
        if(!prev || !prev->next)
            return;
        auto tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        m_count--;
    }
    int count() const {
        return m_count;
    }
    Node<T> *head() {
        return m_root;
    }


private:
    int m_count = 0;
    Node<T> *m_root = nullptr;
};

}
#endif // LINKED_LIST_H
