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

void solve(int m){


    int maior = 0;
    vector<char> subs;
    map<char, int> diffs;
    string str;

    while (str.empty())
        getline(cin, str);

    int counter = 0;
    for (auto const &c : str)
    {
        subs.pb(c);
        diffs[c]++;

        if (diffs[c] == 1)
            counter++;

        if (counter > m)
        {
            while(true)
            {
                int cfront = subs.front();
                subs.erase(subs.begin());
                diffs[cfront]--;
                if (diffs[cfront] == 0)
                {
                    counter--;
                    break;
                }
            }
        } 

        maior = max(maior, (int)subs.size());
    }
    cout << maior << endl;
}

int main(){ _

    int m;
    while (cin >> m)
    {
        if (m == 0)
            break;
        solve(m);
    }
    return 0;
}