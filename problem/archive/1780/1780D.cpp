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

int query(int x) {
    cout << "- " << x << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int cnt; cin >> cnt;

    int n = 0, i = 0;
    while (cnt > 0) {
        int x = 1 << i;
        int cur = query(x);
        int d = cur - cnt;
        if (d < 0) {
            n |= 1 << i;
            i++;
        } else {
            n |= 1 << (i + d + 1);
            repa(j, i + 1, i + d + 1) {
                x |= 1 << j;
            }
            cur = query(x);
            i += d + 2;
        }
        cnt = cur;
    }

    cout << "! " << n << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}