#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    ans = max(ans, trav(i, j, grid));
                }
            }
        }

        return ans;
    }

private:
    int n, m;

    int trav(int i, int j, vector<vector<int>>& grid) {
        // Base case
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        // Mark current cell as visited
        grid[i][j] = 0;

        // Count current cell + 4 directions
        return 1
             + trav(i - 1, j, grid)
             + trav(i + 1, j, grid)
             + trav(i, j - 1, grid)
             + trav(i, j + 1, grid);
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0},
        {1,1,1,0,1},
        {0,1,0,0,1},
        {0,0,0,1,1}
    };

    Solution obj;

    cout << "Maximum Area of Island = "
         << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}