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

vector<int> sacos;

bool eat(int time, int t, int c){

    int p = time * t;
    int qpc = 0;
    for (int i = 0; i < sacos.size(); i++)
    {
        if (qpc + sacos[i] > p)
        {
            qpc = 0;
            c--;
        }
        qpc += sacos[i];

        if (c == 0 || sacos[i] > p)
            return false;
    }
    return true;
}

int bsearch(int t, int c){

    int l = 1, r = INF;
    while(l <= r)
    {
        int mid = (r + l) / 2;
        if (eat(mid, t, c))
            r = mid - 1;
        else 
            l = mid + 1;
    }
    return l; 
}

int main(){ _

    int n, c, t; 
    cin >> n >> c >> t;
    for (int i = 0; i < n; i++)
    {
        int p; cin >> p;
        sacos.pb(p);
    }
    int a = bsearch(t, c);
    cout << a << endl;
}
