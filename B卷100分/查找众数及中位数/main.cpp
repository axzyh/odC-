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

// 查找众数及中位数
// 众数是指一组数据中出现次数量多的那个数，众数可以是多个。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    } else {
        return false;
    }
}

int getResult(vector<int> nums) {
    unordered_map<int, int> count;
    
    for (int num : nums) {
        count[num]++;
    }
    
    vector<pair<int, int>> vec(count.begin(),count.end());
    
    sort(vec.begin(), vec.end(), compare);
    int maxCount = vec.front().second;
    vector<int> ans;
    for (pair<int, int> pa : vec) {
        if (pa.second == maxCount) {
            ans.push_back(pa.first);
        }
    }
    
    sort(ans.begin(), ans.end());
    int mid = (int)ans.size() / 2;
    
    if (ans.size() % 2 == 0) {
        return (ans[mid] + ans[mid - 1]) / 2;
    } else {
        return ans[mid];
    }
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
   vector<int> nums = getArrNumsForString(str);
    
 
    cout << getResult(nums) << endl;
    
    return 0;
}
