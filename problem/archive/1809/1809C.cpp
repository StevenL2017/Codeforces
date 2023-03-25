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
    int n, k; cin >> n >> k;

    int neg_num = n * (n + 1) / 2 - k, neg_len = n;
    rep(i, n) {
        if (i * (i + 1) / 2 >= neg_num) {
            neg_len = i;
            break;
        }
    }
    if (neg_len * (neg_len + 1) / 2 > neg_num) {
        neg_len--;
    }

    vi ans(neg_len, -10);
    int diff = neg_num - neg_len * (neg_len + 1) / 2;
    int pos_first = 10 * (neg_len - diff) + 1;
    if (neg_len < n)
        ans.push_back(pos_first);
    rep(i, max(0, n - neg_len - 1))
        ans.push_back(1000);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}