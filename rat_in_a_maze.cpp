#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<int>> &arr, vector<vector<bool>> &visited, int n) {
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && !visited[newX][newY] && arr[newX][newY] != 0) {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<string> &ans, string path, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;

    // Down
    if (isSafe(x + 1, y, arr, visited, n)) {
        solve(x + 1, y, ans, path + 'D', visited, arr, n);
    }

    // Left
    if (isSafe(x, y - 1, arr, visited, n)) {
        solve(x, y - 1, ans, path + 'L', visited, arr, n);
    }

    // Right
    if (isSafe(x, y + 1, arr, visited, n)) {
        solve(x, y + 1, ans, path + 'R', visited, arr, n);
    }

    // Up
    if (isSafe(x - 1, y, arr, visited, n)) {
        solve(x - 1, y, ans, path + 'U', visited, arr, n);
    }

    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0) {
        return ans;
    }

    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    solve(0, 0, ans, path, visited, arr, n);
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the maze (n x n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (0 for blocked, 1 for open path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> result = searchMaze(maze, n);
    if (result.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Paths found: " << endl;
        for (const string &path : result) {
            cout << path << endl;
        }
    }

    return 0;
}
