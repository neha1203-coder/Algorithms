#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
vector<vector<int> > mergeIntervals(vector<vector<int> >& intervals) {
    vector<vector<int> > result;
    sort(intervals.begin(), intervals.end(), compare);
    vector<int> current = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= current[1]) {
            if (intervals[i][1] > current[1]) {
                current[1] = intervals[i][1];
            }
        } else {
            result.push_back(current);
            current = intervals[i];
        }
    }
    result.push_back(current);
    return result;
}
int main() {
    vector<vector<int> > intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int> > result = mergeIntervals(intervals);
    cout << "Merged Intervals:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "] ";
    }
    return 0;
}