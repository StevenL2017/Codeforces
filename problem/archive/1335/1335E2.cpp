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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<vi> pre(201, vi(n + 1, 0)), pos(201);
    rep(i, n) {
        repa(j, 1, 201) pre[j][i + 1] = pre[j][i];
        pre[a[i]][i + 1]++;
        pos[a[i]].push_back(i);
    }

    int ans = 0;
    repa(j, 1, 201) {
        ans = max(ans, ssz(pos[j]));
        int left = 0, right = ssz(pos[j]) - 1;
        while (left < right) {
            int l = pos[j][left] + 1, r = pos[j][right] - 1;
            repa(k, 1, 201) {
                int mid = pre[k][r + 1] - pre[k][l];
                ans = max(ans, (left + 1) * 2 + mid);
            }
            left++; right--;
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