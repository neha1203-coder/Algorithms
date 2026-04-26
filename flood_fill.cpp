#include <iostream>
#include <vector>
using namespace std;
void dfs(int row, int col, vector<vector<int> >& image, 
         int originalColor, int newColor) {
    int n = image.size();
    int m = image[0].size();
    if (row < 0 || col < 0 || row >= n || col >= m || 
        image[row][col] != originalColor) {
        return;
    }
    image[row][col] = newColor;
    dfs(row - 1, col, image, originalColor, newColor);
    dfs(row + 1, col, image, originalColor, newColor);
    dfs(row, col - 1, image, originalColor, newColor);
    dfs(row, col + 1, image, originalColor, newColor);
}
vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor) {
        return image;
    }
    dfs(sr, sc, image, originalColor, newColor);
    return image;
}
int main() {
    vector<vector<int> > image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1;
    int newColor = 2;
    vector<vector<int> > result = floodFill(image, sr, sc, newColor);
    cout << "Result:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}