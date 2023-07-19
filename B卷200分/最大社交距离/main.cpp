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



// 最大社交距离
// 疫情期间需要大家保证一定的社交距离，公司组织开交流会议。座位一排共 N 个座位，编号分别为[0,N-1],

// 字符串分割成int数组
vector<int> getStringForTest(string s) {
    string tmp;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            
        } else if (s[i] == ',' || s[i] == ']') {
            ans.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    return ans;
}


int getResult(vector<int> nums, int n) {
    vector<int> seat;
    int ans = -1;
    for (int sol:nums) {
        int onSeat = (int)seat.size();
        if (sol != 1) {
            seat.erase(remove(seat.begin(), seat.end(), (-sol)));
            continue;
        }
        if (onSeat == 0) {
            ans = 0;
            seat.push_back(ans);
        } else if (onSeat == 1) {
            ans =  n - 1;
            seat.push_back(ans);
        } else {
            int maxDis = 0;
            int start = -1;
            for (int i = 1; i < seat.size(); i++) {
                int p = seat[i-1];
                int c = seat[i];
                if (c == p+1) {
                    continue;
                }
                int dis = (int)ceil((c - p - 1) /2.0);
                if (dis > maxDis) {
                    maxDis = dis;
                    start = p;
                }
            }
            int brand_dis = n - 1 - seat.back();
            if (brand_dis > maxDis) {
                maxDis = brand_dis;
                start = seat.back();
            }
            ans = start + maxDis;
            if (ans != -1) {
                seat.push_back(ans);
                sort(seat.begin(), seat.end());
            }
        }
    }
   
    return ans;
}



int main(int argc, const char * argv[]) {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    vector<int> nums = getStringForTest(s);
   
    
  
    
    cout << getResult(nums,n) << endl;
    
    return 0;
}
