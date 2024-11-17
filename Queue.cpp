#include "Queue.h"

Queue::Queue()
{
    front = rear = NULL;
    length=0;
};
void Queue::enqueue(char c)
{
    listNode *newNode = new listNode(c);
    length++;
    if (!front)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->prevoius = rear;
        rear = newNode;
    }
}
char Queue::dequeue()
{
    if (isempty())
    {
        cout << "Queue is empty  ";
        return '\0';
    }
    listNode *temp = front;
    front = front->next;
    if (front)
        front->prevoius = NULL;
    if (!front)
        rear = NULL;

    char c = temp->ch;
    length--;
    delete temp;
    return c;
}
bool Queue::isempty()
{
    return (front == NULL && rear == NULL);
}
char Queue::deleteChar()
{
    if (!isempty())
    {
        listNode *temp = rear;
        if (rear->prevoius)
        {
            rear = rear->prevoius;
            rear->next=NULL;
        }else{
            rear=front=NULL;
        }
        char c=temp->ch;
        length--;
        delete temp;;
        return c;
    }
    return '\0';
}
void Queue::printQ()
{
    listNode *temp = front;
    attron(color.getColorPair(5));
    while (temp)
    {
        printw("%c", temp->ch);

        temp = temp->next;
    }
    printw("\n");
    
}
void Queue:: makeQueueEmpty(){
 while (!isempty())
    {
        dequeue();
    }
}
Queue::~Queue()
{
   makeQueueEmpty();
}