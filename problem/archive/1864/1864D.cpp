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
    vector<string> a(n); in(a);

    int ans = 0;
    vector<vi> cnt(n, vi(n, 0));
    vector<vi> pre(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                pre[i][j] += cnt[i - 1][j];
                if (j > 0) pre[i][j] += pre[i - 1][j - 1];
                if (j < n - 1) pre[i][j] += pre[i - 1][j + 1];
                if (i > 1 && j > 0 && j < n - 1) pre[i][j] -= pre[i - 2][j];
            }
            
            if (a[i][j] == '1' && pre[i][j] % 2 == 0) {
                ans++;
                cnt[i][j]++;
                pre[i][j]++;
            }
            if (a[i][j] == '0' && pre[i][j] % 2 == 1) {
                ans++;
                cnt[i][j]++;
                pre[i][j]++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}