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
    vi a(n), b(n);
    in(a); in(b);

    vi diff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i]) {
            diff[b[i]]++;
            diff[a[i]]--;
        }
    }
    for (int i = 0; i < n; i++) {
        diff[i + 1] += diff[i];
    }

    vi ans;
    for (int k = 1; k <= n; k++) {
        bool ok = true;
        for (int x = k; x <= n; x += k) {
            if (diff[x]) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(k);
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