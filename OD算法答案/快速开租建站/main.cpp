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



// 快速开租建站
// 当前IT部门支撑了子公司颗粒化业务，该部门需要实现为子公司快速开租建站的能力，建站是指在一个全新的环境部署一套IT服务。
int getResult(int taskNums,vector<vector<int>>relations) {
    map<int, vector<int>> next;
    vector<int> inDegree(taskNums);
    for (auto relation : relations) {
        int a = relation[0];
        int b = relation[1];
        vector<int> v = next[a];
        v.push_back(b);
        next[a] = v;
        inDegree[b]++;
    }
    queue<vector<int>> queue;
    int t = 1;
    for (int i = 0; i < taskNums; i++) {
        if (inDegree[i] == 0) {
            queue.push({i,t});
        }
    }
    
    while (queue.size() > 0) {
        vector<int> tmp = queue.front();
        queue.pop();
        int task = tmp[0];
        int time = tmp[1];
        if (next.count(task) && next[task].size() > 0) {
            for (int nxt : next[task]) {
                if (--inDegree[nxt] == 0) {
                    t = time+1;
                    queue.push({nxt,t});
                }
            }
        }
    }
    
    return t;
    
}

int main(int argc, const char * argv[]) {
    int taskNum, relationsNum;
    cin >> taskNum >> relationsNum;
    vector<vector<int>>vec(relationsNum,vector<int>(2));
    
    for (int i = 0; i < relationsNum; i++) {
        cin >> vec[i][0];
        cin >> vec[i][1];
    }
  cout << getResult(taskNum, vec) << endl;
    
    return 0;
}
