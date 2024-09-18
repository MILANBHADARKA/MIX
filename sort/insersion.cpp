#include<bits/stdc++.h>
using namespace std;

void insertion(int *arr,int low,int high){
    int k = low;
    int l = high;

    for(int i=0; i<= high;i++){
        int key = arr[i];
        for(int j = i;j>=0 ;j--){
            if(key < arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[100];

    cout << "How many elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertion(arr,0,n-1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
