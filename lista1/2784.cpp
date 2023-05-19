#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define ii pair<int, int>
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> mx(1010, vector<int>(1010, -1));
vector<int> d(1010, INF);

void djikstra(int b){
    
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({d[b], b});
    
    vector<bool> vis(1010, false);
    while (!q.empty())
    {
        int v = q.top().s;
        q.pop();
        if (vis[v])
            continue;
        vis[v] = true;
        for (int i = 1; i <= 1002; i++)
        {
            if (vis[i] || mx[v][i] < 0)
                continue;
            d[i] = min(d[i], d[v] + mx[v][i]);
            q.push({d[i], i});
        }
    }
}

int main(){ _
    
    int n, c; cin >> n >> c;
    for (int i = 0; i < c; i++)
    {
        int u, v, p; cin >> u >> v >> p;
        mx[u][v] =  p;
        mx[v][u] = p;
    }
    int b; cin >> b;
    d[b] = 0;
    djikstra(b);

    int M = 0, m = INF;
    for (int i = 1; i <= n; i++)
    {
        M = max(d[i], M);
        if (i != b)
            m = min(d[i], m);
    }
    cout << M - m << endl;
}
