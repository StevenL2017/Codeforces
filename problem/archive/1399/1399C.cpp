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
    int n; cin >> n;
    vi w(n); in(w);

    if (n < 4) {
        if (n == 1) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }

    sorta(w);
    int k = 1;
    repa(s, w[0] + w[1], w[n - 2] + w[n - 1] + 1) {
        int cnt = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            auto cur = w[i] + w[j];
            if (cur > s) {
                j--;
            }
            else if (cur < s) {
                i++;
            }
            else {
                cnt++;
                j--;
                i++;
            }
        }
        k = max(k, cnt);
    }
    cout << k << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}