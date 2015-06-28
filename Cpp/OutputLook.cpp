/*****************************************************************************
******************************STAR*TRAVELS************************************
******************************************************************************

   FileName    : OutputLook.cpp
   Module      : OutputLook
   Author      : Muhammed Ashiq KP
   Date        : 27 FEB 2014
   Team        : V8 Engine (HYD-17_H78_Group6)
   Guide       : Santhosh
   Description : Colour code definitions and printline funtions.
  
 This file source file is a part of StarTravels Project.
 This project was developed by Tcs Hyderabad ILP's HYD 17-H78 LG (Jan 6 2014)
 Our Project Team is Known as V8Engine it's an alias for H78_Group6

*****************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include "../Include/OutputLook.h"
using namespace std;

char OL::ticketType(int ROW=0,int COL=0)
{
    int ch;
    int pos=1;
    Color FG=NONE,BG=NONE;
    int exit_val=1;
    do{

       gotoxy(ROW,COL);
       if(pos==0) {FG=WHITE; BG=BLUE;}
       cout<<setColor(FG,BG)<<"  ONEWAY  \x1b[0m";
       FG=BLUE; BG=NONE;

       if(pos==1) {FG=WHITE; BG=BLUE;}
       cout<<setColor(FG,BG)<<"  ROUND   \x1b[0m";
       FG=BLUE; BG=NONE;

       ch=getArrowLR();
       if(ch==1 || ch== -1)
       {
          pos=pos+ch;
          if(pos<0) pos=1;
          if(pos>1) pos=0;
          continue;
       }
       else if(ch==100)
       {
          switch(pos)
           {
              case 0:return 'O';//cout<<endl<<"***CANCELN***";
                     exit_val=0;
                     break;
              case 1:return 'R';break;//*CONTINUE***";break;
           }
       }

    }while(exit_val);
}

char OL::gender(int ROW=0,int COL=0)
{
    int ch;
    int pos=1;
    Color FG=NONE,BG=NONE;
    int exit_val=1;
    do{

       gotoxy(ROW,COL);
       if(pos==0) {FG=WHITE; BG=BLUE;}
       cout<<setColor(FG,BG)<<"   MALE   \x1b[0m";
       FG=BLUE; BG=NONE;

       if(pos==1) {FG=WHITE; BG=BLUE;}
       cout<<setColor(FG,BG)<<"  FEMALE  \x1b[0m";
       FG=BLUE; BG=NONE;

       ch=getArrowLR();
       if(ch==1 || ch== -1)
       {
          pos=pos+ch;
          if(pos<0) pos=1;
          if(pos>1) pos=0;
          continue;
       }
       else if(ch==100)
       {
          switch(pos)
           {
              case 0:return 'M';//cout<<endl<<"***CANCELN***";
                     exit_val=0;
                     break;
              case 1:return 'F';break;//*CONTINUE***";break;
           }
       }

    }while(exit_val);
}

int OL::yesNo(int ROW=0,int COL=0)
{
    int ch;
    int pos=1;
    Color CLR=NONE;
    int exit_val=1;
    do{
       if(pos==1) CLR=BLUE;
       button("YES",ROW,COL,10,CLR,CLR);cout<<"\x1b[0m";
       CLR=NONE;

       if(pos==0) CLR=BLUE;
       button("NO",ROW,COL+20,10,CLR,CLR);cout<<"\x1b[0m";
       CLR=NONE;

       ch=getArrowLR();
       if(ch==1 || ch== -1)
       {
          pos=pos+ch;
          if(pos<0) pos=0;
          if(pos>1) pos=1;
          continue;
       }
       else if(ch==100)
       {
          switch(pos)
           {
              case 0:return 0;//cout<<endl<<"***CANCELN***";
                     exit_val=0;
                     break;
              case 1:return 1;break;//*CONTINUE***";break;
           }
       }

    }while(exit_val);
}

const std::string OL::currentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "DATE : %d/%m/%Y  TIME : %X", &tstruct);
    return buf;
}

void OL::box(int Row=0,int Column=0,const int hight=20,const int width=20,Color FILL=BLACK)
{
   cout<<"\e7"<<"\033["<<Row<<";"<<Column<<"H"<<setColor(FILL,FILL);
   for(int i=0;i<hight;i++){ for(int j=0;j<width;j++) cout<<"\u2588"; cout<<"\033["<<Row++<<";"<<Column<<"H";}
   cout<<"\e8"<<setColor(NONE,NONE);
}

void OL::printline(char p_Char='_',int p_Number=102)
{
   for(int Index=0;Index<p_Number;Index++) cout<<p_Char;
}

void OL::key(){char ch=getchar();}
/*
void OL::border(const int Row=0,const int Column=0,const int size=20)
{
   int i=0,StringSize=size;
   cout<<"\e7"<<"\033["<<Row<<";"<<Column<<"H";
   cout<<"\u250c";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2510";
   cout<<"\e[1E\033["<<Column-1<<"C\u2502";for(int i=0;i<size;i++) cout<<" "; cout<<"\u2502";
   cout<<"\e[1E\033["<<Column-1<<"C\u2514";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2518\e[1F\e["<<Column<<"C";
   //ringSize/=2;for(int i=0;i<StringSize;i++) cout<<" "; cout<<p_StringData;//getline(cin,p_StringData);
   cout<<"\e8";
}*/
/*
void printline(char ch='-',int count=102)
{
   for(int i=0;i<count;i++) cout<<ch;
}
*/


string OL::setColor(Color foreground = NONE, Color background = NONE)
{
    std::stringstream s; s << "\033[";
    if (!foreground && ! background){s << "0";}
    if (foreground) {s << 29 + foreground; if (background) s << ";";}
    if (background) {s << 39 + background;}
    s << "m"; return s.str();
}

void OL::button(string p_StringData,const int Row=0,const int Column=0,const int size=20,Color FG=NONE,Color BG=NONE)
{
   int i=0,StringSize=size-p_StringData.size();
   cout<<"\e7";
   box(Row+1,Column+1,4,size+2,BG);
   cout<<"\033["<<Row<<";"<<Column<<"H\u250c";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2510";
   cout<<"\e[1E\033["<<Column-1<<"C\u2502";for(int i=0;i<size;i++) cout<<" "; cout<<"\u2502";//\u2588";
   cout<<"\e[1E\033["<<Column-1<<"C\u2514";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2518\e[1F\e["<<Column<<"C";
   StringSize/=2;for(int i=0;i<StringSize;i++) cout<<" "; cout<<setColor(BG,NONE)<<p_StringData<<"\x1b[0m";//getline(cin,p_StringData);
  // cout<<"\e[2E\033["<<Column-1<<"C\u2514";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2518\e[1F\e["<<Column<<"C";
   cout<<"\e8";
}

void OL::textBoxLayout(const int Row=0,const int Column=0,const int size=20)
{
   int i=0;
   cout<<"\e7"<<"\033["<<Row<<";"<<Column<<"H";
   cout<<"\u250c";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2510";
   cout<<"\e[1E\033["<<Column-1<<"C\u2502";for(int i=0;i<size;i++) cout<<" "; cout<<"\u2502";
   cout<<"\e[1E\033["<<Column-1<<"C\u2514";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2518\e[1F\e["<<Column<<"C";
   cout<<"\e8";
}

void OL::textBoxInput(string &p_StringData,const int Row=0,const int Column=0,const int size=20)
{
   int i=0;
   cout<<"\e7"<<"\033["<<Row<<";"<<Column<<"H";
   cout<<"\u250c";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2510";
   cout<<"\e[1E\033["<<Column-1<<"C\u2502";for(int i=0;i<size;i++) cout<<" "; cout<<"\u2502";
   cout<<"\e[1E\033["<<Column-1<<"C\u2514";for(int i=0;i<size;i++) cout<<"\u2500";cout<<"\u2518\e[1F\e["<<Column<<"C";
   getline(cin,p_StringData);
   cout<<"\e8";
}

void OL::label(string p_StringData,const int Row=0,const int Column=0,const int size=30)
{
   int i=0;
   cout<<"\e7"<<"\033["<<Row<<";"<<Column<<"H"<<p_StringData<<"\e8";
}

void OL::header(string p_Username="User")
{
   cout<<"\e7\e[2J\e[0;0H"<<setColor(WHITE,BLUE);
   printline(' ');cout<<endl;
   printline(' ',45);cout<<"STAR TRAVELS";printline(' ',45);cout<<endl;
   printline(' ');cout<<endl<<setColor(BLACK,YELLOW);
   printline(' ');cout<<endl;
   cout<<"\033[4;0H Hi, "<<p_Username<<"\e8\033[4;65H"<<setColor(BLUE,YELLOW)<<currentDateTime();
   cout<<setColor()<<"\e[5;0H";
   footer();
}

void OL::header()
{ 
   cout<<"\e7\e[2J\e[0;0H\e[32;1m"<<setColor(WHITE,BLUE);
   printline(' ');cout<<endl;
   printline(' ');cout<<endl;
   printline(' ');cout<<endl<<setColor(BLACK,YELLOW);
   printline(' ');cout<<endl;
   cout<<"\033[4;0H";
   cout<<setColor()<<"\e[5;0H";//\e8";
   footer();
}


void OL::footerTrue(char msg[])
{
   cout<<"\e7\e[38;0H\e[32;1m"<<setColor(WHITE,BLUE);
   printline(' ');
   cout<<"\e[38;0H"<<msg;
   cout<<setColor()<<"\e[5;0H\e8";
}

void OL::footerFail(char msg[])
{
   cout<<"\e7\e[38;0H\e[32;1m"<<setColor(WHITE,RED);
   printline(' ');
   cout<<"\e[38;0H"<<msg;
   cout<<setColor()<<"\e[5;0H\e8";
}

void OL::footer(char msg[])
{
   cout<<"\e7\e[38;0H\e[32;1m"<<setColor(WHITE,YELLOW);
   printline(' ');
   cout<<"\e[38;0H"<<msg;
   cout<<setColor()<<"\e[5;0H\e8";
}
void OL::footer()
{
   cout<<"\e7\e[38;0H\e[32;1m"<<setColor(WHITE,YELLOW);
   printline(' ');
   cout<<setColor()<<"\e[5;0H\e8";
}


void OL::sidePanelAdmin()
{
   cout<<"\e7\e[32;1m\e[5;0H"<<setColor(RED,CYAN);
   for(int i=0;i<33;i++) {printline(' ',25);cout<<endl;}
   ifstream file("Properties/admin.msg");
   int i=0,Row=7;
   char ch='\0';
   cout<<setColor(WHITE,BLUE)<<"\e[5;0H     ADMIN MESSAGES      "<<setColor(BLACK,CYAN);
   cout<<"\e[7;0H";
   while(file)
   {
      if(i>=24){i-=24;cout<<"\e["<<++Row<<";0H";}
      cout<<ch;
      ch=file.get();i++;
      if(Row>32) {Row-=32; cout<<"\e[7;0H";}
   }
   file.close(); 
   cout<<setColor()<<"\e8";
}

void OL::sidePanelClerk()
{
   cout<<"\e7\e[32;1m\e[5;0H"<<setColor(RED,CYAN);
   for(int i=0;i<33;i++) {printline(' ',25);cout<<endl;}
   ifstream file("Properties/clerk.msg");
   int i=0,Row=7;
   char ch='\0';
   cout<<setColor(WHITE,BLUE)<<"\e[5;0H     CLERK MESSAGES      "<<setColor(BLACK,CYAN);
   cout<<"\e[7;0H";
   while(file)
   {
      if(i>=24){i-=24;cout<<"\e["<<++Row<<";0H";}
      cout<<ch;
      ch=file.get();i++;
      if(Row>32) {Row-=32; cout<<"\e[7;0H";}
   }
   file.close(); 
   cout<<setColor()<<"\e8";
   sidePanelOffers();
}

void OL::sidePanelOffers()
{
   cout<<"\e7\e[32;1m\e[30;0H"<<setColor(RED,CYAN);
   for(int i=0;i<8;i++) {printline(' ',25);cout<<endl;}
   ifstream file("Properties/offers.msg");
   int i=0,Row=31;
   char ch='\0';
   cout<<setColor(WHITE,BLUE)<<"\e[30;0H     OFFERS & PROMO      "<<setColor(BLACK,CYAN);
   cout<<"\e[31;0H";
   while(file)
   {
      if(i>=24){i-=24;cout<<"\e["<<++Row<<";0H";}
      cout<<ch;
      ch=file.get();i++;
      if(Row>36) {Row-=36; cout<<"\e[31;0H";}
   }
   file.close(); 
   cout<<setColor()<<"\e8";
}

void OL::sidePanelRight(char p_Head[],char p_FileName[])
{
   char l_FileName[50]="Properties/";
   strcat(l_FileName,p_FileName);
   cout<<"\e7\e[32;1m\e[30;0H"<<setColor(BLUE,CYAN);
   for(int i=5;i<38;i++) {cout<<"\e["<<i<<";78H";printline(' ',25);cout<<endl;}
   ifstream file(l_FileName);
   int i=0,Row=6;
   int l_Pos=90-strlen(p_Head)/2;
   char ch='\0';
   cout<<setColor(WHITE,BLUE)<<"\e[5;78H                         ";
   cout<<"\e[5;"<<l_Pos<<"H"<<p_Head<<setColor(BLUE,CYAN);
   cout<<"\e[6;79H";
   while(file)
   {
      if(i>=24){i-=24;cout<<"\e["<<++Row<<";79H";}
      cout<<ch;      
      ch=file.get();i++;
      if(ch=='\n') {++Row;i=0;while(ch=file.get()){if(ch=='\n') {Row++; continue;} else break;}cout<<"\e["<<Row<<";79H";}
      if(Row>36) {Row-=6; cout<<"\e[6;79H";}
   }
   file.close();
   cout<<setColor()<<"\e8";
}


void OL::sidePanel()
{
   cout<<"\e7\e[32;1m\e[5;0H"<<setColor(RED,CYAN);
   for(int i=0;i<33;i++) {printline(' ',25);cout<<endl;}
   cout<<setColor()<<"\e8";
}
void OL::sidePanelCalender()
{
   cout<<"\e7\e[32;1m\e[5;0H"<<setColor(RED,CYAN);
   for(int i=0;i<33;i++) {printline(' ',25);cout<<endl;}
   cout<<setColor()<<"\e8";
   gotoxy(7,80);
   system("cal");
}


void OL::gotoxy(int x,int y)
{
        cout<<"\033["<<x<<";"<<y<<"H";
}

void *DynamicTime(void * argument)
{
   while(1)
   {
      cout<<"\e7\e[0;0H";
      system("date");
      cout<<"\e8";
      sleep(1);
   }
}

int OL::maskChar(char p_PrintChar='\0')
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );//reading serial flags (Current Attributes)
    newattr = oldattr;//backup the flags
    newattr.c_lflag &= ~( ICANON | ECHO );// input specific flags (bitmask) */ ICANON :> Canonical input mode
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );//setting serial interface attributes flags with old flags //TCSANOW :> Configuration Changed Immediatly
    ch = getchar();//read the charector
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );//Setting flags
    //printf("-%d-%c-",ch,ch);
    if(ch!=127)
      printf("%c",p_PrintChar);//printing given argument
    else
      {printf("%c",'\b');printf("%c",' ');printf("%c",'\b');}
    return ch;//returning readed value
}

void OL::readPassword(string&p_Password,char p_printChar)
{
   char l_CPassword[100];
   int i=0;
   do{
      l_CPassword[i]=(char)maskChar(p_printChar);
   }while(l_CPassword[i++]!='\n');
   l_CPassword[--i]='\0';
   string temp(l_CPassword);
   p_Password=l_CPassword;
}


int OL::bus()
{
   road();
   int i=10;
   int ROW=3;
   int COL=0;
      box(2+ROW,30+COL,3,50,RED); //name Bord
      box(4+ROW,30+COL,15,50,CYAN); //glass
      box(4+ROW,30+COL,1,50,BLACK);//Glass top BAR
      box(17+ROW,30+COL,1,50,BLACK);//Glass bottom BAR
      box(4+ROW,30+COL,15,1,BLACK);//Glass left BAR
      box(4+ROW,79+COL,15,1,BLACK);//Glass right BAR
      box(4+ROW,55+COL,15,1,BLACK);//Glass right BAR
      box(7+ROW,27+COL,3,2,BLUE); //left Mirror
      gotoxy(15+ROW,31+COL);cout<< setColor(BLACK,CYAN)<<" /--------\\";
      gotoxy(16+ROW,31+COL);cout<<"/          \\"<< setColor(NONE,NONE);
      gotoxy(7+ROW,29+COL);cout<< setColor(BLUE,NONE)<<"_";
      box(7+ROW,81+COL,3,2,BLUE); //Right Mirror
      gotoxy(7+ROW,80+COL);cout<< setColor(BLUE,NONE)<<"_";
      box(18+ROW,30+COL,7,50,BLUE); //face HeadLight, Grill, Indicator
      box(19+ROW,32+COL,3,3,WHITE); //headlight left
      box(19+ROW,75+COL,3,3,WHITE); //headlight right
      box(22+ROW,32+COL,1,3,YELLOW);//indicator left
      box(22+ROW,75+COL,1,3,YELLOW);//indiacator right
      gotoxy(19+ROW,35+COL);cout<< setColor(WHITE,BLUE)<<"    --------------------------------    ";
      gotoxy(20+ROW,35+COL);cout<< setColor(WHITE,BLUE)<<"    --------------------------------    ";
      gotoxy(21+ROW,35+COL);cout<< setColor(WHITE,BLUE)<<"    --------------------------------    ";
      gotoxy(22+ROW,35+COL);cout<< setColor(WHITE,BLUE)<<"    --------------------------------    ";
      box(24+ROW,30+COL,1,50,YELLOW); //bumber
      gotoxy(24+ROW,51+COL);cout<< setColor(BLUE,YELLOW)<<"ILP HYD";//ILP HYD NUMBER PLATE
      box(25+ROW,32+COL,4,4,BLACK); //left tire
      box(25+ROW,74+COL,4,4,BLACK); //right tire
       footer();
      gotoxy(0,0);
      
      i=500;
      long j;
      Color HCLR=WHITE,ICLR=YELLOW;
      while(i--)
      {
         ICLR = YELLOW;
         j=4000000;//##########################################################
         if(i%2==0) HCLR=RED;
         else HCLR=WHITE;

         if(i%3==0) ICLR=GREEN;

         box(19+ROW,32+COL,3,3,HCLR);//headlight left
         box(19+ROW,75+COL,3,3,HCLR);//headlight right
         box(22+ROW,32+COL,1,3,ICLR);//indicator left
         box(22+ROW,75+COL,1,3,ICLR);//indiacator right
         while(j--){}
      }
}

int OL::thanku()
{

   int i=20;
   int ROW=0;
   int COL=-20;
   while(i--)
   {
       cout<<"\e[2J";
       Color CLR=(Color)(i%9);
       if(!CLR) CLR=GREEN;
       if((++ROW)>=36) ROW=0;
       if((COL++)>=15) COL=-33;
       //THANK
       box(6+ROW,32+COL,1,5,CLR);
       box(6+ROW,34+COL,6,1,CLR);

       box(6+ROW,38+COL,6,1,CLR);
       box(6+ROW,42+COL,6,1,CLR);
       box(8+ROW,38+COL,1,5,CLR);

       box(6+ROW,44+COL,6,1,CLR);
       box(6+ROW,48+COL,6,1,CLR);
       box(6+ROW,44+COL,1,5,CLR);
       box(8+ROW,44+COL,1,5,CLR);

       box(6+ROW,50+COL,6,1,CLR);
       box(6+ROW,55+COL,6,1,CLR);
       box(6+ROW,51+COL,1,1,CLR);
       box(10+ROW,54+COL,1,1,CLR);
       box(7+ROW,52+COL,1,1,CLR);
       box(9+ROW,53+COL,1,1,CLR);
       box(8+ROW,52+COL,1,2,CLR);

       box(6+ROW,57+COL,6,1,CLR);
       box(8+ROW,58+COL,1,1,CLR);
       box(7+ROW,59+COL,1,1,CLR);
       box(9+ROW,59+COL,1,1,CLR);
       box(6+ROW,60+COL,1,2,CLR);
       box(10+ROW,60+COL,1,2,CLR);

      // CLR=BLUE;

       //YOU
       box(6+ROW,69+COL,3,1,CLR);
       box(6+ROW,73+COL,6,1,CLR);
       box(10+ROW,69+COL,1,5,CLR);
       box(8+ROW,69+COL,1,5,CLR);

       box(6+ROW,75+COL,1,5,CLR);
       box(10+ROW,75+COL,1,5,CLR);
       box(6+ROW,75+COL,6,1,CLR);
       box(6+ROW,79+COL,6,1,CLR);

       box(6+ROW,81+COL,6,1,CLR);
       box(10+ROW,81+COL,1,5,CLR);
       box(6+ROW,85+COL,6,1,CLR);
       usleep(300000);
   }
   easyBookingPro();
    key();
}

int OL::easyBookingPro()
{
   //PRO
   box(6,79,1,5,CYAN);
   box(6,79,6,1,CYAN);
   box(8,79,1,5,CYAN);
   box(6,83,3,1,CYAN);

   box(6,85,1,5,CYAN);
   box(6,85,6,1,CYAN);
   box(8,85,1,5,CYAN);
   box(6,89,3,1,CYAN);
   box(9,87,1,1,CYAN);
   box(10,88,2,1,CYAN);

   box(6,91,1,5,CYAN);
   box(10,91,1,5,CYAN);
   box(6,91,6,1,CYAN);
   box(6,95,6,1,CYAN);

   // BOOKING
   box(8,36,1,5,GREEN);
   box(10,36,1,5,GREEN);
   box(6,36,6,1,GREEN);
   box(8,40,3,1,GREEN);

   box(6,42,1,5,GREEN);
   box(10,42,1,5,GREEN);
   box(6,42,6,1,GREEN);
   box(6,46,6,1,GREEN);

   box(6,48,1,5,GREEN);
   box(10,48,1,5,GREEN);
   box(6,48,6,1,GREEN);
   box(6,52,6,1,GREEN);

   box(6,54,6,1,GREEN);
   box(8,55,1,1,GREEN);
   box(7,56,1,1,GREEN);
   box(9,56,1,1,GREEN);
   box(6,57,1,2,GREEN);
   box(10,57,1,2,GREEN);

   box(6,60,6,1,GREEN);

   box(6,62,6,1,GREEN);
   box(6,67,6,1,GREEN);
   box(6,63,1,1,GREEN);
   box(10,66,1,1,GREEN);
   box(7,64,1,1,GREEN);
   box(9,65,1,1,GREEN);
   box(8,64,1,2,GREEN);
   
   box(6,69,1,5,GREEN);
   box(10,69,1,5,GREEN);
   box(6,69,6,1,GREEN);
   box(8,71,1,3,GREEN);
   box(8,73,3,1,GREEN);

   // EASY 
   box(6,8,1,5,BLUE);
   box(6,8,5,1,BLUE);
   box(10,8,1,5,BLUE);
   box(8,8,1,5,BLUE);
   box(6,12,4,1,BLUE);

   box(6,14,1,5,BLUE);
   box(8,14,1,5,BLUE);
   box(10,14,1,5,BLUE);
   box(6,18,5,1,BLUE);   
   box(8,14,3,1,BLUE);

   box(6,20,1,5,BLUE);
   box(8,20,1,5,BLUE);
   box(10,20,1,5,BLUE);
   box(6,20,3,1,BLUE);
   box(8,24,3,1,BLUE);  

   box(8,26,1,5,BLUE);
   box(10,26,1,5,BLUE);
   box(6,26,3,1,BLUE);
   box(6,30,6,1,BLUE);
}

int OL::road()
{
  
   int Row=21;
   for(int Length=24;Length<41;Length++)
   {
      gotoxy(Row++,55-Length);
      for(int j=0;j<2*Length;j++) cout<<"\u2591";
   }
}

int OL::getArrowUD()
{
    struct termios oldattr, newattr;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    int ch;
    while(1)
    {
       ch=getchar();
       if(ch==27)
       {
          if(getchar()==91)
          {
             ch=getchar();
             if(ch==65) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return -1;} //printf("UP");
             else if(ch==66) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 1; } //printf("DOWN");
             else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0; }
          }
          else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0; }
       }
       else if(ch==10) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 100;}
       else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0;}
       tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
       return 0;  
    }
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return 0;
}

int OL::getArrowLR()
{
    struct termios oldattr, newattr;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    int ch;
    while(1)
    {
       ch=getchar();
       if(ch==27)
       {
          if(getchar()==91)
          {
             ch=getchar();
             if(ch==67) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return -1;} //printf("RIGHT");
             else if(ch==68) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 1; } //printf("LEFT");
             else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0; }
          }
          else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0; }
       }
       else if(ch==10) { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 100;}
       else { tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); return 0;}
       tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
       return 0;
    }
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return 0;
}
