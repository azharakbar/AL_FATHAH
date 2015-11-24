#include <windows.h>
#include <process.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std ;

struct news_list
{
	string headline ;
};

news_list news_feed[6] ;

extern void gotoxy ( int , int ) ;

extern void init_news_roll () ;
extern void display_news_roll ( void* params ) ;
extern int general_tasks ( string , int* data = 0 ) ;
extern void update_news_roll ( int d ) ;

extern bool newsPause = false ;

extern void init_news_roll ()
{

	int val = 0 ;
	char temp[5] = "" ;

	news_feed[0].headline = "*** WELCOME TO ALFATHAH EDUCATION CENTER ***" ;

	general_tasks ( "get_enroll" , &val );
	itoa ( val , temp , 10 ) ;
	news_feed[1].headline = "*** TOTAL STUDENTS ENROLLED :  " ;
	news_feed[1].headline += temp ;
	news_feed[1].headline += " ***";

	news_feed[2].headline = "*** TOTAL STUDENTS ADMITTED TODAY : 0 ***" ;

	general_tasks ( "get_fee_default" , &val ) ;
	itoa ( val , temp , 10 ) ;
	news_feed[3].headline = "*** TOTAL FEE DEFAULTERS :  " ;
	news_feed[3].headline += temp ;
	news_feed[3].headline += " ***";	

	general_tasks ( "get_collexn_day" , &val ) ;
	itoa ( val , temp , 10 ) ;
	news_feed[4].headline = "*** TOTAL FEE COLLECTED TODAY :  " ;
	news_feed[4].headline += temp ;
	news_feed[4].headline += " INR ***";	

	general_tasks ( "get_collexn_month" , &val ) ;
	itoa ( val , temp , 10 ) ;
	news_feed[5].headline = "*** TOTAL FEE COLLECTED THIS MONTH :  " ;
	news_feed[5].headline += temp ;
	news_feed[5].headline += " INR ***";
	
}

extern void display_news_roll ( void* params ) 
{

	Sleep ( 1000 ) ;

	for ( int j = 0 ; j < 6 ; ++j )
	{
		while ( newsPause ) Sleep (500) ;

		int size = news_feed[j].headline.length() ;
		
		string msg = news_feed[j].headline ;

		size /= 2 ;
		
		while ( newsPause ) Sleep (500) ;

		gotoxy ( 10 , 52 ) ;
		for ( int i = 0 ; i < 148 ; ++i ) 
		{				
				cout << " " ;
				while ( newsPause ) { Sleep (500) ; i = -1 ; }
		}
		cout<<endl;

		while ( newsPause ) ;

		for ( int i = 0 ; news_feed[j].headline[i] != '\0' ; ++i )
		{
			gotoxy (( 84 - size )+i , 52 ) ;
			cout<<news_feed[j].headline[i]<<endl ;
			while ( newsPause ) { Sleep (500) ; i = -1 ; }

			Sleep ( 80 ) ;
			while ( newsPause ) { Sleep (500) ; i = -1 ; }
		}

		while ( newsPause ) Sleep (500) ;
		Sleep ( 1500 ) ;
		while ( newsPause ) Sleep (500) ;
		if ( j == 5 ) j = -1 ;
	}

	_endthread () ;

}

extern void update_news_roll ( int d )
{

	int val = 0 ;
	char temp[5] = "" ;

	if ( d == 1 )
	{
		general_tasks ( "get_enroll" , &val ) ;
		itoa ( val , temp , 10 ) ;
		news_feed[1].headline = "*** TOTAL STUDENTS ENROLLED :  " ;
		news_feed[1].headline += temp ;
		news_feed[1].headline += " ***";				
	}

	if ( d == 3 )
	{
		general_tasks ( "get_fee_default" , &val ) ;
		itoa ( val , temp , 10 ) ;
		news_feed[3].headline = "*** TOTAL FEE DEFAULTERS :  " ;
		news_feed[3].headline += temp ;
		news_feed[3].headline += " ***";						
	}

	if ( d == 4 )
	{
		general_tasks ( "get_collexn_day" , &val ) ;
		itoa ( val , temp , 10 ) ;
		news_feed[4].headline = "*** TOTAL FEE COLLECTED TODAY :  " ;
		news_feed[4].headline += temp ;
		news_feed[4].headline += " INR ***";	

		general_tasks ( "get_collexn_month" , &val ) ;
		itoa ( val , temp , 10 ) ;
		news_feed[5].headline = "*** TOTAL FEE COLLECTED THIS MONTH :  " ;
		news_feed[5].headline += temp ;
		news_feed[5].headline += " INR ***";
	}
}