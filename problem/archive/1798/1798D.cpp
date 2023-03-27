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

    sorta(a);
    if (a.back() == 0) {
        cout << "No\n";
        return;
    }

    vi ans(n, -1), pos, neg;
    int k = 0;
    rep(i, n) {
        if (a[i] > 0) pos.push_back(a[i]);
        else if (a[i] < 0) neg.push_back(a[i]);
        else ans[k++] = a[i];
    }

    int i = 0, j = 0;
    ll pre = 0;
    while (i < ssz(pos) || j < ssz(neg)) {
        if (i < ssz(pos) && pre < 0) {
            pre += pos[i];
            ans[k++] = pos[i++];
        }
        if (j < ssz(neg) && pre >= 0) {
            pre += neg[j];
            ans[k++] = neg[j++];
        }
    }

    cout << "Yes\n";
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}