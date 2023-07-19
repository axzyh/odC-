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



// 污染水域
// 输入一行字符串，字符串可转换为N*N的数组，数组可认为是一个水域，判断多少天后，水域被全部污染。

vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ',') {
            tVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(stoi(tmp));
    }
    return tVec;
}

int getResult(vector<int>nums) {
    int n = (int)sqrt(nums.size());
    int total = (int)nums.size();
    
    queue<pair<int, int>> queue;
    vector<vector<int>> matirx(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matirx[i][j] = nums[n *i + j];
            if (matirx[i][j] == 1) {
                queue.push(make_pair(i, j));
                total--;
            }
        }
    }
    
    if (queue.size() == 0 || queue.size() == nums.size()) {
        return -1;
    }
    
    int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while (queue.size() > 0) {
        pair<int, int> pos = queue.front();
        queue.pop();
        int i = pos.first;
        int j = pos.second;
        int num = matirx[i][j];
        for (auto offset:offsets) {
            int newI = i + offset[0];
            int newJ = j + offset[1];
            if (newI >= 0 && newI < n && newJ >= 0 && newJ <n && matirx[newI][newJ] == 0) {
                matirx[newI][newJ] = num + 1;
                queue.push(make_pair(newI, newJ));
                total--;
                if (total == 0) {
                    return num;
                }
            }
        }
    }
    return -1;
}



int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    vector<int> nums = getNumsForString(s);
    
    cout << getResult(nums) << endl;
    
    return 0;
}
