#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

int score1=0,score2=0;
int again=1;
int plen=1;
int startmenu(){

int sel=1;
int x=210,y=260;

for(;;){


settextstyle(10,0,4);
setcolor(GREEN);
outtextxy(220,150,"Snake Game");

settextstyle(8,0,3);
setcolor(7);
outtextxy(230,250,"Start Game");
outtextxy(230,300,"Exit Game");
setcolor(WHITE);
circle(x,y,5);
setfillstyle(1,4);
floodfill(x,y,WHITE);
if(GetAsyncKeyState(VK_UP))
{
	sel=1;
	x=210,y=260;
}
else if(GetAsyncKeyState(VK_DOWN))
{
		sel=2;
	x=210,y=310;
}
else if(GetAsyncKeyState(VK_RETURN))
{
	break;
}


delay(80);
cleardevice();

}

return sel;
}


int playerscreen()
{

delay(500);

int x=210,y=260;

for(;;){


settextstyle(10,0,4);
setcolor(GREEN);
outtextxy(220,150,"Players");

settextstyle(8,0,3);
setcolor(7);
outtextxy(230,250,"1  player");
outtextxy(230,300,"2 players");
setcolor(WHITE);
circle(x,y,5);
setfillstyle(1,4);
floodfill(x,y,WHITE);
if(GetAsyncKeyState(VK_UP))
{
plen=1;
	x=210,y=260;
}
else if(GetAsyncKeyState(VK_DOWN))
{
plen=2;
	x=210,y=310;
}
else if(GetAsyncKeyState(VK_RETURN))
{
	break;
}


delay(80);
cleardevice();

}
}

int player_(int k)
{
	
	cleardevice();
	settextstyle(8,0,4);
	setcolor(5);
	if(k==0)
	outtextxy(getmaxx()/2-70,getmaxy()/2,"Player 1");
	else if(k==1)
	outtextxy(getmaxx()/2-70,getmaxy()/2,"Player 2");

	delay(2000);
	
}


int endscreen()
{
	cleardevice();
	char a[3];
	if(plen==1)
	{
               sprintf(a,"%d",score1);
               settextstyle(8,0,4);
               setcolor(1);
               outtextxy(getmaxx()/2-120,getmaxy()/2,"player score");
                outtextxy(getmaxx()/2+150,getmaxy()/2,a);
                delay(2000);
	}
	else if(plen==2)
	{
		
		sprintf(a,"%d",score1);
               settextstyle(8,0,4);
               setcolor(1);
               outtextxy(getmaxx()/2-130,getmaxy()/2-100,"player 1 score");
                outtextxy(getmaxx()/2+180,getmaxy()/2-100,a);
                		sprintf(a,"%d",score2);
               settextstyle(8,0,4);
               setcolor(1);
               outtextxy(getmaxx()/2-120,getmaxy()/2,"player 2 score");
                outtextxy(getmaxx()/2+180,getmaxy()/2,a);
               
                
                if(score1==score2)
                {
                	   outtextxy(getmaxx()/2,getmaxy()/2+80,"Draw");
				}
				else if( score1 > score2)
				{
					outtextxy(getmaxx()/2-150,getmaxy()/2+80,"Player 1 won");
				}
                else{
                	outtextxy(getmaxx()/2-150,getmaxy()/2+80,"player 2 won");
				}
                
                
	}
	 
	 delay(4000);
	
}

int retry()
{
	setbkcolor(BLACK);
	int x=getmaxx()/2-50,y=getmaxy()/2+15;
	for(;;)
	{
		cleardevice();
		setcolor(WHITE);
		outtextxy(getmaxx()/2,getmaxy()/2,"Retry");
		outtextxy(getmaxx()/2,getmaxy()/2+90,"Quit");
setcolor(WHITE);
		circle(x,y,7);
setfillstyle(1,4);
floodfill(x,y,WHITE);

		if(GetAsyncKeyState(VK_UP))
{
	x=getmaxx()/2-50,y=getmaxy()/2+15;
	again=1;
}
else if(GetAsyncKeyState(VK_DOWN))
{
		x=getmaxx()/2-50,y=getmaxy()/2+105;
		again=0;
}
else if(GetAsyncKeyState(VK_RETURN))
{
	break;
}

delay(80);



	}	
}

int main()
{
	
score1=0,score2=0;

	initwindow(600,600,"snake",100,100);
	
				int sel=startmenu();
		if(sel==2)
		{
    exit(0);
		
		}
	
	delay(20);
		playerscreen();
		
	cleardevice();	
		setbkcolor(WHITE);
	cleardevice();	
	int i;																					
	int gd=DETECT,gm;
//	int x=120 ,y= 300;
	int fx=60,fy=60;
	int length =2;
	srand(time(NULL));
int x[151]={0},y[151]={0};
int dir=1,move;
x[0]=120,y[0]=300;


for(int k=0;k<plen;k++){
	
	player_(k);
	
	for(int o=0; o<151;o++)
	{
		x[o]=0;
		y[o]=0;
	}
	
x[0]=120,y[0]=300;
dir=1;
length=2;

	for(int i=0;;i++)	
	{

settextstyle(1,0,5); // score
setcolor(2);
moveto(500,100);
char a[3];

if(k==0)
sprintf(a,"%d",score1);
else if(k==1)
sprintf(a,"%d",score2);
outtextxy(500,40,a);

//border
			setfillstyle(1,11);
			//border
		bar(0,0,30,600);

		bar(0,0,600,30);
	bar(0,600,600,570);
		bar(600,0,570,600);
		
		//food
		if(x[0]==fx && y[0]==fy)
		{
			
			if(k==0)
			score1++;
			else if(k==1)
			score2++;
			
length++;	
			fx=1+rand()%18;
				fy=1+rand()%18;
		
	fx*=30;	
	fy*=30;	
		
		}
		
		
			setfillstyle(1,RED);
		bar(fx,fy,fx+30,fy+30); //food
		
		if(length>150)
		{
			length=150;
		}
		
	
		if(k==0)
		{
	
		setfillstyle(1,2);
			}
			else{
				
					setfillstyle(1,9);
			}
			
			
		if(GetAsyncKeyState(VK_RIGHT) )
		{
				move=1;
			
		}
		else if(GetAsyncKeyState(VK_LEFT)){
		move=2;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			move=3;
		}
			else if(GetAsyncKeyState(VK_DOWN))
		{
			move=4;
		}
		else{
			move=0;
		}
		
	switch(move)
	{
		case 0:
		if(dir==1)
		{
			
				x[0]=x[0]+30;
		}
		else if(dir==2)
		{
			
				x[0]=x[0]-30;
		}
			else if(dir==3)
		{
				y[0]=y[0]-30;
		}
			else if(dir==4)
		{
				y[0]=y[0]+30;
		}
			break;
		
		
			case 1:

if(dir!=2)
{
		dir=1;
			x[0]=x[0]+30;
}
else{
	dir=2;
			x[0]=x[0]-30;
}
			
			break;
			
			case 2:
				if(dir!=1){
			
			x[0]=x[0]-30;
			dir=2;
				}
				else{
					x[0]=x[0]+30;
					dir=1;
				}
			
			break;
			
			case 3:
				if(dir!=4){
				
	    	dir=3;
			y[0]=y[0]-30;
		}
		else{
			dir=4;
			y[0]=y[0]+30;
		}
			break;
			
			case 4:
				if(dir!=3){
			
				dir=4;
				y[0]=y[0]+30;
					}
					else{
						dir=3;
			y[0]=y[0]-30;	
					}
				break;
			
	}
		
	for(int i=0;i<length;i++){

	bar(x[i],y[i],x[i]+30,y[i]+30); // snake


	
		}
		for(int j=150;j>0;j--)
	{

		x[j]=x[j-1];
		y[j]=y[j-1];
	}
	
	
		delay(120);
	for(int i=2 ;i<length;i++)
	{
		if(x[0]==x[i] && y[0]==y[i])
		{
			goto end;
		}
	}
	
			
		if((x[0]<25) ||(x[0]>540) || (y[0]<25) || (y[0]>540))
		{
		
			break;
		}
		
	
		cleardevice();
		
			}
			}
			
			
			
end:
	
	endscreen();
	cleardevice();
	retry();
	if(again!=0)
	{
		delay(500);
		main();
	}
		
	getch();
	closegraph();
	
	return 0;
}
