#include <iostream> 
#include <cstdio>
using namespace std;

int input(char i)
{
	int j;
	
	cout<<i<<": ";
	while(cin>>j)
	{
	if(j>-1&&j<3)
	break;
	
	cout<<i<<": ";
	}	
	return j;
}

bool o(char a)
{
if(a=='O'||a=='0'||a=='o')
return true;
return false;
}
bool x(char a)
{
if(a=='X'||a=='x'||a=='k')
return true;
return false;
}


bool checkwin(char t[3][3], char a)
{
	bool win=0;
	for(int i = 0 ; i < 3 ; i ++)
	{
	if(t[i][0]==a&&t[i][1]==a&&t[i][2]==a)
	win=1;
	if(t[0][i]==a&&t[1][i]==a&&t[2][i]==a)
	win=1;
	}
	if(t[1][1]==a&&((t[2][2]==a&&t[0][0]==a)||(t[0][2]==a&&t[2][0]==a)))
	win=1;
	if(win)
	{
	cout<<"\n\nThe game has come to an end, the player "<<a<<" has won.";
	return 1;
	}
	return 0;
}
void display(char t[3][3])
{
	system("cls");	
		cout<<"  0 1 2 j\n";
	for(int i=0;i<3;i++) 
	{
		cout<<i;
		for(int j=0;j<3;j++) 
		{
			cout<<"|"<<t[i][j];
		}
		cout<<"|\n";
	}
	cout<<"i\n\n";	
	
}
char restart(char t[3][3],char a)
{
		for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) 
		t[i][j]=' ';

	display(t);
cout<<"X or O?\n";		
	 
while(cin>>a)
	{
	display(t);
cout<<"X or O?\n";
	if(o(a)||x(a)) 
		break; 
	}
	
	
	return a;
}


void cpu1(char t[3][3],char a)
{
	bool s=0;
		for(int i=0;i<3;i++) 
			for(int j=0;j<3;j++) 
		if(t[i][j]==' ')//checking whether it's empty - for the AI
	{	
	if(s) break;
		t[i][j]=a;
		s=1;
		break;
	}
}

void game(char t[3][3],char a)
{
	int licznik=0;
	a=restart(t,a);
	while(licznik<9)
	{
		if(o(a))
		{	
		
			display(t);
		if(	checkwin(t,a)  ||	checkwin(t,'x'))
	break;
		cpu1(t,'x')	;
			display(t);
			licznik++;
	if(	checkwin(t,a)  ||	checkwin(t,'x'))
	break;
		}
		cout<<"Where do you wanna play, "<<a<<"?\n";
		
		while(a!=' ') //checking whether it's empty - for the player
			{	
			bool s=1;
			for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) 
		if(t[i][j]==' ')
		s=0;
		if(s) break;
			
			
				int temp_i=input('i'),temp_j=input('j');
				if(t[temp_i][temp_j]==' ')
					{
						t[temp_i][temp_j]=a;
						licznik++;
						break;
					}
					cout<<"\nThat's not an option!\n";
					
			}
		
		if(x(a))
			{
		display(t);
		if(	checkwin(t,a)  ||	checkwin(t,'o'))
	break;
			cpu1(t,'o')	;
			display(t);
			licznik++;
			if(	checkwin(t,a)  ||	checkwin(t,'o'))
	break;
			}
			
				if(licznik>8)
	{
	system("cls");	
		cout<<"\nThere was a tie!\n"; 
		break;
	}
			
			
		}//while 
	}//game
	

int main()
{
	char t[3][3]={' '};	
	char a;  
game(t,a);  
	return 0;
}
