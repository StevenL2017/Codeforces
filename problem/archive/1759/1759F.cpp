#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
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

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, p; cin >> n >> p;
    vi a(n); in(a);

    set<int> has;
    rep(i, n) {
        has.insert(a[i]);
    }
    
    int pre_mx = a.back() - 1, suf_mn = p - 1;
    while (pre_mx >= 0 && has.count(pre_mx)) pre_mx--;
    while (suf_mn >= 0 && has.count(suf_mn)) suf_mn--;

    if (pre_mx < 0 && suf_mn < 0) {
        cout << 0 << endl;
        return;
    }

    if (pre_mx < 0 && suf_mn >= 0) {
        cout << suf_mn - a.back() << endl;
        return;
    }

    int ans = p - a.back();
    has.insert(0);
    if (n == 1) has.insert(1);
    repd(i, n - 2, -1) {
        a[i]++;
        if (a[i] < p) {
            has.insert(a[i]);
            break;
        } else {
            if (i == 0) {
                has.insert(1);
            }
        }
    }

    int mx = 0;
    repd(i, pre_mx, -1) {
        if (!has.count(i)) {
            mx = i;
            break;
        }
    }
    ans += mx;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}