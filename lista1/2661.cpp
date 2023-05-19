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

vector<ll> prime = {2};
vector<ll> fact;

void primos(ll x){
    for (ll i = 3; i * i <= x; i += 2)
    {
        if (i % 2 == 0)
            continue;
        bool isprime = true;
        for (ll j = 3; j * j <= i; j++)
        {
            if (i % j == 0) 
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
            prime.push_back(i);
    }
}

void fatora(ll x){
    for (ll i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << endl;
        if (prime[i] >= x)
        {
            fact.push_back(x);
            break;
        }
        if (x % prime[i] == 0)
        {
            while (x % prime[i] == 0)
                x /= prime[i];
            fact.push_back(prime[i]);
        }
    }
}

int main(){ 
    ll x; cin >> x;

    primos(x);
    if (prime.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    fatora(x);

    int total = pow(2, fact.size()) - 1 - fact.size();
    cout << total << endl;
}
