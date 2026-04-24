#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {4, 5, 6, 5, 4, 3};
    int n = nums.size();
    vector<int> freq(n, 0);
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        freq[i] = count;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (freq[i] < freq[j] || 
               (freq[i] == freq[j] && nums[i] > nums[j])) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
    }
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}