#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int>& arr, int n, int k, int dist) {
    int cows = 1; // First cow placed at first stall
    int lastPos = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            cows++;
            lastPos = arr[i];

            if (cows >= k)
                return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[n - 1] - arr[0];
    int result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, k, mid)) {
            result = mid;
            low = mid + 1; // Try larger distance
        } else {
            high = mid - 1;
        }
    }
    return result;
}
int main() {
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of cows: ";
    cin >> k;
    int result = aggressiveCows(arr, n, k);
    cout << "Largest minimum distance: " << result << endl;
    return 0;
}