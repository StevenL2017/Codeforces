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
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    string s;
    if (n0 > 0) rep(i, n0 + 1) s += '0';
    if (n2 > 0) rep(i, n2 + 1) s += '1';
    if (n0 > 0 && n2 > 0) {
        int x = 1;
        rep(i, n1 - 1) {
            if (x & 1) s += '0';
            else s += '1';
            x ^= 1;
        }
    }
    else if (n0 > 0) {
        int x = 1;
        rep(i, n1) {
            if (x & 1) s += '1';
            else s += '0';
            x ^= 1;
        }
    }
    else if (n2 > 0) {
        int x = 1;
        rep(i, n1) {
            if (x & 1) s += '0';
            else s += '1';
            x ^= 1;
        }
    }
    else {
        int x = 1;
        rep(i, n1 + 1) {
            if (x & 1) s += '0';
            else s += '1';
            x ^= 1;
        }
    }

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}