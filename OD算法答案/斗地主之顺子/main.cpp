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



// 斗地主之顺子
// 在斗地主扑克牌游戏中， 扑克牌由小到大的顺序为：3,4,5,6,7,8,9,10,J,Q,K,A,2，玩家可以出的扑克牌阵型有：单张、对子、顺子、飞机、炸弹等。
vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
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

int mapToNum(string card) {
    if (card == "J") {
        return 11;
    }
    if (card == "Q") {
        return 12;
    }
    if (card == "K") {
        return 13;
    }
    if (card == "A") {
        return 14;
    }
    return stoi(card);
}

string mapToCard(int num) {
    if (num == 11) {
        return "J";
    }
    if (num == 12) {
        return "Q";
    }
    if (num == 13) {
        return "K";
    }
    if (num == 14) {
        return "A";
    }
    return to_string(num);
}

bool isStraight(vector<int> count, int start,int end) {
    int i = start;
    for (; i <= end; i++) {
        if (count[i] == 0) {
            break;
        }
    }
    return i > end;
}

void getResult(vector<string>cards) {
    int totoal = (int)cards.size();
    
    vector<int>count(15);
    for (string card : cards) {
        int num = mapToNum(card);
        count[num]++;
    }
    vector<vector<int>> straights;
    
    for (int i = 3; i <= 10; i++) {
        if (isStraight(count, i, i + 4)) {
            straights.push_back({i, i + 4});
            totoal -=5;
            for (int j = i; j <= i + 4; j++) {
                count[j]--;
            }
//            i = 2; 此处看用例是否需要
        }
    }
    if (totoal > 0) {
        for (vector<int> &straight : straights) {
            for (int i = 3; i <= 14; i++) {
                if (count[i] > 0 && i - straight[1] == 1) {
                    straight[1] = i;
                    count[i]--;
                }
            }
        }
    }
    
    if (straights.size() == 0) {
        cout << "No" << endl;
        return;
    }
    for (auto staight :straights) {
        int start = staight[0];
        int end = staight[1];
        string str;
        for (int i = start; i <= end; i++) {
            if (str.length() > 0) {
                str += " ";
            }
            str += mapToCard(i);
        }
        cout << str << endl;
    }
    
   
}

int main(int argc, const char * argv[]) {
    
    string s1;
    getline(cin, s1);
    vector<string> cards = getArrForString(s1);
    
     getResult(cards);
    
    return 0;
}
