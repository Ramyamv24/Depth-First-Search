#include <iostream>
#include <vector>
#include <numeric> // for iota
using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path Compression
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        // Union by Rank
        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        parent.resize(n);
        rank.assign(n, 0);

        // Initially every node is its own parent
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j])
                    Union(i, j);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans++;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: "
         << obj.findCircleNum(isConnected) << endl;

    return 0;
}