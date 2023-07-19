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



// 打印任务排序
// 某个打印机根据打印队列执行打印任务。打印任务分为九个优先级，分别用数字1-9表示，数字越大优先级越高。打印机每次从队列头部取出第一个任务A，

vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ',') {
            tVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(stoi(tmp));
    }
    return tVec;
}

bool compare(pair<int, int> a, pair<int, int>b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first && a.second < b.second) {
        return true;
    }
    else {
        return false;
    }
}

string getResult(vector<int> nums) {
    vector<pair<int, int>>tasks(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        tasks[i] = make_pair(nums[i], i);
    }
    sort(tasks.begin(), tasks.end(), compare);
    
    vector<int>ids(nums.size());
    for (int i = 0; i < tasks.size(); i++) {
        ids[tasks[i].second] = i;
    }
    
    string sj;
    for (auto i : ids) {
        if (sj.length() > 0) {
            sj += ",";
        }
        sj += to_string(i);
    }
    return sj;
}



int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    vector<int> nums = getNumsForString(s);
    
    cout << getResult(nums) << endl;
    
    return 0;
}
