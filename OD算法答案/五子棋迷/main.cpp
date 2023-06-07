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



// 五子棋迷
//张兵和王武是五子棋迷迷，工作之余经常切磋棋艺。这不，这会儿又下起来了。走了一会儿，轮张兵了，对着一条线思考起来了，这条线上的棋子分布如下:

vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ' ') {
            tVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(stoi(tmp));
    }
    
    
    return tVec;
}


int mid;

bool compare(vector<int>a,vector<int>b) {
    if (a[1] - b[1] > 0 ) {
        return true;
    } else if (a[1] == b[1]) {
        int dis1 = abs(a[0] - mid);
        int dis2 = abs(b[0] - mid);
        if (dis1 != dis2  ) {
            if (dis1 < dis2) {
                return true;
            } else {
                return false;
            }
        }  else {
             if(a[0] < b[0]) {
                return true;
             } else {
                 return false;
             }
           
        }
    }
    else {
        return false;
    }
}
int getResult(vector<int> nums,int color) {
    vector<vector<int>> ans;
    int l = 0;
    int r = 0;
    int zero = 0;
    int pos = -1;
    while (r < nums.size()) {
        if (nums[r] == 0) {
            zero++;
            if (zero > 1 && r - l <= 5) {
                ans.push_back({pos,r-l});
            }
            if (zero > 1) {
                zero--;
                l = pos+ 1;
            }
            pos = r;
            ++r;
        }
        else if (nums[r] != color) {
            if (zero == 1 && r-l <= 5) {
                ans.push_back({pos,r - l});
            }
            pos = -1;
            zero = 0;
            l = ++r;
        }else {
            ++r;
        }
    }
    // 收尾操作
    if (zero == 1 && r - l <= 5) {
        ans.push_back({pos,r-l});
    }
    if (ans.size() == 0) {
        return -1;
    }
   mid = nums.size() / 2;
    sort(ans.begin(), ans.end(), compare);
    
    
    return ans[0][0];
}

int main(int argc, const char * argv[]) {
    int color;
    cin >> color;
    string str;
    cin.ignore();
    getline(cin, str);
    vector<int>nums = getNumsForString(str);
    cout << getResult(nums,color);
    return 0;
}
