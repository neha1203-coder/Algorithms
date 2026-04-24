#include <iostream>
#include <vector>
using namespace std;
vector<int> unionArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        int val;
        if (arr1[i] < arr2[j]) {
            val = arr1[i];
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            val = arr2[j];
            j++;
        }
        else {
            val = arr1[i];
            i++;
            j++;
        }
        if (result.size() == 0 || result[result.size() - 1] != val) {
            result.push_back(val);
        }
    }
    while (i < arr1.size()) {
        if (result.size() == 0 || result[result.size() - 1] != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }
    while (j < arr2.size()) {
        if (result.size() == 0 || result[result.size() - 1] != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;
}
int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5, 6};
    vector<int> result = unionArray(arr1, arr2);
    cout << "Union: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}