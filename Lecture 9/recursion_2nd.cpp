#include <iostream>

using namespace std;

int sumTilln(int n){
	if(n==1){
		return 1;
	}

	int sumtilln1 = sumTilln(n-1);
	int total = sumtilln1*n;
	return total;
}

void printID(int n,int temp){
	if(temp==n+1){
		return;
	}

	cout<<temp<<endl;
	printID(n,temp+1);
	cout<<temp<<endl;
	return;
}

int fib(int n){
	// if(n==0){
	// 	return 0;
	// }
	// if(n==1){
	// 	return 1;
	// }

	if(n==0 or n==1){
		return n;
	}

	int fibn1 = fib(n-1);
	int fibn2 = fib(n-2);
	int fibatn = fibn2 + fibn1;
	return fibatn;
}

int powerBetter(int n,int p){
	if(p==0){
		return 1;
	}

	if(p&1){
		int powernby2 = powerBetter(n,p/2);
		int powertilln = powernby2*powernby2*n;
		return powertilln;
	}else{
		int powernby2 = powerBetter(n,p/2);
		int powertilln = powernby2*powernby2;
		return powertilln;
	}
}

string removeDuplicate(string str){
	if(str.length()==1){
		return str;
	}

	// if(str.length()==0){
	// 	return "";
	// }

	char ch = str[0];
	string ros = str.substr(1);

	string result = removeDuplicate(ros);

	if(result[0]==ch){
		return result;
	}else{
		return ch+result;
	}
}

string replacePi(string str){
	//Base Case
	if(str.length()==0){
		return "";
	}

	//Recursive Case

	char ch = str[0];
	string ros = str.substr(1);

	string result = replacePi(ros);

	if(ch=='p' and result[0]=='i'){
		return "3.14" + result.substr(1);
	}else{
		return ch + result;
	}
}

string moveToEnd(string str){
	//Base
	if(str.length()==0){
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);

	string result = moveToEnd(ros);

	if(ch=='x'){
		return result+ch;
	}else{
		return ch+result;
	}
}

// int check = 0;

void printSubsequence(string str,string ans){
	// check++;
	if(str.length()==0){
		// cout<<"Count"<<endl;
		cout<<ans<<endl;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros,ans+ch);
	printSubsequence(ros,ans);

}

void merge(int arr[],int brr[],int size1,int size2){

	int c[size1 + size2];

	int i = 0;
	int j = 0;
	int k = 0;

	while(i<size1 and j<size2){

		if(arr[i]>brr[j]){
			c[k] = brr[j];
			k++;
			j++;
		}else{
			c[k] = arr[i];
			k++;
			i++;
		}
	}

	while(i<size1){
		c[k] = arr[i];
		i++;
		k++;
	}

	while(j<size2){
		c[k] = brr[j];
		j++;
		k++;
	}

	for(int x=0;x<size1+size2;x++){
		cout<<c[x]<<" ";
	}
	cout<<endl;

}

int main(){

	// cout<<sumTilln(10)<<endl;
	// printID(5,1);
	
	// cout<<fib(7)<<endl;

	// cout<<powerBetter(2,5)<<endl;
	// cout<<powerBetter(2,8)<<endl;

	// cout<<removeDuplicate("aabbbccghjikkjj")<<endl;

	// cout<<replacePi("xxpipipiipxxppixx")<<endl;

	// cout<<moveToEnd("nxaxmxaxnx")<<endl;

	printSubsequence("abc","");
	// cout<<check<<endl;

	// int arr[] = {1,3,5,7};
	// int brr[] = {2,4,6,8,10,12,23,56,89};
	// merge(arr,brr,4,9);


	// string str = "p";
	// cout<<"String"<<str[2]<<"END"<<endl;

	// int x = 10;
	// cout<<(x++)<<endl;
	// cout<<x<<endl;
	// x++;

	// cout<<(++x)<<endl;

	return 0;
}