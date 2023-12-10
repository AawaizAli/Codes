// Aawaiz Ali 22k-4573
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int start = l;
    int end = r;

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[l], arr[end]);
    return end;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int P = partition(arr, l, r);
        quickSort(arr, l, P - 1);
        quickSort(arr, P + 1, r);
    }
}

int main()
{
    int arr[] = {7, 100, 2, 62, 300, 81};
    int size = 6;

    cout << "Initial array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
