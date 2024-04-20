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

bool check(string &s) {
    int tot = 0;
    for (auto x: s) {
        tot += (x - '0');
        tot %= 3;
    }
    return tot == 0;
}

string del1(string &s) {
    int n = ssz(s), tot = 0;
    for (auto x: s) {
        tot += (x - '0');
        tot %= 3;
    }
    vi del(n);
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 3 == tot) {
            del[i] = 1;
            break;
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        if (!del[i]) ans += s[i];
    }
    bool sz = !ans.empty();
    reverse(ans.begin(), ans.end());
    while (!ans.empty() && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (check(ans) && !ans.empty()) return ans;
    if (check(ans) && sz) return "0";
    if (check(ans)) return ans;
    return "";
}

string del2(string &s) {
    int n = ssz(s), tot = 0;
    for (auto x: s) {
        tot += (x - '0');
        tot %= 3;
    }
    vi del(n);
    for (int i = n - 1; i >= 0 && tot != 0; i--) {
        if ((s[i] - '0') % 3) {
            del[i] = 1;
            tot = (tot - (s[i] - '0') % 3 + 3) % 3;
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        if (!del[i]) ans += s[i];
    }
    bool sz = !ans.empty();
    reverse(ans.begin(), ans.end());
    while (!ans.empty() && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (check(ans) && !ans.empty()) return ans;
    if (check(ans) && sz) return "0";
    if (check(ans)) return ans;
    return "";
}

void solve() {
    string s; cin >> s;

    string ans = max(del1(s), del2(s), [&] (string s1, string s2) { return ssz(s1) < ssz(s2); });
    if (ans.empty()) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}