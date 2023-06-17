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

void solve()
{

   

   
    int n, x;
    cin >> n >> x;

    int z;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> z;

        if ((z & x) == x)
        {

            nums.push_back(z);
        }
    }
    int count=x;
    for(int i=0;i<nums.size();i++){
         count=(count&nums[i]);
    }
    if(count==x&&nums.size()>1){
        cout<<"Yes"<<endl;
        
    }else{
        cout<<"NO";
    }
    return;
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

