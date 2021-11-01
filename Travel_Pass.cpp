#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,a,b;
	    cin>>n>>a>>b;
	    string s;
	    cin>>s;
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        if(s[i] == '0'){
	            ans += a;
	        }
	        else{
	            ans += b;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
