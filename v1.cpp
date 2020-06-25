#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	ll input1,input2,output;
	node():input1(0),input2(0),output(0){}
	node(ll x,ll y,ll z):input1(x),input2(y),output(z){}
};
ll check_function(ll &input1,ll &input2){
	return input1 + input2;
}
bool check(vector<node> &inputs){
    for(int i=0;i<inputs.size();i++){
    	ll input1=inputs[i].input1;
    	ll input2=inputs[i].input2;
    	ll output=check_function(input1,input2);
    	if(output!=inputs[i].output)return false;
    }

    return true;
}
int main(){
    
	ifstream myFile ("names.txt");

	vector<string>answer;

	if(myFile.is_open()){
		string fileName="";
		vector<node>inputs;

		while(getline(myFile,fileName)){
          string databaseName=fileName.substr(0,fileName.find("."));
          databaseName+="_database.txt";
          ifstream databaseFile (databaseName);
          string inputString;
          while(getline(databaseFile,inputString)){
          	    stringstream inputStream(inputString);
          	    ll input1,input2,output;
          	    inputStream>>input1>>input2>>output;
          	    node input(input1,input2,output);
          	    inputs.push_back(input);
          }

          databaseFile.close();
          bool f=check(inputs);
          if(f)answer.push_back(fileName);
		}
		myFile.close();

		if(answer.size()==0)cout<<"no match"<<"\n";
		else{
			cout<<answer.size()<<" "<<(answer.size()==1 ? "match" : "matches")<<"\n";
			for(int i=0;i<answer.size();i++){
				cout<<answer[i]<<"\n";
			}
		}
	}else{
		cout<<"error"<<"\n";
	}
}