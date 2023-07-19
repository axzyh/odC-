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

// 太阳能板最大面积
// 给航天器一侧加装长方形或正方形的太阳能板（图中的红色斜线区域），需要先安装两个支柱（

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

long getResult(vector<int> arr) {
    
    int l = 0;
    int r = (int)arr.size() - 1;
    long maxArea = 0;
    while (l < r) {
        long x = r - l;
        long y = 0;
        if (arr[l] < arr[r] ) {
           y = arr[l++];
        } else {
           y = arr[r--];
        }
        
        maxArea = max(maxArea, x * y);
    }
    
   
    return maxArea;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    
    vector<int> arr = getArrStrForString(str);
//    1,3,6,2,8,7,4,10,9,5
//    此题答案存疑
  cout << getResult(arr) << endl;
    
    return 0;
}
