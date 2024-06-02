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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vector<multiset<int>> s(m);
    int left = 0, mx = 0, end = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s[j].insert(a[i][j]);
        }
        int tot = 0;
        for (int j = 0; j < m; j++) {
            if (s[j].empty()) continue;
            tot += *s[j].rbegin();
        }
        while (left <= i && tot > k) {
            for (int j = 0; j < m; j++) {
                if (s[j].empty()) continue;
                tot -= *s[j].rbegin();
                s[j].erase(s[j].find(a[left][j]));
                if (s[j].empty()) continue;
                tot += *s[j].rbegin();
            }
            left++;
        }
        if (i - left + 1 > mx) {
            mx = i - left + 1;
            end = i + 1;
        }
    }

    vi cnt(m);
    for (int i = end - mx; i < end && end != -1; i++) {
        for (int j = 0; j < m; j++) {
            cnt[j] = max(cnt[j], a[i][j]);
        }
    }

    out(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}