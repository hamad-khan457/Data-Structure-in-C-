#include <iostream>
using namespace std;
struct edge
{
    int data;
    edge *next;
    edge(int val)
    {
        data = val;
        next = nullptr;
    }
};
struct node
{
    int data;
    edge *head;
    edge *tail;
    node *next;
    node(int val)
    {
        data = val;
        head = NULL;
        tail = NULL;
        next = NULL;
    }
};
node *head = NULL;
node *tail = NULL;

void insertVertex(int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        head = tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
}

bool vertexExits(int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

void addEdge(int vData, int uData)
{
    if (!vertexExits(vData))
    {
        cout << "Vertex: " << vData << " doesn't exist." << endl;
        return;
    }
    if (!vertexExits(uData))
    {
        cout << "Vertex: " << uData << " doesn't exist." << endl;
        return;
    }

    node *n = head;
    while (n != NULL && n->data != vData)
    {
        n = n->next;
    }
    edge *e = new edge(uData);
    if (n->head == NULL)
    {
        n->head = n->tail = e;
    }
    else
    {
        n->tail->next = e;
        n->tail = e;
    }
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        edge *etemp = temp->head;
        while (etemp != nullptr)
        {
            cout << etemp->data << " ";
            etemp = etemp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

void deleteEdge(int vdata, int udata)
{
    if (!vertexExits(vdata) || !vertexExits(udata))
    {
        cout << "One or both vertex not exist." << endl;
        return;
    }
    node *n = head;
    while (n != nullptr && n->data != vdata)
    {
        n = n->next;
    }
    edge *prev = nullptr;
    edge *curr = n->head;
    while (curr != nullptr && curr->data != udata)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr)
    {
        n->head = curr->next;
        delete curr;
    }
    else
    {
        prev->next = curr->next;
        delete curr;
    }
}
int main()
{
    insertVertex(1);
    insertVertex(2);
    insertVertex(3);
    insertVertex(4);
    insertVertex(5);

    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(5, 1);
    addEdge(4, 2);
    cout << "Graph before deleting edge:" << endl;
    display();

    deleteEdge(1, 4);

    cout << "Graph after deleting edge:" << endl;
    display();
}