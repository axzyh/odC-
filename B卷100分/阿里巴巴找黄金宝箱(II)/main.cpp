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



// 阿里巴巴找黄金宝箱(II)
//一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0-N的箱子，每个箱子上面贴有箱子中藏有金币数量

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

bool cmp(pair<int, int> a,pair<int, int> b) {
    return a.second >= b.second;
}

int getResult(vector<int> nums) {
    unordered_map<int, int> count;
    for (int num:nums) {
        count[num]++;
    }
    int half = ceil(nums.size() / 2.0);
    
    vector<pair<int, int>>vec(count.begin(),count.end());
    sort(vec.begin(), vec.end(), cmp);
    
    int remove = 0;
    int numCount = 0;
    
    for (auto i : vec) {
        remove += i.second;
        numCount++;
        if (remove >= half) {
            return numCount;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int> nums = getNumsForString(str);
    cout << getResult(nums) << endl;
    
    return 0;
}
