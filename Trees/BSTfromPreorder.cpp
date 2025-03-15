#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};
// node *root = NULL;

void preorderDisplay(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderDisplay(root->left);
    preorderDisplay(root->right);
}

node *preOrderToBST(int preOrder[], int *preOrderIndex, int key, int min, int max, int n)
{
    if (*preOrderIndex >= n)
    {
        return nullptr;
    }
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preOrderIndex = *preOrderIndex + 1;
        if (*preOrderIndex < n)
        {
            root->left = preOrderToBST(preOrder, preOrderIndex, preOrder[*preOrderIndex], min, key, n);
        }
        if (*preOrderIndex < n)
        {
            root->right = preOrderToBST(preOrder, preOrderIndex, preOrder[*preOrderIndex], key, max, n);
        }
    }
    return root;
}

int main()
{
    int preOrder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preOrderIndex = 0;
    int key = preOrder[0];
    node *root = preOrderToBST(preOrder, &preOrderIndex, key, INT32_MIN, INT32_MAX, n);
    preorderDisplay(root);
}