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

// 补种未成活胡杨
// 近些年来，我国防沙治沙取得显著成果。某沙漠新种植N棵胡杨（编号1-N），排成一排。

int getResult(vector<int> arr,int k) {
    int left = 0;
    vector<int> occur;
    int maxLen = 0;
    for (int right = 0; right < arr.size(); right++) {
        if(arr[right] == 0) {
            occur.push_back(right);
        if (occur.size() > k) {
            maxLen = max(maxLen, right - left);
            left = occur.front() + 1;
            occur.erase(occur.begin() + 0);
            continue;
        }
    }
    maxLen = max(maxLen, right - left + 1);
}

   
    
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    int n,m,idx,k;
    cin >> n >> m;
    vector<int> arr(n);
    fill(arr.begin(), arr.end(), 1);
    for (int i = 0; i < m; i++) {
        cin >> idx;
        arr[idx - 1] = 0;
    }
    cin >> k;

    cout << getResult(arr,k) << endl;
    
    return 0;
}
