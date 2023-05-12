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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    sort(a.begin(), a.end());
    
    if (k == 0) {
        if (a.front() == 1) cout << -1 << endl;
        else cout << 1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && a[j] == a[i]) {
            j++;
        }
        cnt += j - i;
        if (cnt == k) {
            cout << a[i] << endl;
            return;
        }
        else if (cnt > k) {
            cout << -1 << endl;
            return;
        }
        i = j;
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}