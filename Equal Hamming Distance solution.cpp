#include<bits/stdc++.h>
 using namespace std;
using ll = long long int ; // 
#define hi cout << "test\n" ;
const int mod = 1e9 + 7  ;
#define files freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout),freopen("error.txt","w",stderr) 
#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif    
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll gcd(ll a, ll b) { return((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
void _print(auto t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//----------------------------------------------------------------------------------------------------------------------------------
#define int long long 
int out ( int a , int b ) {
   return ( ( a % mod ) * ( b % mod )) % mod ; // it's the same as ( a * b ) % mod 
}
void solve() { 
    int n ; 
    cin >> n ;
    string a , b ; 
    cin >> a >> b ; 
    int ans = 0 ; 
    vector < int > power ( n + 1 ) , inverse ( n + 1 ) , fact ( n + 1 ) ; 
    power[0] = inverse[0] = fact[0] = 1; 
    for ( int i = 0  ; i < n ; i++ ){
       ans += a[i] != b[i]  ; 
       fact[i + 1] = out ( fact[i] , i + 1 ) ; // for finding the factorial
       power[i+ 1] = out ( power[i] , 2 ) ; // for finding the power of 2 
       inverse[i+1] = expo ( fact[i+1] , mod - 2 , mod )  ; // for finding the inverse of of a number by using fermat little theorem
      //so it says the inverse of a number x is equal to  x ^ (m-2) mod m 
     // we can use the modular exponentiation for counting the large number (a ^ b mod p) that's why we used expo function
    }
    if ( ans & 1 ) {
       cout << 0 ; 
       return ; 
    }
  cout << out ( power[n-ans] , out (fact[ans] , out (inverse[ans/2] , inverse[ans/2]) ) ) ; 

}//--------- -----------------------------------------------------------------------------------------------------------------
int32_t main(){
 #ifndef ONLINE_JUDGE
     files;
  #endif 
     FastIO;
 int test = 1;
   cin>>test; 
    while(test--){
  //cout << " test case " <<++i<<endl;
     solve(); 
     if(test>0)
       cout << endl; 
}
 
 }  
