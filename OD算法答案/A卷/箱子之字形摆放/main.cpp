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
#include <algorithm>
#include <regex>
#include <iomanip>


using namespace std;

// 箱子之字形摆放
// 有一批箱子（形式为字符串，设为str），
/*
 ABCDEFG
 3
*/

// 并查集

class UnionFindSet {
public: int count;
    vector<int> fa;
    
public: UnionFindSet(int n) {
    count = n;
    fa = vector<int>(n);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}
    int find(int x) {
        if (x != fa[x]) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
    void unionn(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y) {
            fa[fa_x] = fa_y;
            count--;
        }
    }

    
};

void getResult(int n, string str) {
    vector<vector<char>> matrix;
    for (int i = 0; i < n; i++) {
        matrix.push_back({});
    }
    bool reverse = true;
    for (int i = 0; i < str.length(); i++) {
        int k = i % n;
        if (k == 0) {
            reverse = !reverse;
        }
        if (reverse) {
            k = n - 1 - k;
        }
        matrix[k].push_back(str[i]);
    }
    
    for (vector<char> list : matrix) {
        string res;
        for ( char c : list) {
            res += c;
            
        }
        cout << res << endl;
    }
    
}



int main(int argc, const char * argv[]) {
  
    
    string str;
    getline(cin, str);
    int n;
    cin >> n;
  
    getResult(n,str) ;
//
    return 0;
}




