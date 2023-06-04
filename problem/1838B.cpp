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

    int idx1, idx2, idxn;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) idx1 = i;
        if (a[i] == 2) idx2 = i;
        if (a[i] == n) idxn = i;
    }

    if (idx1 < idx2 && idx2 < idxn || idx1 > idx2 && idx2 > idxn) {
        cout << idx2 + 1 << " " << idxn + 1 << endl;
    }
    else if (idx2 < idx1 && idx1 < idxn || idx2 > idx1 && idx1 > idxn) {
        cout << idx1 + 1 << " " << idxn + 1 << endl;
    }
    else {
        cout << idxn + 1 << " " << idxn + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}