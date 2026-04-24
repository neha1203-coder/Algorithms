#include <iostream>
using namespace std;

int peakIndexMountainArray(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter mountain array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peak = peakIndexMountainArray(arr, n);

    cout << "Peak element index: " << peak << endl;
    cout << "Peak element value: " << arr[peak] << endl;

    return 0;
}