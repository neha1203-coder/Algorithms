#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n = arr.size();
    int index = 0;
    for (int i = 0; i <= k && i < n; i++) {
        minHeap.push(arr[i]);
    }
    for (int i = k + 1; i < n; i++) {
        arr[index] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
        index++;
    }
    while (!minHeap.empty()) {
        arr[index] = minHeap.top();
        minHeap.pop();
        index++;
    }
}
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sortKSortedArray(arr, k);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}