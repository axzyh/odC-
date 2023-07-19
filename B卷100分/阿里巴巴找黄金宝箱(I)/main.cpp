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



// 阿里巴巴找黄金宝箱(I)
//一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0~N的箱子，每个箱子上面贴有一个数字，箱子中可能有一个黄金宝箱。


vector<int> getNumsForString(string s) {
    vector<int>nums;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (temp.length() >0 && s[i] == ',' ) {
            nums.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0) {
        nums.push_back(stoi(temp));
    }
    return nums;
}

int getResult(vector<int>nums) {
   
    int RightSum = 0;
    int LeftSum = 0;
    for (int i = 1; i < nums.size(); i++) {
        RightSum += nums[i];
    }
    if (LeftSum == RightSum) {
        return 0;
    }
    
    for (int i = 1; i < nums.size(); i++) {
        LeftSum += nums[i - 1];
        RightSum -= nums[i];
        if (LeftSum == RightSum) {
            return i;
        }
    }
    
    
    return -1;
}

int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);

    cout << getResult(getNumsForString(s)) << endl;
    
    return 0;
}
