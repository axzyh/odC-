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



// 区间交集
// 给定一组闭区间，其中部分区间存在交集。

bool compare(pair<int, int>a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void getResult(int n,vector<pair<int, int>>ranges) {

    sort(ranges.begin(), ranges.end());
    vector<pair<int, int>> combine;
    for (int i = 0; i < n; i++) {
        int s1 = ranges[i].first, e1 = ranges[i].second;
        for (int j = i + 1; j < n; j++) {
            int s2 = ranges[j].first, e2 = ranges[j].second;
            if (s2 <= e1) {
                combine.push_back(make_pair(s2, min(e1, e2)));
            } else {
                break;
            }
        }
    }
    
    if (combine.size() == 0) {
        cout << "None" << endl;
        return;
    }
    
    sort(combine.begin(), combine.end(),compare);
    pair<int, int>pre = combine[0];
    for (int i = 1; i < combine.size(); i++) {
        pair<int, int> cur = combine[i];
        
        if (pre.second >= cur.first) {
            pre.second = max(pre.second, cur.second);
        } else {
            cout << to_string(pre.first) << " " << to_string(pre.second) << endl;
            pre = cur;
        }
    }
    cout << to_string(pre.first) << " " << to_string(pre.second) << endl;
    
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    
    getResult(n, ranges);
    
    return 0;
}
