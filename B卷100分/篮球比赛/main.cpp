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

// 篮球比赛
// 篮球(5V5)比赛中，每个球员拥有一个战斗力，每个队伍的所有球员战斗力之和为该队伍的总体战斗力。

void dfs(vector<int> arr, int index, int level, int sum, vector<int> &res) {
    if (level == 5) {
        res.push_back(sum);
        return;
    }
    
    for (int i = index; i < 10; i++) {
        if ((i > 0 && arr[i] == arr[i - 1])) {
            continue;
        }
        sum += arr[i];
        
        dfs(arr, i + 1, level + 1, sum, res);
//        res.pop_back();
    }
}

long getResult(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<int> res;
    
    dfs(arr, 0, 0, 0, res);
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    int ans = sum;
    for (int i : res) {
        int tmp = abs(sum - i - i);
        ans = min(ans, tmp);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr(10);
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
   
    cout << getResult(arr) << endl;
    
    return 0;
}
