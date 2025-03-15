#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    PriorityQueue()
    {
        front = -1;
        rear = -1;
    }

    bool is_empty()
    {
        return front == -1;
    }

    bool is_full()
    {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value)
    {
        if (is_full())
        {
            cout << "Priority queue is full." << endl;
            return;
        }

        // Inserting element at appropriate position based on priority
        int i;
        for (i = rear; i >= 0; i--)
        {
            if (value < arr[i])
            {
                arr[i + 1] = arr[i]; // Shift elements to make space
            }
            else
            {
                break;
            }
        }
        arr[i + 1] = value; // Insert element
        rear++;
        if (front == -1)
        {
            front = 0;
        }
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Priority queue is empty." << endl;
            return -1;
        }

        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1; // Reset front and rear pointers
        }
        else
        {
            front++; // Move front pointer
        }
        return value;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Priority queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueue(3);
    pq.enqueue(8);
    pq.enqueue(1);
    pq.enqueue(5);

    cout << "Front element: " << pq.peek() << endl;

    cout << "Dequeued: " << pq.dequeue() << endl;
    cout << "Dequeued: " << pq.dequeue() << endl;

    cout << "Front element: " << pq.peek() << endl;

    pq.enqueue(10);

    cout << "Front element: " << pq.peek() << endl;

    return 0;
}
