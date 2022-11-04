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
    vi a(n); in(a);

    int k = 1, idx = 0;
    map<int, int> mp;
    rep(i, n) {
        if (mp.find(a[i] - 1) == mp.end()) {
            mp[a[i]] = 1;
        } else {
            mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
        }
        if (mp[a[i]] > k) {
            k = mp[a[i]];
            idx = i;
        }
    }

    vi ans;
    int cur = a[idx];
    repd(i, idx, -1) {
        if (a[i] == cur) {
            ans.push_back(i + 1);
            cur--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << k << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}