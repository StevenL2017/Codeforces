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

void solve() {
    int n; cin >> n;
    map<string, int> cnt;
    vector<pair<string, int>> a;
    rep(i, n) {
        string name; cin >> name;
        int score; cin >> score;
        cnt[name] += score;
        a.emplace_back(name, score);
        
    }

    int mx = 0;
    for (auto& [k, v]: cnt) {
        mx = max(mx, v);
    }

    set<string> s;
    for (auto& [k, v]: cnt) {
        if (v == mx) {
            s.insert(k);
        }
    }

    cnt.clear();
    for (auto& x: a) {
        cnt[x.first] += x.second;
        if (cnt[x.first] >= mx && s.count(x.first)) {
            cout << x.first << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}