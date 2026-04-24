#include <iostream>
using namespace std;
int singleNonDuplicate(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mid % 2 == 1)
            mid--;
        if (arr[mid] == arr[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    return arr[low];
}
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted array (pairs + one single): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = singleNonDuplicate(arr, n);

    cout << "Single element is: " << result << endl;

    return 0;
}