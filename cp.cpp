#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define REP(i, a, b) for (long long int i = a; i < b; i++)
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define vb vector<bool>
#define vs vector<string>
#define ll long long int
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define ld long double
#define ull unsigned long long int
#define mod 1e9 + 7

// #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//     #endif

//----------------------------- # --- MAIN CODE --- # -----------------------------//


#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    int lastd = 0;
    int digit = 0;
    int c = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        x = (int)log2(v[i]) + 1;
        if (x > digit)
        {
            c = 1;
            lastd = digit;
            digit = x;
        }
        else if (x == digit)
        {
            c++;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    if(c==1){
        cout<<c<<endl;
    }
    else if (c == n || (digit > (lastd + 1)))
    {
        int rem = c % 2;
        cout << (c / 2) + rem<<endl;
    }
    else
    {
        cout << c << endl;
    }
}

int main()
{

    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}



