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
    string s; cin >> s;
    int m; cin >> m;
    vi b(m); in(b);

    vi cnt(26, 0);
    for (auto& c: s) cnt[c - 'a']++;

    string t(m, '.');
    int j = 25;
    set<int> idx;
    rep(i, m) {
        if (!b[i]) idx.insert(i);
    }
    while (!idx.empty()) {
        while (j >= 0 && cnt[j] < ssz(idx)) j--;
        for (auto& i: idx) {
            t[i] = 'a' + j;
        }
        j--;
        idx.clear();
        rep(i, m) {
            if (t[i] != '.') continue;
            int c = 0;
            rep(i0, m) {
                if (t[i0] != '.') c += abs(i - i0);
            }
            if (b[i] == c) {
                idx.insert(i);
            }
        }
    }

    cout << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}