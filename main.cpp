//<<!!=============HEADER FILES===========!!>>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
//<<!!===========================================!!>>

using namespace std ;

extern void login_module ( void* params ) ;
extern void retrieve_login_details ( void* param ) ;	// remove this at the end of the project
extern void authenticate ( void* text ) ;
extern void gotoxy ( int x , int y ) ;
extern void display_time ( void* params ) ;
extern void blink_text ( void* text ) ;
extern void draw_msg_box ( void* params ) ;
extern void display_msg ( void* ) ;
extern void draw_banner_line ( void* params ) ;
extern void exit_screen () ;
extern void read_data ( char data[] , int x , int y , int max_size , int special ) ;

extern bool threadFinishPoint = false ;
extern bool logged_in = false ;

extern void startup_tasks ( void* ) ;
extern void header () ;
extern int  main_menu () ;
extern int student_menu () ;
extern void student_central_control ( int );
extern int fee_menu () ;
extern void fee_central_control ( int ) ;
extern int admin_menu () ;
extern void admin_central_control ( int ) ;

extern void news_roll ( void* ) ;

struct msg_list_main
{
	int n ;
	int sleep ;
	char message[5][100];
};

int main ()
{

	char username[100] , password[100] , login_entered[200] ;
	strcpy ( login_entered , "" ) ;

	threadFinishPoint = false ;

	msg_list_main Msg ;

	HANDLE h1 , h2 , h3 , h4 , h5 , h6 , h7 ;

	system ( "cls" ) ;

	system (" title ** AL FATHAH EDUCATION CENTER ** PONNANI ** ") ;

	h1 = (HANDLE)_beginthread ( display_time , 0 , NULL ) ;
	WaitForSingleObject ( h1 , 200 ) ;

	goto NOW ;	

	WaitForSingleObject((HANDLE)_beginthread ( draw_banner_line , 0 , NULL ) , INFINITE ) ;

	WaitForSingleObject ( (HANDLE)_beginthread ( login_module , 0 , NULL ) , INFINITE ) ;

	WaitForSingleObject( (HANDLE)_beginthread ( draw_msg_box , 0 , NULL ) , INFINITE ) ;


	while ( strcmp ( login_entered , "success") )
	{	
		Msg.n = 2 ;
		Msg.sleep = 100 ;
		strcpy ( Msg.message[0] , "*** WELCOME TO ALFATHAH EDUCATION CENTER ***");
		strcpy ( Msg.message[1] , "*** ENTER YOUR LOGIN CREDENTIALS ***" );

		h2 = (HANDLE)_beginthread ( display_msg , 0 , &Msg );

		strcpy ( login_entered , "" ) ;

		gotoxy( 85 , 33 ) ;
		printf("                  ") ;
		gotoxy( 85 , 35 ) ;
		printf("             ") ;		

		read_data ( username , 85 , 33 , 20 , 0 ) ;
		strcpy ( login_entered , username ) ;
		strcat ( login_entered , " " ) ;

		read_data ( password , 85 , 35 , 20 , 1 ) ;
		strcat ( login_entered , password ) ;

		strcpy ( Msg.message[2] , "terminate" );

		Msg.n = 1 ;
		Msg.sleep = 25 ;
		strcpy ( Msg.message[0] , "         --- AUTHENTICATING ---         ");

		h3 = (HANDLE)_beginthread ( display_msg , 0 , &Msg );

		h4 = (HANDLE)_beginthread ( authenticate , 0 , (char*)login_entered ) ;
		
		WaitForSingleObject ( h4 , INFINITE ) ;

		threadFinishPoint = false ;
		while (  threadFinishPoint == false ) ; 
		threadFinishPoint = false ;

		strcpy ( Msg.message[1] , "terminate" );

		if ( !strcmp ( login_entered , "not success" ) )
		{
			msg_list_main Msg ;
			Msg.n = 1 ;
			Msg.sleep = 50 ;
			strcpy ( Msg.message[0] , "--- AUTHENTICATION FAILURE ---" );
		
			display_msg ( &Msg ) ;
		}
		else
		{
			msg_list_main Msg ;
			Msg.n = 2 ;
			Msg.sleep = 50 ;
			strcpy ( Msg.message[0] , "--- AUTHENTICATION SUCCESS ---" );
			strcpy ( Msg.message[1] , "--- LOGGING YOU IN ---" );
			
			h5 = (HANDLE)_beginthread ( display_msg , 0 , &Msg ) ;

			h6 = (HANDLE)_beginthread ( startup_tasks , 0 , NULL ) ;
			WaitForSingleObject ( h6 , INFINITE ) ;

			threadFinishPoint = false ;
			while (  threadFinishPoint == false ) ; 
			threadFinishPoint = false ;

			strcpy ( Msg.message[2] , "terminate" );
			
		}
	}

NOW :
	logged_in = true ;			

	startup_tasks ( NULL ) ;		// delete this line when invalidating the NOW label

	int pos = 0 ;
	
	while ( pos != 5 )
	{
		pos = main_menu () ;

		switch (pos)
		{
			case 1:
				student_central_control ( student_menu () ) ;
				break ;
			case 2:
				fee_central_control  	( fee_menu () ) ;
				break ;
			case 3:
				admin_central_control 	( admin_menu () ) ;
				break ;
			case 4:
				gotoxy ( 0 , 0 ); cout << "option 4" ;
				break ;
			case 5:
				exit_screen () ;
				break ;												
		}
	}

	return 0 ;
}
