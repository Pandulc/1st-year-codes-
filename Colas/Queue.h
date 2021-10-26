#ifndef INFOII_QUEUE_H
#define INFOII_QUEUE_H

#include "Node.h"

template<typename T>
class Queue {
private:
    Node<T> *front, *back;
public:
    Queue();

    void enqueue(T data);

    T dequeue();

    T peek();

    bool isEmpty() { return front == nullptr; };
};

template<typename T>
Queue<T>::Queue() {
    front = back = nullptr;
}

template<typename T>
void Queue<T>::enqueue(T data) {
    auto *newNode = new Node<T>(data, nullptr);
    if (back == nullptr) { // La cola está vacia
        front = back = newNode;
    } else {
        back->setNext(newNode);
        back = newNode;
    }
}

template<typename T>
T Queue<T>::dequeue() {
    if (front == nullptr)
        throw 404;

    T toReturn = front->getData();
    auto *toDelete = front;
    front = front->getNext();
    delete toDelete;
    if (front == nullptr) {
        back = front;
    }
    return toReturn;
}

template<typename T>
T Queue<T>::peek() {
    if (front == nullptr)
        throw 404;
    return front->getData();
}


#endif //INFOII_QUEUE_H