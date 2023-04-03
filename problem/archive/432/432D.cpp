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

vector<int> z_func(string& s) {
    int n = s.size(), L = -1, R = -1;
    vector<int> z(n);
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i <= R)
            z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    string s; cin >> s;

    auto z = z_func(s);
    int n = ssz(s);
    map<int, int> ans, cnt;
    rep(i, n) {
        if (i + z[i] >= n) {
            ans[z[i]] = 0;
        }
        if (z[i]) {
            cnt[z[i]]++;
        }
    }

    vector<pair<int, int>> pre;
    for (auto& [k, v]: cnt) {
        pre.emplace_back(k, v);
    }

    sorta(pre);
    for (int i = ssz(pre) - 2; i >= 0; i--) {
        pre[i].second += pre[i + 1].second;
    }

    rep(i, ssz(pre)) {
        if (ans.find(pre[i].first) != ans.end()) {
            ans[pre[i].first] = pre[i].second;
        }
    }

    cout << ssz(ans) << endl;
    for (auto& [k, v]: ans) {
        cout << k << " " << v << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}