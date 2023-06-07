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



// 书籍叠放
// 书籍的长、宽都是整数对应 (l,w)。如果书A的长宽度都比B长宽大时，则允许将B排列放在A上面。现在有一组规格的书籍，书籍叠放时要求书籍不能做旋转，请计算最多能有多少个规格书籍能叠放在一起。


vector<pair<int, int>> getArrForString(string s) {
    string tmp;
    vector<pair<int, int>> arr;
    int left = 0, right = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (tmp.length() > 0 &&(c == ',' || c == ']')) {
            if (left > 0) {
                right = stoi(tmp);
                tmp = "";
                arr.push_back(make_pair(left, right));
                left = 0;
                right = 0;
            } else {
                left = stoi(tmp);
                tmp ="";
            }
        } else {
            if (isnumber(c)) {
                tmp += c;
            }
        }
    }
    return arr;
}

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        }
        return false;
    }
    return false;
}

int getMaxLis(vector<int> nums) {
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > dp[dp.size() - 1]) {
            dp.push_back(nums[i]);
            continue;
        }
        if (nums[i] < dp[0]) {
            dp[0] = nums[i];
        }
        int idx = binary_search(dp.begin(), dp.end(), nums[i]);
        if (idx < 0) {
            dp[-idx - 1] = nums[i];
        }
    }
    return (int)dp.size();
}

int getResult(vector<pair<int, int>> books) {
    sort(books.begin(), books.end(), compare);
   vector<int> widths;
    for (int i = 0; i < books.size(); i++) {
        widths.push_back(books[i].second);
    }
    return getMaxLis(widths);
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<pair<int, int>> books = getArrForString(str);
    
    cout << getResult(books) << endl;
    return 0;
}
