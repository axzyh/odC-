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
#include <unordered_set>
#include <regex>

using namespace std;



// 乘坐保密电梯
// 有一座保密大楼，你从0楼到达指定楼层m，必须这样的规则乘坐电梯：
int expectUpCount;
int limitUpSum;
int MaxUpSumBelowLimit = 0;
vector<vector<bool>> paths;


int compare(vector<int> list1, vector<int> list2) {
    for (int i = 0; i < list1.size(); i++) {
        int v1 = list1[i];
        int v2 = list2[i];
        if (v1 > v2) {
            return -1;
        }
        if (v1 < v2) {
            return 1;
        }
    }
    return 0;
}

bool compare2(int a, int b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

void dfs(vector<int> nums, int index, vector<bool> &path, int sum, int count) {
    if (count > expectUpCount) {
        return;
    }
    if (count == expectUpCount) {
        if (sum < MaxUpSumBelowLimit) { // 非最优解
            return;
        }
        if (sum > MaxUpSumBelowLimit) {
            MaxUpSumBelowLimit = sum;
            paths.clear();
        }
//        paths(path.begin(),path.end());
//        paths.push_back(path.begin(),path.end());
//        paths.insert( path.begin(),path.end());
        paths.push_back(path);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        int num = nums[i];
        if (sum + num > limitUpSum) {
            continue;
        }
        path[i] = true;
        dfs(nums, i + 1, path, sum + num, count + 1);
        path[i] = false;
    }
    
}

vector<int> getSeq(vector<bool> &path, vector<int> nums) {
    // 上升序列
    vector<int> up;
    vector<int> down;
    for (int i = 0; i < nums.size(); i++) {
        if (path[i]) {
            up.push_back(nums[i]);
        } else {
            down.push_back(nums[i]);
        }
    }
    vector<int> seq;
    for (int i = 0; i < nums.size() / 2; i++) {
        seq.push_back(up.front());
        up.erase(up.begin());
        seq.push_back(down.front());
        down.erase(down.begin());
    }
    if (up.size() > 0) {
        seq.push_back(up.front());
        up.erase(up.begin());
    }
    return seq;
}

string getResult(int m, int n, vector<int> nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum += nums[i];
    }
    expectUpCount = n / 2 + n % 2;
    limitUpSum = (sum + m) / 2;
    sort(nums.begin(), nums.end(),compare2);
    vector<bool> path(n);
    dfs(nums, 0, path, 0, 0);
    if (paths.size() == 0) {
        return "-1";
    }
    
    vector<int> res = getSeq(paths[0], nums);
    sort(res.begin(), res.end(), compare2);
    string sj;
    for (int v : res) {
        if (sj.length() > 0) {
            sj += " ";
        }
        sj += to_string(v);
    }
    return sj;
    
}

int main(int argc, const char * argv[]) {
  
    int m,n;
    cin >> m >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
   
    cout << getResult(m, n, nums) << endl;
   
    
    return 0;
}
