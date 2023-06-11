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

// 找单词
// 给一个字符串和一个二维字符数组，如果该字符串存在于该数组中，则按字符串的字符顺序输出字符串每个字符所在单元格的位置下标字符串，如果找不到返回字符串“N”。


vector<char> getArrCharForString(string s) {
    vector<char> arr;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ',') {
            arr.push_back(s[i]);
        }
    }
    return arr;
}

int n;
vector<vector<char>> matrix;
string tar;

bool dfs(int i, int j, int k, vector<vector<int>> &path) {
   
    if (i < 0 || i >= n || j < 0 ||j >= n || tar.substr(k, 1)[0] !=matrix[i][j]) {
        return false;
    }
    path.push_back({i,j});
    if (path.size() == tar.length()) {
        return true;
    }
    
    char tmp = matrix[i][j];
    matrix[i][j] = '\0';
    bool res =  dfs(i - 1, j, k+1, path) ||
    dfs(i + 1, j, k+1, path)||
    dfs(i, j-1, k+1, path)||
    dfs(i, j+1, k + 1, path);
    if (!res) {
        matrix[i][j] = tmp;
        path.pop_back();
    }
    return res;
}

string getResult() {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<int>> path;
            if (dfs(i, j, 0, path)) {
                string ans;
                for (vector<int> pos : path) {
                    if (ans.length() > 0) {
                        ans += ",";
                    }
                    ans += to_string(pos[0]) + "," + to_string(pos[1]);
                  
                }
                return ans;
            }
        }
    }
    
      return "N";
    
}

int main(int argc, const char * argv[]) {
   
    cin >> n;
    cin.ignore();
    matrix = vector<vector<char>>(n,vector<char>(n));
    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        matrix[i] = getArrCharForString(str);
    }
    getline(cin, tar);
    
    cout << getResult() << endl;
    return 0;
}
