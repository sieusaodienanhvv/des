#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main(){
	string name;
	int i,old,child,numold,numchild,donate;
	double da;
	cout.clear();
	cout <<"name movies: ";
	getline(cin,name);
	cout <<"Adult ticket price: ";
	cin >>old;
	cout <<"Child ticket price: ";
	cin >>child;
	cout <<"Number of adult tickets sold: ";
	cin >>numold;
	cout <<"Number of child tickets sold: ";
	cin >>numchild;
	cout <<"Amount Donated: ";
	cin >>donate;
	cout.clear();
	for(i=0;i<60;i++){
		if(i%2==0){
			cout <<"_";
		}
		else{
			cout <<"*";
		}
	}
	da=(donate*100)/(old*numold+child*numchild);
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Movie name: "<<setw(20)<<setfill(' ')<<right<<name;
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Number of Tickets Sold: "<<setw(20)<<setfill(' ')<<right<<numold+numchild;
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Gross Amount: "<<setw(10)<<setfill(' ')<<right<<"$"<<setw(10)<<setfill(' ')<<right<<old*numold+child*numchild;
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Percentage of Gross Amount Donated: "<<setw(20)<<setfill(' ')<<right<<fixed<<setprecision(3)<<da<<"%";
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Amount Donated: "<<setw(10)<<setfill(' ')<<right<<"$"<<setw(10)<<setfill(' ')<<right<<donate;
	cout <<endl<<setw(40)<<setfill('-')<<left<<"Net Sale: "<<setw(10)<<setfill(' ')<<right<<"$"<<setw(10)<<setfill(' ')<<right<<(old*numold+child*numchild)-donate;
	return 0;
}
