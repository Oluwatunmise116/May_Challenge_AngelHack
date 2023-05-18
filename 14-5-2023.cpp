#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 500;

int findMinimumDeletion(int l, int r, vector<vector<int>>& dp, const string& s) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    
    int res = 1 + findMinimumDeletion(l + 1, r, dp, s);
    
    for (int i = l + 1; i <= r; ++i) {
        if (s[l] == s[i]) {
            res = min(res, findMinimumDeletion(l + 1, i - 1, dp, s) + findMinimumDeletion(i, r, dp, s));
        }
    }
    
   
    return dp[l][r] = res;
}

int main() {
    string s = "kjslaqpwoereeeeewwwefifjdksjdfhjdksdjfkdfdlddkjdjfjfjfjjjjfjffnefhkjgefkgjefkjgkefjekihutrieruhigtefhgbjkkkknbmssdsdsfdvneurghiueor";
    int n = s.length();
    vector<vector<int>> dp(N, vector<int>(N, -1));
    
    cout << "The minimum number of steps required for the series is: "
         << findMinimumDeletion(0, n - 1, dp, s) << endl;
    
    return 0;
}
