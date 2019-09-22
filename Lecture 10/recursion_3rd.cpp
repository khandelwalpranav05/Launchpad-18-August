#include <iostream>

using namespace std;

void mappedString(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	//Recursive case

	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';
	ch1 = ch1_int + 'A' - 1;

	mappedString(ros1,ans+ch1);

	if(str.length()>1){
		char ch2 = str[1];
		string ros2 = str.substr(2);

		int ch2_int = ch2 - '0';
		ch2 = ch2_int + 'A' - 1;

		if(ch1_int*10 + ch2_int <= 26){
			char second_char = ch1_int*10 + ch2_int + 'A' - 1;
			mappedString(ros2,ans+second_char);
		}
	}
}

string code[] = {" ",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

void printKeypad(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch-'0'];

	// printKeypad(ros,ans+key[0]);
	// printKeypad(ros,ans+key[1]);
	// printKeypad(ros,ans+key[2]);

	for(int i=0;i<key.length();i++){
		printKeypad(ros,ans+key[i]);
	}
}

void printPermutations(string str,string ans){
	//Base case
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	//Recursive case
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		string ros = str.substr(0,i)+str.substr(i+1);

		printPermutations(ros,ans+ch);
	}
}

int countBoardPath(int end,int start){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int i=1;i<=6;i++){
		count += countBoardPath(end,start+i);
	}

	return count;
}

int countMazePath(int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return 1;
	}

	if(sr>er or sc>ec){
		return 0;
	}

	int count = 0;

	count+= countMazePath(sr+1,sc,er,ec);
	count+= countMazePath(sr,sc+1,er,ec);

	return count;
}

void printBoardPath(int end,int start,string path){
	if(start==end){
		cout<<path<<endl;
		return;
	}

	if(start>end){
		return;
	}

	for(int i=1;i<=6;i++){
		char x = i + '0';
		printBoardPath(end,start+i,path + "->" +x);
	}

	return;
}

int main(){

	// mappedString("2314","");
	// printKeypad("34","");

	// printPermutations("abc","");

	// cout<<countBoardPath(4,0)<<endl;
	printBoardPath(4,0,"");

	// cout<<countMazePath(0,0,4,4)<<endl;

	return 0;
}