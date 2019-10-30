ll  mul(ll a,ll b)
{
    a %=mod; b %=mod;
    ll q = (long double) a*b/mod;
    return ((a*b-q*mod)%mod+mod)%mod;
}

