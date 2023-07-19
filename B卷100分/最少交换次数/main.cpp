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

// 最少交换次数
// 给出数字K,请输出所有结果小于K的整数组合到一起的最少交换次数。

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

int getResult(vector<int> arr,int k) {
    int count = 0;
    for (int a : arr) {
        if (a < k) {
            count++;
        }
    }
    if (count == 1) {
        return 0;
    }
    
    int minSwapCount = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) {
            minSwapCount++;
        }
    }
    
    int tmpSwapCount = minSwapCount;
    
    for (int i = count; i < arr.size(); i++) {
        int preLeft = i - count;
        if (arr[preLeft] >= k && arr[i] < k) {
            tmpSwapCount--;
        } else if (arr[preLeft] < k && arr[i] >= k) {
            tmpSwapCount++;
        }
        minSwapCount = min(minSwapCount, tmpSwapCount);
    }
    return minSwapCount;
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    vector<int> arr = getArrStrForString(str);
    int k;
    cin >> k;

    cout << getResult(arr,k) << endl;
    
    return 0;
}
