#pragma once
#include "queue.hpp"

#include <ostream>

template<typename T, typename Cmp>
std::ostream &operator<<(std::ostream &out, const Queue<T, Cmp> &queue) {
    out << "Queue size: " << queue.size() << std::endl;
    out << "Queue contents: ";
    for (int i = 0; i < queue.size(); i++)
        out << queue.heap[i] << " ";
    out << std::endl;
    return out;
}

EmptyQueueException::EmptyQueueException(const std::string &msg)
    : std::runtime_error(msg) {}

template<typename T, typename Cmp>
Queue<T, Cmp>::Queue(Cmp cmp) : cmp(std::move(cmp)) {}

template<typename T, typename Cmp>
Queue<T, Cmp>::Queue() = default;

template<typename T, typename Cmp>
void Queue<T, Cmp>::siftUp(int index) {
    if (index == 0) return;

    int parent_ind = (index - 1) / 2;
    T &current = heap[index];
    T &parent = heap[parent_ind];
    if (cmp(current, parent)) {
        std::swap(parent, current);
        siftUp(parent_ind);
    }

    return;
}

template<typename T, typename Cmp>
void Queue<T, Cmp>::siftDown(int index) {
    T &current = heap[index];
    int left_ind = index * 2 + 1;
    int right_ind = index * 2 + 2;

    if (right_ind < heap.size() && 
        cmp(heap[right_ind], current) && 
        cmp(heap[right_ind], heap[left_ind])) {
        std::swap(heap[right_ind], current);
        siftDown(right_ind);
    } else if (left_ind < heap.size() && 
        cmp(heap[left_ind], current)) {
        std::swap(heap[left_ind], current);
        siftDown(left_ind);
    }
}

template<typename T, typename Cmp>
void Queue<T, Cmp>::push(T value) {
    heap.push_back(std::move(value));
    siftUp(heap.size() - 1);
}

template<typename T, typename Cmp>
T Queue<T, Cmp>::top() const {
    if (heap.empty()) 
        throw EmptyQueueException("Trying to get the top of an empty heap.");
    return heap.front();
}

template<typename T, typename Cmp>
void Queue<T, Cmp>::pop() {
    if (heap.empty()) 
        throw EmptyQueueException("Trying to pop an empty heap.");

    std::swap(heap.front(), heap.back());
    heap.pop_back();
    siftDown(0);
}

template<typename T, typename Cmp>
std::size_t Queue<T, Cmp>::size() const {
    return heap.size();
}

template<typename T, typename Cmp>
bool Queue<T, Cmp>::empty() const {
    return size() == 0;
}

template<typename T, typename Cmp>
void Queue<T, Cmp>::clear() {
    return heap.clear();
}
