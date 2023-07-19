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


using namespace std;

// 字符串加密
// 给你一串未加密的字符串str，通过对字符串的每一个字母进行改变来实现加密，加密方式是在每一个字母str[i]偏移特定数组元素a[i]的量，数组a前三位已经赋值：a[0]=1,a[1]=2,a[2]=4。


string getResult(string s1) {
 
    int n = (int)s1.length();
    
    vector<long> vec(n);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 4;
    
    if (n >= 3) {
        for (int i = 3; i < n; i++) {
            vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
        }
    }
    vector<char> cArr;
    
    for (char c : s1) {
        cArr.push_back(c);
    }
    string res;
    for (int i = 0; i < n; i++) {
        cArr[i] = (char)((vec[i] + (cArr[i] - 'a')) % 26 + 'a');
        res += cArr[i];
    }
    
  
    return res;
}

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout << getResult(arr[i]) << endl;
    }
    
   
    
    return 0;
}
