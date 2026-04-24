#include <iostream>
#include <vector>
using namespace std;
void sortArrayByParity(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        if (nums[left] % 2 == 0) {
            left++;
        }
        else if (nums[right] % 2 == 1) {
            right--;
        }
        else {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}
int main() {
    vector<int> nums = {3, 1, 2, 4, 7, 6};
    sortArrayByParity(nums);
    cout << "Result: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0; 
}