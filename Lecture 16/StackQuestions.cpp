#include <iostream>
#include <stack>

using namespace std;

bool balancedParathesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch=='('){
			s.push(ch);
		}else{

			if(!s.empty() and s.top()=='('){
				s.pop();
			}else{
				return false;
			}

		}

	}
	
	return s.empty();
}

bool isDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		char ch = str[i];

		if(ch!=')'){
			s.push(ch);
		}else{

			char check = s.top();

			if(check=='('){
				return true;
			}

			while(s.top()!='('){
				s.pop();
			}
			s.pop();

		}
	}

	return false;
}

void stockSpan(int arr[],int n){

	//

}

int main(){

	// stack<char> s; 

	cout<<balancedParathesis("(()))")<<endl;
	cout<<isDuplicate("((a+b)+((c+d)))")<<endl;

	return 0;
}