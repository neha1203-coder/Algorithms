#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    int invCount = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid - i + 1); 
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
    return invCount;
}
int mergeSort(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}
int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int result = mergeSort(arr, 0, arr.size() - 1);

    cout << "Number of Inversions: " << result;

    return 0;
}