#pragma once

#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>


struct EmptyQueueException : std::runtime_error {
    EmptyQueueException(const std::string &msg);
};

template<typename T, typename Cmp = std::greater<T> >
struct Queue {
    
    Queue(Cmp cmp);
    Queue();

    T top() const;
    void pop();
    void push(T value);
    
    void clear();

    std::size_t size() const;
    bool empty() const;

private:
    Cmp cmp;
    std::vector<T> heap;

    void siftUp(int index);
    void siftDown(int index);

    template<typename Q, typename Cmprtr>
    friend std::ostream &operator<<(std::ostream &, const Queue<Q, Cmprtr> &);
};

#include "queue_impl.hpp"