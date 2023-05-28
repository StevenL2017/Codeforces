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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vi a(n); in(a);
    vi b(n); in(b);

    vi cnta(2 * n + 1, 0), cntb(2 * n + 1, 0);
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && a[j] == a[i]) {
            j++;
        }
        cnta[a[i]] = max(cnta[a[i]], j - i);
        i = j;
    }
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && b[j] == b[i]) {
            j++;
        }
        cntb[b[i]] = max(cntb[b[i]], j - i);
        i = j;
    }

    int mx = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (cnta[i] + cntb[i] > mx) {
            mx = cnta[i] + cntb[i];
        }
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}