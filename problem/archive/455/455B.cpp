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

class Trie {
public:
    vector<Trie*> children;
    bool win, lose;

    Trie() : children(26) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
    }
};

void dfs(Trie* node) {
    node->win = false;
    node->lose = false;
    bool is_leaf = true;
    for (auto child : node->children) {
        if (child == nullptr) continue;
        dfs(child);
        node->win |= !child->win;
        node->lose |= !child->lose;
        is_leaf = false;
    }
    if (is_leaf) {
        node->lose = true;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    in(a);

    Trie* tree = new Trie();
    for (auto s : a) {
        tree->insert(s);
    }
    dfs(tree);

    if (tree->win && (tree->lose || (k & 1))) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}