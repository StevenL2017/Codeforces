#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    in(a); in(b);

    ll tot = 0;
    rep(i, n) {
        tot += a[i];
    }
    if (tot < m) {
        cout << -1 << endl;
        return;
    }

    vi one, two;
    rep(i, n) {
        if (b[i] == 1) one.push_back(a[i]);
        else two.push_back(a[i]);
    }
    sortd(one); sortd(two);
    
    ll s1 = 0;
    ll s2 = accumulate(two.begin(), two.end(), 0ll);
    int ans = INF, i = 0, j = ssz(two);
    while (i <= ssz(one)) {
        while (j - 1 >= 0 && s1 + s2 - two[j - 1] >= m) {
            s2 -= two[j - 1];
            j--;
        }
        if (s1 + s2 >= m) ans = min(ans, i + j * 2);
        if (i == ssz(one)) break;
        s1 += one[i];
        i++;
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