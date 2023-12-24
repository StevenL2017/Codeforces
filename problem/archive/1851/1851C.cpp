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
    int n, k;
    cin >> n >> k;
    vi a(n); in(a);

    int left = n, right = -1;
    int cntl = 0, cntr = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) {
            cntl++;
            if (cntl == k) {
                left = i;
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == a[n - 1]) {
            cntr++;
            if (cntr == k) {
                right = i;
                break;
            }
        }
    }

    if (a.front() == a.back()) {
        if (cntl == k) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    if (left < right) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}