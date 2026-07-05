#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> memo;

    int dfs(int i, int j) {
        // If already calculated, return it
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int best = 1;

        // Right
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j + 1));
        }

        // Left
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j - 1));
        }

        // Down
        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i + 1, j));
        }

        // Up
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i - 1, j));
        }

        memo[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& inputMatrix) {
        matrix = inputMatrix;
        m = matrix.size();
        n = matrix[0].size();

        memo.resize(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    int ans = obj.longestIncreasingPath(matrix);

    cout << "Longest Increasing Path Length = " << ans << endl;

    return 0;
}