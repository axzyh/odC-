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



// 最小传输时延
// 某通信网络中有N个网络结点，用1到N进行标识。网络通过一个有向无环图表示，其中图的边的值表示结点之间的消息传递时延。

int getResult(vector<vector<int>> times, int n,int src,int tar) {
    map<int, vector<vector<int>>> map;
    for (auto time : times) {
        int f = time[0], s = time[1], t = time[2];
        map[f].push_back({s,t});
    }
    
    vector<int> dist(n+1);
    for (int i = 0; i < n + 1; i++) {
        dist[i] = INT_MAX;
        dist[src] = 0;
    }
    vector<int> needCheck;
    while (true) {
        bool flag = true;
        if (map.count(src)) {
            for (vector<int> next: map[src]) {
                int v = next[0], w = next[1];
                int newDist = dist[src] + w;
                if (newDist >= dist[v]) {
                    break;
                }
                dist[v] = newDist;
                vector<int>::iterator iter = find(needCheck.begin(), needCheck.end(), v);
                if (iter == needCheck.end()) {
                    needCheck.push_back(v);
                    flag = true;
                }
            }
        }
        if (needCheck.size() == 0) {
            break;
        }
        if (flag) {
            sort(needCheck.begin(), needCheck.end());
        }
        
        src = needCheck.back();
        needCheck.pop_back();
    }
   
    return dist[tar] == INT_MAX ? -1:dist[tar];
}



int main(int argc, const char * argv[]) {
    int n, m,src,dist;
    cin >> n >> m;
    vector<vector<int>> times(m,vector<int>(3));
    for (int i = 0; i < m; i ++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }
    cin >> src >> dist;
    cout << getResult(times, n, src, dist) << endl;
    return 0;
}
