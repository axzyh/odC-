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



// 阿里巴巴找黄金宝箱(IV)
//一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0-N的箱子，每个箱子上面有一个数字，箱子排列成一个环，编号最大的箱子的下一个是编号为0的箱子。

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

void findNextBig(vector<int> arr,stack<pair<int, int>>&stack,vector<int> &res) {
    for (int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        while (true) {
            if (stack.size() == 0) {
                stack.push(make_pair(ele, i));
                break;
            } else {
                pair<int, int> peek = stack.top();
                int peekEle = peek.first;
                int peekIndex = peek.second;
                if (ele > peekEle) {
                    res[peekIndex] = ele;
                    stack.pop();
                } else {
                    stack.push(make_pair(ele, i));
                    break;
                }
            }
        }
    }
    
}

string getResult(vector<int> arr1 ) {
    stack<pair<int, int>> stack;
    vector<int> res(arr1.size());
    for (int i = 0; i < res.size(); i++) {
        res[i] = -1;
    }
    
    findNextBig(arr1, stack, res);
    if (stack.size() != 1 ) {
        findNextBig(arr1, stack, res);
    }
    
    string sj;
    for (int num : res) {
        if (sj.length() > 0) {
            sj += ",";
        }
        sj += to_string(num);
    }
    
    return sj;
}

int main(int argc, const char * argv[]) {
    string s1;
    getline(cin, s1);
    vector<int> arr1 = sprtStringToVecInt(s1, ',');
   
    
   cout << getResult(arr1) << endl;
    return 0;
}
