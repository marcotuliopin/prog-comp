#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define ii pair<int, int>
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ii>> mx(10005);
vector<bool> vis(10005, false);
vector<int> d(10005, INF);
vector<ii> loops;

void dfs(int v, int a, int q){

    if (v == q)
    {
        loops.pb({q, a - d[q]});
        return;
    }

    if (vis[v])
        return;

    vis[v] = true;
    for (int i = 0; i < mx[v].size(); i++)
    {
        dfs(mx[v][i].S, a + mx[v][i].F, q);
    }
}

void djikstra(){

}

void solve(int s, int size){

}

int main(){ 

    int s, t;
    while (cin >> s >> t)
    {
        for (int i = 0; i < t; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            mx[a].pb({c, b});
            mx[b].pb({c, a});
        }
        dfs(s, 0, 0);
        int q; cin >> q;
        for (int i = 0; i < q; i++)
        {
            int x, m; cin >> x >> m;
            solve(x, m);
        }
    }
}
