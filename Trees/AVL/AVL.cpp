#include <iostream>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
node *root = NULL;
void insert(int val)
{
    node *n = new node(val);
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        node *curr = root;
        node *prev;
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
        if (prev->data < n->data)
        {
            prev->right = n;
        }
        else
        {
            prev->left = n;
        }
    }
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
bool isBalanced(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }

    // for root
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // insert(1);
    // insert(2);
    // insert(3);
    // insert(4);
    // insert(5);
    // insert(6);
    // insert(7);
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right = new node(3);
    root1->right->left = new node(6);
    root1->right->right = new node(7);

    preOrder(root1);
    if (isBalanced(root1))
    {
        cout << "\nBalanced BST." << endl;
    }
    else
    {
        cout << "\nUnbalanced BST." << endl;
    }
}