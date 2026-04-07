#include <iostream>
using namespace std;
// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;        // Assume root is largest
    int left = 2*i + 1;     // Left child
    int right = 2*i + 2;    // Right child
    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if(largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}
// Main Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Step 2: Extract elements from heap
    for(int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // Call heapify on reduced heap
        heapify(arr, i, 0);
    }
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    heapSort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}