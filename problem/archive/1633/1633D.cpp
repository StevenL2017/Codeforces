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
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 1;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

vi d(MAXN, MAXN);

void calc() {
    d[1] = 0;
    for (int i = 1; i < MAXN; i++) {
        for (int x = 1; x <= i; x++) {
            int j = i + i / x;
            if (j < MAXN) d[j] = min(d[j], d[i] + 1);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);
    int s = 0;
    for (auto& x: b) {
        cin >> x;
        s += d[x];
    }
    for (auto& x: c) cin >> x;
    
    k = min(k, s);
    vll f(k + 1, 0);
    rep(i, n) {
        repD(j, k, -1) {
            if (j - d[b[i]] >= 0) {
                f[j] = max(f[j], f[j - d[b[i]]] + c[i]);
            }
        }
    }
    cout << f[k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}