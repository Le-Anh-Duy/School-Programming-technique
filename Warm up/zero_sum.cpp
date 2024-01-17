#include <iostream>
using namespace std;

bool isZeroSumSubArr(int arr[], int n);
bool isSubStr(string s, string sSub) {
    int slen = s.length();
    int sSublen = sSub.length();

    for (int i = 0; i < 1 + slen - sSublen; i++) {
        if (s[i] != sSub[0]) continue;
        int j = i;
        while (s[j] == sSub[j - i]) {
            j ++;
            if (j - i == sSublen) return true;
        }
    }

    return false;
}

int main() {
    // cout << isSubStr("aaaaaacb", "cb");
    cout << (0[*1]);
    return 0;
}

bool isZeroSumSubArr(int arr[], int n) {
    for (int i = 0; i < n; i ++) {
        int s = 0;
        for (int j = i; j < n; j ++) {
            s += arr[j];
            if (s == 0) return true;
        }
    } 
    return false;
}

