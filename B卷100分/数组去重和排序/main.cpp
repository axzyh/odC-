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

// 数组去重和排序
// 给定一个乱序的数组，删除所有的重复元素，使得每个元素只出现一次，并且按照出现的次数从高到低进行排序，相同出现次数按照第一次出现顺序进行先后排序。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
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
unordered_map<int, int> frist;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        if (frist[a.first] < frist[b.first]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

string getResult(vector<int> nums) {
    unordered_map<int, int> count;
   
    
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        count[num]++;
        if (!frist.count(num)) {
            frist[num] = i;
        }
    }
    string ans;
    vector<pair<int, int>> res(count.begin(),count.end());
   
    sort(res.begin(), res.end(), compare);
    for (pair<int, int> pa : res) {
        if (ans.length() > 0) {
            ans += ",";
        }
        ans += to_string(pa.first);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    vector<int> nums = getArrNumsForString(str);
   
    cout << getResult(nums) << endl;
    
    return 0;
}
