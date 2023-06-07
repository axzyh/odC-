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



// 最差产品奖
// A公司准备对他下面的N个产品评选最差奖，
//  评选的方式是首先对每个产品进行评分，然后根据评分区间计算相邻几个产品中最差的产品。

// 字符串分割成整型数组
vector<int> sprtStringToVecInt(string str,char c) {
    vector<int> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
        temp = "";
    }
    return vec;
}

string getResult(int k, vector<int>nums){
    deque<int>queue;
    string sj;
    for (int i = 0; i < k; i++) {
        while (queue.size() > 0 && queue.back() > nums[i]) {
            queue.pop_back();
        }
        queue.push_back(nums[i]);
    }
    if (sj.length() > 0) {
        sj += ",";
    }
    sj += to_string(queue.front());
    
    for (int i = k; i < nums.size(); i++) {
        if (nums[i - k] - queue.front() ==0) {
            queue.pop_front();
        }
        while (queue.size() > 0 && queue.back() > nums[i]) {
            queue.pop_back();
        }
        queue.push_back(nums[i]);
       
        if (sj.length() > 0) {
            sj += ",";
        }
        sj += to_string(queue.front());
    }
    return sj;
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline(cin, str);
    vector<int> vec = sprtStringToVecInt(str, ',');
    cout << getResult(n,vec) << endl;
    
    return 0;
}
