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

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

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
    vector<string> s(n);
    vector<set<string>> h(n);
    rep(i, n) {
        cin >> s[i];
        rep(j, m) {
            char origin = s[i][j];
            for (char c = 'a'; c <= 'z'; c++) {
                s[i][j] = c;
                h[i].insert(s[i]);
            }
            s[i][j] = origin;
        }
    }

    rep(i, n) {
        for (auto& x: h[i]) {
            int cnt = 0;
            rep(j, n) {
                if (h[j].count(x)) cnt++;
            }
            if (cnt == n) {
                cout << x << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}