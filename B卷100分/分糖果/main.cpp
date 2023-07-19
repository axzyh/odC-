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

// 分糖果
// 小明从糖果盒中随意抓一把糖果，每次小明会取出一半的糖果分给同学们。

void recuriive(long num, int count, int &ans) {
    if (num == 1) {
        ans = min(ans, count);
        return;
    }
    if (num % 2 == 0) {
        count++;
        recuriive(num / 2, count, ans);
    } else {
        recuriive(num + 1, count + 1, ans);
        recuriive(num - 1, count + 1, ans);
    }
}

int getResult(long n) {
    int ans = INT_MAX;
    recuriive(n, 0, ans);
    
    
    return ans;
}

int main(int argc, const char * argv[]) {
   
    long n;
    cin >> n;
    
    cout << getResult(n) << endl;
    
    return 0;
}
