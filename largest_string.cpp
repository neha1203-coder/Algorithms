#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b) {
    string order1 = a + b;
    string order2 = b + a;
    if (order1 > order2)
        return true;
    else
        return false;
}
int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    vector<string> arr;
    for (int i = 0; i < nums.size(); i++) {
        arr.push_back(to_string(nums[i]));
    }
    sort(arr.begin(), arr.end(), compare);
    if (arr[0] == "0") {
        cout << "Largest Number: 0";
        return 0;
    }
    string result = "";
    for (int i = 0; i < arr.size(); i++) {
        result = result + arr[i];
    }
    cout << "Largest Number: " << result;
    return 0;
}