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
    int n, x; cin >> n >> x;
    string s; cin >> s;

    vi pre(n);
    if (s[0] == '0') pre[0] = 1;
    else pre[0] = -1;
    repa(i, 1, n) {
        pre[i] = pre[i - 1];
        if (s[i] == '0') pre[i]++;
        else pre[i]--;
    }

    bool has = false;
    int cnt = (x == 0 ? 1 : 0);
    rep(i, n) {
        if (pre[i] == x) {
            has = true;
        }
        if (pre.back() > 0 && x >= pre[i] && (x - pre[i]) % pre.back() == 0) {
            cnt++;
        }
        if (pre.back() < 0 && x <= pre[i] && (pre[i] - x) % abs(pre.back()) == 0) {
            cnt++;
        }
    }

    if (has && pre.back() == 0) {
        cout << -1 << endl;
        return;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}