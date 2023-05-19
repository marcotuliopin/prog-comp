#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int v, e; cin >> v >> e;
    vector<vector<int>> m(26, vector<int>(26, 0));
    for (int i = 0; i < e; i++)
    {
        char a, b; cin >> a >> b;
        m[a - 97][b - 97] = 1;
        m[b - 97][a - 97] = 1;
    }
    vector<int> visitado(26, 0); 
    int c = 0;
    for (int i = 0; i < v; i++)
    {
        if (visitado[i] == 0)
        {
            visitado[i] = 1;
            vector<int> vct = {i + 97};
            stack<int> q;
            q.push(i);
            while(!q.empty())
            {
                int p = q.top();
                q.pop();
                for (int j = 0; j < v; j++)
                {
                    if (m[p][j] == 1 && visitado[j] == 0)
                    {
                        visitado[j] = 1;
                        q.push(j);
                        vct.pb(j + 97);
                    }
                }
            }
            sort(vct.begin(), vct.end());
            for (int i = 0; i < vct.size(); i++)
                cout << (char) vct[i] << ",";
            cout << endl;
            c++;
        }
    }
    cout << c << " connected components" << endl;
    cout << endl;
}

int main(){ 
    int x; cin >> x;
    int i = 1;
    while (x--)
    {
        cout << "Case #" << i << ":" << endl;
        solve();
        i++;
    }
}
