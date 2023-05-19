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

void solve(int x){

    vector<pair<int, int>> v(x);
    for (int i = 0; i < x; i++)
    {
        int a, b; cin >> a >> b;
        v[i].f = a;
        v[i].s = b;
    }

    bool isq = true;
    queue<int> q;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].f == 1) q.push(v[i].s);
        else
        {
            if (q.empty() || v[i].s != q.front())
            {
                isq = false;
                break;
            }
            q.pop();
        }
    }

    bool iss = true;
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].f == 1) s.push(v[i].s);
        else
        {
            if (s.empty() || v[i].s != s.top())
            {
                iss = false;
                break;
            }
            s.pop();
        }
    }

    bool isp = true;
    vector<int> p;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].f == 1)
        {
            p.push_back(v[i].s);
            sort(p.begin(), p.end());
        }
        else
        {
            if (p.empty() || v[i].s != p.back())
            {
                isp = false;
                break;
            }
            p.pop_back();
        }
    }

    if (iss && !isq && !isp)
        cout << "stack" << endl;
    else if (!iss && isq && !isp)
        cout << "queue" << endl;
    else if (!iss && !isq && isp)
        cout << "priority queue" << endl;
    else if (!iss && !isq && !isp)
        cout << "impossible" << endl;
    else 
        cout << "not sure" << endl;
}

int main(){ _

    int x;
    while(cin >> x)
        solve(x);
}
