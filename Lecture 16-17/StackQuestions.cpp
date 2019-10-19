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

int histogram(int arr[],int n){

	stack<int> s;
	int max_area = 0;

	int i=0;

	while(i<n){
		if(s.empty() or arr[s.top()] <= arr[i]){
			s.push(i);
			i++;
		}else{

			int extractedTop = s.top();
			s.pop();

			int currArea=0;

			if(s.empty()){
				currArea = arr[extractedTop]*i;
			}else{
				currArea = arr[extractedTop]*(i - s.top() - 1);
			}

			if(currArea>max_area){
				max_area = currArea;
			}

		}

	}

	while(!s.empty()){
		int extractedTop = s.top();
		s.pop();

		int currArea=0;

		if(s.empty()){
			currArea = arr[extractedTop]*i;
		}else{
			currArea = arr[extractedTop]*(i - s.top() - 1);
		}

		if(currArea>max_area){
			max_area = currArea;
		}
	}

	return max_area;
}

int main(){

	// stack<char> s; 

	// cout<<balancedParathesis("(()))")<<endl;
	// cout<<isDuplicate("((a+b)+((c+d)))")<<endl;

	// int arr[] = {2,1,2,3,1};
	// cout<<histogram(arr,5)<<endl;

	return 0;
}