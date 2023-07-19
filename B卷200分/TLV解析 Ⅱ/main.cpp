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

// TLV解析 Ⅱ
// 两端通过TLV格式的报文来通信，现在收到对端的一个TLV格式的消息包，要求生成匹配后的(tag, length, valueOffset)列表。


// 进制转换
int charInt(char target) {
    if (target >= '0' && target <= '9') {
        return target - '0';
    } else {
        return target - 'A' + 10;
    }
}

int coverM2T(string str,int m) {
    int number = 0;
    for (int i = 0; i < str.length(); i++) {
        number *= m;
        number += charInt(str[i]);
    }
    return number;
}

string coverMT(long number,int n) {
    string str;
    while (number > 0) {
        str += to_string(number % n);
        number /= n;
    }
    reverse(str.begin(), str.end());
    return to_string(stol(str));
}


void getResult(string msg, vector<int> tags) {
    
    unordered_map<int, vector<int>> tagMap;
    for (int i = 0; i + 3 < msg.length(); i++) {
        int tag = coverM2T(msg.substr(i,i+2), 16);
        int len = coverM2T(msg.substr(i+2,2), 16);
        int valueOffset = (i + 5) /2;
        i += 3 + len * 2;
        if (i >= msg.length()) {
            break;
        }
        tagMap[tag] = {len,valueOffset};
        
    }
    
    for (int tag : tags) {
        if (tagMap.count(tag)) {
            vector<int> tmp = tagMap[tag];
            int len = tmp[0];
            int valueOffset = tmp[1];
            cout << to_string(len) + " " + to_string(valueOffset) << endl;
        } else {
            cout << "0 0" << endl;
        }
    }
   
    
}

int main(int argc, const char * argv[]) {
    string msg;
    int n;
    getline(cin, msg);
    
    cin >> n;
    vector<int> tags(n);
    for (int i = 0; i < n; i++) {
       cin >> tags[i];
    }
    getResult(msg, tags);
    return 0;
}
