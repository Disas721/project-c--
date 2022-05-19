#include "queue.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

QueueElement::QueueElement(int value, int key) {
    _value = value;
    _key = key;
}

void Queue::show() {
    if (_queue.size() == 0) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    std::cout << "Queue: ";
    for (int i = 0; i < _queue.size(); i++)
        std::cout << _queue[i]._value << " ";
    std::cout << std::endl << "Queue size: " << _queue.size() << std::endl;
}

void Queue::siftUp(int index) {
    if (index == 1) return;

    QueueElement& child = _queue[index - 1];
    QueueElement& parent = _queue[index / 2 - 1];
    if (parent._key < child._key) {
        std::swap(parent, child);
        siftUp(index / 2);
    }

    return;
}

void Queue::siftDown(int index) {
    int max_index = index;
    int max_key = _queue[index - 1]._key;

    if (index * 2 <= _queue.size() && _queue[index * 2 - 1]._key > max_key) {
        max_index = index * 2;
        max_key = _queue[max_index - 1]._key;
    }

    if (index * 2 + 1 <= _queue.size() && _queue[index * 2]._key > max_key) {
        max_index = index * 2 + 1;
        max_key = _queue[max_index - 1]._key;
    }

    if (_queue[index - 1]._key != max_key) {
        QueueElement& parent = _queue[index - 1];
        QueueElement& max_child = _queue[max_index - 1];
        std::swap(parent, max_child);
        siftDown(max_index);
    }

    return;
}

void Queue::insert(int value, int key) {
    QueueElement elem(value, key);
    _queue.push_back(elem);
    siftUp(_queue.size());
}

int Queue::extractMax() {
    if (_queue.size() == 0) return -1;

    int max_value = _queue[0]._value;

    QueueElement& parent = _queue[0];
    QueueElement& last = _queue[_queue.size() - 1];
    std::swap(parent, last);
    _queue.pop_back();
    siftDown(1);

    return max_value;
}

int main() {
    Queue queue = Queue();
    queue.insert(1, 1);
    queue.show();

    queue.insert(2, 2);
    queue.show();

    queue.insert(4, 4);
    queue.show();

    queue.insert(9, 9);
    queue.show();

    queue.insert(8, 8);
    queue.show();

    queue.insert(3, 3);
    queue.show();
}
