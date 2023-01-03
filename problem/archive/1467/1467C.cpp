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

ll calc(vi a1, vi a2, vi a3) {
    ll mn1 = *min_element(a1.begin(), a1.end());
    ll mn2 = *min_element(a2.begin(), a2.end());
    ll mn3 = *min_element(a3.begin(), a3.end());
    ll s1 = 0, s2 = 0, s3 = 0;
    for (auto& x: a1) s1 += x;
    for (auto& x: a2) s2 += x;
    for (auto& x: a3) s3 += x;
    return max({s1 + s2 + s3 - 2ll * (mn2 + mn3), s1 + s2 - s3, s1 + s3 - s2});
}

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vi a1(n1), a2(n2), a3(n3);
    in(a1); in(a2); in(a3);

    ll ans = LLONG_MIN;
    ans = max(ans, calc(a1, a2, a3));
    ans = max(ans, calc(a2, a1, a3));
    ans = max(ans, calc(a3, a1, a2));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}