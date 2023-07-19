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

// 总最快检测效率
// 在系统、网络均正常的情况下组织核酸采样员和志愿者对人群进行核酸检测筛查。
/*
 2 2
 100 20
*/

vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(stoi(temp));
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(stoi(temp));
    }
    return arr;
}


bool compare(int a, int b) {
    if (a > b) {
        return true;
    }
    return false;
}

int getResult(vector<int> arr, int x, int y) {
    sort(arr.begin(), arr.end(), compare);
    int maxRen =0;
    int count = 0;
    int i = 0;
    int j = 0;
    if (y < x) {
        for (int k = 0; k < x; k++) {
            maxRen += k < y ? arr[k] :arr[k] * 0.8;
        }
        i = 0;
        j = y - 1;
    } else {
        if (y >= 4 * x) {
            y = 4 * x;
        }
        
        for (int val : arr) {
            maxRen += val;
        }
        
        int surplus = y - x;
        i = 0;
        j = x - 1;
        while (surplus > 0) {
            maxRen += arr[i] * 0.1;
            surplus--;
            if (++count == 3) {
                count = 0;
                i++;
            }
        }
    }
    
    while (i < j) {
        if (arr[i] * 0.1 > arr[j] * 0.2) {
            maxRen += arr[i] * 0.1 - arr[j] * 0.2;
            if (++count == 3) {
                count = 0;
                i++;
            }
            j--;
        } else {
            break;
        }
    }
    
    return maxRen;
}



int main(int argc, const char * argv[]) {
  
    int x, y;
    cin >> x >> y;
    vector<int> arrX(x);
    for (int i = 0; i < x; i++) {
        cin >> arrX[i];
    }

  
   cout << getResult(arrX,x,y) << endl;
//
    return 0;
}




