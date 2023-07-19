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

// TLV解析Ⅰ
// TLV编码是按[Tag Length Value]格式进行编码的，一段码流中的信元用Tag标识，Tag在码流中唯一不重复，Length表示信元Value的长度，Value表示信元的值。

bool isCharStr(char c) {
    
    return (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z');
}

vector<string> getArrStrForString(string str) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
}

int charInt(char target) {
    if (target >= '0' && target <= '9') {
        return target - '0';
    } else {
        return target - 'A' + 10;
    }
}

int jinzhi(string str,int number) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num *= number;
        num += charInt(str[i]);
    }
    return num;
    
}


string getResult(string target, vector<string> arr) {
    int i = 0;
    while (i < arr.size()) {
        string tag = arr[i++];
        string tmp1 = arr[i++];
        string tmp2 = arr[i++];
        int len = jinzhi(tmp1, 16) + jinzhi(tmp2, 16);
        vector<string> val;
        for (int j = 0; j < len; j++) {
            val.push_back(arr[i++]);
        }
        if (tag == target) {
            string ans;
            for (string s: val) {
                if (ans.length() > 0) {
                    ans += " ";
                }
                ans += s;
            }
            return ans;
        }
    }
    return "";
}

int main(int argc, const char * argv[]) {

    string target, stream;
    getline(cin, target);
    getline(cin, stream);
    
    vector<string> arr = getArrStrForString(stream);
    
   
    cout << getResult(target, arr) << endl;
    
    return 0;
}
