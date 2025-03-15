#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node(int key)
    {
        data = key;
        right = left = nullptr;
    };
};
node *root = NULL;
void insert(int key)
{
    node *n = new node(key);
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        node *p, *k;
        p = root;
        while (p != NULL)
        {
            k = p;
            if (n->data < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (k->data < n->data)
        {
            k->right = n;
        }
        else
        {
            k->left = n;
        }
    }
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node *searchInBst(node *root, int key)
{
    if (root == NULL)
    {
        // cout << "Root is empty." << endl;
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBst(root->left, key);
    }
    else if (root->data < key)
    {
        return searchInBst(root->right, key);
    }
}
node *inOrderSuccessor(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
node *deleteinBst(node *root, int key)
{
    if (searchInBst(root, key) == NULL || root == NULL)
    {
        cout << "Key doesn't exist or root is empty." << endl;
        return nullptr;
    }
    if (root->data > key)
    {
        root->left = deleteinBst(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteinBst(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        node *temp = inOrderSuccessor(root->right);
        root->data = temp->data;
        deleteinBst(root->right, temp->data);
    }
    return root;
}

bool isValidBST(node *root, node *min, node *max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftValid = isValidBST(root->left, min, root);
    bool rightValid = isValidBST(root->right, root, max);
    return leftValid && rightValid;
}

int main()
{
    // node *n = root;
    insert(4);
    insert(5);
    insert(6);
    insert(9);
    insert(3);
    insert(2);
    insert(1);
    // inorder(root);
    // cout << endl;
    // deleteinBst(root, 2);
    // inorder(root);
    // preorder(root);
    // postOrder(root);
    // if (searchInBst(root, 2) == NULL)
    // {
    //     cout << "Key doesn't exits." << endl;
    // }
    // else
    // {
    //     cout << "Key found." << endl;
    // }
    if (isValidBST(root, nullptr, nullptr))
    {
        cout << "Valid bst." << endl;
    }
    else
    {
        cout << "Invalid bst." << endl;
    }
}