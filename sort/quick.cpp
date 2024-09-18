#include<bits/stdc++.h>
using namespace std;

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int pivot = arr[low]; 

        while (i < j) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);

        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int main() {
    int arr[100];

    cout << "How many elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


