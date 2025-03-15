#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevSum = sum(n - 1);
    return n + prevSum;
}
int searchFromLast(int arr[], int size, int i, int key)
{
    if (i == size)
    {
        return -1;
    }
    int restArr = searchFromLast(arr, size, i + 1, key);
    if (restArr != -1)
    {
        return restArr;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    // int n;
    // cin >> n;
    // cout << sum(n) << endl;
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    cout << searchFromLast(arr, 7, 0, 2) << endl;
}