#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
    node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Utility function to get the height of the tree
int height(node *n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}

// Utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Utility function to right rotate subtree rooted with y
node *rotateRight(node *y)
{
    node *x = y->left;
    node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Utility function to left rotate subtree rooted with x
node *rotateLeft(node *x)
{
    node *y = x->right;
    node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Utility function to get Balance factor of node N
int getBalance(node *n)
{
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree
node *insert(node *&root, int key)
{
    if (root == nullptr)
    {
        root = new node(key);
        return root;
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // Duplicate keys not allowed
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data)
    {
        return rotateRight(root);
    }

    if (balance < -1 && key > root->right->data)
    {
        return rotateLeft(root);
    }

    if (balance > 1 && key > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root; // Return root unchanged if no rotation is needed
}
node *minValueNode(node *root)
{
    node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
node *deleteNode(node *&root, int key)
{
    if (root == NULL)
    {
        cout << "Root not found." << endl;
        return root;
    }

    if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrderTraversal(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int main()
{
    node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    // root = insert(root, 253);
    preorder(root);
    cout << endl;
    // root = deleteNode(root, 11);
    // preorder(root);
    // cout << endl;
    // levelOrderTraversal(root);
    return 0;
}
