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



// 单词搜索
// 找到它是一个小游戏，你需要在一个矩阵中找到给定的单词。
vector<string> matrix;
string word;
int n,m;
vector<vector<bool>> visited;

bool backTracking(int i,int j, int k) {
    if (k == word.size()) {
        return true;
    }
    if (i < 0 || i >= n || j < 0 || j >= m ||visited[i][j] || matrix[i][j] != word[k]) {
        return false;
    }
    visited[i][j] = true;
    
    int newK = k + 1;
    bool res =  backTracking(i + 1, j, newK) || backTracking(i - 1, j, newK) || backTracking(i, j - 1, newK) || backTracking(i, j+1, newK);
    visited[i][j] = false;
    return res;
}

string getResult() {

    visited = vector<vector<bool>>(n,(vector<bool>(m)));
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (backTracking(i, j, 0)) {
                return to_string(i + 1) + " " + to_string(j + 1);
            }
        }
    }
    return "NO";
}



int main(int argc, const char * argv[]) {
    
    cin >> n >> m >> word;
    
   matrix = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
  cout << getResult() << endl;
    
    return 0;
}
