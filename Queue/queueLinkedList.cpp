#include <iostream>
using namespace std;
struct node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct Queue
{
    node *front;
    node *back;

    Queue()
    {
        front = back = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            front = back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow." << endl;
            return;
        }
        node *todel = front;
        front = front->next;
        delete todel;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue underflow." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue underflow." << endl;
            return;
        }
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.display();
    cout << q.peek() << endl;
    q.pop();
    q.display();
    return 0;
}