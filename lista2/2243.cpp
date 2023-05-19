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

vector<int> muro(50000);
int n, ans = 0; 

bool solve(int mid){
    
    for (int i = 0; i < n; i++)
    {
        if (muro[i] < mid)
            continue;
        int l = i - 1, r = i + 1, tmp = mid;
        while (true)
        {
            tmp--;
            if (tmp < 1)
                return true;

            if (l < 0 || r >= n) 
                break;
            if (muro[l] < tmp || muro[r] < tmp) 
                break;
            l--; r++;
        }
    }
    return false;
}

int main(){ _
    
    cin >> n;
    
    int maior = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> muro[i];
        maior = max(maior, muro[i]);
    }

    int l = 0, r = maior;
    while (l <= r)
    {
        int mid = (r + l)/2;
        if (solve(mid))
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
