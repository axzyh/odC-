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


using namespace std;

// 报数游戏
// 100个人围成一圈，每个人有一个编码，编号从1开始到100。



string getResult(int m) {
    if (m <= 1 || m >= 100) {
        return "ERROR!";
    }
    
    vector<int> list;
//    int idx = 1;
    
    queue<int> q;
    for (int i = 1; i <= 100; i++) {
        list.push_back(i);
        q.push(i);
    }
    int l = 1;
    while (q.size() >= m) {
        if (l == m) {
            q.pop();
            l = 0;
        } else {
            q.push(q.front());
            q.pop();
        }
        l++;
    }
   
    vector<int> ans;
    
    while (q.size() > 0) {
        ans.push_back(q.front());
        q.pop();
    }
    sort(ans.begin(), ans.end());
    
    string res;
    for (int i : ans) {
        if (res.length() > 0) {
            res += ",";
        }
        res += to_string(i);
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
   
    int m;
    cin >> m;
    cout << getResult(m) << endl;
    
    return 0;
}
