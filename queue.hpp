#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#pragma once

class QueueElement {
  public:
    int _value;
    int _key;

    QueueElement(int value, int key);
};

class Queue {
  private:
    std::vector< QueueElement > _queue;
    
    void siftUp(int index);

    void siftDown(int index);
  
  public:
    void insert(int value, int key);

    int extractMax();

    void show();

};