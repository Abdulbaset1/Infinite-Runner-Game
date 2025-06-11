#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;


//contants for game
const int rows = 16;
const int cols = 16;
const char player = '^';
const char boundary = 'O';
const int max_life = 3;

//Variables for game
int life = 4;
int score = 0;
int x = 16;
int y = 8;
int a = 0, b = 0;
//initializing coins with some value
int coins = 0, coin1 = 1, coin2 = 6, coin3 = 2, coin4 = 8, coin5 = 12, coin6 = 4;
//initializing hurdles with some value
int obstacle1 = 1, obstacle2 = 5, obstacle3 = 2, obstacle4 = 7, obstacle5 = 11, obstacle6 = 13;
int choice;

//---------------------Function for selection menu
void menu()
{
	cout << "Please make your choice!" << endl;
	cout << "Press 1 to PLay" << endl;
	cout << "Press 2 to view Instructions" << endl;
	cout << "Press 3 to exit the game" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
}

//------------------------Function for Instructions
void instructions()
{
	system("cls");
			cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
			cout << "----------------------Instructions---------------------" << endl;
			cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
	cout << endl;
	cout << ">> Long Press 'W' to move forward! " << endl;
	cout << ">> Long Press 'S' to move backward! " << endl;
	cout << ">> Long Press 'D' to move right! " << endl;
	cout << ">> Long Press 'A' to move left! " << endl;
	cout << ">> Long Press 'T' to jump! " << endl;
	cout << ">> Long Press 'Y' to slide! " << endl;
	cout << ">> x is Obstacle!"<<endl;
    cout << ">> | is Player Chaser! (will chase when you cross 2000 Distance)"<<endl;
    cout << ">> o is Coin! "<<endl;
    cout << "Enter 1 to Play!" << endl;
    cin >> choice;
}
    
//-------------------Function for map
char maparr[500][500];
void map()
{
			cout << "Score: " << score << "      Lifes: " <<life <<"    Coins: "<< coins << endl;
	int i = 0;

srand(time(0));
system("cls");
a=x+1;
b=y;
while(i<=rows)
{
	int j=0;
while(j<cols)
{
if (j == 0 || j == 16 - 1)
{
	//boundaries
maparr[i][j]='O';
}
else if (i == x && j == y)
{
    //Player
maparr[i][j]='^';
}
else if(i==16){
maparr[i][j]='O';
}
    //hurdles in game
else if (i == obstacle1 && j == obstacle2)
{
maparr[i][j]='x';
}
else if (i == obstacle3 && j == obstacle4)
{
maparr[i][j]='x';
}
else if (i == obstacle5 && j == obstacle6)
{
maparr[i][j]='x';
}
else if (i == coin1 && j == coin2)
{
    //coins for Player
maparr[i][j]='o';
}
else if (i == coin3 && j == coin4)
{
maparr[i][j]='o';
}
else if (i == coin5 && j == coin6)
{
maparr[i][j]='o';
}
    //Player Chaser
else if(score>2000 && i==a&&j==b){
maparr[i][j]='|';
}
    //Spaces 
else
{
maparr[i][j]=' ';
}

j++;}

i++;}
// Displaying the Map
i = 0;
while(i<=rows)
{
	int j = 0;
while(j<cols)
{
cout<<maparr[i][j];
j++;
}
i++;
cout<<endl;
}
score = score+15;
obstacle1++;
obstacle3++;
obstacle5++;
coin1++;
coin3++;
coin5++;
}

//------------Function to generate hurdles
void generateObctacle()
{
	srand(time(0));
//Random obstacle generation
	if (obstacle1 == 15)
{
obstacle1 = 1;
obstacle2 = rand() % 15 + 1;
}
if (obstacle3 == 15)
{
obstacle3 = 1;
obstacle4= rand() % 15 + 1;
}
if (obstacle5 == 1)
{
obstacle5 = 1;
obstacle6= rand() % 16 + 1;
}
//Random coins generation
if (coin1 == 16)
{
coin1 = 1;
coin2 = rand() % 16 + 1;
}
if (coin3 == 16)
{
coin3 = 1;
coin4 = rand() % 16 + 1;
}
if (coin5 == 16)
{
coin5 = 1;
coin6 = rand() % 16 + 1;
}
}

//------------------Checking for life
void lifeCheck()
{
	if(x>15)
	{
		x=15;
		life--;
	}
	if(x<1)
	{
		x=1;
		life--;
	}
	if(y>14)
	{
		y=14;
		life--;
	}
	if(y<1)
	{
		life--;
	}
    if(a>14)
	{
	x=14;
	a=15;	
	}	
	if(x==obstacle1 && y==obstacle2 || x==obstacle3 && y==obstacle4 || x==obstacle5 && y==obstacle6)
	{
		life--;
	}
	if(x==coin1 && y==coin2 || x==coin3 && y==coin4 || x==coin5 && y==coin6)
	{
		coins++;
	}
}

//-----------------Function to Increase Speed
void speedIncrease()
{
if(score<150)
{
Sleep(100);
}
if(score>150 && score<500)
{
Sleep(75);
}
if(score>500 && score<1000)
{
Sleep(65);
}
if(score>1000 && score<2000)
{
Sleep(55);
}
if(score>2000)
{
Sleep(50);
}
}


 //----------------Function for controls
	void control()
{
switch (getch())
{
case 'w':
x--;
break;
case 's':
x++;
break;
case 'a':
y--;
break;
case 'd':
y++;
break;
case 'z':
x = x-2;
break;
case'x':
x = x-2;
break;
}
}

	void welcome()
	{
		cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
		cout << "-------------WELCOME TO INFINITY RUNNER GAME-------------" << endl;
		cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
		
		cout << endl;
	}
	int main()
	{
		welcome();
		menu();
		if (choice == 1)
		{system("cls");

		while(life!=0)
		{
			welcome();
			map();
			generateObctacle();
			lifeCheck();
			if(_kbhit())
			{
				control();
			}
			speedIncrease();	
		}
		cout<<endl;
		cout<<"'''''''''''''''''''''''''''''''''''''''''''"<<endl;
		cout<<"-----------------Game Over----------------"<<endl;
		cout<<"'''''''''''''''''''''''''''''''''''''''''''"<<endl;
		cout<<endl;
cout<<"Distance  = "<<score<<endl;
cout<<"Coins = "<<coins<<endl;

		system("pause");
	    }
		else if (choice == 2)
		{
			instructions();
			if(choice == 1)
			{
			while(life!=0)
			{
            welcome();
			map();
			generateObctacle();
			lifeCheck();
			if(_kbhit())
			{
				control();
			}
			speedIncrease();	
			}   
		cout<<endl;
		cout<<"'''''''''''''''''''''''''''''''''''''''''''"<<endl;
		cout<<"-----------------Game Over-----------------"<<endl;
		cout<<"'''''''''''''''''''''''''''''''''''''''''''"<<endl;
		cout<<endl;
cout<<"Distance  = "<<score<<endl;
cout<<"Coins = "<<coins<<endl;

		system("pause");     
		    }
			else
			{
			cout << " You made an invalid entry!" << endl;				
			}
		}
		else if (choice == 3)
		{
			cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
			cout << "------------------The game is Exited------------------" << endl;
			cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
		}
		else
		{
			cout << " You made an invalid entry!" << endl;
		}

}
