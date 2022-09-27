#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.begin(), v.end(), greater<auto>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

int main() {
    int n;
    cin >> n;
    int maxv;
    map<int, int> cnt;
    rep(i, n) {
        int num;
        cin >> num;
        maxv = max(maxv, num);
        cnt[num]++;
    }

    vll f(maxv + 1, 0);
    f[1] = (cnt.find(1) != cnt.end()) ? 1LL * cnt[1] : 0LL;
    repA(i, 2, maxv + 1) {
        int v = (cnt.find(i) != cnt.end()) ? cnt[i] : 0;
        f[i] = max(f[i - 1], f[i - 2] + 1LL * i * v);
    }
    cout << f[maxv];
    return 0;
}