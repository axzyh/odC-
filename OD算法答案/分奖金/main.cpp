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



// 分奖金
// 公司老板做了一笔大生意，想要给每位员工分配一些奖金，想通过游戏的方式来决定每个人分多少钱。
//   按照员工的工号顺序，每个人随机抽取一个数字。

string getResult(vector<int>vec,int m) {
    vector<int> ans;
    bool isFlag = false;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (vec[j] > vec[i]) {
                ans.push_back((j - i)*(vec[j] - vec[i]));
                isFlag = true;
                break;
            }
        }
        if (isFlag == false) {
            ans.push_back(vec[i]);
        } else {
            isFlag = false;
        }
    }
    
    string str;
    for (int i : ans) {
        if (str.length() > 0) {
            str += " ";
        }
        str += to_string(i);
    }
    return str;
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<int>vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    cout << getResult(vec, n) << endl;
    
    return 0;
}
