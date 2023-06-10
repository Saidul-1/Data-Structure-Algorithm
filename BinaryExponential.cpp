int BinaryExponential(int base, int power, int MOD){
    int ans=1;
    while(power>0){
        if(power%2){
            ans=(ans*base)%MOD;
        }
        base=(base*base)%MOD;
        power/=2;
    }
    return ans;
}
