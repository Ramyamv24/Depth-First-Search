#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;

        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            ans.push_back(t);

            for (auto x : adj[t]) {
                indegree[x]--;

                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        return ans.size() == n;
    }
};

int main() {
    Solution obj;

    int n = 2;

    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    bool ans = obj.canFinish(n, prerequisites);

    if (ans)
        cout << "Yes, all courses can be finished." << endl;
    else
        cout << "No, all courses cannot be finished." << endl;

    return 0;
}