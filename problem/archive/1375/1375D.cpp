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
const ll  INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vi ans;
    while (true) {
        int idx = n;
        vector<bool> has(n + 1, false);
        rep(i, n) {
            has[a[i]] = true;
            if (a[i] == i) continue;
            idx = i;
        }
        if (idx == n) break;

        int mex = n;
        rep(i, n) {
            if (!has[i]) {
                mex = i;
                break;
            }
        }
        if (mex == n) {
            a[idx] = mex;
            ans.push_back(idx + 1);
        } else {
            a[mex] = mex;
            ans.push_back(mex + 1);
        }
    }
    
    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}