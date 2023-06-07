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



// 经典屏保
// DVD机在视频输出时，为了保护电视显像管，在待机状态会显示“屏保动画”，如下图所示，DVD Logo在屏幕内来回运动，碰到边缘会反弹。

bool check(int m, int add,vector<int>nums) {
    m -= nums[0];
    for (int i = 1; i <nums.size(); i++) {
        m += add;
        if (m > nums[i]) {
            m -= nums[i];
        } else {
            return false;
        }
    }
    return true;
}

string getResult(vector<int> nums) {
    int x = nums[0];
    x += nums[2];
    int y = nums[1];
    y += nums[2];
    
    while (y + 25 > 600 || y < 0 || x + 50 > 800 || x < 0) {
        if (y + 25 > 600) {
            y = 1150 - y;
        }
        if (x + 50 > 800) {
            x = 1500 - x;
        }
        if (x < 0) {
            x = -x;
        }
        if (y < 0) {
            y = -y;
        }
    }
    return to_string(x) + " " + to_string(y);
}

int main(int argc, const char * argv[]) {
    vector<int> nums(3);
    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }
    cout << getResult(nums) << endl;
    
    return 0;
}
