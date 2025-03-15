#include <iostream>
#include <stack>
using namespace std;
void displayStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void insertAtBottom(stack<int> &st, int elem)
{
    if (st.empty())
    {
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topElem);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int elem = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, elem);
}
int main()
{
    stack<int> st;
    st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    displayStack(st);
    reverseStack(st);
    displayStack(st);
}