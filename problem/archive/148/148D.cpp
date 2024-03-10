#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

map<pair<int, int>, long double> memo;

long double dfs(int x, int y) {
    if (x <= 0) return 0.0;
    if (y <= 0) return 1.0;
    if (memo.find(make_pair(x, y)) != memo.end()) {
        return memo[make_pair(x, y)];
    }

    long double ans = (long double)(x) / (long double)(x + y);
    if (y > 1)
        ans += (long double)(y) / (long double)(x + y) * (long double)(y - 1) / (long double)(x + y - 1) * ((long double)x / (long double)(x + y - 2) * dfs(x - 1, y - 2) + (long double)(y - 2) / (long double)(x + y - 2) * dfs(x, y - 3));
    memo[make_pair(x, y)] = ans;
    return ans;
}

void solve() {
    int w, b;
    cin >> w >> b;

    cout.precision(10);
    cout << dfs(w, b) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}