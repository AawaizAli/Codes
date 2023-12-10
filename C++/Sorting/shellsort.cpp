#include <iostream>
using namespace std;

int main() {
    int arr[] = {8,24,3,4,31,6,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int gap = n/2 ; gap > 0 ; gap = gap / 2) {
        for (int i = gap ; i < n ; i++) {
            int temp = arr[i];
            int j;
            for (j = i ; j >= gap && arr[j - gap] > temp  ; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        for (int i = 0 ; i < n ; i++) {
            cout << arr[i] << ' ';
        }

        cout << endl;
    }

    
}