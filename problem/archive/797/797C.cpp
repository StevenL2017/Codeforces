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
    string s;
    cin >> s;

    int n = ssz(s);
    set<pair<char, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(s[i], i);
    }
    
    string ans;
    vector<pair<char, int>> stk;
    int p = 0;
    for (auto [c, i]: st) {
        while (!stk.empty() && stk.back().first <= c) {
            ans += stk.back().first;
            stk.pop_back();
        }
        while (p <= i) {
            stk.emplace_back(s[p], p);
            p++;
        }
    }
    while (!stk.empty()) {
        ans += stk.back().first;
        stk.pop_back();
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}