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

int getInitMaxConstantLen(int color, vector<int> nums) {
    int maxLen = 0;
    int len = 0;
    for (int num : nums) {
        if (num != color) {
            maxLen = max(len, maxLen);
            len = 0;
        } else {
            len++;
        }
    }
    
    return max(maxLen, len);
}

int getResult(vector<int> nums,int color) {
    
    // 获取目标初始化最大连续长度
    int maxConstantLen = getInitMaxConstantLen(color, nums);
    
    vector<vector<int>> ans;
    int l = 0;
    int r = 0;
    int zero = 0;
    int pos = -1;
    while (r < nums.size()) {
        // 如果nums[r] 是空位
        if (nums[r] == 0) {
            // 则可以落子，因此落子个数++
            zero++;
            // 如果落子数量超过一个了，则此时l～r - 1，范围就是一个连棋（PS：r位置不算在内），
            // 如果连续长度（r- l） - l + 1 <= 5（pS: 五子棋约束），则是一个合法的连棋
            // 本题要求落子可以是的当前子的最大连续长度变大
            
            if (zero > 1 && r - l <= 5 && r - l > maxConstantLen) {
                ans.push_back({pos,r-l});
            }
            if (zero > 1) {
                zero--;
                l = pos+ 1;
            }
            pos = r;
            ++r;
        }
        // 如果nums[r]位置有其他颜色棋子，则连续中断
        else if (nums[r] != color) {
            // 此时需检查l～ r-1 范围内是否落过子，且是否符合五子棋约束
            // 若是， 则记录 l～ r-1 范围落子位置pos，以及连续长度 r-l
            // 本题要求落子可以使得当前子的最大连续变大
            if (zero == 1 && r-l <= 5 && r-l > maxConstantLen) {
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
    mid = (int)nums.size() / 2;
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
    cout << getResult(nums,color) << endl;
    return 0;
}
