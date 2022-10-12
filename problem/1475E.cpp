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

const int MAXN = 1e3 + 1;
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

long long c[MAXN][MAXN];

void comb(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int, greater<int>> cnt;
    rep(i, n) {
        int x; cin >> x;
        cnt[x]++;
    }

    int last = 0;
    for (auto& [x, v]: cnt) {
        if (k >= v) {
            k -= v;
        } else {
            last = v;
            break;
        }
    }
    cout << c[last][k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    comb(MAXN);
    int t = 1;
    cin >> t;
    while (t--) solve();
}