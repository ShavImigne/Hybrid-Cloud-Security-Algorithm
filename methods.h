typedef long long int ll;

ll gcd(ll a,ll b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}