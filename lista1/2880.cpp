#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define dbg(x) cout << #x << " = " << x << endl
#define FOR(i, a, n) for(int i = a; i < n; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    string m, c; cin >> m >> c;
    int co = 0;
    for (int i = 0; i < m.size() - c.size() + 1; i++)
    {
        bool p = true;
        for (int j = 0; j < c.size(); j++)
        {
            if (m[i + j] == c[j])
            {
                p = false;
                break;
            }
        }
        if (p)
            co++;
    }
    cout << co << endl;
}
