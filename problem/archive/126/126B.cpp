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

vector<int> get_fail(string s) {
    int n = s.size();
    vector<int> fail(n + 1, -1);
    for (int i = 1, j = -1; i <= n; i++) {
        while (j >= 0 && s[j] != s[i - 1]) {
            j = fail[j];
        }
        fail[i] = ++j;
    }
    return fail;
}

void solve() {
    string s; cin >> s;

    auto f = get_fail(s);
    if (f.back() <= 0) {
        cout << "Just a legend" << endl;
        return;
    }
    rep(i, ssz(f) - 1) {
        if (f[i] == f.back()) {
            cout << s.substr(0, f[i]) << endl;
            return;
        }
    }
    if (f[f.back()] > 0) {
        cout << s.substr(0, f[f.back()]) << endl;
        return;
    }

    cout << "Just a legend" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}