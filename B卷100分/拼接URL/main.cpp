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

// 拼接URL
// 给定一个url前缀和url后缀,通过,分割 需要将其连接为一个完整的url
vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}


string getResult(string prefix, string suffix) {
    string res = "/" + prefix + "/" + suffix;
    int pos = 0;
    while ((pos = res.find("//")) != string::npos) {
        res.replace(pos, 1, "");
    }
    
    

    return res;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
   
    vector<string> arr = getArrStrForString(str);
    string prefix = arr.size() > 0 ? arr[0] : "";
    string suffix = arr.size() > 1 ? arr[1] : "";
    
    cout << getResult(prefix, suffix) << endl;
    
    return 0;
}
