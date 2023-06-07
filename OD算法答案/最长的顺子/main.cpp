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



// 最长的顺子
// 斗地主起源于湖北十堰房县，据说是一位叫吴修全的年轻人根据当地流行的扑克玩法“跑得快”改编的，如今已风靡整个中国，并流行于互联网上。

vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}


string getResult(vector<string>myArr,vector<string>usedArr) {
    map<int, string> mapToK;
    map<string, int> map;
  
    map["3"] = 3;
    map["4"] = 4;
    map["5"] = 5;
    map["6"] = 6;
    map["7"] = 7;
    map["8"] = 8;
    map["9"] = 9;
    map["10"] = 10;
    map["J"] = 11;
    map["Q"] = 12;
    map["K"] = 13;
    map["A"] = 14;
    map["2"] = 16;
    map["B"] = 17;
    map["C"] = 18;
    
    
    mapToK[3] = "3";
    mapToK[4] = "4";
    mapToK[5] = "5";
    mapToK[6] = "6";
    mapToK[7] = "7";
    mapToK[8] = "8";
    mapToK[9] = "9";
    mapToK[10] = "10";
    mapToK[11] = "J";
    mapToK[12] = "Q";
    mapToK[13] = "K";
    mapToK[14] = "A";
    mapToK[16] = "2";
    mapToK[17] = "B";
    mapToK[18] = "C";
    
    
    vector<int>count = {0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,4,1,1};
    for (string k: myArr) {
        count[map[k]]--;
    }
    
    for (string k: usedArr) {
        count[map[k]]--;
    }
   
    string ans = "NO-CHAIN";
    int maxLen = 0;
    int l = 3;
    
    while (l <=10) {
        vector<string> tmp;
        string sj;
        for (int r = l; r < 16; r++) {
            if (count[r] >=1) {
                tmp.push_back(mapToK[r]);
                if (sj.length() > 0) {
                    sj += "-";
                }
                sj += mapToK[r];
            } else {
                if (tmp.size() >= 5 && tmp.size() >= maxLen) {
                    maxLen = (int)tmp.size();
                    ans = sj;
                }
                l = r;
                break;
            }
        }
        l++;
    }
    
    
  
    return ans;
}



int main(int argc, const char * argv[]) {
    
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<string> myArr = getArrForString(s1);
    vector<string> usedArr = getArrForString(s2);
    
  cout << getResult(myArr,usedArr) << endl;
    
    return 0;
}
