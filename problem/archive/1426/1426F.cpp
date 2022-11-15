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
    string s; cin >> s;

    // count of a, ab, abc with i elements
    vector<vector<ll>> f(n + 1, vector<ll>(3, 0));
    ll k = 1;
    rep(i, n) {
        if (s[i] == 'a') {
            f[i + 1][0] = f[i][0] + k;
            f[i + 1][1] = f[i][1];
            f[i + 1][2] = f[i][2];
        }
        else if (s[i] == 'b') {
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = f[i][1] + f[i][0];
            f[i + 1][2] = f[i][2];
        }
        else if (s[i] == 'c') {
            f[i + 1][0] = f[i][0];
            f[i + 1][1] = f[i][1];
            f[i + 1][2] = f[i][2] + f[i][1];
        }
        else {
            f[i + 1][0] = f[i][0] * 3 + k;
            f[i + 1][1] = f[i][1] * 3 + f[i][0];
            f[i + 1][2] = f[i][2] * 3 + f[i][1];
            k *= 3;
            k %= MOD;
        }
        f[i + 1][0] %= MOD;
        f[i + 1][1] %= MOD;
        f[i + 1][2] %= MOD;
    }

    cout << f[n][2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}