#include <iostream> 
#include <cstdio>
using namespace std;

 
struct tab {
    char t[3][3];
    char a;
};



int input(char i)//ok
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

bool o(char a)//ok
{
if(a=='O'||a=='0'||a=='o')
return true;
return false;
}
bool x(char a)//ok
{
if(a=='X'||a=='x'||a=='k')
return true;
return false;
}

bool fullcheck(tab v)//ok checks whether it's full
{
		bool s=1;
			for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) 
		if(v.t[i][j]==' ')
		s=0;
		return s;
}
bool checkwin(char t[3][3], char a)//ok ale nie zmienione
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
void display(char t[3][3])//ok
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
void restart(tab v)//ok
{
	v.a=' ';
		for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) 
		v.t[i][j]=' ';
do
{
	if(o(v.a)||x(v.a)) 
		break; 
display(v.t);
cout<<"X or O?\n";
}
while(cin>>v.a);
	 
}
void cpu1(char t[3][3],char a)//ok ale nie zmienione
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
void playerturn(tab v)
{
	cout<<"Where do you wanna play, "<<v.a<<"?\n";
	while(v.a!=' ') //checking whether it's empty - for the player
	{	
		if(fullcheck(v)) 
			break;
		int temp_i=input('i'),temp_j=input('j');
		if(v.t[temp_i][temp_j]==' ')
		{
			v.t[temp_i][temp_j]=v.a;
			break;
		}
		cout<<"\nThat's not an option!\n";
	}	
}

void game(tab v)
{
	char ai=' ';
	restart(v);
	if(o(v.a))
	{
		v.t[1][1]='x';
		ai='x';
	}
	else
		ai='o';
	display(v.t);
	while(v.a!=' ')
	{
		playerturn(v);
		
		display(v.t);
		if(	checkwin(v.t,v.a) || checkwin(v.t,ai) )
			break;	 
			
		cpu1(v.t,ai);
			
		display(v.t);
		if(	checkwin(v.t,v.a) || checkwin(v.t,ai) )
			break;
			
			
		if(fullcheck(v))
		{
			system("cls");	
			cout<<"\nThere was a tie!\n"; 
			break;
		}
			
					
	}//while 
}//game
	

int main()
{
	tab v; 
game(v);  
	return 0;
}
