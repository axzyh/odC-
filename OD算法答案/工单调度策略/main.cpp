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



// 工单调度策略
//当小区通信设备上报警时，系统会自动生成待处理的工单，华为工单调度系统需要根据不同的策略，调度外线工程师（FME）上站修复工单对应的问题。
bool compare12(vector<int> a, vector<int>b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0]) {
        return true;
    } else {
        return false;
    }
    return false;
}

int getResult(vector<vector<int>>wos,int n) {
    sort(wos.begin(), wos.end(),compare12);
    priority_queue<int,vector<int>,greater<int>> pq;
    int curTime = 0;
    int ans = 0;
    for (auto wo:wos) {
        int endTime = wo[0];
        int score = wo[1];
        
        if (endTime >= curTime+1) {
            pq.push(score);
            ans += score;
            curTime++;
            continue;
        } else {
            if (pq.size() == 0) {
                continue;
            }
        }
        int min_score = pq.top();
        if (score > min_score) {
            pq.pop();
            pq.push(score);
            ans += score - min_score;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> wos(n,vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> wos[i][0] >> wos[i][1];
    }
    cout << getResult(wos, n) << endl;
    
    return 0;
}
