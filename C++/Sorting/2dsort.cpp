#include <iostream>
using namespace std;

void selectionSort(int arr[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int min_x = i;
            int min_y = j;

            for (int k = i; k < n; k++)
            {
                for (int l = (k == i) ? j + 1 : 0; l < 5; l++)
                {
                    if (arr[k][l] < arr[min_x][min_y])
                    {
                        min_x = k;
                        min_y = l;
                    }
                }
            }

            if (min_x != i || min_y != j)
            {
                swap(arr[i][j], arr[min_x][min_y]);
            }
        }
    }
}

int main()
{
    const int rows = 5;
    const int cols = 5;
    int arr[rows][cols] = {
        {121, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 1, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 0}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    cout << endl;

    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
