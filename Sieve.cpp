vector<int>prime;
void sieve(int n){
	int i,j,x=sqrt(n);
	vector<bool>tmp(n+1,false);
	for(i=4;i<=n;i+=2){tmp[i]=true;}
	for(i=3;i<=x;i+=2){
		if(tmp[i]){continue;}
		for(j=i*i;j<=n;j+=i){
			tmp[j]=true;
		}
	}
	prime.push_back(2);
	for(i=3;i<=n;i+=2){
		if(!tmp[i]){prime.push_back(i);}
	}
}
