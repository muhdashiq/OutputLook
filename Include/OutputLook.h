/*****************************************************************************
******************************STAR*TRAVELS************************************
******************************************************************************

   FileName    : OutputLook.h
   Module      : OutputLook
   Author      : Muhammed Ashiq KP
   Date        : 26 JAN 2014
   Team        : V8 Engine (HYD-17_H78_Group6)
   Guide       : Santhosh
   Description : Color funtions for Update
  
 This file source file is a part of StarTravels Project.
 This project was developed by Tcs Hyderabad ILP's HYD 17-H78 LG (Jan 6 2014)
 Our Project Team is Known as V8Engine it's an alias for H78_Group6

*****************************************************************************/

#ifndef _OUTPUTLOOK_H_
#define _OUTPUTLOOK_H_

#include <string>
#include <iostream>
enum Color
{
    NONE = 0,
    BLACK, RED, GREEN,
    YELLOW, BLUE, MAGENTA,
    CYAN, WHITE
};

using namespace std;

class OL
{
   public:
   static const std::string currentDateTime();
   static string setColor(Color,Color);
   static void printline(char,int);
   static void header();
   static void key();
   static void boxBorder(const int,const int ,const int,const int,Color, Color );
   static void button(string,const int,const int ,const int , Color, Color);
   static void box(int,int,const int,const int ,Color);
   static void textBoxLayout(const int ,const int,const int);
   static void textBoxInput(string &,const int,const int,const int);
   static void label(string,const int,const int,const int );
   static void header(string);
   static void footer();
   static void footer(char[]);
   static void footerTrue(char[]);
   static void footerFail(char[]);
   static void sidePanel();
   static void sidePanelRight(char[],char[]);
   static void sidePanelAdmin();
   static void sidePanelClerk();
   static void sidePanelOffers();
   static void *DynamicTime(void *);
   static void gotoxy(int,int);
   static int maskChar(char);
   static void readPassword(string&,char);
   static int road();
   static int bus();
   static int easyBookingPro();
   static int thanku();
   static void sidePanelCalender();
   static int getArrowUD();
   static int getArrowLR();
   static int yesNo(int,int);
   static char gender(int,int);
   static char ticketType(int,int);
};


#endif
