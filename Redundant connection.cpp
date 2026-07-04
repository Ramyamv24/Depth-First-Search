#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void join(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially every node is its own parent
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            if (find(u) == find(v))
                return edge;   // Cycle found

            join(u, v);
        }

        return {};
    }
};

int main() {
    Solution obj;

    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3}
    };

    vector<int> ans = obj.findRedundantConnection(edges);

    cout << "Redundant Edge: ";
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}