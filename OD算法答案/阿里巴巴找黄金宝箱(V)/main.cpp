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



// 阿里巴巴找黄金宝箱(V)
// 一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0~N的箱子，每个箱子上面贴有一个数字。


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

int getResult(vector<int>nums,int k) {
    
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int ans = windowSum;
    for (int i = 1; i <= nums.size() - k; i++) {
        windowSum -= nums[i - 1];
        windowSum += nums[i + k - 1];
        ans = max(ans, windowSum);
        
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    string s;
    int k;
    getline(cin, s);
    cin >> k;

    cout << getResult(getNumsForString(s),k) << endl;
    
    return 0;
}
