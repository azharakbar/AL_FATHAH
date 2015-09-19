#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std ;

extern void header () ;
extern void gotoxy ( int , int ) ;
extern int  menu_control ( int , int , int , int esc = 0 ) ;
extern void general_tasks ( string , int* data = 0 ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void display_msg_static ( string msg )  ;

extern void admin_central_control ( int ) ;

int change_fee_structure () ;

extern void admin_central_control ( int choice ) 
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
			//x = new_student_entry () ;
			break ;
		case 2 :
			x = change_fee_structure () ;
			break ;
		case 3 :
			return ;

	}	
}


int change_fee_structure () 
{
	int i = 0 , j = 0 ;
	int d1 = 0 , d2 = 0 , d3 = 0 , fees = 0 ;
	string data = "" ;

	header();
	gotoxy(74 , 8) ;
	cout<<"CHANGE FEE STRUCTURE"<<endl;
	gotoxy(73,9);
	for ( i = 1 ; i <= strlen ("CHANGE FEE STRUCTURE")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;	

	general_tasks ( "get_adm_fee" , &d1 ) ;
	general_tasks ( "get_lp_fee" , &d2 ) ;
	general_tasks ( "get_up_fee" , &d3 ) ;


	gotoxy ( 63 , 15 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;
	for ( j = 0 ; j <= 6 ; ++j )
	{	
		gotoxy ( 63 , 16+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 63 , 16+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 71 , 14) ; cout << "** CURRENT FEE STRUCTURE **" ;
	gotoxy ( 64 , 17 ) ; cout << "     ADMISSION FEES       : " << setw(7) << d1 << endl ;	
	gotoxy ( 64 , 19 ) ; cout << "     LOWER PRIMARY FEES   : " << setw(7) << d2 << endl ;
	gotoxy ( 64 , 21 ) ; cout << "     UPPER PRIMARY FEES   : " << setw(7) << d3 << endl ;

	int pos = menu_control ( 65 , 17 , 21 , 1 ) ;

	if ( pos == 0 ) return 0 ;

	pos = (pos+2)/2 ;	

	if ( pos == 1 || pos == 2 || pos == 3 )
	{
		gotoxy ( 76 , 25 ) ;
		cout << "** UPDATE FEES **" << endl ;

		gotoxy ( 63 , 26 ) ;
		cout << (char)201 ;
		for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
		cout << (char)187 << endl ;
		for ( j = 0 ; j <= 2 ; ++j )
		{	
			gotoxy ( 63 , 27+j ) ;
			cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
		}
		gotoxy ( 63 , 27+j ) ;
		cout << (char)200 ;
		for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
		cout << (char)188 << endl ;		
	}

	if ( pos == 1 )
	{
		gotoxy ( 64 , 28 ) ;
		cout << "  :: NEW ADMISSION FEES   :          :: " << endl ;
	}
	else if ( pos == 2 )
	{
		gotoxy ( 64 , 28 ) ;
		cout << "  :: NEW LWR PRMRY FEES   :          :: " << endl ;		
	}
	else if ( pos == 3 )
	{
		gotoxy ( 64 , 28 ) ;
		cout << "  :: NEW UPR PRMRY FEES   :          :: " << endl ;		
	}

	while ( data != "done" )
	{
		read_data_continuous ( &data , 96 , 28 , 8 , 1 , &fees ) ;
		if ( data == "-1" )
		{
			return 0 ;
		}
	}

	display_msg_static ( "!! CONFIRM ?? [ Y / N ] !!") ;

	char decision = ' ' ;
	char items[] = { 'Y' , 'N' } ;
	read_char ( &decision , 0 , 0 , items , 2 ) ;

	if ( decision == 'Y' || decision == 'y' ) 
	{
		if ( pos == 1 )
		{
			general_tasks ( "set_adm_fee" , &fees ) ;
		}
		else if ( pos == 2 )
		{
			general_tasks ( "set_lp_fee" , &fees ) ;		
		}
		else if ( pos == 3 )
		{
			general_tasks ( "set_up_fee" , &fees ) ;	
		}	
		return 1 ;
	}	

	return 0 ;

	//cin.get () ;
}