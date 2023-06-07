//
//  main.cpp
//  ODTest3
//
//  Created by YuChao on 2023/6/1.
//

#include <iostream>
#include <unordered_map>

using namespace std;


//恢复数字序列
//对于一个连续正整数组成的序列，可以将其拼接成一个字符串，再将字符串里的部分字符打乱顺序。如序列8 9 10 11 12，拼接成的字符串为89101112，打乱一部分字符后得到90811211，原来的正整数10就被拆成了0和1。


bool cmp(unordered_map<char, int> base,unordered_map<char, int> &count) {
    for (auto c: base) {
        if (!count.count(c.first) || count[c.first] - base[c.first] != 0) {
            return false;
        }
    }
    return true;
}


void countNumberChar(string num,unordered_map<char, int> &count,bool isAdd) {
    for (int j = 0; j < num.length(); j++) {
        char c = num[j];
        if (isAdd) {
            count[c]++;
        } else {
            count[c]--;
        }
    }
}

int getResult(string s, int k) {
    unordered_map<char, int> base;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        base[c]++;
    }
    unordered_map<char, int> count;
    for (int i = 1; i <= k; i++) {
        countNumberChar(to_string(i), count, true);
    }
    
    if (cmp(base, count)) {
        return 1;
    }
    
    for (int i = 2; i <= 1000 - k + 1; i++) {
        string remove = to_string(i - 1);
        countNumberChar(remove, count, false);
        
        string add = to_string(i+k-1);
        countNumberChar(add, count, true);
        if (cmp(base, count)) {
            return i;
        }
        
    }
    
    return -1;
}

/*恢复数字序列*/
int main(int argc, const char * argv[]) {
    string str;
    int k;
    getline(cin, str);
    
    cin >> k;
    cout <<  getResult(str, k) << endl;
    
    return 0;
}
