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

// 字符串筛选排序
// 输入一个由N个大小写字母组成的字符串

int getResult(string str, int k) {
    
    vector<char> chars = vector<char>(str.begin(),str.end());
    
    sort(chars.begin(), chars.end());
    
    if (k > str.length()) {
        k = (int)str.length();
    }
    
    char tar = chars[k - 1];
    
    int pos = (int)str.find(tar);
    return pos;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    int k;
    cin >> k;
    cout << getResult(str, k) << endl;
    
    return 0;
}
