#include <iostream>
#include <vector>
using namespace std;
vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return result;
}
int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 4, 6};
    vector<int> result = intersection(arr1, arr2);
    cout << "Intersection: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}