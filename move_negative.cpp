#include <iostream>
#include <vector>
using namespace std;
void moveNegatives(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        if (arr[left] < 0) {
            left++; // already correct
        }
        else if (arr[right] >= 0) {
            right--; // already correct
        }
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
int main() {
    vector<int> arr = {1, -2, 3, -4, -1, 4};
    moveNegatives(arr);
    cout << "Result: ";
    for (int x : arr) cout << x << " ";
}