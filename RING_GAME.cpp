#include <bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define mod 1e9+7


// #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//     #endif 


//----------------------------- # --- MAIN CODE --- # -----------------------------//


void leftCyclicShift(int a[],ll s,ll f)
{
    int initial = a[s];
    REP(i,s,f)
    {
        a[i]=a[i+1];
    }
    a[f]=initial;
    return;
}
void solve() 
{
 ll n;
 int player=0;
 cin>>n;
 int a[n];
 REP(i,0,n)
 {
     cin>>a[i];
 }
 
 
 int flag=0,s,f,lastVal,contSameVal=0;
 REP(i,0,n)
 {
     if(a[i]==a[i+1]&&flag==0)
     {
         lastVal=a[i];
         s=i;
         flag=1;
     }
    //  if(a[i]==a[i+1]&&flag==1)
    //  {
    //     contSameVal++;
         
    //  }
     if(a[i]!=a[i+1]&&flag==1)
     {  
         if(i<n-1)
         {
             if(a[i+1]==a[i+2])
         {
             f=i+1;
        if(player==0)
        player=1;
        else
        player=0;
        leftCyclicShift(a,s,f);
        flag=0;
        i=s;
         }
         }
         if(i=n-1)
         {
              if(a[n-1]==a[0])
         {
             f=n-1;
        if(player==0)
        player=1;
        else
        player=0;
        leftCyclicShift(a,s,f);
        flag=0;
        i=s;
         }
         }
       
     }
     
 }
 
 if(player==0)
 cout<<"\n Bob";
 else
 cout<<"\n Alice";

}


int main()
{

    fastio();
    ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
} 