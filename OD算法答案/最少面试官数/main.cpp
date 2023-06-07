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



// 最少面试官数
// 面试采用一对一的方式，即一名面试官同时只能面试一名应试者，一名面试官完成一次面试后可以立即进行下一场面试，且每个面试官的面试人次不超过 m。


bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second < b.second) {
        return true;
    } else {
        return false;
    }
}

void getResult(int m, int n, vector<pair<int, int>> ranges) {
    sort(ranges.begin(), ranges.end(), compare);
    vector<vector<int>> buckets(n);
    for (auto range: ranges) {
        int s = range.first;
        int e = range.second;
        for (auto &bucket : buckets) {
            if (bucket.size() < m && (bucket.size() == 0 || bucket.back() < s)) {
                bucket.push_back(e);
                break;
            }
        }
    }
    
    int ans = 0;
    for (auto i: buckets) {
        if (i.size() > 0) {
            ans++;
        }
    }
    
    cout <<ans <<endl;
    
}

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first;
        cin >> ranges[i].second;
    }
    
   getResult(m,n,ranges);
    return 0;
}
