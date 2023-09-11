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

int query(int x) {
    cout << x << endl;
    cout.flush();
    int y; cin >> y;
    return y;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    sort(a.begin(), a.end());
    if (a.front() == 0) {
        int i = 0;
        while (i < n && i == a[i]) {
            i++;
        }
        int j = query(i);
        while (j >= 0) {
            j = query(j);
        }
    } else {
        query(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}