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



// 硬件产品销售方案
// 某公司目前推出了AI开发者套件，AI加速卡，AI加速模块，AI服务器，智能边缘多种硬件产品，每种产品包含若干个型号。
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

void dfs(int amount,vector<int>vec,int index,int sum,vector<string> &res,vector<int> &path ){
    if (sum >= amount) {
        if (sum == amount) {
//            res.push_back(string(path.begin(),path.end()));
            if (res.size() > 0) {
                res.push_back(",");
            }
            res.push_back("[");
            for (auto v : path) {
//                if (res.size() > 0) {
//                    res.push_back(",");
//                }
                res.push_back(to_string(v));
                res.push_back(",");
                
            }
            res.pop_back();
            res.push_back("]");
        }
        return;
    }
    for (int i = index; i < vec.size(); i++) {
        path.push_back(vec[i]);
        dfs(amount, vec, i, sum + vec[i], res, path);
        path.pop_back();
    }
}

string getResult(vector<int> vec, int amout) {
    vector<string>res;
    vector<int> path;
    dfs(amout, vec, 0, 0, res, path);
    string ans;
    ans += "[";
    for (auto r:res) {
        ans += r;
//        ans +=",";
    }
//    ans.pop_back();
    ans +="]";
    return ans;
    
}

void test9() {
   
}
int main(int argc, const char * argv[]) {
    int amount;
    string str;
    cin >> amount;
    cin.ignore();
    getline(cin, str);
    vector<int> vec = getStringForTest(str);
    cout << getResult(vec, amount)<<endl;
    
    return 0;
}
