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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

vector<int> get_fail(string s) {
    int n = s.size();
    vector<int> fail(n + 1, -1);
    for (int i = 1, j = -1; i <= n; i++) {
        while (j >= 0 && s[j] != s[i - 1]) {
            j = fail[j];
        }
        fail[i] = ++j;
    }
    return fail;
}

void solve() {
    string s; cin >> s;

    int n = ssz(s), l = 0, r = n - 1;
    while (l < n && s[l] == s[r]) {
        l++; r--;
    }

    if (l == n) {
        cout << s << endl;
        return;
    }

    string t = s.substr(l, n - 2 * l);
    string tr = t;
    reverse(tr.begin(), tr.end());
    string t1 = t + "#" + tr;
    string t2 = tr + "#" + t;
    auto f1 = get_fail(t1), f2 = get_fail(t2);
    auto mx = max(f1.back(), f2.back());
    if (f1.back() < f2.back()) swap(t1, t2);

    string ans = l > 0 ? s.substr(0, l) : "";
    ans += t1.substr(0, mx);
    if (l > 0) {
        string suf = s.substr(0, l);
        reverse(suf.begin(), suf.end());
        ans += suf;
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