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
    int k; cin >> k;
    string s; cin >> s;
    reverse(s.begin(), s.end());

    int n = 1 << k;
    vi cnt(2 * n, 1);
    auto update = [&](int i) {
        return cnt[i] = (s[i] != '0' ? cnt[i * 2 + 1] : 0) + (s[i] != '1' ? cnt[i * 2 + 2] : 0);
    };
    
    repD(i, n - 2, -1) {
        update(i);
    }

    int q; cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;

        p = n - p - 1;
        s[p] = c;
        while (p) {
            update(p);
            p = (p - 1) / 2;
        }
        cout << update(0) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}