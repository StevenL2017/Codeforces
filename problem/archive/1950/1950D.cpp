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

const int N = 1e5;

int vis[N + 1], valid[N + 1];

bool check(int x) {
    while (x) {
        if (x % 10 != 0 && x % 10 != 1) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int dfs(int x) {
    if (vis[x]) {
        return valid[x];
    }
    if (check(x)) {
        vis[x] = valid[x] = 1;
        return valid[x];
    }
    int y = 2;
    while (y * y <= x) {
        if (x % y == 0 && dfs(y) && dfs(x / y)) {
            vis[x] = valid[x] = 1;
            return valid[x];
        }
        y++;
    }
    vis[x] = 1;
    return valid[x];
}

void solve() {
    int n; cin >> n;
    cout << (dfs(n) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}