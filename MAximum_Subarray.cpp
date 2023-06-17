#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define rep(i, a, b) for (long long int i = a; i < b; i++)
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
    ll n, m, sumB=0;
    cin >> n ;

    // vll a(n), b(m);
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
       
        
    }
    cin>>m;
    ll b[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
         if(b[i]>0)
            sumB+=b[i];
    }

    ll sum = 0,maxF=0,maxB=0,pairsum=0;
    vll sumPair,sumFront,sumBack;
    

    rep(i, 0, n)
    { 
        if(a[i]>0)
        {
            sum+=a[i] ;
             pairsum+=a[i];
        }
           
        else if(a[i]<0){
            sumPair.pb(pairsum);
            sumFront.pb(sum);
            sum+=a[i];
            pairsum+=a[i];
            if(pairsum<0)
            pairsum=0;
            
        }


    }
    sumFront.pb(sum);
    sumPair.pb(pairsum);
         for(int i=n;i>0;i--)
    { 
        if(a[i]>0)
        sum+=a[i] ;   
        else if(a[i]<0){
           
            sumBack.pb(sum);
            sum+=a[i];
            
            
        }


    }
    sumBack.pb(sum);
    ll SumApair= *max_element(sumPair.begin(),sumPair.end());
    ll SumAfront= *max_element(sumFront.begin(),sumFront.end());
    ll SumAback= *max_element(sumBack.begin(),sumBack.end());
   vll sumss = {SumApair,SumAback+sumB,SumAfront+sumB} ;
   cout<<"\n "<<*max_element(sumss.begin(),sumss.end());
    



    // rep(i,0,n){
    //     sum=accumulate(a+i,a+n,sum);
    //     if(sum>maxF)
    //     maxF=sum
    // }
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