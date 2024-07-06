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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    int tot = 0;
    vi b;
    for (auto x : a) {
        int tail = 0;
        while (x % 10 == 0) {
            tail++;
            x /= 10;
        }
        b.push_back(tail);
        tot += tail;
        while (x) {
            tot++;
            x /= 10;
        }
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < ssz(b); i += 2) {
        tot -= b[i];
    }

    cout << (tot <= m ? "Anna" : "Sasha") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}