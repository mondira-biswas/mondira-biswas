#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end, int pivot)
{
    int pivotIndex = -1;

    // pivot value খুঁজে বের করা
    for(int i=st; i<=end; i++){
        if(arr[i] == pivot){
            pivotIndex = i;
            break;
        }
    }

    // pivot কে শেষে নিয়ে যাওয়া
    swap(arr[pivotIndex], arr[end]);

    int idx = st - 1;

    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);

    return idx;
}

int main()
{
    vector<int> arr = {2, 31, 35, 8, 32, 17};

    int pivot;
    cout << "Enter Pivot: ";
    cin >> pivot;

    int pos = partition(arr, 0, arr.size()-1, pivot);

    cout << "After Partition:\n";
    for(int x : arr){
        cout << x << " ";
    }

    cout << "\nPivot Position = " << pos << endl;

    return 0;
}