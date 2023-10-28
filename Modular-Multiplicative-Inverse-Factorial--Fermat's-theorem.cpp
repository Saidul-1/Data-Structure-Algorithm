long modInv(long a, long MOD){
	long result=1,base=a,pow=MOD-2;
	while(pow>0){
		if(pow&1){result=(result*base)%MOD;}
		base=(base*base)%MOD;
		pow=pow>>1;
	}
	return result;
}
