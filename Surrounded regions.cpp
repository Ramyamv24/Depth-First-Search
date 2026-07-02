#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int M, N;

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        // Base case
        if (i < 0 || i >= M || j < 0 || j >= N || vis[i][j] || board[i][j] == 'X')
            return;

        vis[i][j] = true;

        // DFS in four directions
        dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
    }

public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        if (M == 0) return;
        N = board[0].size();

        vector<vector<bool>> vis(M, vector<bool>(N, false));

        // Traverse first and last columns
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);

            if (board[i][N - 1] == 'O' && !vis[i][N - 1])
                dfs(i, N - 1, board, vis);
        }

        // Traverse first and last rows
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);

            if (board[M - 1][j] == 'O' && !vis[M - 1][j])
                dfs(M - 1, j, board, vis);
        }

        // Convert surrounded 'O' to 'X'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution obj;
    obj.solve(board);

    cout << "Output Board:\n";
    for (const auto &row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}