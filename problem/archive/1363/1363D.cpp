#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

int interact(vi q) {
    cout << "? " << ssz(q) << " ";
    out(q);
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<set<int>> idx(k);
    rep(i, k) {
        int c; cin >> c;
        rep(j, c) {
            int x; cin >> x;
            idx[i].insert(x);
        }
    }
 
    int l = 1, r = n;
    int pl = l, pr = r;
    int mx = 0, mxi = 0;
    while (l <= r) {
        vi q(r - l + 1);
        iota(q.begin(), q.end(), l);
        auto res = interact(q);
        if (l == r) {
            if (mx == res) mxi = l;
            else mxi = pr;
            break;
        }
 
        int mid = l + (r - l) / 2;
        if (mx == 0) {
            mx = res;
        } else {
            if (mx == res) {
                pr = r;
            } else {
                l = pl = pl + (pr - pl) / 2 + 1;
                mid = pl + (pr - pl) / 2;
            }
        }
        r = mid;
    }
 
    vi ans(k, mx);
    rep(i, k) {
        if (!idx[i].count(mxi)) continue;
        vi q;
        repa(j, 1, n + 1) {
            if (!idx[i].count(j)) {
                q.push_back(j);
            }
        }
        ans[i] = interact(q);
    }
 
    cout << "! ";
    out(ans);
    cout.flush();
    string res; cin >> res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}