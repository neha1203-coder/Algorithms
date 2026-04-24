#include <iostream>
#include <vector>
using namespace std;

// Function to check if allocation is possible
bool isPossible(vector<int>& arr, int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than allowed
        if (arr[i] > maxPages)
            return false;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return false;
        }
    }
    return true;
}

// Main function
int allocateBooks(vector<int>& arr, int n, int m) {
    if (m > n)
        return -1; // Not possible

    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        high += arr[i];
        if (arr[i] > low)
            low = arr[i];
    }

    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // Try smaller value
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter pages in books: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    int result = allocateBooks(arr, n, m);

    if (result == -1)
        cout << "Allocation not possible" << endl;
    else
        cout << "Minimum pages: " << result << endl;

    return 0;
}
