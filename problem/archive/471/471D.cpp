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

vector<int> get_fail(vi& s) {
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

int kmp(vi& query, vi& pattern) {
    int ans = 0;
    int n = query.size(), m = pattern.size();
    auto fail = get_fail(pattern);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != query[i]) {
            j = fail[j];
        }
        if (pattern[j] == query[i]) {
            j++;
            if (j == m) {
                ans++;
                j = fail[j];
            }
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    in(a); in(b);

    if (m == 1) {
        cout << n << endl;
        return;
    }

    vi da;
    for (int i = 1; i < n; i++) {
        da.push_back(a[i] - a[i - 1]);
    }
    vi db;
    for (int i = 1; i < m; i++) {
        db.push_back(b[i] - b[i - 1]);
    }

    cout << kmp(da, db) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}