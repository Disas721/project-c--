#include "queue.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>


int main() {
    Queue<int> queue;

    try {
        queue.pop();
    } catch(const EmptyQueueException &err) {
        if (std::string(err.what()) == "Trying to pop an empty heap.")
            std::cout << "Test_1\t->\tPASSED" << std::endl;
        else
            std::cout << "Test_1\t->\tFAILED" << std::endl;
    }

     try {
        queue.top();
    } catch(const EmptyQueueException &err) {
        if (std::string(err.what()) == "Trying to get the top of an empty heap.")
            std::cout << "Test_2\t->\tPASSED" << std::endl;
        else
            std::cout << "Test_2\t->\tFAILED" << std::endl;
    }

    try {
        for(int i = 0; i < 10; i++) {
            queue.push(i);
        }
    } catch(...) {
        std::cout << "Test_3\t->\tFAILED" << std::endl;
    }
    std::cout << "Test_3\t->\tPASSED" << std::endl;

    std::cout << queue;

    try {
        for(int i = 0; i < 5; i++) {
            queue.pop();
        }
    } catch(...) {
        std::cout << "Test_4\t->\tFAILED" << std::endl;
    }
    std::cout << "Test_4\t->\tPASSED" << std::endl;

    std::cout << queue;

    try {
        queue.top();
    } catch(...) {
        std::cout << "Test_5\t->\tFAILED" << std::endl;
    }
    std::cout << "Test_5\t->\tPASSED" << std::endl;

    std::cout << queue;

    try {
        queue.clear();
    } catch(...) {
        std::cout << "Test_5\t->\tFAILED" << std::endl;
    }
    std::cout << "Test_5\t->\tPASSED" << std::endl;

    std::cout << queue;
}
