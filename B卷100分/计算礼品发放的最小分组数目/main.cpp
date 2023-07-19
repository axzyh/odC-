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

// 计算礼品发放的最小分组数目
// 又到了一年的末尾，项目组让小明负责新年晚会的小礼品发放工作。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
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

int getResult(vector<int> arr, int n) {
   
    sort(arr.begin(), arr.end());
    int count = 0;
    int l = 0;
    int r = (int)arr.size() - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum < n) {
            l++;
        }
        r--;
        count++;
    }
    if (l == r) {
        count++;
    }
    return count;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline(cin, str);
    vector<int> arr = getArrStrForString(str);
   
    cout << getResult(arr,n) << endl;
    
    return 0;
}
