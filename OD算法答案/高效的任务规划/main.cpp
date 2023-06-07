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



// 高效的任务规划
// 你有 n 台机器，编号为 1~n，每台都需要完成一项工作，机器经过配置后都能完成独立完成一项工作。


bool compare(pair<int, int>a,pair<int, int>b){
    if (a.second > b.second) {
        return true;
    } else {
        return false;
    }
}

void getResult(vector<vector<pair<int, int>>>tasks) {
   
    for (auto &task : tasks) {
        sort(task.begin(), task.end(), compare);
        int n = (int)task.size();
        vector<int> dp(n);
        dp[0] = task[0].first + task[0].second;
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 1] - task[i - 1].second + task[i].first +task[i].second);
        }
        cout << to_string(dp[n - 1]) << endl;
    }
}

int main(int argc, const char * argv[]) {
    int m,n;
    cin >> m;
    vector<vector<pair<int, int>>> tasks(m);
    for (int i = 0; i < m; i++) {
        cin >> n;
        vector<pair<int, int>> task(n);
        for (int j = 0; j < n; j++) {
            cin >> task[j].first >> task[j].second;
        }
        tasks[i] = task;
    }
    
    getResult(tasks);
    return 0;
}
