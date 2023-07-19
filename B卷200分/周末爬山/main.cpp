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
#include <unordered_set>
#include <regex>

using namespace std;



// 周末爬山
// 周末小明准备去爬山锻炼，0代表平地，山的高度使用1到9来表示，小明每次爬山或下山高度只能相差k及k以内，每次只能上下左右一个方向上移动一格，小明从左上角(0,0)位置出发


vector<vector<int>> matrix;
int m;
int n;
int k;
vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
int VISITED = 15;


void dfs(int i, int j, int step, map<int, int> &minStepToHight) {
    
    int lastHeight = matrix[i][j];
    for (vector<int> offset: offsets) {
        int newX = i + offset[0];
        int newY = j + offset[1];
        if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
            continue;
        }
        int curHeight = matrix[newX][newY];
        if (abs(curHeight - lastHeight) <= k) {
            step++;
            if (!minStepToHight[curHeight] || minStepToHight[curHeight] > step) {
                minStepToHight[curHeight] = step;
            }
            matrix[i][j] = VISITED;
            dfs(newX, newY, step, minStepToHight);
            matrix[i][j] = lastHeight;
            step--;
        }
    }
   
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second < b.second) {
            return false;
        }
    }
    return false;
}

string getResult(vector<vector<int>> matrix) {
    map<int, int> minStepToHight;
    minStepToHight[matrix[0][0]] = 0;
    dfs(0, 0, 0, minStepToHight);
    
    vector<pair<int, int>> vec(minStepToHight.begin(),minStepToHight.end());
    sort(vec.begin(), vec.end(), compare);
    return to_string(vec[0].first) + " " + to_string(vec[0].second);
}



int main(int argc, const char * argv[]) {
    
    cin >> m >> n >> k;
    
    matrix = vector<vector<int>>(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << getResult(matrix);
    
    return 0;
}
