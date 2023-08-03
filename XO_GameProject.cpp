#include<iostream>
#include <conio.h> 
using namespace std;
char numbers[3][3]={'1','2','3','4','5','6','7','8','9'};//game body
char player='X';//the player
void print_ngame();
void in_put();
char thewin();
int main()
{
	cout<<"This game is for the programmer : \n *** Ghamdan Al-Yamani"<<endl;
	cout<<"\n***** Welcome to my simple game *****\n This game is called X/O Good luck...Enjoy : \n GOOOOO\n";
	while(thewin() == '.')
	{
		print_ngame();
		in_put();
	}
		
	//print_ngame();
	if(thewin() == 'Z')
	cout<<"\n No one is Winner ....\n\n"<<endl;
	else
	cout<<"\n The Winner is Player("<<thewin()<<") ... GOOD GAME.\n\n";	
	cout<<"\n Hope you enjoyed ..... Thank you for using my game***\n";
		getch();
	return 0;
}
void print_ngame()//A function to print the stereoscopic shape of the game
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<numbers[i][j]<<"  ";
		}
		cout<<"\n";	
	}
}
void in_put()//A function to receive the roles of the players
{
	char n=0;
	cout<<"Choose a number to place it in your game --- Player("<<player<<") : ";
	cin>>n;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(numbers[i][j]==n)
			{
				numbers[i][j]=player;
			}
		}
	}
	if(player=='X')//To reverse the roles of the player
	player='O';
	else
	player='X';
}
char thewin()//A function to find out who is the winner of the X or O players and if it is a tie
{
	int nX=0,nO =0,count=0;
	//This is to check every horizontal line
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(numbers[i][j] != 'X' && numbers[i][j] != 'O')count++;//To make sure that there is no winner, any tie expressed with the symbol Z
     		if(numbers[i][j] != 'X' || numbers[i][j] != 'O')count++;
			if(numbers[i][j]=='X')nX++;
			else if(numbers[i][j]=='O')nO++;
			if(nX==3 || nO ==3)
			{
				if(nX>nO)
				return 'X';
				else
				return 'O';
			}
				nX =0;
				nO =0;/*The value of x and o must be zeroed after calculating the horizontal lines
	     	In order to calculate the vertical lines in the following procedure*/
	     
		}
		
	}
//	nX =0;
//	nO =0;/*The value of x and o must be zeroed after calculating the horizontal lines
	     //	In order to calculate the vertical lines in the following procedure*/
	     
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(numbers[j][i]=='X')nX++;
			else if(numbers[j][i]=='O')nO++;
			if(nX==3 || nO==3)
			{
				if(nX>nO)
				return 'X';
				else
				return 'O';
			}
		}
	}
	nX=0;
	nO=0;
	
	if(numbers[0][0]=='X' && numbers[1][1]=='X' && numbers[2][2]=='X')return 'X';//To calculate the diagonal length from the top left
	else if(numbers[0][0]=='O' && numbers[1][1]=='O' && numbers[2][2]=='O')return 'O';//Calculate the diagonal length from the top right
	else if(numbers[0][2]=='X' && numbers[1][1]=='X' && numbers[2][0]=='X')return 'X';//To calculate the diagonal length from the bottom left
	else if(numbers[0][2]=='O' && numbers[1][1]=='O' && numbers[2][0]=='O')return 'O';//Calculate the diagonal length from the bottom right
	if(count==0)return 'Z';//The Z symbol means that the game ended in a tie for both sides
	return '.';//The point symbol means that the game is running and there is no winner

}




