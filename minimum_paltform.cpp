#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0; 
    int j = 0; 
    int platform = 0;
    int maxPlatform = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platform++;  
            i++;
        } else {
            platform--;   
            j++;
        }
        if (platform > maxPlatform) {
            maxPlatform = platform;
        }
    }
    return maxPlatform;
}
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    int result = findPlatform(arr, dep);
    cout << "Minimum Platforms Required: " << result;
    return 0;
}