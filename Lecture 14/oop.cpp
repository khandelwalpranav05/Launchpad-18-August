#include <iostream>
#include <string.h>
#include<string>

using namespace std;

class Car{
private:
	int speed;
	char name[20];
	int model_no;
public:

	void startCar(){
		cout<<"Ignition"<<endl;
	}

	Car(){
		cout<<"Mera Constructor"<<endl;
	}

	Car(int s){
		speed = s;
	}

	Car(int speed,char str[]){
		this->speed = speed;
		strcpy(name,str);
	}

	Car(int speed,int model_no,char str[]){
		this->speed = speed;
		strcpy(name,str);
		this->model_no = model_no;
	}

	void printDetails(){
		cout<<this->speed<<endl;
		cout<<model_no<<endl;
		cout<<name<<endl;
	}

	int getSpeed(){
		return this->speed;
	}

	void setSpeed(int speed){
		if(speed<0){
			cout<<"Not Valid"<<endl;
			return;
		}
		this->speed = speed;
	}

	Car(Car &X){
		this->speed = X.speed;
		this->model_no = X.model_no;
		strcpy(this->name,X.name);
	}
};

int main(){

	// Car droom(10);
	// droom.speed = 100;
	// cout<<droom.speed<<endl;

	// droom.startCar();


	// Car A(120,"Creta");
	// cout<<A.name<<endl;
	// cout<<A.speed<<endl;

	// cout<<"**************"<<endl;

	// Car B(300,12,"Suzuki");
	// B.printDetails();
	// cout<<"***********"<<endl;
	// cout<<"Speed is "<<B.getSpeed()<<endl;
	// cout<<"AFTER CHANGES"<<endl;
	// B.setSpeed(-12);
	// cout<<"Speed is "<<B.getSpeed()<<endl;


	// cout<<B.model_no<<endl;
	// cout<<B.speed<<endl;
	// B.name[0] = 'Y';
	// cout<<B.name<<endl;

	// cout<<"**************"<<endl;
	// Car D;

	// Car newCar;
	// newCar.speed = 120;
	// cout<<newCar.speed<<endl;
	// newCar.startCar();

	// cout<<droom.model_no<<endl;
	
	// Car A(132,1,"First");
	// A.printDetails();
	// cout<<"***********"<<endl;
	// Car B(A);
	// B.printDetails();
	// B.setSpeed(789);
	// cout<<B.getSpeed()<<endl;
	// cout<<A.getSpeed()<<endl;



	// string s = "Pranav";
	// string s("pranav");


	// Car *C = new Car(456,3,"New Car");
	// C->printDetails();

	// int *a = new int(30);
	// int *arr = new int[3];

	// for(int i=1;i<=3;i++){
	// 	arr[i-1] = i;
	// 	cout<<arr[i-1]<<" ";
	// }
	// cout<<endl;

	// delete a;
	// delete [] arr;
	// int a = 10;

	return 0;
}