#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <process.h>

using namespace std ;

extern void header () ;
extern void gotoxy ( int , int ) ;
extern void  authenticate ( char login_entered[] ) ;
extern void write_login_details ( char user[] , char pwd[] ) ;
extern int  menu_control ( int , int , int , int esc = 0 ) ;
extern void general_tasks ( string , int* data = 0 ) ;
extern void read_data ( char data[] , int x , int y , int max_size , int special ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void display_msg_static ( string msg )  ;
extern void hit_enter ( int x , int y ) ;
extern void blink_text ( void* text ) ;
extern void set_news ( string news , int id ) ;

extern void admin_central_control ( int ) ;
extern bool threadFinishPoint ;
extern bool news_control ;

extern char sdate[20] ;
extern char stime[20] ;

int change_fee_structure () ;
int change_login_credits () ;
void create_backup () ;

extern void admin_central_control ( int choice ) 
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
			x = change_login_credits () ;
			break ;
		case 2 :
			x = change_fee_structure () ;			
			break ;
		case 3 :
			create_backup () ;
			return ;
		case 4 :
			return ;

	}	
}


int change_fee_structure () 
{
	int i = 0 , j = 0 ;
	int d1 = 0 , d2 = 0 , d3 = 0 , fees = 0 ;
	string data = "" ;
	HANDLE h ;

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

	if ( pos == -1 ) return 0 ;

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
		threadFinishPoint = false ;
		char text[] = "!!!===== FEE STRUCTURE UPDATED =====!!!" ;
		h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
		hit_enter ( 0 , 0 ) ;
		threadFinishPoint = true ;				
		return 1 ;
	}	

	return 0 ;

}

int change_login_credits () 
{
	int i = 0 , j = 0 ;
	char username[100] = "" , password[100] = "" , pwd[100] = "" , login_entered[200] = "" ;
	HANDLE h ;

	header();
	gotoxy(72 , 8) ;
	cout<<"CHANGE LOGIN CREDENTIALS"<<endl;
	gotoxy(71,9);
	for ( i = 1 ; i <= strlen ("CHANGE LOGIN CREDENTIALS")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;		

	gotoxy ( 63 , 15 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;
	for ( j = 0 ; j <= 12 ; ++j )
	{	
		gotoxy ( 63 , 16+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 63 , 16+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 64 , 17 ) ; cout << "   CURRENT USERNAME  : " << endl ;	
	gotoxy ( 64 , 19 ) ; cout << "   CURRENT PASSWORD  : " << endl ;
	gotoxy ( 66 , 21 ) ; for ( i = 0 ; i < 37 ; ++i ) cout << (char)196 ; cout << endl ;
	gotoxy ( 64 , 23 ) ; cout << "   NEW USERNAME      : " << endl ;
	gotoxy ( 64 , 25 ) ; cout << "   NEW PASSWORD      : " << endl ;
	gotoxy ( 64 , 27 ) ; cout << "   CONFIRM PASSWORD  : " << endl ;

	read_data ( username , 87 , 17 , 20 , 0 ) ;	

	if ( !strcmp ( username , "-1" ) ) return 0 ;

	read_data ( password , 87 , 19 , 20 , 1 ) ;

	strcpy ( login_entered , username ) ;
	strcat ( login_entered , " " ) ;
	strcat ( login_entered , password ) ;	

	strcpy ( username , "" ) ;
	strcpy ( password , "" ) ;

	read_data ( username , 87 , 23 , 20 , 0 ) ;	
	read_data ( password , 87 , 25 , 20 , 1 ) ;
	read_data ( pwd , 87 , 27 , 20 , 1 ) ;	

	authenticate ( login_entered ) ;

	char text[100] = "" ;

	if ( !strcmp ( login_entered , "success") && !strcmp ( password , pwd ) )
	{
		write_login_details ( username , password ) ;
		strcpy ( text ,  "===== LOGIN CREDENTIALS CHANGED SUCCESSFULLY =====" ) ;
	}
	else
		strcpy ( text , "===== LOGIN CREDENTIALS CHANGE FAILED =====" );

	threadFinishPoint = false ;
	h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
	hit_enter ( 0 , 0 ) ;
	threadFinishPoint = true ;		

	return 0 ;
}

void create_backup () 
{
	char fname[15] = "" , text[200] = "" ;
	int i = 0 , j = 0 ;

	for ( i = 0 ; sdate[i] != '\0' ; ++i )
		if ( isdigit ( sdate[i] ) )
			fname[j++] = sdate [i] ;

	for ( i = 0 ; stime[i] != '\0' ; ++i )
		if ( isdigit ( stime[i] ) )
			fname[j++] = stime[i] ;

	fname[j] = '\0' ;
	char dir[30] = "C:\\BACKUP\\" ;
	strcat ( dir , fname ) ;

	char cmd[70] = "mkdir " ;
	strcat ( cmd , dir ) ;
	system ( cmd ) ;


	strcpy ( cmd , "copy /Y " ) ;
	strcat ( cmd , "gen_db.bin ") ;
	strcat ( cmd , dir ) ;
	strcat ( cmd , " > t.txt") ;
	system ( cmd ) ;

	strcpy ( cmd , "copy /Y " ) ;
	strcat ( cmd , "stud_db.bin ") ;
	strcat ( cmd , dir ) ;
	strcat ( cmd ," > t.txt") ;
	system ( cmd ) ;

	strcpy ( cmd , "copy /Y " ) ;
	strcat ( cmd , "fee_db.bin ") ;
	strcat ( cmd , dir ) ;
	strcat ( cmd ," > t.txt") ;
	system ( cmd ) ;		

	strcpy ( text , "!!! << BACKUP CREATED SUCCESSFULLY >> !!!") ;

	remove ( "t.txt" ) ;
	threadFinishPoint = false ;
	HANDLE h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
	hit_enter ( 0 , 0 ) ;
	threadFinishPoint = true ;		

}