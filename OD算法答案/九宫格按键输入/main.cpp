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



// 九宫格按键输入
// 九宫格按键输入，输出显示内容，有英文和数字两个模式，默认是数字模式，数字模式直接输出数字，英文模式连续按同一个按键会依次出现这个按键上的字母，如果输入”/”或者其他字符，则循环中断。

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


vector<string> dict = {" ",",.","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
stack< char> st;
int topRepeat = 0;
bool isEnglish = false;


char mapc(char c,int repeat) {
    int num = c - '0';
    string s = dict[num];
    int i = (repeat - 1) % s.length();
    return s[i];
}

void interrupt() {
    if (!isEnglish || st.size() == 0 || topRepeat == 0) {
        return;
    }
    char c = mapc(st.top(),topRepeat);
    topRepeat = 0;
    st.pop();
    st.push(c);
}


string getResult(string s1) {
    s1 += " ";
    
    for (int i = 0; i < s1.length(); i++) {
        char c = s1[i];
        switch (c) {
            case '#':
                interrupt();
                isEnglish =!isEnglish;
                break;
            case '/':
                interrupt();
                break;
                
            default:
                if (!isEnglish) {
                    st.push(c);
                    break;
                }
                
                if (st.size() == 0) {
                    st.push(c);
                    topRepeat++;
                    break;
                }
                if (c != st.top()) {
                    interrupt();
                    st.push(c);
                }
                topRepeat++;
                
                break;
        }
    }
    
    string ans;
    while (st.size() > 0) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
  
    return ans;
}



int main(int argc, const char * argv[]) {
    
    string s1;
    getline(cin, s1);
   
    
  cout << getResult(s1) << endl;
    
    return 0;
}
