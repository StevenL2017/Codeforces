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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int N = 1e6;

int cnt[N];

void calc() {
    repa(i, 1, N) {
        int x = i, c = 0;
        while (x > 0) {
            if (x % 10 != 0) {
                c++;
            }
            x /= 10;
        }
        if (c <= 1) cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = cnt[i - 1];
    }
}

void solve() {
    int n; cin >> n;
    cout << cnt[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}