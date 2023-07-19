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

// 执行时长
// 为了充分发挥GPU算力，需要尽可能多的将任务交给GPU执行，现在有一个任务数组，数组元素表示在这1秒内新增的任务个数且每秒都有新增任务。

int getResult(int maxCount, int n, vector<int> tasks) {
    
    // 用例不过，降序排列
    int time = 0;
    int remain = 0;
    for (int task : tasks) {
        if (task + remain > maxCount) {
            remain = task + remain - maxCount;
        } else {
            remain = 0;
        }
        time++;
    }
    while (remain > 0) {
        remain -= maxCount;
        time++;
    }
    
    return time;
}

int main(int argc, const char * argv[]) {
    int maxCount,n;
    cin >> maxCount >> n;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }
    
    cout << getResult(maxCount, n, tasks) << endl;
    
    return 0;
}
