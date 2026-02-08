#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void adjust(int arr[], int i, int n)
{
    int x;
    x = arr[i];
    int j = i * 2;

    while (j <= n)
    {
        if (j < n && arr[j + 1] < arr[j])
        {
            j = j + 1;
        }
        if (x > arr[j])
        {
            arr[j / 2] = arr[j];
            j = j * 2;
        }
        else
        {
            break;
        }
    }
    arr[j / 2] = x;
}

int main()
{
    int arr[] = {0, 100, 50, 200, 85, 150, 600, 70, 800};
    int n = 8;

    for (int i = n / 2; i >= 1; i--)
    {
        adjust(arr, i, n);
    }
    for (int i = n; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        adjust(arr, 1, i - 1);
    }
    for (int i = 1; i <= n; i++)
    {

        cout << arr[i] << endl;
    }
}