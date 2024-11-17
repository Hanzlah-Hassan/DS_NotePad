#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<ncurses.h>
#include "listNode.h"
#include "colorPair.h"
using namespace std;
class Queue{
    public:
    listNode * front;
    listNode* rear;
    ColorPair color;
int length;
    
    Queue();
   void enqueue(char c);
    char dequeue();
    bool isempty();
    char deleteChar();
    void makeQueueEmpty();
    void printQ();
    ~Queue();
};
#endif