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
    vi a(n); in(a);

    int tot = 0;
    rep(i, n) tot += a[i];
    if (tot % n != 0) {
        cout << -1 << endl;
        return;
    }
    int target = tot / n;

    vector<vi> ans;
    repa(i, 1, n) {
        if (a[i] % (i + 1) == 0) {
            int x = a[i] / (i + 1);
            vi temp = {i + 1, 1, x};
            ans.push_back(temp);
        } else {
            int x = i + 1 - (a[i] % (i + 1));
            vi temp = {1, i + 1, x};
            ans.push_back(temp);
            temp = {i + 1, 1, (a[i] + x) / (i + 1)};
            ans.push_back(temp);
        }
    }
    repa(i, 1, n) {
        vi temp = {1, i + 1, target};
        ans.push_back(temp);
    }

    cout << ssz(ans) << endl;
    rep(i, ssz(ans)) out(ans[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}