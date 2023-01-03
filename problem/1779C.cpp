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
    vector<ll> a(n); in(a);

    int ans = 0;
    
    priority_queue<int, vi> q1;
    ll pre = 0;
    repd(i, m - 1, 0) {
        if (a[i] > 0) q1.push(a[i]);
        pre += a[i];
        if (pre > 0) {
            pre -= 2ll * q1.top();
            q1.pop();
            ans++;
        }
    }

    priority_queue<int, vi> q2;
    ll suf = 0;
    repa(i, m, n) {
        if (a[i] < 0) q2.push(-a[i]);
        suf += a[i];
        if (suf < 0) {
            suf += 2ll * q2.top();
            q2.pop();
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}