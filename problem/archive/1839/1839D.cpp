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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    a.insert(a.begin(), 0);
    a.push_back(n + 1);
    vector<vi> f(n + 2, vi(n + 2, -1));
    f[0][0] = 0;
    for (int i = 1; i < n + 2; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) continue;
            for (int k = 0; k < n + 2; k++) {
                if (f[j][k] == -1) continue;
                f[i][k + (i - j > 1)] = max(f[i][k + (i - j > 1)], f[j][k] + 1);
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        f[n + 1][j] = max(f[n + 1][j], f[n + 1][j - 1]);
        cout << n + 1 - f[n + 1][j] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}