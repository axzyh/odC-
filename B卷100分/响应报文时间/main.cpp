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
#include <unordered_set>
#include <regex>

using namespace std;



// 响应报文时间
// IGMP 协议中，有一个字段称作最大响应时间 (Max Response Time) ，HOST收到查询报文，解折出 MaxResponsetime 字段后，需要在 (0，MaxResponseTime] 时间 (s) 内选取随机时间回应一个响应报文，如果在随机时间内收到一个新的查询报文，则会根据两者时间的大小，选取小的一方刷新回应时间。

string toBinaryString(int m, int n) {
    string res;
    while (m != 0) {
        int tmp = m %2;
        res = to_string(tmp) + res;
        m = m /2;
    }
    
    return res;
}

int getNumForStr(string str, int m) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num *= m;
        num += str[i] - '0';
    }
    return num;
}


int getMaxResponseTime(int m) {
    if (m >= 128) {
        string bStr = toBinaryString(m, 2);
        while (bStr.length() < 8) {
            bStr.insert(0, "0");
        }
        int exp = getNumForStr(bStr.substr(1,3), 2);
        int mant = getNumForStr(bStr.substr(4,7), 2);
        
        return (mant | 16) << (exp + 3);
    } else {
        return m;
    }
}


int getResult(vector<vector<int>> messages) {
    int ans = INT_MAX;
    for (vector<int> message : messages) {
        int respTime = message[0] + getMaxResponseTime(message[1]);
        ans = min(ans, respTime);
    }
    
  
    return ans;
}



int main(int argc, const char * argv[]) {
  
    int c;
    cin >> c;
    vector<vector<int>> messages(c,vector<int>(2));
    for (int i = 0; i < c; i++) {
        cin >> messages[i][0];
        cin >> messages[i][1];
    }
    
    cout << getResult(messages) << endl;
   
    
    return 0;
}
