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

using namespace std;
// 无向图染色
// 给一个无向图染色，可以填红黑两种颜色，必须保证相邻两个节点不能同时为红色，输出有多少种不同的染色方案？

int dfs(map<int, set<int>> map,int m,int index, int count,vector<set<int>> path ) {
    
    if (path.size() == m) {
        return count;
    }
   
    for (int i = index; i <= m; i++) {
        bool isF = false;
        // 如果新加入节点i 和已有节点j相邻，则说明心加入节点不能染成红色，需要剪枝
        for (auto set : path) {
            if (set.count(i)) {
                isF = true;
                break;
            }
        }
        if (isF) {
            continue;
        }
        count++;
        
        if ((map.count(i))) {
            set<int>dd = map[i];
            path.push_back(dd);
            count = dfs(map, m, i+1, count, path);
            path.pop_back();
          
        } else {
            count = dfs(map, m, i+1, count, path);
        }
        
    }
    
    return count;
}

int getResult(vector<pair<int, int>>vec, int m) {
    // map用于存放每个节点的相邻节点
    map<int, set<int>> map;
    for (auto i: vec) {
        set<int> s = map[i.first];
        s.insert(i.second);
        map[i.first] = s;
        
        s = map[i.second];
        s.insert(i.first);
        map[i.second] = s;
        
    }
    
    vector<set<int>> path;
    // 节点从index= 1开始，必有count =1 个的全黑染色方案
    return dfs(map, m, 1, 1, path);
    
    
}

int main(int argc, const char * argv[]) {
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> vec;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pair<int, int> v = make_pair(a, b);
        vec.push_back(v);
    }
    
    cout << getResult(vec, n) << endl;
    
    return 0;
}
