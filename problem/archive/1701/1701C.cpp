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
    int n, m; cin >> n >> m;
    vi a(m); in(a);

    vi cnt(n, 0);
    rep(i, m) {
        cnt[a[i] - 1]++;
    }

    priority_queue<pair<int, int>> q1, q2;
    rep(i, n) {
        q1.emplace(cnt[i], i);
        q2.emplace(-cnt[i], i);
    }
    while (true) {
        auto [c1, i] = q1.top();
        auto [c2, j] = q2.top();
        c2 = -c2;
        if (i == j || c1 - 1 < c2 + 2) {
            break;
        }
        q1.pop();
        q2.pop();
        q1.emplace(c1 - 1, i);
        q2.emplace(-(c2 + 2), j);
    }

    cout << q1.top().first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}