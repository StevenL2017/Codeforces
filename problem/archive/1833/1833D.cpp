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

    int idx = 0, idx1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == n) {
            idx = i;
        }
        else if (a[i] == n - 1) {
            idx1 = i;
        }
    }
    if (!idx) idx = idx1;

    for (int i = idx; i < n; i++) {
        cout << a[i] << " ";
    }
    if (idx == n - 1 && idx - 1 >= 0 && a[0] > a[idx - 1]) {
        for (int i = 0; i < idx; i++) {
            cout << a[i] << " ";
        }
    } else {
        for (int i = idx - 1; i >= 0; i--) {
            cout << a[i] << " ";
            if (i - 1 >= 0 && a[0] > a[i - 1]) {
                for (int j = 0; j < i; j++) {
                    cout << a[j] << " ";
                }
                break;
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