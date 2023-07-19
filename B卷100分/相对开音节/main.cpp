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

// 相对开音节
// 相对开音节构成的结构为：辅音 + 元音（aeiou）+ 辅音(r除外) + e。

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
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

int getResult(vector<string> sArr) {
    int count = 0;
    
    regex noLetter("[^a-z]");
    regex reg1("[^aeiou][aeiou][^aeiour]e");
    regex reg2("e[^aeiour][aeiou][^aeiou]");
    smatch matchResult;
    for (string word : sArr) {
        regex reg = regex_match(word, matchResult, noLetter) ? reg1 : reg2;
        for (int i = 0; i <= (int)word.length() - 4; i++) {
            string tmp = word.substr(i,4);
            if (regex_match(tmp, matchResult, reg)) {
                count++;;
            }
        }
    }
   
    return count;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    
    vector<string> sArr = getArrStrForString(str);
    cout << getResult(sArr) << endl;
    
    return 0;
}
