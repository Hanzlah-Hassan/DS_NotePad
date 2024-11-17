#ifndef LISTNODE_H
#define LISTNODE_H
#include<iostream>
using namespace std;
class listNode {
public:
char ch;
listNode * next;
listNode * prevoius;
listNode(char c);
};
#endif