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

// 积木最远距离
// 小华和小薇一起通过玩积木游戏学习数学。
/*
 5
 1
 2
 3
 1
 4
*/

int getResult(vector<int> arr, int n) {
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        idx[num].push_back(i);
    }
    int ans = -1;
    for (auto &k : idx) {
        vector<int> link = k.second;
        if (link.size() > 1) {
            ans = max(ans, link.back() - link.front());
        }
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
    cout << getResult(arr,n) << endl;
//
    return 0;
}




