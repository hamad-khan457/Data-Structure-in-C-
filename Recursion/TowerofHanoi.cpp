#include <iostream>
using namespace std;
void towerOfHanoi(int n, char src, char des, char hlpr)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, src, hlpr, des);
    cout << "Move from " << src << " to " << des << endl;
    towerOfHanoi(n - 1, hlpr, des, src);
}
int main()
{
    towerOfHanoi(4, 'A', 'B', 'C');
}