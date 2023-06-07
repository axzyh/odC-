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



// 连续出牌数量
// 有这么一款单人卡牌游戏，牌面由颜色和数字组成，颜色为红、黄、蓝、绿中的一种，数字为0-9中的一个。游戏开始时玩家从手牌中选取一张卡牌打出，接下来如果玩家手中有和他上一次打出的手牌颜色或者数字相同的手牌，他可以继续将该手牌打出，直至手牌打光或者没有符合条件可以继续打出的手牌。

vector<string> getNumsForString(string s) {
    string tmp;
    vector<string> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ' ') {
            tVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(tmp);
    }
    return tVec;
}

class UnionFindSet {
    vector<int> fa;
public:int count;
public: UnionFindSet(int n) {
        for (int i = 0; i < n; i++) {
            fa.push_back(i);
            count = n;
        }
    }
    
    int find(int x) {
        if (x != fa[x]) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
   void uniond(int x , int y) {
        int x_fa = find(x);
        int y_fa = find(y);
        if (x_fa != y_fa) {
            fa[y_fa] = x_fa;
            count--;
        }
    }
};

int getResult(vector<string>nums,vector<string>colors) {
    
    int n = (int)nums.size();
    
    UnionFindSet ufs = UnionFindSet(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j] || colors[i] == colors[j]) {
                ufs.uniond(i, j);
            }
        }
    }
    
    map<int, int> count;
    for (int i = 0; i< n; i++) {
        int f = ufs.find(i);
        count[f]++;
    }
    int ans = 0;
    for (auto i:count) {
        ans = max(ans, i.second);
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<string> nums = getNumsForString(s1);
    vector<string> colors = getNumsForString(s2);
    cout << getResult(nums,colors) << endl;
    
    return 0;
}
