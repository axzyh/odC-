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

// 跳房子II https://fcqian.blog.csdn.net/article/details/130771324
// 跳房子，也叫跳飞机，是一种世界性的儿童游戏。
//
class Step {
public: int val;
    int idx;
public: Step(int v, int id) {
        val = v;
        idx = id;
    }
};


vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] == ',' || s[i] == ']') && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else if (s[i] == '[')
            continue;
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}


bool compare(Step a, Step b) {
    if (a.val < b.val) {
        return true;
    } else if (a.val == b.val) {
        if (a.idx < b.idx) {
            return true;
        }
    }
    return false;
}

bool compare1(Step a, Step b) {
    if (a.idx < b.idx) {
        return true;
    }
    return false;
}

string getResult(vector<int> steps, int count) {
    int n = (int)steps.size();
    vector<Step> newSteps;
    for (int i = 0; i < n; i++) {
        newSteps.push_back(Step(steps[i], i));
    }
    sort(newSteps.begin(), newSteps.end(), compare);
    int minStepIdxSum = INT_MAX;
    string ans;
    for (int i = 0; i < n; i++) {
        if (newSteps[i].val > count && newSteps[i].val > 0 && count > 0) {
            break;
        }
        if (i > 0 && newSteps[i].val == newSteps[i - 1].val) {
            continue;
        }
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int stepValSum = newSteps[i].val + newSteps[l].val + newSteps[r].val;
            if (stepValSum < count) {
                l++;
            } else if (stepValSum > count) {
                r--;
            } else {
                while (l < r - 1 && newSteps[r].val == newSteps[r - 1].val) {
                    r--;
                }
                int stepIdxSum = newSteps[i].idx + newSteps[l].idx + newSteps[r].idx;
                if (stepIdxSum < minStepIdxSum) {
                    minStepIdxSum = stepIdxSum;
                    vector<Step> arr = {newSteps[i],newSteps[l], newSteps[r]};
                    sort(arr.begin(), arr.end(),compare1);
                    string res;
                    res += "[";
                    for (Step step : arr) {
                        if (res.length() > 1) {
                            res += ",";
                        }
                        res += to_string(step.val);
                    }
                    res += "]";
                    ans = res;
//
                }
                while (l + 1 < r && newSteps[l].val == newSteps[l + 1].val) {
                    l++;
                }
                l++;
                r--;
            }
        }
    }

    return ans;
    
}

int main(int argc, const char * argv[]) {
    string str;
    int count;
    getline(cin, str);
    vector<int> steps = getArrNumsForString(str);
    cin >> count;
    
    cout << getResult(steps, count) << endl;
    return 0;
}
