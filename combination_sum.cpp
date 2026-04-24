#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& candidates, int target, 
               vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            current.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, current, result);
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    cout << "Combinations:\n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}