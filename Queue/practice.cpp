#include <iostream>
using namespace std;
#define n 20
struct Queue
{
    int *arr;
    int front;
    int back;
    Queue()
    {
        arr = new int[n];
        front = back = -1;
    }

public:
    void push(int val)
    {
        if (back == n - 1)
        {
            cout << "queue overflow." << endl;
            return;
        }
        back++;
        arr[back] = val;
        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in queue." << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in queue." << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
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
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    q.pop();
    return 0;
}