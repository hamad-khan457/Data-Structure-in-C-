#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *arrToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);

    root->left = arrToBST(arr, start, mid - 1);
    root->right = arrToBST(arr, mid + 1, end);
    return root;
}
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

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    node *root = arrToBST(arr, 0, 4);
    preorderDisplay(root);
}