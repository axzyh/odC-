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

// 查找树中元素
//已知树形结构的所有节点信息，现要求根据输入坐标（x,y）找到该节点保存的内容值，其中x表示节点所在的层数，根节点位于第0层，根节点的子节点位于第1层，依次类推；y表示节点在该层内的相对偏移，从左至右，第一个节点偏移0，第二个节点偏移1，依次类推；


vector<vector<int>>nodes;

// 字符串分割成整型数组
vector<int> sprtStringToVecInt(string str,char c) {
    vector<int> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
        temp = "";
    }
    return vec;
}

void dfs(vector<vector<int>>&matrix, vector<int>v,int level){
    if (v.size() == 0) {
        return;
    }
    int val = v[0];
    if (level < matrix.size()) {
        matrix[level].push_back(val);
    } else {
        vector<int>list;
        list.push_back(val);
        matrix.push_back(list);
    }
    
    for (int i = 1; i < v.size(); i++) {
        int child = v[i];
        dfs(matrix, nodes[child], level+1);
    }
}

string getResult(vector<vector<int>>vec,int x, int y) {
    
    if (x < 0 || y < 0) {
        return "{}";
    }
    vector<vector<int>>matrix;
    dfs(matrix, vec[0], 0);
    if (x < matrix.size() && y < matrix[x].size()) {
        return "{" +to_string(matrix[x][y]) + "}";
    } else {
        return "{}";
    }
    return "";
}

int main(int argc, const char * argv[]) {
    int n,x,y;
    
    cin >> n;
    cin.ignore();
    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        vector<int>v = sprtStringToVecInt(str, ' ');
        nodes.push_back(v);
    }
    cin >> x >> y;
    cout << getResult(nodes, x, y) << endl;
    
    return 0;
}
