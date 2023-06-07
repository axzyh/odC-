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

using namespace std;

// 最大化控制资源成本
// 公司创新实验室正在研究如何最小化资源成本，最大化资源利用率，请你设计算法帮他们解决一个任务混部问题：

bool compareTest15(vector<int>a, vector<int>b) {
    if (a[0] < b[0]) {
        return true;
    }
    return false;
}

int getResultTest15(vector<vector<int>>vec) {
    sort(vec.begin(), vec.end(), compareTest15);
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> end;
    int max = 0;
    int sum = 0;
    for (auto range : vec) {
        int s = range[0];
        int e = range[1];
        int p = range[2];
        while (end.size() > 0) {
           pair<int, int> top = end.top();
            if (top.first <= s) {
                sum -=top.second;
                end.pop();
            } else {
                break;
            }
        }
        end.push(make_pair(e, p));
        sum += p;
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}


int main(int argc, const char * argv[]) {
    int n,a,b,c;
    cin >> n;
   
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        vector<int> v = {a,b,c};
        vec.push_back(v);
    }
    cout << getResultTest15(vec) << endl;
    
    return 0;
}
