#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1; // Not found
}
int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = searchRotated(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}