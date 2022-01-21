#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

void rules(){
	cout<<"Casino Number Guessing Rules :"<<endl;
	cout<<"1. Choose a number between 1 to 10 :"<<endl;
	cout<<"2. Winner gets 10 times of the money bet :"<<endl;
	cout<<"3.Wrong bet , and you lose the amount you bet :"<<endl;
}

int main(){
	
	string playername;
	int balance; //stores the player balance
	int bettingAmount;
	int guess; 
	int dice;// stores the random number
	char choice;
	srand(time(0));
	
	cout<<"===========Welcome to Casino World========="<<endl;
	cout<<"What is your Name :"<<endl;
	getline(cin , playername);
	
	cout<<"Enter the initial amount to start the game :"<<endl;
	cin>>balance;
	
	do{
		rules();
		cout<<"Your current balance is :"<<balance<<endl;
		
		do{
			cout<<"Hey ,"<<playername<<" : Enter amount to bet"<<endl;
			cin>>bettingAmount;
			
			if(bettingAmount> balance){
				cout<<"Betting amount can't be more than your current balance"<<endl;
				cout<<"Please re-enter the Betting amount :"<<endl;
			}
		}
		while(bettingAmount>balance);
		//Get Player's number
		do{
			cout<<"Guess any betting number between 1 to 10 :"<<endl;
			cin>>guess;
			if(guess <= 0 || guess >10){
				cout<<"Number should be between 1 to 10"<<endl;
				cout<<"Please re-enter the number"<<endl;
			}
		}
		while(guess <= 0 || guess >10);
		dice = rand()%10+1;
		if(dice == guess){
			cout<<"You are lucky!!"<<endl;
			cout<<"You have won Rs."<<bettingAmount*10;
			balance = balance+bettingAmount*10;
		}
		else{
			cout<<"Oops , better luck next time !!"<<endl;
			cout<<"You lost Rs."<<bettingAmount<<endl;
			balance = balance - bettingAmount;
		}
		cout<<"The winning number was :"<<dice<<endl;
		cout<<playername<<"You have balance of Rs."<<balance<<endl;
		if(balance == 0){
			cout<<"You have no money to Play :"<<endl;
			break;
		}
		cout<<"Do you want to play again :"<<endl;
		cin>>choice;	
	}
	while(choice == 'Y' || choice == 'y');
	
		
	cout<<"Thanks for playing the game :"<<endl;
	
	return 0;
}
