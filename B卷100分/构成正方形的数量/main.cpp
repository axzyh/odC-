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

// 构成正方形的数量
// 输入N个互不相同的二维整数坐标，求这N个坐标可以构成的正方形数量。[内积为零的的两个向量垂直]

int getResult(int n, vector<pair<int, int>> ranges) {
    int squareCount = 0;
    set<pair<int, int>> set(ranges.begin(), ranges.end());
    for (int i = 0; i < n; i++) {
        pair<int, int> arr = ranges[i];
        int x1 = arr.first, y1 = arr.second;
        
        for (int j = i + 1; j < n; j++) {
            pair<int, int> arr2 = ranges[j];
            int x2 = arr2.first, y2 = arr2.second;
            int x3 = x1 - (y1 - y2), y3 = y1 + (x1 - x2);
            int x4 = x2 - (y1 - y2), y4 = y2 + (x1 - x2);
            pair<int, int> p3 = make_pair(x3, y3);
            if (set.count(p3) && set.count(make_pair(x4, y4))) {
                squareCount++;
            }
            int x5 = x1 + (y1 - y2), y5 = y1 - (x1 - x2);
            int x6 = x2 + (y1 - y2), y6 = y2 - (x1 - x2);
            if (set.count(make_pair(x5, y5)) && set.count(make_pair(x6, y6))) {
                squareCount++;
            }
        }
    }
    
    
    return squareCount / 4;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges (n);
    for (int i = 0; i < n; i++) {
        
        cin >> ranges[i].first >> ranges[i].second;
    }
    
    cout << getResult(n,ranges) << endl;
    
    return 0;
}
