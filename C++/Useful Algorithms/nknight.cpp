// 22k-4573 Aawaiz Ali
#include <iostream>

using namespace std;

void display(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(int row, int col, int n)
{
    return (row >= 0 && row < n && col >= 0 && col < n);
}

bool isSafe(int **arr, int row, int col, int n)
{

    if (isValid(row - 1, col - 2, n) && arr[row - 1][col - 2] == 1)
    {
        return false;
    }

    if (isValid(row - 1, col + 2, n) && arr[row - 1][col + 2] == 1)
    {
        return false;
    }

    if (isValid(row - 2, col - 1, n) && arr[row - 2][col - 1] == 1)
    {
        return false;
    }

    if (isValid(row - 2, col + 1, n) && arr[row - 2][col + 1] == 1)
    {
        return false;
    }

    return true;
}

bool knight(int **arr, int row, int col, int knights, int n)
{
    if (knights == 0)
    {
        return true;
    }

    if (col == n)
    {
        return knight(arr, row + 1, 0, knights, n);
    }

    if (row == n)
    {
        return false;
    }

    if (isSafe(arr, row, col, n))
    {
        arr[row][col] = 1;

        if (knight(arr, row, col + 1, knights - 1, n))
        {
            return true;
        }

        arr[row][col] = 0;
    }

    return knight(arr, row, col + 1, knights, n);
}

int main()
{
    int n = 5;

    cout << "Enter the number of knights you want to place: ";
    int knights;
    cin >> knights;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (knights % 2 == 0)
    {
        if (knights <= ((n * n) / 2))
        {
            if (knight(arr, 0, 0, knights, n))
            {
                display(arr, n);
            }
            else
            {
                cout << "no";
            }
        }
        else
        {
            cout << "too many knights";
        }
    }
    else
    {
        if (knights <= (((n * n) + 1) / 2))
        {
            if (knight(arr, 0, 0, knights, n))
            {
                display(arr, n);
            }
            else
            {
                cout << "no";
            }
        }
        else
        {
            cout << "too many knights";
        }
    }

    return 0;
}
