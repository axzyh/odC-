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
#include <iomanip>


using namespace std;

// 最短木板长度
// 小明有 n 块木板，第 i ( 1 ≤ i ≤ n ) 块木板长度为 ai。
/*
 5 2
 4 5 3 5 5
*/

int getResult(int m, vector<int> arr) {
    unordered_map<int, int> woods;
    
    for (int ar : arr) {
        woods[ar]++;
    }
    
    priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> pq;
    for (auto wood:woods) {
        pq.push({wood.first,wood.second});
    }
    
    while (m > 0) {
        if (pq.size() == 1) {
            vector<int> info = pq.top();
            pq.pop();
            int len = info[0];
            int count = info[1];
            return len + m / count;
        }
        vector<int> min1 = pq.top();
        pq.pop();
        vector<int> min2 = pq.top();
        int diff = min2[0] - min1[0];
        int total = diff * min1[1];
        if (total > m) {
            return min1[0] + m / min1[1];
        }
        
        if (total == m) {
            return min2[0];
        }
        if (total < m) {
            m -= total;
            min2[1] += min1[1];
            pq.pop();
            pq.push(min2);
        }
    }
  
    return pq.top()[0];
}



int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    cin.ignore();
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getResult(m, arr) << endl;
//
    return 0;
}




