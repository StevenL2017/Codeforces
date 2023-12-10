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

    int mx = 0;
    vi ans;
    for (int i = 0; i < n; ) {
        int l = i, r = i;
        while (l && a[l - 1] % a[i] == 0) l--;
        while (r < n - 1 && a[r + 1] % a[i] == 0) r++;
        if (r - l > mx) {
            mx = r - l;
            ans.clear();
            ans.push_back(l + 1);
        } else if (r - l == mx) {
            ans.push_back(l + 1);
        }
        i = r + 1;
    }

    cout << ssz(ans) << " " << mx << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}