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

    if (n & 1) {
        int win = (n - 1) / 2;
        for (int i = 0; i < n - 1; i++) {
            int cnt = n - 1 - i;
            for (int j = 0; j < cnt; j++) {
                if (j < win) cout << 1 << " ";
                else cout << -1 << " ";
            }
        }
    } else {
        int win = (n - 2) / 2;
        for (int i = 0; i < n - 1; i++) {
            int cnt = n - 1 - i;
            for (int j = 0; j < cnt; j++) {
                if (j < win) cout << 1 << " ";
                else if (j == win) cout << 0 << " ";
                else cout << -1 << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}