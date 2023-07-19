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

// IPv4地址转换成整数
// 存在一种虚拟IPv4地址，由4小节组成，每节的范围为0~255，以#号间隔，虚拟IPv4地址可以转换为一个32位的整数，例如：

string test91(string str) {
    string outStr;
    string temp;
    vector<int> vec;
    for (int i = 0; i < str.length() ; i++) {
        if (str[i] == '#' && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
    }
    
    if (vec.size() != 4) {
        return "invalid IP";
    }
    
    int ip1 = vec[0];
    int ip2 = vec[1];
    int ip3 = vec[2];
    int ip4 = vec[3];
    if (ip1 >= 1 && ip1 <=128 && ip2 >= 0 && ip2 <=255&& ip3 >= 0 && ip3 <=255&& ip4 >= 0 && ip4 <=255) {
        long outInt = 0;
        for (int i = 0; i < vec.size(); i++) {
            outInt += vec[i] * pow(2, (3-i) * 8);
        }
        return to_string(outInt);
    } else {
        return "invalid IP";
    }
}
void test9() {
    string str;
    getline(cin, str);
    cout << test91(str) << endl;
}

int main(int argc, const char * argv[]) {
    test9();
    return 0;
}
