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
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            cnt[v]++;
        } else {
            cnt[u]++;
        }
    }

    set<int> d;
    rep(i, n) {
        if (cnt.find(i + 1) != cnt.end() && cnt[i + 1] > 0) {
            d.insert(i + 1);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 3) {
            cout << n - d.size() << endl;
        } else {
            int u, v;
            cin >> u >> v;
            if (u > v) {
                if (t == 1) {
                    cnt[v]++;
                    d.insert(v);
                } else {
                    cnt[v]--;
                    if (cnt[v] == 0) d.erase(v);
                }
            } else {
                if (t == 1) {
                    cnt[u]++;
                    d.insert(u);
                } else {
                    cnt[u]--;
                    if (cnt[u] == 0) d.erase(u);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}