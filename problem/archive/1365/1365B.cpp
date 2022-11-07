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
    int n; cin >> n;
    vi a(n), b(n); in(a), in(b);

    bool ok = true;
    int cnt1 = 0, cnt0 = 0;
    rep(i, n) {
        if (b[i]) cnt1++;
        else cnt0++;
    }
    int pre1 = 0, pre0 = 0;
    rep(i, n) {
        if (b[i] == 0) {
            if (a[i] >= pre0 || cnt1 > 0) {
                pre0 = a[i];
            } else {
                ok = false;
                break;
            }
        } else {
            if (a[i] >= pre1 || cnt0 > 0) {
                pre1 = a[i];
            } else {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}