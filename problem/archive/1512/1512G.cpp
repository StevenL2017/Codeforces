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

const int N = 1e7 + 1;

int tot[N], d[N];

void calc() {
    fill(tot, tot + N, 1);
    for (int x = 2; x < N; x++) {
        for (int y = x; y < N; y += x) {
            tot[y] += x;
        }
    }
    for (int x = N; x > 0; x--) {
        if (tot[x] >= N) continue;
        d[tot[x]] = x;
    }
}

void solve() {
    int c;
    cin >> c;

    cout << (d[c] == 0 ? -1 : d[c]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}