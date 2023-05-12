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

    sort(a.begin(), a.end());
    int mul = 0;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && a[j] == a[i]) {
            j++;
        }
        if (j - i > 2) {
            cout << "cslnb\n";
            return;
        }
        else if (j - i == 2) {
            mul++;
            if (mul > 1 || (i == 0 && a[i] == 0) || (i > 0 && a[i - 1] + 1 == a[i])) {
                cout << "cslnb\n";
                return;
            }
        }
        i = j;
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] - i;
    }

    if (cnt & 1) cout << "sjfnb\n";
    else cout << "cslnb\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}