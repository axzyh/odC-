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

// 数字涂色
// 黑板上已经写上了N个正整数，同学们需要给这每个数分别上一种颜色。

int getResult(int n,vector<int> nums) {
    sort(nums.begin(), nums.end());
    if (nums[0] == 1) {
        return 1;
    }
    vector<bool> colors(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i]) {
            continue;
        }
        
        colors[i] = true;
        for (int j = i + 1; j < n; j++) {
            if (!colors[j] && nums[j] % nums[i] == 0 ) {
                colors[j] = true;
            }
        }
        count++;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    
    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    
    cout << getResult(m,nums) << endl;
    
    return 0;
}
