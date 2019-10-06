#include <iostream>
#include <string.h>
#include<string>

using namespace std;

class Car{
public:
	int speed;
	char *name;

	void startCar(){
		cout<<"Ignition"<<endl;
	}

	Car(){
		cout<<"Mera Constructor"<<endl;
	}

	Car(int s){
		speed = s;
	}

	Car(int speed,char *str){

		this->speed = speed;
		name = new char[strlen(str)+1];
		strcpy(name,str);
		// name = str;
	}

	void printDetails(){
		cout<<this->speed<<endl;
		cout<<name<<endl;
	}

	Car(Car &X){
		this->speed = X.speed;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}

	void operator =(Car &X){
		this->speed = X.speed;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}

	~Car(){
		cout<<"Destruction"<<endl;
		delete [] name;
	}
};

int main(){

	Car A(100,"First");
	A.printDetails();

	cout<<"******************"<<endl;
	Car B;
	B = A;
	B.printDetails();

	cout<<"*******************"<<endl;
	B.name[0] = 'Y';
	A.printDetails();
	B.printDetails();

	return 0;
}