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
    vector<vi> a(n);
    rep(i, n) {
        int c; cin >> c;
        a[i].resize(c);
        in(a[i]);
    }
    int m; cin >> m;
    set<vi> s;
    rep(i, m) {
        vi b(n); in(b);
        s.insert(b);
    }

    vi mx(n);
    rep(i, n) {
        mx[i] = ssz(a[i]);
    }
    if (!s.count(mx)) {
        out(mx);
        return;
    }

    int tot = 0;
    vi ans;
    for (auto& v: s) {
        int cur = 0;
        vi temp = v;
        rep(i, n) {
            cur += a[i][temp[i] - 1];
        }
        rep(i, n) {
            if (temp[i] > 1) {
                temp[i]--;
                if (!s.count(temp) && cur - a[i][temp[i]] + a[i][temp[i] - 1] > tot) {
                    tot = cur - a[i][temp[i]] + a[i][temp[i] - 1];
                    ans = temp;
                }
                temp[i]++;
            }
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}