#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
Node *root = NULL;
void insert(int val)
{
    Node *n = new Node(val);
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        Node *curr = root;
        Node *prev;
        while (curr != NULL)
        {
            prev = curr;
            if (curr->data > n->data)
            {
                curr = curr->left;
            }
            else if (curr->data < n->data)
            {
                curr = curr->right;
            }
        }
        if (prev->data > n->data)
        {
            prev->left = n;
        }
        else
        {
            prev->right = n;
        }
    }
}
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }
    else
    {
        return searchInBST(root->right, key);
    }
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteinBST(Node *root, int key)
{
    if (searchInBST(root, key) == NULL)
    {
        cout << "Root not found." << endl;
        return NULL;
    }
    if (root->data > key)
    {
        root->left = deleteinBST(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteinBST(root->right, key);
    }
    else if (root->data == key)
    {
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

int main()
{
    insert(5);
    insert(1);
    insert(3);
    insert(4);
    insert(2);
    insert(7);
    insert(6);
    preOrder(root);
    cout << endl;
    deleteinBST(root, 2);
    preOrder(root);
    // if (searchInBST(root, 3) == NULL)
    // {
    //     cout << "Key doesn't exist." << endl;
    // }
    // else
    // {
    //     cout << "Key found." << endl;
    // }
    return 0;
}