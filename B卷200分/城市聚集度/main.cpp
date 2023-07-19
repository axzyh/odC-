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

// 城市聚集度
// 一张地图上有n个城市，城市和城市之间有且只有一条道路相连：要么直接相连，要么通过其它城市中转相连（可中转一次或多次）。城市与城市之间的道路都不会成环

class UnionFindSet {
//    int count;
public:  vector<int>fa;
public: UnionFindSet(int n) {
    fa = vector<int>(n);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}
    
    int find(int x) {
        if (fa[x] != x) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
    void uniond(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y ) {
           fa[fa_y] = fa_x;
        }
    }
};

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second >= b.second) {
        return true;
    } else {
        return false;
    }
}


string getResult(int n, vector<vector<int>> relations) {
   
    int min = INT_MAX;
    vector<int>city;
    for (int i = 1; i <= n; i++) {
        UnionFindSet ufs = UnionFindSet(n + 1);
        for (vector<int> relation : relations) {
            int x = relation[0], y = relation[1];
            if (x == i || y == i) {
                continue;
            }
            ufs.uniond(x, y);
        }
        
        unordered_map<int, int> count;
        for (int f :ufs.fa) {
            f = ufs.find(f);
            count[f]++;
        }
        vector<pair<int, int>> vec(count.begin(),count.end());
        sort(vec.begin(), vec.end(), compare);
        int dp = vec[0].second;
        if (dp < min) {
            min = dp;
            city = vector<int>();
            city.push_back(i);
        } else if (dp == min) {
            city.push_back(i);
        }
    }
    string ans;
    for (int c : city) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(c);
    }
   
    

    return ans;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    vector<vector<int>> relations(n-1,vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> relations[i][0] >> relations[i][1];
    }
    
    cout << getResult(n, relations);
    return 0;
}
