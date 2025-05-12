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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

const int N = 1001;
const int K = 1001;

int f[N][K][2];

int dfs(int i, int j, int d, int n) {
    if (j == 1 || i < 1 || i > n) {
        return 1;
    }
    if (f[i][j][d] != -1) {
        return f[i][j][d];
    }
    int ans = dfs(i + d, j, d, n);
    ans = add(ans, dfs(i - d, j - 1, -d, n));
    f[i][j][d] = ans;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    memset(f, -1, sizeof(f));
    cout << dfs(1, k, 1, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}