// #include <bits/stdc++.h>

// using namespace std;

// #define fastio()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define rep(i, a, b) for (long long int i = a; i < b; i++)
// #define MOD 1000000007
// #define pb push_back
// #define ff first
// #define ss second
// #define vb vector<bool>
// #define vs vector<string>
// #define ll long long int
// #define vll vector<ll>
// #define pll pair<ll, ll>
// #define vpll vector<pll>
// #define ld long double
// #define ull unsigned long long int
// #define mod 1e9 + 7
// const int m = mod;
// // #ifndef ONLINE_JUDGE
// //        freopen("input.txt","r",stdin);
// //        freopen("output.txt","w",stdout);
// //     #endif

// //----------------------------- # --- MAIN CODE --- # -----------------------------//

// // User function Template for C++
// const int n = 1e5 + 10;
// int fact[n];

// class Solution
// {

// public:
//     static int flag;
//     int bestNumbers(int N, int A, int B, int C, int D)
//     {
//         int len = N;

//         int ansC = 0;

//         if (flag == 0)
//         {
//             countFact();
//             flag++;
//         }
//         for (int i = 0; i <= len / 2; i++)
//         {
//             bool ansflag1 = false;
//             bool ansflag2 = false;
//             int c1 = (i * A) + ((len - i) * B);
//             int c2 = (i * B) + ((len - i) * A);
         
//             while (c1 >= 1)
//             {
//                 if (c1 % 10 == C || c1 % 10 == D)
//                 {
//                     ansflag1 = true;
//                     break;
//                 }
//                 c1 = c1 / 10;
//             }
//             if (c1 != c2)
//             {
//                 while (c2 >= 1)
//                 {
//                     if (c2 % 10 == C || c2 % 10 == D)
//                     {
//                         ansflag2 = true;
//                         break;
//                     }
//                     c2 = c2 / 10;
//                 }
//             }

//             if (ansflag1)
//             {
//                 int c3 = fact[len];
//                 int c4 = (fact[i] * 1LL * fact[N - i]) % m;
//                 int ans;

//                 ans = (c3 * binexp(c4, m - 2, m)) % m;

//                 ansC += ans;
//             }
//             if (ansflag2)
//             {
//                 int c3 = fact[len];
//                 int c4 = (fact[i] * 1LL * fact[N - i]) % m;
//                 int ans;

//                 ans = (c3*1LL*binexp(c4,m-2,m))%m;
                
//                 ansC += ans;
//             }
//         }

//         return ansC % m;
//     }
//     void countFact()
//     {
//         fact[0] = 1;
//         for (int i = 1; i < n; ++i)
//         {
//             fact[i] = (fact[i - 1] * 1LL * i) % m;
//         }
//     }

//     int binexp(int a, int b, int m)
//     {
//         int result = 1;
//         while (b > 0)
//         {
//             if (b & 1)
//             {
//                 result = (result * 1LL * a) % m;
//             }
//             a = (a * 1LL * a) % m;
//             b >>= 1;
//         }
      

//         return result;
//     }
// };

// int Solution::flag = 0;

// int main()
// {

//     fastio();
//     ll t;

//     Solution obj;
//     cout << obj.bestNumbers(4, 6, 7, 5, 3);
//     return 0;
// }




#define ll long long
const int N = 1e5+5;
const int M = 1e9+7;
ll binpow(ll a,ll b,ll p){
    if(b==0)return 1;
    ll t=binpow(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
 
ll fact[N],invfact[N];
void init(){
    fact[0]=1;
    for(ll i=1;i<N;i++){fact[i]=i*fact[i-1]%M;}
    invfact[N-1]=binpow(fact[N-1],M-2,M);
    for(ll i=N-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1]%M;
    }
}
ll ncr(ll n,ll r,ll p){
    return (((fact[n]*invfact[n-r])%p)*invfact[r])%p;
}
bool f = 0;

class Solution {
  public:
    int bestNumbers(int n, int a, int b, int c, int d) {
        // code here
        if(f==0)
        {
            f = 1;
            init();
        }
        ll ans = 0;
        if(a==b){
            ll sum=n*a;
            while(sum>0){
                if(sum%10==c || sum%10==d){
                    return 1;
                }
                sum/=10;
            }
            return 0;
        }else{
            for(int i=0; i<=n; i++)
            {
                int sum = i*a+(n-i)*b;
                bool good = false;
                while(sum>0)
                {
                    if(sum%10==c || sum%10==d)
                    {
                        good = true;
                        break;
                    }
                    sum /= 10;
                }
                if(good)
                {
                    ans += ncr(n,i,M);
                    ans %= M;
                }
            }
            return ans;
        }
    }
};