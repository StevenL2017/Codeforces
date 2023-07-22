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

    if (n < 3) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    vi ans(n);
    ans[0] = 3;
    ans[n / 2] = 1;
    ans[n - 1] = 2;
    int j = 4;
    for (int i = n / 2 - 1; i > 0; i--) {
        ans[i] = j++;
    }
    for (int i = n / 2 + 1; i < n - 1; i++) {
        ans[i] = j++;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}