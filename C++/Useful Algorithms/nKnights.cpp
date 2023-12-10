#include <iostream>
using namespace std;

bool inRange(int **arr, int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool isSafe(int **arr, int x, int y, int n)
{
    if (inRange(arr, x - 1, y + 2, n))
    {
        return false;
    }
    if (inRange(arr, x - 1, y - 2, n))
    {
        return false;
    }
    if (inRange(arr, x - 2, y - 1, n))
    {
        return false;
    }
    if (inRange(arr, x - 2, y + 1, n))
    {
        return false;
    }

    return true;
}

bool nKnights(int **arr, int row, int col, int n, int k)
{
    if (k == 0)
    {
        return true;
    }
    if (row == n - 1 && col == n)
    {
        return false;
    }
    if (col == n)
    {
        nKnights(arr, row + 1, 0, n, k - 1);
    }

    if (isSafe(arr, row, col, n))
    {

        arr[row][col] = 1;

        if (nKnights(arr, row, col + 1, n, k - 1))
        {
            return true;
        }

        arr[row][col] = 0;
    }

    return nKnights(arr, row, col + 1, n, k);
}

int main()
{
    int n = 5;

    // Dynamically allocate memory for the 2D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    int knights;

    cout << "Enter the number of knights your want to place: " << endl;
    cin >> knights;

    if ((knights % 2) == 0)
    {
        if (knights > (n * n) / 2)
        {
            cout << "Too many knights";
        }
        else
        {
            if (nKnights(arr, 0, 0, n, knights))
            {
                // Print the solution
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "No solution exists." << endl;
            }
        }
    }
    else if ((knights % 2) != 0)
    {
        if (knights > ((n * n) + 1) / 2)
        {
            cout << "Too many knights";
        }
        else
        {
            if (nKnights(arr, 0, 0, n, knights))
            {
                // Print the solution
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "No solution exists." << endl;
            }
        }
    }
}