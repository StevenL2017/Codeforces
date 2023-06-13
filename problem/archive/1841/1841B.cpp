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

    bool dec = false;
    int pre = a[0];
    cout << '1';
    for (int i = 1; i < n; i++) {
        if (!dec) {
            if (a[i] >= pre) {
                cout << '1';
                pre = a[i];
            } else {
                if (a[i] <= a[0]) {
                    cout << '1';
                    pre = a[i];
                    dec = true;
                } else {
                    cout << '0';
                }
            }
        } else {
            if (a[i] >= pre && a[i] <= a[0]) {
                cout << '1';
                pre = a[i];
            } else {
                cout << '0';
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