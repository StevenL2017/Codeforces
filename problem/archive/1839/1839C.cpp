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

    vi b;
    for (int i = n - 1, j = n - 1; i >= 0; ) {
        while (j >= 0 && a[j] == 0) {
            j--;
        }
        int zero = i - j;
        i = j;
        while (j >= 0 && a[j] == 1) {
            j--;
        }
        int one = i - j;
        if (zero == 0 && one > 0) {
            cout << "NO\n";
            return;
        }
        i = j;

        for (int k = 0; k < zero - 1; k++) {
            b.push_back(0);
        }
        for (int k = 0; k < one; k++) {
            b.push_back(0);
        }
        if (one) {
            b.push_back(one);
        } else {
            b.push_back(0);
        }
    }
    
    cout << "YES\n";
    out(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}