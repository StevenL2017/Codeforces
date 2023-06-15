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

const int N = 30001;

int n, d, a[N], f[N][500];

int dfs(int i, int j) {
    if (i >= N) return 0;
    int nj = j - (d - 250);
    if (f[i][nj] != -1) return f[i][nj];
    int ans = 0;
    if (j == 1) {
        ans = max(ans, a[i] + max(dfs(i + j, j), dfs(i + j + 1, j + 1)));
    } else {
        ans = max(ans, a[i] + max({dfs(i + j, j), dfs(i + j + 1, j + 1), dfs(i + j - 1, j - 1)}));
    }
    f[i][nj] = ans;
    return ans;
}

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }

    memset(f, -1, sizeof(f));
    cout << dfs(d, d) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}