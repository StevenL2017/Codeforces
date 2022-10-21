#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    int start = 0;
    ll pre = 0;
    rep(i, n - 1) {
        pre += a[idx[i]];
        if (pre < a[idx[i + 1]]) {
            start = i + 1;
        }
    }

    vi ans;
    repA(i, start, n) {
        ans.push_back(idx[i] + 1);
    }
    sortA(ans);
    
    cout << ans.size() << endl;
    for (auto& x: ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}