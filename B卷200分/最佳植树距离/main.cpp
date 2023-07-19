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



// 最佳植树距离
//按照环保公司要求，小明需要在沙化严重的地区进行植树防沙工作，初步目标是种植一条直线的树带。由于有些区域目前不适合种植树木，所以只能在一些可以种植的点来种植树木。

bool compare(int a,int b) {
    if (a > b) {
        return false;
    } else {
        return true;
    }
}

bool check(vector<int>vec,int m,int mid) {
    int count = 1;
    int curPos = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] - curPos >= mid) {
            count++;
            curPos = vec[i];
        }
    }
    return  count >= m;
}

int getResult(vector<int> nums,int n, int m) {
    sort(nums.begin(), nums.end(),compare);
    int ans = 0;
    int min = 1;
    int max = nums[nums.size() - 1] - nums[0];
    
    while (min <= max) {
        int mid = (min + max) >>1;
        if (check(nums, m, mid)) {
            ans = mid;
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int a,b,c;
    vector<int>vec;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        vec.push_back(b);
    }
    cin >> c;
    cout << getResult(vec, a, c) << endl;
    
    return 0;
}
