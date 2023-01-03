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

void solve() {
    int n; cin >> n;
    vector<string> a(n); in(a);

    int k = 0;
    vi c1(3, 0), c2(3, 0);
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] == 'X') {
                k++;
                c1[(i + j) % 3]++;
            }
            else if (a[i][j] == 'O') {
                k++;
                c2[(i + j) % 3]++;
            }
        }
    }

    rep(i, 3) {
        rep(j, 3) {
            if (j == i) continue;
            if (c1[i] + c2[j] > k / 3) continue;
            rep(r, n) {
                rep(c, n) {
                    if (a[r][c] == 'X' && (r + c) % 3 == i) {
                        a[r][c] = 'O';
                    }
                    else if (a[r][c] == 'O' && (r + c) % 3 == j) {
                        a[r][c] = 'X';
                    }
                }
            }
            rep(i, n) cout << a[i] << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}