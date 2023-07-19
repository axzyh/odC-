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

// 内存资源分配Ⅱ
// 有一个简易内存池，内存按照大小粒度分类，每个粒度有若干个可用内存资源，用户会进行一系列内存申请，需要按需分配内存池中的资源返回申请结果成功失败列表。

vector<vector<int>> getArrNumsForString(string s) {
    vector<vector<int>> arr;
    string tmp;
    vector<int> nums;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
            
        } else if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            arr.push_back(nums);
            nums.clear();
            tmp = "";
        } else {
            tmp +=s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
        arr.push_back(nums);
    }
    return arr;
}

vector<int> getArrStrForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    
    return nums;
}

bool compare(vector<int>a, vector<int>b) {
    if (a[0] <= b[0]) {
        return true;
    } else {
        return false;
    }
}


string getResult(vector<vector<int>>pools, vector<int> applies) {
    sort(pools.begin(), pools.end(), compare);
    
    vector<int> sizes;
    vector<int> counts;
    for (vector<int> pool : pools) {
        sizes.push_back(pool[0]);
        counts.push_back(pool[1]);
    }
    
    
    vector<bool>ans;
    for (int apply: applies) {
      int idx = (int)(upper_bound(sizes.begin(), sizes.end(), apply) - sizes.begin());
        if (idx >= sizes.size()) {
            ans.push_back(false);
            continue;
        }
        
        counts[idx] = counts[idx] - 1;
        ans.push_back(true);
        if (counts[idx] == 0) {
            counts.erase(counts.begin() + idx);
            sizes.erase(sizes.begin() + idx);
        }
    }
    
    string result;
    for (bool an : ans) {
        if (result.length() > 0) {
            result += ",";
        }
        result += an == true ? "true" : "flase";
    }
    

    return result;
    
}

int main(int argc, const char * argv[]) {
   
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    vector<vector<int>> pools = getArrNumsForString(s1);
    vector<int> applies = getArrStrForString(s2);
    
    cout << getResult(pools, applies) << endl;
    return 0;
}
