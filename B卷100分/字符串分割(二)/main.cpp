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

// 字符串分割(二)
// 给定一个非空字符串S，其被N个‘-’分隔成N+1的子串，给定正整数K，要求除第一个子串外，其余的子串每K个字符组成新的子串，并用‘-’分隔。


vector<string> getArrStrForString(string s) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-' && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
    
}

string upperString(string &str) {
    for (int i = 0; i < str.length(); i++) {
      str[i] = toupper(str[i]);
    }
    return str;
}

string lowerString(string &str) {
    for (int i = 0; i < str.length(); i++) {
       str[i] = tolower(str[i]);
    }
    return str;
}

string convert(string str) {
    int lowerCount = 0;
    int upperCount = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upperCount++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            lowerCount++;
        }
    }
    if (lowerCount < upperCount) {
        return upperString(str);
    } else if (lowerCount > upperCount) {
        return lowerString(str);
    } else {
        return str;
    }
}


string getResult(int k, string str) {
    vector<string> arr = getArrStrForString(str);
    string ans;
    ans += arr[0];
//    ans += '-';
    string res;
    for (int i = 1; i < arr.size(); i++) {
        res += arr[i];
    }
    
    for (int i = 0; i < res.length(); i+= k) {
        int index = min(k, (int)res.length() - i);
        string subs = res.substr(i, index);
        ans += "-";
        ans += convert(subs);
    }
    
   
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int k;
    cin >> k;
    cin.ignore();
    
    string str;
    getline(cin, str);
    
    
    cout << getResult(k,str) << endl;
    
    return 0;
}
