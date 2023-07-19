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

using namespace std;



// 计算最接近的数
// 给定一个数组X和正整数K，请找出使表达式：

vector<int> getNumsArrForString(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == ','  && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    
    return arr;
}



int getResult(vector<int> nums, int k) {
    int n = (int)nums.size();
   
    vector<int> tmp = nums;
    
    int mid = n / 2;
    sort(tmp.begin(), tmp.end());
    mid = tmp[mid];
    
    int window = nums[0];
    for (int i = 1; i < k; i++) {
        window -= nums[i];
    }
    
    int minDiff = abs(mid - window);
    int idx = 0;
    
    for (int i = 1; i <= n - k; i++) {
        window += -nums[i - 1] + 2 * nums[i] - nums[i + k -1];
        int diff = abs(mid - window);
        if (diff <= minDiff) {
            idx = i;
        }
    }
    
    
  
    return idx;
}

int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    int pos = (int)str.find(']');
    string s1 = str.substr(1,pos - 1);
    string s2 = str.substr(pos + 2, str.length());
    vector<int> nums = getNumsArrForString(s1);
    
    cout << getResult(nums,stoi(s2)) << endl;
   
    
    return 0;
}
