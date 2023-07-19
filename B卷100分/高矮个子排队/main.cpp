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

// 高矮个子排队
// 现在有一队小朋友，他们高矮不同，我们以正整数数组表示这一队小朋友的身高，如数组{5,3,1,2,3}。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && tmp.length() > 0) {
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

string getResult(vector<int> arr) {
    
    bool flag = true;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] != arr[i + 1] && (arr[i] > arr[i + 1] != flag)) {
            int tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }
        flag = !flag;
    }
    string res;
    for (int i : arr) {
        if (res.length() > 0) {
            res += " ";
        }
        res += to_string(i);
    }
    
   
    return res;
}


int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
    try {
        vector<int>arr = getArrStrForString(str);
        cout << getResult(arr) << endl;
    } catch (exception e) {
        cout << "[]" << endl;
    }
    return 0;
}
