#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void adjust(int a[], int i, int n)
{
    int x;
    x = a[i];
    int j = i * 2;
    while (j <= n)
    {
        if (a[j] < a[j + 1] && j < n)
        {
            j = j + 1;
        }
        if (x < a[j])
        {
            a[j / 2] = a[j];
            j = j * 2;
        }
        else
        {
            break;
        }
    }
    a[j / 2] = x;
}
int main()
{
    int n = 8;
    int arr[] = {0, 100, 50, 200, 85, 150, 600, 70, 800};

    for (int i = n / 2; i >= 1; i--)
    {
        adjust(arr, i, n);
    }
    for (int i = n; i >= 2; i--)
    {
        int x = arr[1];
        arr[1] = arr[i];
        arr[i] = x;
        adjust(arr, 1, i - 1);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << endl;
    }
}
