//****************************************************************************
				  //2048
//****************************************************************************

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

struct array
{
 int n;
 int b;
};


int highest(struct array a[4][4],int h)
{
 int i;
 int j;
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {if(a[i][j].n>=h)
   h=a[i][j].n;
  }
 }
 return h;
}
//************************************************************
// to check if their is any vacant tile left
//************************************************************
int check(struct array a[4][4])
{
int i,j;
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   if(a[i][j].n==0)
   break;
  }
  if(j<4)
  break;
 }
 if(i<4)
 return 1;
 else
 return 0;
}

/*void back()
{
 setcolor(15);
 line(520,430,520,460);
 line(600,430,600,460);
 line(520,430,600,430);
 line(520,460,600,460);
 setcolor(4);
 outtextxy(530,420,"back");
}*/
//starting page
//************************************************
//display the main screen

//***************************************************
char display()
{
char v;

int x=10,y=10,a=10,b=10,z;

setbkcolor(0);
 setcolor(CYAN);
  settextstyle(0,0,1);
  for(x=750;x>=260;x--)
    {

      rectangle(x,100,x+100,130);
      outtextxy(x+30,115,"START");
      rectangle(x,180,x+100,210);
      outtextxy(x+5,195,"LEADER BOARD");
      rectangle(x,260,x+100,290);
      outtextxy(x+30,275,"HELP");
      rectangle(x,340,x+100,370);
      outtextxy(x+30,355,"EXIT");
      delay(10);
      if(x>260)
      cleardevice();
    }
  for(y=10;y<=480;y=y+10)
   {
     setcolor(4);
       for(z=10;z<=260;z=z+10)
	 {
	    line(z,y,a,b);
	 }
    }
  for(y=470;y>=0;y=y-10)
     {
       setcolor(4);
	 for(z=630;z>=360;z=z-10)
	   {
	      line(z,y,630,470);
	   }
     }
 fflush(stdin);
 fflush(stdin);
 scanf("%c",&v);
 sound(400);
 delay(120);
 nosound();
 return v;
}
//*************************************
//to change the diretion of a ball
//**************************************
void change(int x,int y,int xm[])
{
 if(x+50>=640)
   {
    if(xm[0]==10 && xm[1]==-10)
    {x=x-50;xm[0]=-10;xm[1]=-10;}
    else
    {x=x-50;xm[0]=-10;xm[1]=10;}
   }
   else
   {
    if(y+50>=480)
    {
     if(xm[0]==10 && xm[1]==10)
     {y=y-50;xm[0]=10;xm[1]=-10;}
     else
     {y=y-50;xm[0]=-10;xm[1]=-10;}
    }
    else
     {
      if(y-50<=0)
      {
       if(xm[0]==-10 &&xm[1]==-10)
       {y=y+50;xm[0]=-10;xm[1]=10;}
       else
       {y=y+50;xm[0]=10;xm[1]=10;}
      }
      else
      {
       if(x-50<=0)
       {
	if(xm[0]==-10 && xm[1]==10)
	{x=x+50;xm[0]=10;xm[1]=10;}
	else
	{x=x+50;xm[0]=10;xm[1]=-10;}
    }}}}
 }

//*********************************
// to display the end balls
//*********************************
char score()
{
 int x=320,y=240,xm[2]={10,10},x2=320,y2=240,xm2[2]={-10,-10};
  char c1,v;
  cleardevice();
  setbkcolor(BLACK);
  settextstyle(0,0,1);
  do
  {
   setcolor(BLUE);
   circle(x,y,45);
   setfillstyle(SOLID_FILL,BLUE);
   floodfill(x,y,BLUE);
   setcolor(0);
   outtextxy(x-45,y," MAINSCREEN");
    change(x,y,xm);
    x=x+xm[0];
    y=y+xm[1];
    /*setcolor(RED);
    circle(x1,y1,45);
    setfillstyle(SOLID_FILL,RED);
    floodfill(x1,y1,RED);
    setcolor(0);
    outtextxy(x1-45,y1,"   REPLAY");
    change(x1,y1,xm1);
    x1=x1+xm1[0];
    y1=y1+xm1[1];*/

    setcolor(GREEN);
    circle(x2,y2,45);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(x2,y2,GREEN);
    setcolor(0);
    outtextxy(x2-45,y2,"    EXIT");
    change(x2,y2,xm2);
    x2=x2+xm2[0];
    y2=y2+xm2[1];
    /*setcolor(WHITE);
    for(p=1;p<=15;p++)
    circle(x3,y3,p);
    change(x3,y3,xm3);
    x3=x3+xm3[0];
    y3=y3+xm3[1];*/
     delay(100);
   cleardevice();
   }while(!kbhit());
   fflush(stdin);
   scanf("%c",&c1);
   return c1;
   }

/*void color()
{
int a[4][4];
int i=0,j=0;
for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
   {
     if (a[i][j]==2)
      setcolor(3);
   }
 }
}
*/
//*********************************
//to display the help function
//*********************************
void help1()
{
 char pattern[8]={0x00,0x70,0x20,0x27,0x24,0x24,0x07,0x00};
 int x=5,y=5;
 int i;
 char lk;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 clrscr();
 cleardevice();
 for(i=10;i<640;i=i+5)
 {
 delay(5);
 setcolor(3);
 bar(x,y,i,y+3);
 x=i;
 }
 x=635;y=5;
 for(i=10;i<480;i=i+5)
 {
 delay(5);
 setcolor(3);
 bar(x,y,x+3,i);
 y=i;
 }
 x=635;y=475;
 for(i=630;i>0;i=i-5)
 {
 delay(5);
 setcolor(3);
 bar(x,y,i,y+3);
 x=i;
 }
 x=5;y=475;
 for(i=470;i>0;i=i-5)
 {
 delay(5);
 setcolor(3);
 bar(x,y,x+3,i);
 y=i;
 }
  delay(10);
  setfillpattern(pattern,4);

  settextstyle(10,HORIZ_DIR,1);

  //setbkcolor(13);
 setcolor(3);
 outtextxy(30,40,"A:-TO SWIPE LEFT\n");        //ADD GRAPHICS,SAY LINE COLOR
 outtextxy(30,70,"S:-TO SWIPE DOWN\n");
 outtextxy(30,100,"W:-TO SWIPE UP\n");
 outtextxy(30,130,"D:-TO SWIPE RIGHT\n");
 outtextxy(30,160,"M:-FOR MAIN SCREEN\n");
 outtextxy(30,190,"Q:-TO QUIT\n");
 outtextxy(30,250,"L:-TO GO TO LEADERBOARD\n");
 //outtextxy(30,280,"LEVEL1 MAKE 2048 IN 60s\n");
 //outtextxy(30,310,"LEVEL2 16 AT EXTREME CORNERS\n");
 //outtextxy(30,340,"LEVEL3 2048 AT THE CENTER\n");
delay(10);

 }
 //************************************
 //to change the color of tile wrt the no. on it
 //***********************************
 void tilecolor(int z)
 {
  if(z==0)
  setfillstyle(SOLID_FILL,7);
  if(z==2)
  setfillstyle(SOLID_FILL,15);
  if(z==4)
  setfillstyle(SOLID_FILL,3);
  if(z==8)
  setfillstyle(SOLID_FILL,6);
  if(z==16)
  setfillstyle(SOLID_FILL,12);

  if(z==32)
  setfillstyle(SOLID_FILL,14);
  if(z==64)
  setfillstyle(SOLID_FILL,4);

  if(z==128)
  setfillstyle(SOLID_FILL,9);

  if(z==256)
  setfillstyle(SOLID_FILL,10);
  if(z==512)
  setfillstyle(SOLID_FILL,5);

  if(z==1024)
  setfillstyle(SOLID_FILL,1);

  if(z==2048)
  setfillstyle(SOLID_FILL,2);

}
   //***********************************
   //to print the high score with the boxes
   //*************************************
void printscore(int hs,int n)
{char hsc[100],n3[100];
 setfillstyle(SOLID_FILL,6);
 bar(400,50,525,150);
 itoa(hs,hsc,10);
 settextstyle(3,0,1);
 setcolor(1);
 outtextxy(420,55,"Your Score:");
 outtextxy(450,80,hsc);
 setfillstyle(SOLID_FILL,14);
 bar(400,200,525,300);
 itoa(n,n3,10);
 outtextxy(405,210,"High Score:");
 outtextxy(420,230,n3);
}
void sort(FILE *p,int n,int a[])
{
 int i,x=0,t,j,t1;
 p=fopen("LEADER","r");
 while((i=getw(p))!=-1)
 {
  if(i<n)
  {
   t=a[x];
   a[x]=n;
   for(j=x+1;j<5;j++)
   {
    t1=a[j];
    a[j]=t;
    t=t1;
   }
   break;
  }
  x++;
 }
 fclose(p);
}

//********************************************************************
//GETTING DATA
//********************************************************************
void color()
{
 int gd=DETECT,gm,i=20,j=30,a=20,b=30,t=0,p,q,l=45;
 initgraph(&gd, &gm,"C:\\TC\\BGI");
setbkcolor(6);
outtextxy(280,240,"RETRIEVING DATA:HIGH SCORE");
delay(1000);
cleardevice();
//clrscr();
 setfillstyle(SOLID_FILL,BLUE);
 for(p=0;p<12;p++)
 {
 l=l-2;
  for(q=0;q<l;q++)//first
  {
  bar(i,a,j,b);
  i=i+10;
  j=j+10;
  delay(20);
  }
  i=i-10;
  j=j-10;
  a=i;
  i=b;
  t=b;
  b=j;
  j=t+10;
  l=l-1;

  for(q=0;q<l;q++)//second
  {
   bar(a,i,b,j);
   i=i+10;
   j=j+10;
   delay(20);
  }
  i=i-10;
  j=j-10;
  t=a;
  a=i;
  i=t;
  t=b;
  b=j;
  j=t;

  for(q=0;q<l;q++)//third
  {
  bar(i,a,j,b);
   i=i-10;
   j=j-10;
   delay(20);
  }
  i=i+10;
  j=j+10;
  t=a;
  a=i;
  i=t;
  t=b;
  b=j;
  j=t;
  l=l-1;
  for(q=0;q<l;q++)//fourth
  {
   bar(a,i,b,j);
   i=i-10;
   j=j-10;
   delay(20);
  }
  i=b;
  a=j;
  t=j;
  j=b+10;
  b=t+10;

 }
}


//the main function
void main()
{
 FILE *w;
 char c,v,ns[100],v1,n1[100],x1[100];
 int i,j,x=50,y=50,t,p,l,h=0,q=0,hs=0,k=0,z=0,s=250,b=0,g=0,u=0,r,n,f=20,l1[5];
 int gd=DETECT,gm;
 struct array a[4][4];
 initgraph(&gd,&gm,"..\\bgi");
 w=fopen("LEADER","r");
 l1[0]=getw(w);
 fclose(w);
//*******************************************
//function
//*******************************************

 replay:
 fflush(stdin);
 v=display();
 if(v=='h')
 {
  help1();
  if(getch()=='m');
  goto replay;
 }
 if(v=='s')
{
  x=200,y=30;
  //*********************************************
		      //2
    //*********************************************
   cleardevice();
   setbkcolor(14);
   setfillstyle(8,1);
   bar(x,y,x+200,y+30);
  setfillstyle(8,1);
  bar(x+200,y,x+230,y+150);
   setfillstyle(8,1);
  bar(x+230,y+150,x,y+150+30);
   //x=280,y=240;
    setfillstyle(8,1);
  bar(x,y,x+30,y+60);
  // x=280,y=240;
    setfillstyle(8,1);
  bar(x,y+180,x+30,y+250);
  //x=280,y=240;
  setfillstyle(8,1);
  bar(x,y+250,x+230,y+280);
  delay(1000);
  cleardevice();

  //*********************************************
		      //0
  //*********************************************


 x=200,y=50;
  setfillstyle(8,1);
  sound(400);
 delay(120);
 nosound();
  bar(x,y,x+200,y+30);
  setfillstyle(8,1);
  bar(x,y,x+30,y+230);
  setfillstyle(8,1);
  bar(x+200,y,x+230,y+230);
  setfillstyle(8,1);
  bar(x,y+230,x+230,y+260);
   //*********************************************
		      //4
  //*********************************************
   delay(1000);
   sound(400);
 delay(120);
 nosound();
   cleardevice();
  x=200,y=200;
   setfillstyle(8,6);
   bar(x,y,x+200,y+30);

  x=200,y=200;
   setfillstyle(8,6);
   bar(x,y,x+30,y-150);
  x=200,y=240;
   setfillstyle(8,6);
   bar(x+200,y-150,x+230,y+100);

  //*********************************************
		      //8
 //*********************************************
    delay(1000);
    cleardevice();
   x=200,y=50;
    sound(400);
 delay(120);
 nosound();
    setfillstyle(8,1);
    bar(x,y,x+200,y+30);
    setfillstyle(8,1);
    bar(x,y,x+30,y+150);
    setfillstyle(8,1);
    bar(x+200,y,x+230,y+150);
    setfillstyle(8,1);
    bar(x,y+150,x+200,y+180);
    setfillstyle(8,1);
    bar(x,y+150,x+30,y+300);
    setfillstyle(8,1);
    bar(x+200,y+150,x+230,y+300);
    setfillstyle(8,1);
    bar(x,y+300,x+230,y+330);
    //*********************************************
		      //go
    //*********************************************

     delay(1000);

     cleardevice();
   x=50,y=100;

    setfillstyle(8,4);
    bar(x,y,x+200,y+30);
    setfillstyle(8,4);
    bar(x+200,y,x+230,y+50);
    setfillstyle(8,4);
    bar(x,y,x+30,y+200);
    setfillstyle(8,4);
    bar(x,y+200,x+230-30,y+230);
    setfillstyle(8,4);
    bar(x+200-30,y+200,x+230-30,y+150);
    setfillstyle(8,4);
    bar(x+230-30,y+150,x+280-30,y+180);
    setfillstyle(8,4);
    bar(x+250-30,y+180,x+280-30,y+230);
   x=350,y=100;

    setfillstyle(8,1);
    bar(x,y,x+170,y+30);
    setfillstyle(8,1);
    bar(x,y,x+30,y+230-30);
    setfillstyle(8,1);
    bar(x+170,y,x+200,y+230-30);
    setfillstyle(8,1);
    bar(x,y+230-30,x+200,y+260-30);
       sound(400);
 delay(500);
 nosound();
    delay(500);

 setbkcolor(0);
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   a[i][j].n=0;
   a[i][j].b=1;
  }
 }
  i=random(4);
  j=random(4);
  a[i][j].n=2;
  i=random(4);
  j=random(4);
  a[i][j].n=2;
 //background();

 setfillstyle(SOLID_FILL,6);
 setcolor(0);

 while(h!=2048)
 {
  clrscr();
  cleardevice();

  printscore(hs,l1[0]);
  g=0;
  x=50;y=50;
  s=250;
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    z=a[i][j].n;
    tilecolor(z);
    bar(x,y,x+60,y+60);
    if(a[i][j].n!=0)
    {itoa(a[i][j].n,ns,10);
    settextstyle(3,0,1);
    setcolor(0);
    outtextxy(x+10,y+10,ns);
    }
    x=x+67;

   }
  y=y+67;
  x=50;
  }
  settextstyle(3,0,1);
  setcolor(3);
  outtextxy(50,400,"Please swipe:- upwards: w, downwards: s,left: a,right: d");
  c=getch();
  u=0;
  if(c=='m')
  goto replay;
  else
  if(c=='q')
  break;
   if(c=='d')
  {
  for(i=0;i<4;i++)
  {
   for(x=0;x<3;x++)
   {
   for(j=3;j>0;j--)
    {
     if((a[i][j].n==a[i][j-1].n ||a[i][j].n==0) && a[i][j].b &&a[i][j-1].b)
     {
      t=a[i][j].n;
      a[i][j].n=a[i][j].n+a[i][j-1].n;
      if(a[i][j].n!=t)
      u=1;
      if(a[i][j-1].n!=0&&t!=0&&t==a[i][j-1].n)
      {
       hs=hs+a[i][j].n;
       g=1;
      }
      a[i][j-1].n=0;
      if(a[i][j].n==(2*t) &&t!=0)
      a[i][j].b=0;
     }
    }
   }
  }
  if(g)
  {
for(b=0;b<=2;b++)
   {
sound(s);
    delay(100);
    nosound();
    s=s+100;
    }
    s=250;
  }
  else
  {
   sound(s);
    delay(120);
    nosound();
  }
 }
 if(c=='a')
 {
  for(i=0;i<4;i++)
  {
   for(x=0;x<3;x++)
   {
    for(j=0;j<3;j++)
    {
     if((a[i][j].n==a[i][j+1].n || a[i][j].n==0) && a[i][j].b &&a[i][j+1].b)
     {
      t=a[i][j].n;
      a[i][j].n=a[i][j].n+a[i][j+1].n;
      if(a[i][j].n!=t)
      u=1;
      if(a[i][j+1].n!=0&&t!=0&&t==a[i][j+1].n)
      {hs=hs+a[i][j].n;
       g=1;
      }
      a[i][j+1].n=0;
      if(a[i][j].n==(2*t) && t!=0)
      a[i][j].b=0;
     }
    }
   }
  }
 if(g)
  {
   for(b=0;b<=2;b++)
   {
    sound(s);
    delay(100);
    nosound();
    s=s+100;
    }
    s=250;
  }
  else
  {
   sound(s);
    delay(120);
    nosound();
  }

 }
 if(c=='s')
  {
  for(j=0;j<4;j++)
  {
   for(x=0;x<3;x++)
   {
   for(i=3;i>0;i--)
    {
     if((a[i][j].n==a[i-1][j].n ||a[i][j].n==0) && a[i][j].b &&a[i-1][j].b)
      {
      t=a[i][j].n;
      a[i][j].n=a[i][j].n+a[i-1][j].n;
      if(a[i][j].n!=t)
      u=1;
      if(t!=0&&a[i-1][j].n!=0&&t==a[i-1][j].n)
      {
       hs=hs+a[i][j].n;
       g=1;
      }
      a[i-1][j].n=0;
      if(a[i][j].n==(2*t) &&t!=0)
      a[i][j].b=0;
      }
    }
   }
  }
 if(g)
  {
   for(b=0;b<=2;b++)
   {
    sound(s);
    delay(100);
    nosound();
    s=s+100;
    }
    s=250;
  }
  else
  {
    sound(s);
    delay(120);
    nosound();
  }
 }
 if(c=='w')
 {
  for(j=0;j<4;j++)
  {
   for(x=0;x<3;x++)
   {
    for(i=0;i<3;i++)
    {
     if((a[i][j].n==a[i+1][j].n || a[i][j].n==0) && a[i][j].b &&a[i+1][j].b)
     {
      t=a[i][j].n;
      a[i][j].n=a[i][j].n+a[i+1][j].n;
      if(a[i][j].n!=t)
      u=1;
      if(a[i+1][j].n!=0&&t!=0&&t==a[i+1][j].n)
      {
      hs=hs+a[i][j].n;
       g=1;
      }
      a[i+1][j].n=0;
      if(a[i][j].n==(2*t) && t!=0)
      a[i][j].b=0;
     }
    }
   }
  }
 if(g)
  {
   for(b=0;b<=2;b++)
   {
   sound(s);
    delay(100);
    nosound();
    s=s+100;
    }
    s=250;
  }
  else
  {
   sound(s);
    delay(120);
    nosound();
  }
 }
 //******************************************************************
 //gives random no
 //******************************************************************
if(check(a))
 {
  if(u)
  {
  k=0;
  l=random(4);
  p=random(4);
  while(a[l][p].n!=0)
  {
   l=random(4);
   p=random(4);
  }
  a[l][p].n=2;
 } }
  else
  {
   setcolor(4);
   sound(50);
       delay(120);
       nosound();
   outtextxy(50,460,"REMEMBER YOU WILL GET ONLY FOUR CHANCES");
   k++;
   delay(3000);
  }
 if(k==4)
 break;

 h=highest(a,q);
 q=h;
 for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    a[i][j].b=1;}
   }
}
clrscr();
//display();
cleardevice();
x=0;
 w=fopen("LEADER","r");
 while((n=getw(w))!=-1)
 l1[x++]=n;
 fclose(w);
 sort(w,hs,l1);
 w=fopen("LEADER","w");
 for(i=0;i<5;i++)
 putw(l1[i],w);
 putw(-1,w);
 fclose(w);
printscore(hs,l1[0]);
x=50;y=50;
for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    z=a[i][j].n;
    tilecolor(z);
    bar(x,y,x+60,y+60);
    if(a[i][j].n!=0)
    {
    itoa(a[i][j].n,ns,10);
    settextstyle(3,0,1);
    setcolor(11);
    outtextxy(x+10,y+10,ns);
    }
    x=x+67;
   }
   x=50;
   y=y+67;
  }
delay(3000);
cleardevice();

v=score();
if(v=='m')
goto replay;
delay(10);

}
if(v=='e')
{
 cleardevice();
 setcolor(WHITE);
 setbkcolor(BROWN);
 settextstyle(3,0,3);
 outtextxy(300,240,"THANK YOU :D");
 delay(2000);
 exit(1);
}
if(v=='l')
{
 
cleardevice();
printf("\n\n\n\n\n\n\n\n\t\t\tRETREIVING DATA");
color();
cleardevice();
 settextstyle(1,0,4);
 outtextxy(10,10,"LEADER BOARD");
 x=0;
 w=fopen("LEADER","r");
 x=0;
 f=60;
 while((n=getw(w))!=-1)
 {
  settextstyle(1,0,2);
  itoa(n,n1,10);
  //itoa(x++,x1,10);
  //outtextxy(5,f,x1" ");
  outtextxy(5,f,n1);
 f=f+30;

 }
 fclose(w);
fflush(stdin);
if(getch()=='m')
goto replay;
}
getch();
closegraph();


}
