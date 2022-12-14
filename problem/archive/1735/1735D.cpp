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
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v, T)            sort(v.begin(), v.end(), greater<T>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> c(n, vector<int>(k));
    rep(i, n) {
        rep(j, k) {
            cin >> c[i][j];
        }
    }

    vi cnt(n, 0);
    unordered_map<string, int> mp;
    rep(i, n - 1) {
        repA(j, i + 1, n) {
            string temp;
            rep(ii, k) {
                temp += (char)((c[i][ii] + c[j][ii]) % 3);
            }
            mp[temp] += 1;
        }
    }
    rep(i, n) {
        string temp;
        rep(ii, k) {
            temp += (char)((3 - c[i][ii]) % 3);
        }
        cnt[i] += mp[temp];
    }

    ll ans = 0LL;
    for (auto &x : cnt) {
        ans += (x - 1) * x / 2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}