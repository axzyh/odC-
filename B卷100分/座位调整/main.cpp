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



// 座位调整
// 疫情期间课堂的座位进行了特殊的调整，不能出现两个同学紧挨着，必须隔至少一个空位。
/*
1,0,0,0,1
 */


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

int getResult(vector<int>nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            bool isLeftEmpty = i == 0 || nums[i - 1] == 0;
            bool isRightEmpty = i == nums.size() - i || nums[i + 1] == 0;
            if (isLeftEmpty && isRightEmpty) {
                ans++;
                nums[i] = 1;
                i++;
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
    vector<int>nums = getNumsForString(str);
    
    cout << getResult(nums) << endl;
    return 0;
}
