#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int>& arr, int n, int k, int maxTime) {
    int painters = 1;
    int timeSum = 0;
    for (int i = 0; i < n; i++) {
        // If a single board exceeds maxTime
        if (arr[i] > maxTime)
            return false;
        if (timeSum + arr[i] <= maxTime) {
            timeSum += arr[i];
        } else {
            painters++;
            timeSum = arr[i];
            if (painters > k)
                return false;
        }
    }
    return true;
}
int painterPartition(vector<int>& arr, int n, int k) {
    int low = arr[0], high = 0;
    for (int i = 0; i < n; i++) {
        high += arr[i];
        if (arr[i] > low)
            low = arr[i];
    }
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try smaller time
        } else {
            low = mid + 1;
        }
    }
    return result;
}
int main() {
    int n, k;
    cout << "Enter number of boards: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter board lengths: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of painters: ";
    cin >> k;
    int result = painterPartition(arr, n, k);
    cout << "Minimum time required: " << result << endl;
    return 0;
}