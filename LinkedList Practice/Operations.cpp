#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

node *first = NULL;
node *last = NULL;

void insertAtEnd(int val)
{
    node *n = new node();
    n->val = val;
    n->next = NULL;
    if (first == NULL)
    {
        first = n;
        last = n;
    }
    else
    {
        last->next = n;
        last = n;
    }
}

void insertAtStart(int val)
{
    node *n = new node();
    n->val = val;
    n->next = first;
    first = n;
}

void insertAfterSpecificValue(int val, int key)
{
    node *n = new node();
    n->val = val;
    node *temp = first;
    while (temp != NULL && temp->val != key)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        n->next = temp->next;
        temp->next = n;
        if (temp == last)
        {
            last = n;
        }
    }
    else
    {
        cout << "Key not found.\n";
    }
}

void insertBeforeSpecificValue(int val, int key)
{
    node *n = new node();
    n->val = val;
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (first->val == key)
    {
        n->next = first;
        first = n;
        return;
    }
    node *temp = first;
    while (temp->next != NULL && temp->next->val != key)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        n->next = temp->next;
        temp->next = n;
    }
    else
    {
        cout << "Key not found.\n";
    }
}

void deleteFromStart()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *toDel = first;
    first = first->next;
    delete (toDel);
}

void deleteFromEnd()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *temp = first;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete (temp);
    if (prev != NULL)
    {
        prev->next = NULL;
        last = prev;
    }
    else
    {
        first = NULL;
        last = NULL;
    }
}

void deleteSpecificValue(int key)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    if (first->val == key)
    {
        node *toDel = first;
        first = first->next;
        delete (toDel);
        if (first == NULL)
        {
            last = NULL;
        }
        return;
    }
    node *temp = first;
    node *prev = NULL;
    while (temp != NULL && temp->val != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        prev->next = temp->next;
        delete (temp);
        if (prev->next == NULL)
        {
            last = prev;
        }
    }
    else
    {
        cout << "Key not found.\n";
    }
}

void deleteAfterSpecificValue(int key)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *temp = first;
    while (temp != NULL && temp->val != key)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL)
    {
        node *toDel = temp->next;
        temp->next = temp->next->next;
        delete (toDel);
        if (temp->next == NULL)
        {
            last = temp;
        }
    }
    else
    {
        cout << "Key not found or no element after key.\n";
    }
}

void deleteBeforeSpecificValue(int key)
{
    if (first == NULL || first->next == NULL)
    {
        cout << "List is empty or has only one element.\n";
        return;
    }
    if (first->next->val == key)
    {
        deleteFromStart();
        return;
    }
    node *temp = first;
    while (temp->next != NULL && temp->next->next != NULL && temp->next->next->val != key)
    {
        temp = temp->next;
    }
    if (temp->next != NULL && temp->next->next != NULL)
    {
        node *toDel = temp->next;
        temp->next = temp->next->next;
        delete (toDel);
    }
    else
    {
        cout << "Key not found or no element before key.\n";
    }
}
void printReverse(node *first)
{
    if (first == NULL)
    {
        return;
    }
    printReverse(first->next);
    cout << first->val << " ";
}
void reverse()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *prevptr = NULL;
    node *currptr = first;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    last = first;
    first = prevptr;
}

void reverseFirstHalfandSecondHalf(int k)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *prevptr = NULL;
    node *currptr = first;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        first->next = currptr;
        first = prevptr;
    }
    else
    {
        last = prevptr;
    }
}

void makeCycle(int pos)
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *temp = first;
    node *startnode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (pos == count)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
    last = temp;
}

bool detectCycle()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return false;
    }
    node *slow = first;
    node *fast = first;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeDuplicates()
{
    if (first == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    node *temp1 = first;
    while (temp1 != NULL && temp1->next != NULL)
    {
        node *temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->val == temp2->next->val)
            {
                node *toDel = temp2->next;
                temp2->next = temp2->next->next;
                delete (toDel);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}
void splitEvenOddNodes(node *&evenNode, node *&oddNode)
{
    if (first == NULL)
    {
        cout << "Linked list is empty.";
        return;
    }
    node *curr = first;
    node *evenptr = NULL;
    node *oddptr = NULL;
    while (curr != NULL)
    {
        if (curr->val % 2 == 0)
        {
            if (evenNode == NULL)
            {
                evenNode = evenptr = curr;
            }
            else
            {
                evenptr->next = curr;
                evenptr = evenptr->next;
            }
        }
        else
        {
            if (oddNode == NULL)
            {
                oddNode = oddptr = curr;
            }
            else
            {
                oddptr->next = curr;
                oddptr = oddptr->next;
            }
        }
        curr = curr->next;
        if (evenptr != NULL)
        {
            evenptr->next = NULL;
        }
        if (oddptr->next != NULL)
        {
            oddptr->next = NULL;
        }
    }
}
node *reversek(node *&head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Linked list is empty or have only one node.";
    }
    node *prev = NULL;
    node *curr = head;
    node *nextptr;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return prev;
}
void display(node *first)
{
    node *temp = first;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->val << ",";
        temp = temp->next;
    }
    cout << "----->"
         << "NULL" << endl;
}

int main()
{
    node *evenNode = NULL;
    node *oddNode = NULL;
    node *res;
    int choice;
    int val, key, k, pos;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Start\n";
        cout << "3. Insert After Specific Value\n";
        cout << "4. Insert Before Specific Value\n";
        cout << "5. Delete from Start\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Value\n";
        cout << "8. Delete After Specific Value\n";
        cout << "9. Delete Before Specific Value\n";
        cout << "10. Reverse\n";
        cout << "11. Reverse First Half and Second Half\n";
        cout << "12. Make Cycle\n";
        cout << "13. Detect Cycle\n";
        cout << "14. Remove Duplicates\n";
        cout << "16. Print Reverse\n";
        cout << "15. Display\n";
        cout << "17. split Even and Odd\n";
        cout << "18. Reverse k nodes\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 2:
            cout << "Enter value to insert at start: ";
            cin >> val;
            insertAtStart(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter key value after which to insert: ";
            cin >> key;
            insertAfterSpecificValue(val, key);
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter key value before which to insert: ";
            cin >> key;
            insertBeforeSpecificValue(val, key);
            break;
        case 5:
            deleteFromStart();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteSpecificValue(key);
            break;
        case 8:
            cout << "Enter key value after which to delete: ";
            cin >> key;
            deleteAfterSpecificValue(key);
            break;
        case 9:
            cout << "Enter key value before which to delete: ";
            cin >> key;
            deleteBeforeSpecificValue(key);
            break;
        case 10:
            reverse();
            cout << "List reversed.\n";
            break;
        case 11:
            cout << "Enter value of k: ";
            cin >> k;
            reverseFirstHalfandSecondHalf(k);
            cout << "List reversed in first half and second half.\n";
            break;
        case 12:
            cout << "Enter position to make cycle: ";
            cin >> pos;
            makeCycle(pos);
            cout << "Cycle created.\n";
            break;
        case 13:
            cout << "Cycle Detected: " << detectCycle() << endl;
            break;
        case 14:
            removeDuplicates();
            cout << "Duplicates removed.\n";
            break;

        case 15:
            display(first);
            break;
        case 16:
            printReverse(first);
            break;
        case 17:
            splitEvenOddNodes(evenNode, oddNode);
            display(evenNode);
            display(oddNode);
            break;
        case 18:
            int k;
            cout << "Enter the number of k: ";
            cin >> k;
            res = reversek(first, k);
            display(res);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter again.\n";
        }
    } while (choice != 0);

    return 0;
}
