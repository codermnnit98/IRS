#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll MOD=1e9+7;
int main(){
	    
	    srand(time(NULL));
        freopen("general_database.txt","w",stdout);
	    for(int i=1;i<=100;i++){
	    	ll a=rand();
	    	ll b=rand();
	    	a=a%MOD;
	    	b=b%MOD;
	    	cout<<a<<" "<<b<<" "<<((a+b)-(a*b))-(a-b)<<"\n";
	    }
            
}
