#include <iostream>
using namespace std;
class PriorityQueue
{
    int *heap;
    int capacity;
    int size;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex])
            {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void heapifyDown(int index)
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && heap[largest] < heap[leftChild])
        {
            largest = leftChild;
        }
        if (rightChild < size && heap[largest] < heap[rightChild])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue(int cap)
    {
        heap = new int[cap];
        capacity = cap;
        size = 0;
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Priority queue is full. Can't insert more element." << endl;
            return;
        }
        heap[size++] = val;
        heapifyUp(size - 1);
    }
    void deleteVal()
    {
        if (size == 0)
        {
            cout << "Priority queue is empty." << endl;
            return;
        }
        cout << "Deleted Value: " << heap[0] << endl;
        heap[0] = heap[--size];
        heapifyDown(0);
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int arr[] = {14, 24, 12, 11, 25, 8, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    PriorityQueue pq(n);
    for (int i = 0; i < n; i++)
    {
        pq.insert(arr[i]);
    }
    pq.print();
    pq.deleteVal();
    pq.deleteVal();
    pq.deleteVal();
    pq.deleteVal();
    pq.deleteVal();
    cout << "After deletion: ";
    pq.print();
}