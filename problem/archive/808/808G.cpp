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
    string s, t;
    cin >> s >> t;

    auto fail = get_fail(t);
    int n = ssz(s), m = ssz(t);
    vi f(m + 1, -1);
    f[0] = 0;
    rep(i, n) {
        repd(j, m - 1, -1) {
            f[j + 1] = -1;
            if (f[j] != -1 && (s[i] == t[j] || s[i] == '?')) {
                f[j + 1] = f[j] + (j == m - 1);
            }
        }
        int j = m;
        while (j > 0) {
            auto last = fail[j];
            f[last] = max(f[last], f[j]);
            j = last;
        }
    }

    cout << *max_element(f.begin(), f.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}