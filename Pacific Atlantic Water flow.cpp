#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

    void bfs(int X, int Y, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        queue<pair<int,int>> q;
        q.push({X,Y});
        vis[X][Y] = true;
        int n = heights.size(), m = heights[0].size();

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                   !vis[nx][ny] &&
                   heights[nx][ny] >= heights[x][y]) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> po(n, vector<bool>(m, false));
        vector<vector<bool>> ao(n, vector<bool>(m, false));
        vector<vector<int>> res;

        // Pacific (left & top)
        for(int i = 0; i < n; i++) {
            bfs(i, 0, heights, po);
            bfs(i, m - 1, heights, ao);
        }

        // Atlantic (right & bottom)
        for(int j = 0; j < m; j++) {
            bfs(0, j, heights, po);
            bfs(n - 1, j, heights, ao);
        }

        // Cells reachable from both oceans
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(po[i][j] && ao[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    Solution obj;
    vector<vector<int>> result = obj.pacificAtlantic(heights);

    cout << "Cells that can flow to both Pacific and Atlantic:\n";
    for (auto &cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }

    return 0;
}