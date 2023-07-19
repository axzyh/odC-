//
//  main.cpp
//  ODTest3
//
//  Created by YuChao on 2023/6/1.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

// 战场索敌
// 有一个大小是N*M的战场地图，被墙壁 '#' 分隔成大小不同的区域，上下左右四个方向相邻的空地 '.' 属于同一个区域，只有空地上可能存在敌人'E”，请求出地图上总共有多少区域里的敌人数小于K。
//

int n, m, k;
vector<vector<char>> matrix;
vector<vector<bool>> visited;

vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};


vector<string> getArrNumsForString(string s) {
    vector<string> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(tmp);
    }
    return nums;
}

void recusive(queue<string> &q, int level, int childCount, vector<vector<string>> &tree) {
    for (int i = 0; i < childCount; i++) {
        string comment = q.front();
        q.pop();
        if (tree.size() < level) {
            tree.push_back(vector<string>());
        }
        tree[level- 1].push_back(comment);
        int count = stoi(q.front());
        q.pop();
        if (count > 0) {
            recusive(q, level + 1, count, tree);
        }
    }
}

int bfs(int i , int j) {
    int count = 0;
    visited[i][j] = true;
    if (matrix[i][j] == 'E') {
        count++;
    }
    
    queue<vector<int>> q;
    q.push({i,j});
    
    while (q.size() > 0) {
        vector<int> pos = q.front();
        q.pop();
        int x = pos[0], y = pos[1];
        for (vector<int> offset : offsets) {
            int newX = x + offset[0];
            int newY = y + offset[1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && matrix[newX][newY] != '#') {
                visited[newX][newY] = true;
                if (matrix[newX][newY] == 'E') {
                    count += 1;
                }
                q.push({newX,newY});
            }
        }
    }
    return count;
}


int getResult() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || matrix[i][j] == '#') {
                continue;
            }
            ans += bfs(i, j) < k ? 1 : 0;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> k;
    visited = vector<vector<bool>>(n,vector<bool>(m));
    matrix = vector<vector<char>>(n);
    cin.ignore();
    string charStr;
    for (int i = 0; i < n; i++) {
        getline(cin, charStr);
        for (char c : charStr) {
            matrix[i].push_back(c);
        }
    }
    
    cout << getResult() << endl;
    
    
    return 0;
}
