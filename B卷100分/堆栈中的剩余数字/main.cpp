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

// 堆栈中的剩余数字
// 向一个空栈中依次存入正整数，假设入栈元素 n(1<=n<=2^31-1)按顺序依次为 nx…n4、 n3、n2、 n1, 每当元素入栈时，如果 n1=n2+…+ny(y 的范围[2,x]， 1<=x<=1000)，则 n1~ny 全部元素出栈，重新入栈新元素 m(m=2*n1)。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
   
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        }  else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

vector<double> getDoubleForArr(vector<string> arr) {
    int n = (int)arr.size();
    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = stod(arr[i]);
    }
    return vec;
}

string getResult(vector<int> arr) {
    int n = (int)arr.size();
    vector<int> dp(n + 1);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] == arr[i]) {
            arr[i] *= 2;
            fill(arr.begin(), arr.begin() + i, 0);
            fill(dp.begin(), dp.begin() + i, 0);
            continue;
        }
        if (dp[i - 1] > arr[i]) {
            int preSum = dp[i - 1] - arr[i];
            for (int j = 0; j < i - 1; j++) {
                if (dp[j] == preSum) {
                    arr[i] *= 2;
                    fill(arr.begin(), arr.begin() + j, 0);
                    fill(dp.begin(), dp.begin() + j, 0);
                    break;
                }
                if (dp[j] > preSum) {
                    break;
                }
            }
        }
        
    }
    string res;
    
    for (int i = (int)arr.size() - 1; i >= 0; i --) {
        
        if (arr[i] != 0 ) {
            if (res.length() > 0) {
                res += " ";
            }
            res += to_string(arr[i]);
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    vector<int> arr = getArrStrForString(str);
    
    cout << getResult(arr) << endl;
    
    return 0;
}
