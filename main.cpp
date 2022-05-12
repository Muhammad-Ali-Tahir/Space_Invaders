#include "mygraphics.h"  //Library which perform game functions like kb hit etc.
#include<conio.h>
#include<iostream>
using namespace std;
int main(){

	cout<<"SPACE INVADERS GAME LOADING"<<endl;
	cout<<"PLAY IN FULL SCREEN MODE"<<endl;
	// Initialising
	int w , h ;  //w is width and h is height of console window
	delay(1000);
	delay(1000);delay(1000);
	getWindowDimensions(w,h);
	bool win=true;
	 //A delay of total 3 seconds introduced.
	cls();  //Screen cleared
	showConsoleCursor(false); //Initialised to Boolean False as we disable blinking of mouse cursor.
	gotoxy(30,30);
	cout<<w<<" "<<h;
	bool bull=false; //bull boolean variable used for Bullet
	drawLine(0,5,w+40,5,255);      //Drawing of line.  drawEllipse(w+50,200,w+50,150,0,255,0,0,0,255);
	drawEllipse(w-50,200,w+50,150,0,255,0,0,0,255);//*Important Model rectangle upon which others are based drawRectangle(w-150,200,w,150,0,255,0,0,0,255);
	//drawRectangle(50,100,150,200,0,0,255,0,0,255); It draws a square
	drawEllipse(w-250,200,w-150,150,0,255,0,0,0,255);
	drawEllipse(w-450,200,w-350,150,0,255,0,0,0,255);
	drawEllipse(w-650,200,w-550,150,0,255,0,0,0,255);
	drawEllipse(w-850,200,w-750,150,0,255,0,0,0,255);
	int t=0,l=0; //Declaration of t and l.
	w+=500; //w incremented by 500.
	int ydm=0; //Variable introduced to make aliens move down. ydm stands for ydownmovement
	int col=255; //Declaration of variable col which is further used to blackout enemy.
	int col1=255;
	int col2=255;
	int col3=255;
	int col4=255;       //Declarations for colour of aliens
	int colour=255; int colour1=255; int colour2=255; int colour3=255; int colour4=255;
	int count=0;
	
	//For second row of aliens.
	drawEllipse(w-50,300,w+50,250,0,255,0,0,0,255);
	drawEllipse(w-250,300,w-150,250,0,255,0,0,0,255);
	drawEllipse(w-450,300,w-350,250,0,255,0,0,0,255);
	drawEllipse(w-650,300,w-550,250,0,255,0,0,0,255);
	drawEllipse(w-850,300,w-750,250,0,255,0,0,0,255);
	char c='\0';
	// Main Event loop:
	int i=0,j=650;
	while (true){
		cls();
		drawRectangle(10*i+0,j+0,10*i+45,j+45,0,0,0,255,0,0); //For hero character.
		delay(1); //change made here I also changed the delay to make it move slower and play easily
		drawRectangle(10*i+0,j+0,10*i+45,j+45,0,0,0,0,0,0);

		bull=false;
		if (10*i > w) i = 0;

		//char c ;//= getKey();
		if(kbhit())
		c=getch(); //Input of key stored into this variable c.
		if (c == 'q') break;
		

		if (c == 'a') i -=5;        // On clicking a it moves to the left

		if (c == 's') j += 10;     //j=j+10 On clicking s it moves down.

		if (c == ' ')             // Rectangle is drawn. which moves upward simply it outputs laser.   
		{	
			drawRectangle(10*i+10,j-1000,10*i+15-10,j+45,0,0,0,150,255,255);// Throws laser projectile.
			delay(55); //Previously it was 70.
			bull=true; //Boolean set to TRUE only when space pressed other than that it is false.
			drawRectangle(10*i+10,j-1000,10*i+15-10,j+45,0,0,0,0,0,0);//
		}
		
		if (c == 'd') i += 5;     // On clicking  d it moves to the right.
		c='\0';
		
	//For first row of Aliens
	drawEllipse(w-50+t,200+ydm,w+50+t,150+ydm,0,colour,0,0,0,colour);
	if(10*i+10>w-50+t&&10*i+45-10<w+50+t&&bull)//&&col!=0){ //*Here I used a nested if condition which checks that if colour of alien below is 
	if(col==0){                                 //black meaning it is destroyed only then will the alien be destroyedby assigning 0 to colour.
	colour=0;
	count++;}
	drawEllipse(w-250+t,200+ydm,w-150+t,150+ydm,0,colour1,0,0,0,colour1);
	if(10*i+10>w-250+t&&10*i+45-10<w-150+t&&bull){   
	if (col1==0){
	colour1=0;count++;}  // Variable used to store new value of colour.
	}
	drawEllipse(w-450+t,200+ydm,w-350+t,150+ydm,0,colour2,0,0,0,colour2);
	if(10*i+10>w-450+t&&10*i+45-10<w-350+t&&bull){   
	if (col2==0){
	colour2=0;
	count++;}  
	}
	drawEllipse(w-650+t,200+ydm,w-550+t,150+ydm,0,colour3,0,0,0,colour3);
	if(10*i+10>w-650+t&&10*i+45-10<w-550+t&&bull){   
	if (col3==0){
	colour3=0; count++;}  
	}
	drawEllipse(w-850+t,200+ydm,w-750+t,150+ydm,0,colour4,0,0,0,colour4);
	if(10*i+10>w-850+t&&10*i+45-10<w-750+t&&bull){   
	if (col4==0){
	colour4=0;count++;}  
	}
	//if(count==3)  //This is test statement to check whether count variable is actually counting
	//	{
	//	cout<<"Congratulations!!!! You have won the game and destroyed all the Space Invaders"<<endl; }
	

	//For second row of aliens.
	drawEllipse(w-50+t,300+ydm,w+50+t,250+ydm,0,col,0,0,0,col); //Incremenet of t is used here to make the circles move.
	if(10*i+10>w-50+t&&10*i+45-10<w+50+t&&bull){  //If projectile x1 is greater than enemy x1 change colour to 0 meaning disappear 
	col=0;count++;}
	drawEllipse(w-250+t,300+ydm,w-150+t,250+ydm,0,col1,0,0,0,col1);
	if(10*i+10>w-250+t&&10*i+45-10<w-150+t&&bull)
	{   
	col1=0;
	count++;
	}
	drawEllipse(w-450+t,300+ydm,w-350+t,250+ydm,0,col2,0,0,0,col2);
	if(10*i+10>w-450+t&&10*i+45-10<w-350+t&&bull){   
	col2=0;count++;}
	drawEllipse(w-650+t,300+ydm,w-550+t,250+ydm,0,col3,0,0,0,col3);
	if(10*i+10>w-650+t&&10*i+45-10<w-550+t&&bull){   //Over here bull is false as it was initialised to false.
	col3=0;count++;}
	drawEllipse(w-850+t,300+ydm,w-750+t,250+ydm,0,col4,0,0,0,col4);
	if(10*i+10>w-850+t&&10*i+45-10<w-750+t&&bull){   
	col4=0;
	count++;
	}
	gotoxy(30,30);
	
	if(w-50+t>w) //w-50+t is right most x coordinate,I used it to know when to make the aliens move backward.
	{
		l=1; //Variable which tells to decrement t by 10.
	ydm+=20;}
	if(w-750+t<0) //w-750+t is the leftmost most x coordinate,I used it to know when to make the aliens move backward.
	{
		l=0;
	ydm+=20;}
	if(l==0){
	t+=30;  //Variable t is relevant for movement in x axis.
	
	}
	else{
	t-=30; //was previously 10
	
	}
	/*if(t==20) //This I have done to ensure that after increment of 30 in t the aliens move 30 downward.
	{
		//This code written on 2-12-2019:-
	delay(10); //A delay of 10 mili seconds.
	//First row of aliens.
	drawEllipse(w-50,200+ydm,w+50,150+ydm,0,255,0,0,0,255);
	drawEllipse(w-250,200+ydm,w-150,150+ydm,0,255,0,0,0,255);
	drawEllipse(w-450,200+ydm,w-350,150+ydm,0,255,0,0,0,255);
	drawEllipse(w-650,200+ydm,w-550,150+ydm,0,255,0,0,0,255);
	drawEllipse(w-850,200+ydm,w-750,150+ydm,0,255,0,0,0,255);
	//For 2nd row of aliens
	drawEllipse(w-50,300+ydm,w+50,250+ydm,0,255,0,0,0,255); 
	drawEllipse(w-250,300+ydm,w-150,250+ydm,0,255,0,0,0,255);
	drawEllipse(w-450,300+ydm,w-350,250+ydm,0,255,0,0,0,255);
	drawEllipse(w-650,300+ydm,w-550,250+ydm,0,255,0,0,0,255);
	drawEllipse(w-850,300+ydm,w-750,250+ydm,0,255,0,0,0,255);
	ydm=ydm+40; //Down movement
	if(h=1300) //h==//reached below of screen)
		{
			cout<<"Game finished. You have lost the game :("<<endl;
		}
	}
	
*/
	if(ydm+300>j){
		//cout<<":( You have Lost try better next time"<<endl;
		win=false;
		cout<<":( You have Lost try better next time. To view Score and Number of Bullets fired press space bar"<<endl<<count;
		break;
	}
	//if(count>=15){
	
	//break;} Latest count if condition commented.****
		//if(count==9){
		//cout<<"Congratulations!!!! You have won the game and destroyed all the Space Invaders"<<endl;
		//}
	if (col==0 &&colour==0 &&col1==0 &&colour1==0&&col2==0 &&colour2==0 &&col3==0 &&colour3==0 &&col4==0 &&colour4==0)
	{
		win=true;
		cout<<"Congratulations!!!! You have won the game and destroyed all the Space Invaders. To view Score and Number of Bullets fired press space bar"<<endl;
		break;
	}
	}  //<-----*This curly bracket marks end of the main event while loop

	// cleaning
	//cout<<"Score:" <<w<<endl; just to check functioning
	drawLine(0,5,w,5,0);
	drawEllipse(w-10,0,w,10,0,0,0,0,0,0); //Semi colon after calling these functions
	drawLine(0,10,w,10,0);//drawLine(0,5,w,5,0);
	drawLine(0,20,w,20,0); 
	drawEllipse(w-10,0,w,10,0,0,0,0,0,0);
	getch();
	cls();
	if(win){  //This if 1st part runs only when Boolean win is true else lost message output. 
		cls();	
		gotoxy(0,0);
		cout<<"Congratulations!!!! You have won the game and destroyed all the Space Invaders"<<endl<<"Number of Bullets Fired: "<<count<<endl;
		cout<<"Total Score after destroying all aliens: "<<count*10-50<<endl;
		}
	else
	{
		cout<<":( You have Lost try better next time"<<endl<<"Number of Bullets Fired: "<<count<<endl;
		cout<<"Total Score after destroying some aliens: "<<count*10-50<<endl;
		//break;
	}
	getch();
	getch();
	getch();
	getch();
	showConsoleCursor(true);

	gotoxy(0,0);

	return 0;
}

