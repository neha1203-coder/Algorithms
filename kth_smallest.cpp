#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k - 1)
            return arr[pi];
        else if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}
int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int result = quickSelect(arr, 0, arr.size() - 1, k);
    cout << "Kth smallest element: " << result;
    return 0;
}