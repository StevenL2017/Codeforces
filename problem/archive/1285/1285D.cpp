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

    function<int(int, vi&)> dfs = [&] (int i, vi& a) -> int {
        if (i < 0) return 0;

        int cnt = 0;
        for (auto& x: a) {
            if (x >> i & 1) cnt++;
        }

        if (cnt > 0 && cnt < ssz(a)) {
            vi b, c;
            for (auto& x: a) {
                if (x >> i & 1) b.push_back(x);
                else c.push_back(x);
            }
            return (1 << i) | min(dfs(i - 1, b), dfs(i - 1, c));
        } else {
            return dfs(i - 1, a);
        }
    };
    cout << dfs(31, a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}