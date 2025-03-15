#include <iostream>
#include <vector>
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

vector<node *> constructBST(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftSubtree = constructBST(start, i - 1);
        vector<node *> rightSubtree = constructBST(i + 1, end);
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            node *left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                node *right = rightSubtree[k];
                node *n = new node(i);
                n->left = left;
                n->right = right;
                trees.push_back(n);
            }
        }
    }
    return trees;
}
void preOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    vector<node *> totalTrees = constructBST(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preOrder(totalTrees[i]);
        cout << endl;
    }
}