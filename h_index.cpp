#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }
    return h;
}
int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = hIndex(citations);
    cout << "H-Index: " << result;
    return 0;
}