#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapSort(int arr[], int length)
{
    int q = length;
    int parent = length / 2;
    while (parent > 0)
    {
        int pass = parent;
        while (pass != 0)
        {
            if (arr[(parent * 2) + 1] > arr[(parent + 1) + 1])
            {
                if (arr[parent] < arr[(parent * 2) + 1])
                {
                    swap(arr[parent], arr[(parent + 1) + 1]);
                }
            }
            else if (arr[(parent * 2) + 1] < arr[(parent * 2 + 1) + 1])
            {
                if (arr[parent] < arr[((parent * 2) + 1) + 1])
                {
                    swap(arr[parent], arr[(parent * 2 + 1) + 1]);
                }
            }
            pass--;
        }
        swap(arr[0], arr[length - 1]);
        length = length - 1;
        parent = length / 2;
    }

    for (int i = 0; i < q; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{

    int arr[] = {100, 50, 200, 85, 150, 600, 70, 800};
    int length = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, length);
}