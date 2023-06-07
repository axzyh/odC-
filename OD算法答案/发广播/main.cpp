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



// 发广播
// 某地有N个广播站，站点之间有些有连接，有些没有。有连接的站点在接受到广播后会互相发送。
vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}

class UnoinFindSet {
public:  int count;
    vector<int>fa;
public:   UnoinFindSet(int n) {
        fa = vector<int>(n);
        count = n;
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    
  int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
            return fa[x];
        } else {
            return x;
        }
    }
    
    void uniond(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y ) {
            fa[fa_y] = fa_x;
            count--;
        }
    }
    
};

int getResult(vector<string> arr) {
    int n = (int)arr.size();
    UnoinFindSet ufs = UnoinFindSet(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1') {
                ufs.uniond(i, j);
            }
        }
    }
    
    return ufs.count;
}

int main(int argc, const char * argv[]) {
    
    string s;
    getline(cin, s);
    vector<string> arr = getArrForString(s);
    cout << getResult(arr) << endl;
    
    return 0;
}
