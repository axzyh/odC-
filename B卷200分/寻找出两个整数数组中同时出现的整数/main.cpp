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



// 寻找出两个整数数组中同时出现的整数
// 现有两个整数数组，需要你找出两个数组中同时出现的整数，并按照如下要求输出:

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

void getResult(vector<int> arr1,vector<int>arr2 ) {
    
    map<int, int> countMap1;
    for (int i = 0; i < arr1.size(); i++) {
        countMap1[arr1[i]]++;
    }
    map<int, int> countMap2;
    for (int i = 0; i < arr2.size(); i++) {
        countMap2[arr2[i]]++;
    }
    
    map<int, set<int>> sameCountMap;
    
    for (auto num:countMap1) {
        if (countMap2.count(num.first)) {
            int count = min(countMap1[num.first], countMap2[num.first]);
            sameCountMap[count].insert(num.first);
        }
    }
    
    
    if (sameCountMap.size() == 0) {
        cout << "NULL" << endl;
        return ;
    }
    
    
    for (auto num : sameCountMap) {
        
        string s1;
        for (auto i: num.second) {
            if (s1.length() > 0) {
                s1 += ",";
            }
            s1 += to_string(i);
        }
        cout << num.first << ":" << s1 << endl;
    }
   
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<vector<int>> nums;
    vector<int> arr1 = sprtStringToVecInt(s1, ',');
    vector<int> arr2 = sprtStringToVecInt(s2, ',');
    
    getResult(arr1, arr2);
    return 0;
}
