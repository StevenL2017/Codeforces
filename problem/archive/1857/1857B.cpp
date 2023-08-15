#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    string s; cin >> s;

    string ans;
    reverse(s.begin(), s.end());
    int carry = 0, k = 0;
    for (int i = 0; i < ssz(s); i++) {
        auto c = s[i];
        auto cur = (int)(c - '0') + carry;
        if (cur < 5) {
            ans = (char)(cur + '0') + ans;
            carry = 0;
        } else {
            ans = '0' + ans;
            carry = 1;
            k = i;
        }
    }
    if (carry) {
        ans = '1' + ans;
        k = ssz(s);
    }
    for (int i = ssz(ans) - k; i < ssz(ans); i++) {
        ans[i] = '0';
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}