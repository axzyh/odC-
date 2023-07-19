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



// 最长广播响应
// 某通信网络中有N个网络结点，用1到N进行标识。

int getResult(vector<pair<int, int>> relations, int n, int src ) {
   
    map<int, vector<int>> graph;
    
    for (auto relation:relations) {
        int u = relation.first;
        int v = relation.second;
        graph[u].push_back(v);
    }
    
    vector<int> dist;
    for (int i = 0; i < n + 1; i++) {
        dist.push_back(INT_MAX);
    }
    dist[src] = 0;
    priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
    
    while (true) {
        if (graph.count(src)) {
            for (auto v : graph[src]) {
                int newDist = dist[src] + 1;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({v,newDist});
                }
            }
        }
        if (pq.size() == 0) {
            break;
        }
        vector<int> c = pq.top();
        pq.pop();
        src = c[0];
        
    }
    dist.erase(dist.begin() +0);
    sort(dist.begin(), dist.end());
    return dist[dist.size() - 1] * 2;
}

int main(int argc, const char * argv[]) {
    int n, t, src;
    cin >> n >> t;
    vector<pair<int, int>> relations(t);
    for (int i = 0 ; i < t; i++) {
        cin >> relations[i].first >> relations[i].second;
    }
    cin >> src;
    
    getResult(relations, n, src);
    return 0;
}
