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
#include <iomanip>


using namespace std;

// 匿名信
// 电视剧《分界线》里面有一个片段，男主为了向警察透露案件细节，且不暴露自己，于是将报刊上的字减下来，剪拼成匿名信。
/*
 ab ef
 aef
*/

vector<string> getArrStringForS(string str) {
    vector<string> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(temp);
    }
    return arr;
}

string getResult(vector<string> newspapers, vector<string> anonymousLetters) {
    unordered_map<string, int> count;
    for (string str : newspapers) {
        sort(str.begin(), str.end());
        count[str]++;
    }
    
    bool flag = true;
    
    for (string str : anonymousLetters) {
        sort(str.begin(), str.end());
        if (count.count(str) && count[str] > 0) {
            count[str]--;
        } else {
            flag = false;
            break;
        }
    }
  
    return flag ? "true" : "false";
}



int main(int argc, const char * argv[]) {
  
    string newspaper, anonymousLetter;
    getline(cin, newspaper);
    getline(cin, anonymousLetter);
    vector<string> newspapers = getArrStringForS(newspaper);
    vector<string> anonymousLetters = getArrStringForS(anonymousLetter);
   

    cout <<  getResult(newspapers, anonymousLetters) << endl;
//
    return 0;
}




