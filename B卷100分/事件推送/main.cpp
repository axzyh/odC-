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

// 事件推送
// 同一个数轴X上有两个点的集合A={A1, A2, …, Am}和B={B1, B2, …, Bn}，Ai和Bj均为正整数，A、B已经按照从小到大排好序，

void getResult(int r ,vector<int> a, vector<int> b) {
    
    for (int ai : a) {
        vector<int>::iterator iter = lower_bound(b.begin(), b.end(), ai);
        if (*iter >= 0 && *iter - r <= ai) {
            cout << to_string(ai) + " " + to_string(*iter) << endl;
        } else {
           
            if (*iter - ai <= r) {
                cout << to_string(ai) + " " + to_string(*iter) << endl;
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    int m, n, r;
     
    cin >> m >> n >> r;
    
    vector<int> a(m);
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
   
   
    getResult(r, a, b);
    
    return 0;
}
