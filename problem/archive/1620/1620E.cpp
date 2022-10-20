#include <iostream>
#include <cstdio>
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
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int q;
    cin >> q;
    vector<vi> query(q);
    map<int, int> mp;
    int k = 0;
    rep(i, q) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            query[i].push_back(x);
            mp[x] = x;
            k++;
        } else {
            int x, y; cin >> x >> y;
            query[i].push_back(x);
            query[i].push_back(y);
            mp[y] = y;
        }
    }

    vi ans(k);
    int j = k - 1;
    repD(i, q - 1, -1) {
        if (query[i].size() == 1) {
            int x = query[i][0];
            ans[j] = mp[x];
            j--;
        } else {
            int x = query[i][0];
            int y = query[i][1];
            mp[x] = mp[y];
        }
    }

    rep(i, k) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}