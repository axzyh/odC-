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

// 找朋友
// 在学校中，N个小朋友站成一队， 第i个小朋友的身高为height[i]，

string getResult(int n ,vector<int> nums) {
    
    stack<vector<int>> st;
    int len = (int)nums.size();
    vector<int> res(len);
    for (int i = 0; i < len; i++) {
        int ele = nums[i];
        while (true) {
            if (st.size() == 0) {
                st.push({ele,i});
                break;
            }
            vector<int> peek = st.top();
            int peekEle = peek[0];
            int peekIndex = peek[1];
            if (ele > peekEle) {
                res[peekIndex] = i;
                st.pop();
            } else {
                st.push({ele, i});
                break;
            }
        }
    }
    string ans;
    for (int v : res) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(v);
    }
    return ans;
}

int main(int argc, const char * argv[]) {

    int n;
     
    cin >> n;
    
    
    vector<int> nums(n);
  
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
   
   
    cout << getResult(n,nums) << endl;
    
    return 0;
}
