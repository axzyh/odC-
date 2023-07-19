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

// 生日礼物
// 小牛的孩子生日快要到了，他打算给孩子买蛋糕和小礼物，蛋糕和小礼物各买一个，他的预算不超过x元。蛋糕cake和小礼物gift都有多种价位的可供选择。

vector<int> getArrNumForString(string str) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}


int searchLast(vector<int> arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int midVal = arr[mid];
        if (midVal > target) {
            high = mid - 1;
        } else if (midVal < target) {
            low = mid + 1;
        } else {
            if (mid == arr.size() - 1 || arr[mid] != arr[mid + 1]) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }
    return -low - 1;
}


long getResult(vector<int> cakes, vector<int> gifts, int x) {

    sort(cakes.begin(),cakes.end());
    long ans = 0;
    for (int gift : gifts) {
        if (x <= gift) {
            continue;
        }
        int maxCake = x - gift;
        int i = searchLast(cakes, maxCake);
        if (i >= 0) {
            ans += i + 1;
        } else {
            i = -i - 1;
            ans += i;
        }
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
   
    string cakeStr, giftStr;
    int x;
    
    getline(cin, cakeStr);
    getline(cin, giftStr);
    vector<int> cakes = getArrNumForString(cakeStr);
    vector<int> gifts = getArrNumForString(giftStr);
    cin >> x;
    cout << getResult(cakes,gifts,x) << endl;
    return 0;
}
