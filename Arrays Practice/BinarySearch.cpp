#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int value)
{
    int start = 0, end = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int value;
    cout << "Enter the value you wanna search: ";
    cin >> value;
    int res = binarySearch(arr, n, value);
    cout << res;
}
