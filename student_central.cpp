#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include <process.h>

using namespace std ;

class student_data ;

extern void gotoxy ( int , int ) ;
extern void header () ;
extern int get_next_adm_no () ;
extern void read_date ( string* data , int x , int y , int max_size , int today , int skip ) ;
extern void read_data ( string* data , int x , int y , int max_size , int number , int skip = 0 ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void read_list ( string* data , int x , int y , string list[] , int size ) ;
extern void change_date_admitted ( int , string ) ;
extern void hit_enter ( int x , int y ) ;
extern int  find_age  ( string data ) ;
extern void fee_student_init ( int admno , char [] , char[] ) ;
extern string get_student_name ( int admno ) ;
extern string get_student_class ( int admno ) ;
extern void display_msg_static ( string ) ;
extern int grab_date ( char [] , char [] ) ;
extern string get_last_payed ( int admno ) ;
extern int menu_control ( int  x , int start_y , int end_y , int esc ) ;
extern void lexi_sort ( char words[][50] , int n ) ;
extern void blink_text ( void* text ) ;
extern int general_tasks ( string , int* data = 0 ) ;
extern void set_news ( string news , int id ) ;

extern int show_student_data_brief ( int admno , int *lp ) ;

extern int next_admno ;
extern bool news_control ;

int new_student_entry () ;
int edit_student_entry () ;
int search_student_entry () ;
int all_student_list () ;
void create_sorted_file ( char[] ) ;

student_data search_student_file ( int* admno ) ;

extern void convert ( string d , char cnvt[] ) ;
extern char sdate[20] ;
extern bool threadFinishPoint ;

struct address
{
	char hname[30] ;
	char place[20] ;
	char post[20] ;
	char pin[10] ;
};

class student_data 
{
public:
	int adm_no ;
	char date_admitted[12] ;
	char skul_name[30] ;

	char student_name[50] ;
	char father_name[50] ;
	char mother_name[50] ;
	char guard_name[50] ;
	char gender ;
	char relation ;

	address addr ;
	char phone[15] ;

	char dob[12] ;
	int age ;

	char class_admitted[5] ;

		student_data () 
		{
			adm_no = 0 ;
			gender = 'M' ;
			relation = 'P' ;
			age = 0 ;
			strcpy ( date_admitted , "NT ASSIGNED"  );
			strcpy ( skul_name , "NT ASSIGNED"  );
			strcpy ( student_name , "NT ASSIGNED"  );
			strcpy ( father_name , "NT ASSIGNED"  );
			strcpy ( mother_name , "NT ASSIGNED"  );
			strcpy ( guard_name , "NT ASSIGNED"  );
			strcpy ( phone , "NT ASSIGNED"  );
			strcpy ( dob , "NT ASSIGNED"  );
			strcpy ( class_admitted , "NT ASSIGNED"  );
			strcpy ( addr.hname , "NT ASSIGNED ");
			strcpy ( addr.place ,"NT ASSIGNED ");
			strcpy ( addr.post , "NT ASSIGNED ");
			strcpy ( addr.pin , "010101" );
		}
		void set_admno ( int d )
		{
			adm_no = d ;
		}
		int get_admno () 
		{
			return adm_no ;
		}
		void set_date_admitted ( string d )
		{
			convert ( d , date_admitted );

		}
		void set_skul_name ( string d )
		{
			convert ( d , skul_name );
		}		
		void set_student_name ( string d )
		{
			convert ( d , student_name );
		}
		void set_student_gender ( string d )
		{
			if ( d == "MALE" )
				gender = 'M' ; 
			else
				gender = 'F' ;
		}		
		void set_father_name ( string d )
		{
			convert ( d , father_name );
		}
		void set_mother_name ( string d )
		{
			convert ( d , mother_name );
		}
		void set_student_relation ( string d )
		{
			if ( d == "FATHER" )
				relation = 'F' ; 
			else if ( d == "MOTHER")
				relation = 'M' ;
			else if ( d == "BROTHER")
				relation = 'B' ;
			else if ( d == "SISTER")
				relation = 'S' ;
			else if ( d == "UNCLE")
				relation = 'U' ;
			else if ( d == "AUNTY")
				relation = 'A' ;
			else
				relation = 'O' ;																			
		}	
		void set_guard_name ( string d )
		{
			convert ( d , guard_name );
		}							
		void set_dob ( string d )
		{
			convert ( d , dob );
		}
		void set_class_admitted ( string d )
		{
			convert ( d , class_admitted );
		}
		void set_addr_hname ( string d )
		{
			convert ( d , addr.hname );
		}		
		void set_addr_place ( string d )
		{
			convert ( d , addr.place );
		}		
		void set_addr_post ( string d )
		{
			convert ( d , addr.post );
		}		
		void set_addr_pin ( string d )
		{
			convert ( d , addr.pin );
		}			
		void set_age ( int d )
		{
			age = d ;
		}		
		void set_phone ( string d )
		{
			convert ( d , phone );
		}
		void full_details_display ()
		{
			gotoxy ( 35 , 14 ) ;
			if ( adm_no < 10 ) cout << "0000" ;
			else if ( adm_no < 100 ) cout << "000" ;
			else if ( adm_no < 10000) cout << "00" ;
			cout << adm_no << endl ;			
			gotoxy ( 35 , 16 ) ; cout << date_admitted << endl ;
			gotoxy ( 35 , 18  ) ; cout << class_admitted << endl ;
			gotoxy ( 35 , 25 ) ; cout << student_name << endl ;
			gotoxy ( 35 , 27 ) ; cout << gender << endl ;
			gotoxy ( 35 , 29 ) ; cout << dob << endl ;
			if ( strcmp ( dob , "NT ASSIGNED") )
				{gotoxy ( 35 , 31 ) ; cout << grab_date ( sdate , "year" ) - grab_date ( dob , "year" ) << endl ;}			
			else
				{gotoxy ( 35 , 31 ) ; cout << 0 << endl ;}			
			gotoxy ( 35 , 33 ) ; cout << skul_name << endl ;
			gotoxy ( 35 , 40 ) ; cout << father_name << endl ;
			gotoxy ( 35 , 42 ) ; cout << mother_name << endl ;
			gotoxy ( 35 , 44 ) ; cout << guard_name << endl ;
			gotoxy ( 35 , 46 ) ; cout << relation << endl ;
			gotoxy ( 124 , 14 ) ; cout << addr.hname << endl ;
			gotoxy ( 124 , 16 ) ; cout << addr.place << endl ;
			gotoxy ( 124 , 18 ) ; cout << addr.post << endl ;
			gotoxy ( 124 , 20 ) ; cout << addr.pin << endl ;
			gotoxy ( 124 , 22 ) ; cout << phone << endl ;
		}
		void list_details_display ( int y )
		{
			gotoxy ( 12 , 18+y ) ;		cout << setw(5) << adm_no << endl ;
			gotoxy ( 25 , 18+y ) ;		cout << student_name << endl ;
			gotoxy ( 70 , 18+y ) ;		cout << setw (3) << class_admitted << endl ;
			gotoxy ( 100 , 18+y ) ;		cout << setw (13) << date_admitted << endl ;
			gotoxy ( 125 , 18+y ) ;		cout << get_last_payed ( adm_no ) << endl ;
		}	
}student_global;

extern void student_central_control ( int choice )
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
			x = new_student_entry () ;
			break ;
		case 2 :
			x = edit_student_entry () ;
			break ;
		case 3 :
			x = search_student_entry () ;
			break ;
		case 4 :
			x = all_student_list () ;
			break ;
		case 5 :
			break ;

	}
}

int new_student_entry ()
{
	student_data s ;

	int i = 0 , j = 0 ;
	string data = "" ;
	char special_encode[12] = "" ;
	data.reserve ( 50 ) ;
	HANDLE h ;

START:
	header();
	gotoxy(75 , 8) ;
	cout<<"NEW STUDENT ENTRY"<<endl;
	gotoxy(74,9);
	for ( i = 1 ; i <= strlen ("NEW STUDENT ENTRY")+1 ; ++i )
		cout<<char(205);		
	cout << endl ;

	gotoxy ( 5 , 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 6 ; ++j )
	{	
		gotoxy ( 5 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 11) ; cout << "** OFFICIAL INFO **" ;
	gotoxy ( 6 , 14 ) ; cout << " >>  ADMISSION NUMBER     : " << endl ;
	gotoxy ( 6 , 16 ) ; cout << " >>  DATE  OF ADMISSION   : " << endl ;
	gotoxy ( 6 , 18 ) ; cout << " >>  CLASS OF ADMISSION   : " << endl ;



	gotoxy ( 5 , 23 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 5 , 24+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 24+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 22) ; cout << "** PERSONAL INFO **" ;
	gotoxy ( 6 , 25 ) ; cout << " >>  STUDENT NAME         : " << endl ;
	gotoxy ( 6 , 27 ) ; cout << " >>  GENDER               : " << endl ;
	gotoxy ( 6 , 29 ) ; cout << " >>  DATE OF BIRTH        : " << endl ;
	gotoxy ( 6 , 31 ) ; cout << " >>  AGE                  : " << endl ;
	gotoxy ( 6 , 33 ) ; cout << " >>  SCHOOL               : " << endl ;



	gotoxy ( 5 , 38 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 8 ; ++j )
	{	
		gotoxy ( 5 , 39+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 39+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 37) ; cout << "** PARENTAL & GUARDIAN INFO **" ;
	gotoxy ( 6 , 40 ) ; cout << " >>  FATHER'S NAME        : " << endl ;
	gotoxy ( 6 , 42 ) ; cout << " >>  MOTHER'S NAME        : " << endl ;
	gotoxy ( 6 , 44 ) ; cout << " >>  GUARDIAN'S NAME      : " << endl ;
	gotoxy ( 6 , 46 ) ; cout << " >>  RELATION             : " << endl ;
   

	gotoxy ( 98, 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 98 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 58 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 98 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 100 , 11) ; cout << "** CONTACT INFO **" ;
	gotoxy ( 101 , 14 ) ; cout << " >>  HOUSE NAME     : " << endl ;
	gotoxy ( 101 , 16 ) ; cout << " >>  CITY / TOWN    : " << endl ;
	gotoxy ( 101 , 18 ) ; cout << " >>  POST OFFICE    : " << endl ;
	gotoxy ( 101 , 20 ) ; cout << " >>  PIN            : " << endl ;
	gotoxy ( 101 , 22 ) ; cout << " >>  PHONE          : " << endl ;

	gotoxy ( 98, 27 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 2 ; ++j )
	{	
		gotoxy ( 98 , 28+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 58 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 98 , 28+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 100 , 26) ; cout << "** SPECIAL STATUS **" ;
	gotoxy ( 101 , 29 ) ; cout << " >>  SPECIAL FEES ? : " << endl ;

	gotoxy ( 35 , 14 ) ;
	if ( next_admno < 10 ) cout << "0000" ;
	else if ( next_admno < 100 ) cout << "000" ;
	else if ( next_admno < 10000) cout << "00" ;
	cout << next_admno << endl ;

	s.set_admno ( next_admno ) ;

	string rltn_list[] = { "FATHER" , "MOTHER" , "BROTHER" , "SISTER" , "UNCLE" , "AUNTY" , "OTHER" } ;

READ_DATE_ADMITTED :
	data = "" ;
	read_date ( &data , 35 , 16 , 10 , 1 , 1 ) ;
	if ( data == "-1" )
	{
		return 0 ;
	}
	s.set_date_admitted ( data ) ;

READ_CLASS :
	data = "" ;
	string list_class[] = { "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" , "11" , "12" } ;
	read_list ( &data , 35 , 18 , list_class , 12 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 16 ) ;
		printf ( "          " ) ;
		goto READ_DATE_ADMITTED;	
	}
	s.set_class_admitted ( data ) ;

READ_STUDENT_NAME:
	data = "" ;
	read_data ( &data , 35 , 25 , 52 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 18 ) ;
		printf ( "  " ) ;		
		goto READ_CLASS;
	}

	s.set_student_name ( data ) ;

READ_STUDENT_GENDER:
	data = "" ;
	string gen_list[] = { "MALE" , "FEMALE" } ;
	read_list ( &data , 35 , 27 , gen_list , 2 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 25 ) ;
		printf ( "                                                      " ) ;			
		goto READ_STUDENT_NAME;		
	}

	else if ( data == "-2" )
		goto READ_DOB ;

	s.set_student_gender ( data ) ;

READ_DOB:
	data = "" ;
	read_date ( &data , 35 , 29 , 10 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 27 ) ;
		printf ( "       " ) ;			
		goto READ_STUDENT_GENDER;		
	}
	else if ( data == "-2" )
	{
		s.set_age ( find_age ( sdate ) ) ;
		goto READ_SKUL ;
	}

	s.set_dob ( data ) ;
	s.set_age ( find_age ( data ) ) ;
	gotoxy ( 35 , 31 ) ; cout << find_age ( data ) << endl ;

READ_SKUL:
	data = "" ;
	read_data ( &data , 35 , 33 , 32 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 29 ) ;
		printf ( "          " ) ;	
		gotoxy ( 35 , 31 ) ;
		printf ( "  " ) ;						
		goto READ_DOB ;			
	}

	else if ( data == "-2" )
		goto READ_FATHER_NAME ;

	s.set_skul_name ( data ) ;

READ_FATHER_NAME:
	data = "" ;
	read_data ( &data , 35 , 40 , 52 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 33 ) ;
		printf ( "                                  " ) ;			
		goto READ_SKUL;			
	}

	else if ( data == "-2" )
		goto READ_MOTHER_NAME ;

	s.set_father_name ( data ) ;

READ_MOTHER_NAME:
	data = "" ;
	read_data ( &data , 35 , 42 , 52 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 40 ) ;
		printf ( "                                            " ) ;			
		goto READ_FATHER_NAME;			
	}

	else if ( data == "-2" )
		goto READ_GUARD_NAME ;

	s.set_mother_name ( data ) ;		

READ_GUARD_NAME:
	data = "" ;
	read_data ( &data , 35 , 44 , 52 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 42 ) ;
		printf ( "                                            " ) ;			
		goto READ_MOTHER_NAME;			
	}

	else if ( data == "-2" )
		goto READ_ADDR_HNAME ;

	s.set_guard_name ( data ) ;	

READ_GUARD_RLTN:
	data = "" ;
	
	read_list ( &data , 35 , 46 , rltn_list , 7 ) 	;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 44 ) ;
		printf ( "                                             " ) ;			
		goto READ_GUARD_NAME;		
	}

	else if ( data == "-2" )
		goto READ_ADDR_HNAME ;

	s.set_student_relation ( data ) ;	

READ_ADDR_HNAME:
	data = "" ;
	read_data ( &data , 124 , 14 , 32 , 0 , 1  ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 46 ) ;
		printf ( "         " ) ;			
		goto READ_GUARD_RLTN;			
	}

	else if ( data == "-2" )
		goto READ_ADDR_PLACE ;

	s.set_addr_hname( data ) ;

READ_ADDR_PLACE:
	data = "" ;
	read_data ( &data , 124 , 16 , 22 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 14 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_HNAME;			
	}

	else if ( data == "-2" )
		goto READ_ADDR_POST ;

	s.set_addr_place ( data ) ;

READ_ADDR_POST:
	data = "" ;
	read_data ( &data , 124 , 18 , 22 , 0 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 16 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_PLACE;			
	}

	else if ( data == "-2" )
		goto READ_ADDR_PIN ; 

	s.set_addr_post ( data ) ;						

READ_ADDR_PIN:
	data = "" ;
	read_data ( &data , 124 , 20 , 8 , 1 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 18 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_POST;			
	}

	else if ( data == "-2" )
		goto READ_PHONE ;

	s.set_addr_pin ( data ) ;

READ_PHONE:
	data = "" ;
	read_data ( &data , 124 , 22 , 13 , 1 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 20 ) ;
		printf ( "                  " ) ;
		goto READ_ADDR_PIN;			
	}

	else if ( data == "-2" )
		goto READ_SPECIAL ;

	s.set_phone ( data ) ;

READ_SPECIAL:
	data = "" ;
	string list[] = { "NO" , "YES" } ;
	read_list ( &data , 124 , 29 , list , 2 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 22 ) ;
		printf ( "               " ) ;			
		goto READ_PHONE;		
	}	

	if ( data == "YES" )
	{
		char temp[5] = "" ;

		strcpy ( special_encode , "1-" ) ;
		gotoxy ( 98, 27 ) ;
		cout << (char)201 ;
		for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
		cout << (char)187 << endl ;

		for ( j = 0 ; j <= 6 ; ++j )
		{	
			gotoxy ( 98 , 28+j ) ;
			cout << (char)186 ;for ( i = 0 ; i <= 58 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
		}
		gotoxy ( 98 , 28+j ) ;
		cout << (char)200 ;
		for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
		cout << (char)188 << endl ;

		gotoxy ( 100 , 26) ; cout << "** SPECIAL STATUS **" ;
		gotoxy ( 101 , 29 ) ; cout << " >>  SPECIAL FEES ? :  " << data << endl ;		
		gotoxy ( 101 , 31 ) ; cout << " >>  ADMISSION FEES :  " << endl ;		
		gotoxy ( 101 , 33 ) ; cout << " >>  TUTION FEES    :  " << endl ;		

		data = "" ;
		read_data ( &data , 124 , 31 , 6 , 1 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 29 ) ;
			printf ( "                  " ) ;
			goto READ_SPECIAL ;			
		}	
		data = data + "-" ;

		convert ( data , temp ) ;
		strcat ( special_encode , temp ) ;

		data = "" ;
		read_data ( &data , 124 , 33 , 6 , 1 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 29 ) ;
			printf ( "                  " ) ;			
			gotoxy ( 124 , 31 ) ;
			printf ( "                  " ) ;
			goto READ_SPECIAL ;			
		}	

		convert ( data , temp ) ;
		strcat ( special_encode , temp ) ;

	}
	else
		strcpy ( special_encode , "0" ) ;

	display_msg_static ( "!! CONFIRM ?? [ Y / N ] !!") ;

	char decision = ' ' ;
	char items[] = { 'Y' , 'N' } ;
	read_char ( &decision , 0 , 0 , items , 2 ) ;

	if ( decision == 'Y' || decision == 'y' ) 
	{
		FILE* fp ;

		fp = fopen ( "stud_db.bin" , "ab+" ) ;

		if ( fp != NULL )
		{
				fwrite( &s , sizeof(student_data) , 1 , fp );
				++next_admno ;
		}

		fclose ( fp ) ;

		fee_student_init ( s.get_admno() , s.date_admitted , special_encode ) ;
		general_tasks ( "set_enroll" ) ;

		threadFinishPoint = false ;
		char text[] = "!!! HIT >> ENTER << TO CONTINUE !!!" ;
		h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
		hit_enter ( 0 , 0 ) ;
		threadFinishPoint = true ;	
		goto START ;
		
		return 1 ;
	}
	else
		goto START ;

	return  0 ;
}

int edit_student_entry()
{
	int i = 0 , j = 0 , lp = 0 ;
	int adm = 0 ;

	string data = "" ;
	HANDLE h ;

START:
	header();
	gotoxy(75 , 8) ;
	cout<<"EDIT STUDENT ENTRY"<<endl;
	gotoxy(74,9);
	for ( i = 1 ; i <= strlen ("EDIT STUDENT ENTRY")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;

	gotoxy ( 5 , 10 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 30 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	gotoxy ( 6 , 11 ) ;
	cout << " >> ADMISSION NUMBER :  " ;

	gotoxy ( 5 , 12 ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 30 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 73 , 14 ) ; cout << "||| SEARCH RESULTS |||"<<endl ;

	data = "" ;
	adm = 0 ;
	lp = 0 ;

	while ( data != "done" )
	{
		read_data_continuous ( &data , 30 , 11 , 8 , 1 , &adm ) ;
		if ( data == "-1" )
		{
			return 0 ;
		}

		int found =	show_student_data_brief ( adm , &lp ) ;

		if ( !found )
			data = "" ;

	}

DISPLAY:
	header();
	gotoxy(74 , 8) ;
	cout<<"SEARCH STUDENT ENTRY"<<endl;
	gotoxy(73,9);
	for ( i = 1 ; i <= strlen ("SEARCH STUDENT ENTRY")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;


	gotoxy ( 5 , 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 6 ; ++j )
	{	
		gotoxy ( 5 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 11) ; cout << "** OFFICIAL INFO **" ;
	gotoxy ( 6 , 14 ) ; cout << " >>  ADMISSION NUMBER     : " << endl ;

	if ( get_last_payed(student_global.adm_no) == "ADM FEES NT PAID" )
	{ 
		gotoxy ( 6 , 16 ) ; cout << " A:  DATE  OF ADMISSION   : " << endl ;
	}
	else
	{
		gotoxy ( 6 , 16 ) ; cout << "     DATE  OF ADMISSION   : " << endl ;
	}

	gotoxy ( 6 , 18 ) ; cout << " B:  CLASS OF ADMISSION   : " << endl ;



	gotoxy ( 5 , 23 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 5 , 24+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 24+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 22) ; cout << "** PERSONAL INFO **" ;
	gotoxy ( 6 , 25 ) ; cout << " C:  STUDENT NAME         : " << endl ;
	gotoxy ( 6 , 27 ) ; cout << " D:  GENDER               : " << endl ;
	gotoxy ( 6 , 29 ) ; cout << " E:  DATE OF BIRTH        : " << endl ;
	gotoxy ( 6 , 31 ) ; cout << " >>  AGE                  : " << endl ;
	gotoxy ( 6 , 33 ) ; cout << " F:  SCHOOL               : " << endl ;



	gotoxy ( 5 , 38 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 8 ; ++j )
	{	
		gotoxy ( 5 , 39+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 39+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 37) ; cout << "** PARENTAL & GUARDIAN INFO **" ;
	gotoxy ( 6 , 40 ) ; cout << " G:  FATHER'S NAME        : " << endl ;
	gotoxy ( 6 , 42 ) ; cout << " H:  MOTHER'S NAME        : " << endl ;
	gotoxy ( 6 , 44 ) ; cout << " I:  GUARDIAN'S NAME      : " << endl ;
	gotoxy ( 6 , 46 ) ; cout << " J:  RELATION             : " << endl ;
   

	gotoxy ( 98, 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 98 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 58 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 98 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 100 , 11) ; cout << "** CONTACT INFO **" ;
	gotoxy ( 101 , 14 ) ; cout << " K:  HOUSE NAME     : " << endl ;
	gotoxy ( 101 , 16 ) ; cout << " L:  CITY / TOWN    : " << endl ;
	gotoxy ( 101 , 18 ) ; cout << " M:  POST OFFICE    : " << endl ;
	gotoxy ( 101 , 20 ) ; cout << " N:  PIN            : " << endl ;
	gotoxy ( 101 , 22 ) ; cout << " O:  PHONE          : " << endl ;

	student_global.full_details_display () ;

	display_msg_static ("--- ENTER THE FIELD NUMBER TO EDIT ---") ;

	char decision = ' ' ;

	if ( get_last_payed(student_global.adm_no) != "ADM FEES NT PAID" )
	{ 
		char items[] = { 'B' , 'C', 'D' , 'E' , 'F' , 'G', 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O'  } ;
		read_char ( &decision , 0 , 0 , items , 14 ) ;
	}
	else
	{
		char items[] = { 'A' , 'B' , 'C', 'D' , 'E' , 'F' , 'G', 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O'  } ;
		read_char ( &decision , 0 , 0 , items , 15 ) ;
	}

	if ( decision == '0' )
		return 0 ;

	if ( decision == 'A' || decision == 'a' ) 
	{
		gotoxy ( 35 , 16 ) ;
		printf("          ") ;
		data = "" ;
		read_date ( &data , 35 , 16 , 10 , 1 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 16 ) ;
			cout << student_global.date_admitted << endl ;		
			goto DISPLAY;
		}
		student_global.set_date_admitted ( data ) ;		
	}
	else if ( decision == 'B' || decision == 'b' ) 
	{
		gotoxy ( 35 , 18 ) ;
		printf("          ") ;
		data = "" ;
		string list_class[] = { "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" , "11" , "12" } ;
		read_list ( &data , 35 , 18 , list_class , 12 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 18 ) ;
			cout << student_global.class_admitted << endl ;
			goto DISPLAY ;
		}
		student_global.set_class_admitted ( data ) ;
	}
	else if ( decision == 'C' || decision == 'c' ) 
	{
		gotoxy ( 35 , 25 ) ;
		printf("                                    ") ;
		data = "" ;
		read_data ( &data , 35 , 25 , 52 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 25 ) ;
			cout << student_global.student_name << endl ;		
			goto DISPLAY;
		}
		student_global.set_student_name ( data ) ;		
	}
	else if ( decision == 'D' || decision == 'd' ) 
	{
		gotoxy ( 35 , 27 ) ;
		printf("      ") ;
		data = "" ;
		string gen_list[] = { "MALE" , "FEMALE" } ;
		read_list ( &data , 35 , 27 , gen_list , 2 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 27 ) ;
			cout << student_global.gender << endl ;
			goto DISPLAY ;		
		}
		student_global.set_student_gender ( data ) ;
	}
	else if ( decision == 'E' || decision == 'e' ) 
	{
		gotoxy ( 35 , 29 ) ;
		printf("          ") ;
		data = "" ;
		read_date ( &data , 35 , 29 , 10 , 0 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 29 ) ;
			cout << student_global.dob << endl ;
			goto DISPLAY ;
		}
		student_global.set_dob ( data ) ;
		student_global.set_age ( find_age ( data ) ) ;
		gotoxy ( 35 , 31 ) ; cout << find_age ( data ) << endl ;
	}
	else if ( decision == 'F' || decision == 'f' ) 
	{
		gotoxy ( 35 , 33 ) ;
		printf("                                    ") ;
		data = "" ;
		read_data ( &data , 35 , 33 , 32 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 33 ) ;
			cout << student_global.skul_name << endl ;
			goto DISPLAY ;			
		}
		student_global.set_skul_name ( data ) ;
	}
	else if ( decision == 'G' || decision == 'g' ) 
	{
		gotoxy ( 35 , 40 ) ;
		printf("                                    ") ;
		data = "" ;
		read_data ( &data , 35 , 40 , 52 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 40 ) ;
			cout << student_global.father_name << endl ;
			goto DISPLAY;			
		}
		student_global.set_father_name ( data ) ;
	}
	else if ( decision == 'H' || decision == 'h' ) 
	{
		gotoxy ( 35 , 42 ) ;
		printf("                                    ") ;
		data = "" ;
		read_data ( &data , 35 , 42 , 52 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 42 ) ;
			cout << student_global.mother_name << endl ;
			goto DISPLAY;			
		}
		student_global.set_mother_name ( data ) ;
	}
	else if ( decision == 'I' || decision == 'i' ) 
	{
		gotoxy ( 35 , 44) ;
		printf("                                    ") ;
		data = "" ;
		read_data ( &data , 35 , 44 , 52 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 44 ) ;
			cout << student_global.guard_name << endl ;
			goto DISPLAY ;
		}
		student_global.set_guard_name ( data ) ;	
	}
	else if ( decision == 'J' || decision == 'j' ) 
	{
		gotoxy ( 35 , 46 ) ;
		printf("          ") ;
		data = "" ;
		string rltn_list[] = { "FATHER" , "MOTHER" , "BROTHER" , "SISTER" , "UNCLE" , "AUNTY" , "OTHER" } ;
		read_list ( &data , 35 , 46 , rltn_list , 7 ) 	;
		if ( data == "-1" )
		{
			gotoxy ( 35 , 46 ) ;
			cout << student_global.relation << endl ;
			goto DISPLAY ;
		}
		student_global.set_student_relation ( data ) ;
	}
	else if ( decision == 'K' || decision == 'k' ) 
	{
		gotoxy ( 124 , 14 ) ;
		printf("                               ") ;
		data = "" ;
		read_data ( &data , 124 , 14 , 32 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 14 ) ;
			cout << student_global.addr.hname << endl ;
			goto DISPLAY ;			
		}
		student_global.set_addr_hname( data ) ;
	}
	else if ( decision == 'L' || decision == 'l' ) 
	{
		gotoxy ( 124 , 16 ) ;
		printf("                               ") ;
		data = "" ;
		read_data ( &data , 124 , 16 , 22 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 16 ) ;
			cout << student_global.addr.place << endl ;
			goto DISPLAY ;			
		}
		student_global.set_addr_place ( data ) ;
	}
	else if ( decision == 'M' || decision == 'm' ) 
	{
		gotoxy ( 124 , 18 ) ;
		printf("                               ") ;
		data = "" ;
		read_data ( &data , 124 , 18 , 22 , 0 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 18 ) ;
			cout << student_global.addr.post << endl ;		
			goto DISPLAY ;
		}
		student_global.set_addr_post ( data ) ;
	}
	else if ( decision == 'N' || decision == 'n' ) 
	{
		gotoxy ( 124 , 20 ) ;
		printf("          ") ;
		data = "" ;
		read_data ( &data , 124 , 20 , 8 , 1 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 20 ) ;
			cout << student_global.addr.pin << endl ;		
			goto DISPLAY ;	
		}
		student_global.set_addr_pin ( data ) ;
	}													
	else if ( decision == 'O' || decision == 'o' ) 
	{
		gotoxy ( 124 , 22 ) ;
		printf("              ") ;
		data = "" ;
		read_data ( &data , 124 , 22 , 13 , 1 ) ;
		if ( data == "-1" )
		{
			gotoxy ( 124 , 22 ) ;
			cout << student_global.phone << endl ;		
			goto DISPLAY ;			
		}
		student_global.set_phone ( data ) ;
	}

	display_msg_static ( "          !! CONFIRM ?? [ Y / N ] !!          ") ;

	char dcsn = ' ' ;
	char Items[] = { 'Y' , 'N' } ;
	read_char ( &dcsn , 0 , 0 , Items , 2 ) ;

	if ( dcsn == 'Y' || dcsn == 'y' ) 
	{
		student_data x ;
		int y = 1 ;

		fstream oldfile ;
		fstream newfile ;
		oldfile.open ( "stud_db.bin" , ios::in | ios::binary ) ;
		newfile.open ( "temp.bin" , ios::out | ios::binary ) ;

		while ( y < next_admno )
		{
			oldfile.read (( char* ) &x , sizeof(student_data) ) ;
			if ( x.adm_no == student_global.adm_no )
			{
				x = student_global ;
			}
			newfile.write (( char* ) &x , sizeof ( student_data ) ) ;
			++y ;
		}
		oldfile.close() ;
		newfile.close() ;

		remove ( "stud_db.bin" );
		system ( "rename temp.bin stud_db.bin" );

		if ( decision == 'a' || decision == 'A' )
		{
			change_date_admitted ( student_global.adm_no , data ) ;
		}

		threadFinishPoint = false ;
		char text[] = "    !!! HIT >> ENTER << TO CONTINUE !!!    " ;
		h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
		hit_enter ( 0 , 0 ) ;
		threadFinishPoint = true ;	
		goto START ;
		
		return 1 ;
	}
	else
		goto START ;


	return  0 ;
}

int search_student_entry()
{
	int i = 0 , j = 0 , lp = 0 ;
	int adm = 0 ;

	string data = "" ;
	HANDLE h ;

START:
	header();
	gotoxy(74 , 8) ;
	cout<<"SEARCH STUDENT ENTRY"<<endl;
	gotoxy(73,9);
	for ( i = 1 ; i <= strlen ("SEARCH STUDENT ENTRY")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;

	gotoxy ( 5 , 10 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 30 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	gotoxy ( 6 , 11 ) ;
	cout << " >> ADMISSION NUMBER :  " ;

	gotoxy ( 5 , 12 ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 30 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 73 , 14 ) ; cout << "||| SEARCH RESULTS |||"<<endl ;

	data = "" ;
	adm = 0 ;
	lp = 0 ;

	while ( data != "done" )
	{
		read_data_continuous ( &data , 30 , 11 , 8 , 1 , &adm ) ;
		if ( data == "-1" )
		{
			return 0 ;
		}

		int found =	show_student_data_brief ( adm , &lp ) ;

		if ( !found )
			data = "" ;

	}

	header();
	gotoxy(74 , 8) ;
	cout<<"SEARCH STUDENT ENTRY"<<endl;
	gotoxy(73,9);
	for ( i = 1 ; i <= strlen ("SEARCH STUDENT ENTRY")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;


	gotoxy ( 5 , 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 6 ; ++j )
	{	
		gotoxy ( 5 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 11) ; cout << "** OFFICIAL INFO **" ;
	gotoxy ( 6 , 14 ) ; cout << " >>  ADMISSION NUMBER     : " << endl ;
	gotoxy ( 6 , 16 ) ; cout << " >>  DATE  OF ADMISSION   : " << endl ;
	gotoxy ( 6 , 18 ) ; cout << " >>  CLASS OF ADMISSION   : " << endl ;



	gotoxy ( 5 , 23 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 5 , 24+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 24+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 22) ; cout << "** PERSONAL INFO **" ;
	gotoxy ( 6 , 25 ) ; cout << " >>  STUDENT NAME         : " << endl ;
	gotoxy ( 6 , 27 ) ; cout << " >>  GENDER               : " << endl ;
	gotoxy ( 6 , 29 ) ; cout << " >>  DATE OF BIRTH        : " << endl ;
	gotoxy ( 6 , 31 ) ; cout << " >>  AGE                  : " << endl ;
	gotoxy ( 6 , 33 ) ; cout << " >>  SCHOOL               : " << endl ;



	gotoxy ( 5 , 38 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 8 ; ++j )
	{	
		gotoxy ( 5 , 39+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 85 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 5 , 39+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 85 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 7 , 37) ; cout << "** PARENTAL & GUARDIAN INFO **" ;
	gotoxy ( 6 , 40 ) ; cout << " >>  FATHER'S NAME        : " << endl ;
	gotoxy ( 6 , 42 ) ; cout << " >>  MOTHER'S NAME        : " << endl ;
	gotoxy ( 6 , 44 ) ; cout << " >>  GUARDIAN'S NAME      : " << endl ;
	gotoxy ( 6 , 46 ) ; cout << " >>  RELATION             : " << endl ;
   

	gotoxy ( 98, 12 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 10 ; ++j )
	{	
		gotoxy ( 98 , 13+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 58 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 98 , 13+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 58 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 100 , 11) ; cout << "** CONTACT INFO **" ;
	gotoxy ( 101 , 14 ) ; cout << " >>  HOUSE NAME     : " << endl ;
	gotoxy ( 101 , 16 ) ; cout << " >>  CITY / TOWN    : " << endl ;
	gotoxy ( 101 , 18 ) ; cout << " >>  POST OFFICE    : " << endl ;
	gotoxy ( 101 , 20 ) ; cout << " >>  PIN            : " << endl ;
	gotoxy ( 101 , 22 ) ; cout << " >>  PHONE          : " << endl ;

	student_global.full_details_display () ;

	threadFinishPoint = false ;
	char text[] = "!!! HIT >> ENTER << TO CONTINUE !!!" ;
	h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
	hit_enter ( 0 , 0 ) ;
	threadFinishPoint = true ;	

	return  0 ;
}

int all_student_list () 
{
	int i = 0 , j = 0 , y = 1 ;
	student_data s ;
	fstream file ;
	HANDLE h ;

	header();
	gotoxy(76 , 8) ;
	cout<<"ALL STUDENT LIST"<<endl;
	gotoxy(75,9);
	for ( i = 1 ; i <= strlen ("ALL STUDENT LIST")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;

	gotoxy ( 12 , 14 ) ; cout << "-- SORTING METHOD -- " << endl ;
	gotoxy ( 14 , 15 ) ;	for ( i = 1 ; i <= 16 ; ++i ) cout << (char)196 ; cout << endl ;
	gotoxy ( 12 , 17 ) ; cout << "    ADMISSION NUMBER" << endl ;
	gotoxy ( 12 , 19 ) ; cout << "    NAME" << endl ;
	gotoxy ( 12 , 21 ) ; cout << "    CLASS" << endl ;
	
	int pos = menu_control ( 11 , 17 , 21 , 1 ) ;

	if ( pos == -1 ) return 0 ;

	pos = ( pos+2 ) / 2 ;

	if ( pos == 1 ) file.open ( "stud_db.bin" , ios :: in | ios :: binary ) ;

	if ( pos == 2 ) create_sorted_file ( "name" ) ;

	if ( pos == 3 ) create_sorted_file ( "class" ) ;

	if ( pos == 2 || pos == 3 )
		file.open ( "temp.bin" , ios :: in | ios :: binary ) ;
START:
	header();
	gotoxy(76 , 8) ;
	cout<<"ALL STUDENT LIST"<<endl;
	gotoxy(75,9);
	for ( i = 1 ; i <= strlen ("ALL STUDENT LIST")+2 ; ++i )
		cout<<char(205);		
	cout << endl ;

	gotoxy ( 9 , 12 ) ;
	for ( i = 1 ; i <= 149 ; ++i )
		cout << (char)196 ;
	cout << endl ;

	gotoxy ( 9 , 16 ) ;
	for ( i = 1 ; i <= 149 ; ++i )
		cout << (char)196 ;
	cout << endl ;	

	gotoxy ( 128 , 10 ) ;
	cout << ">> TOTAL STUDENTS :: " << next_admno-1 << " ::" << endl ;

	gotoxy ( 12 , 14 ) ;
	cout << "ADM NO." << endl ;

	gotoxy ( 25 , 14 ) ;
	cout << "NAME" << endl ;

	gotoxy ( 70 , 14 ) ;
	cout << "CLASS" << endl ;	

	gotoxy ( 100 , 14 ) ;
	cout << "DATE OF ADMISSION" << endl ;

	gotoxy ( 125 ,14 ) ;
	cout << "FEE LAST PAYED" << endl ;

	int pos_index = 1 ;
	while ( y < next_admno )
	{	
		file.read ( ( char* )&s , sizeof (student_data) ) ;
		s.list_details_display ( (pos_index-1)*2 ) ;
		++pos_index ;
		++y ;
		if ( y % 16 == 0  && y < next_admno ) 
		{
			display_msg_static ( "!!! HIT >> ENTER << TO VIEW MORE !!!") ;
			hit_enter ( 0 , 0 ) ;

			goto START ;
		}
	}
	file.close () ;

	remove ( "temp.bin" ) ;

	threadFinishPoint = false ;
	char text[] = "!!! HIT >> ENTER << TO CONTINUE !!!" ;
	h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
	hit_enter ( 0 , 0 ) ;
	threadFinishPoint = true ;	

	return  0 ;
}

extern int get_next_adm_no ()
{
	int x = 0 ;

	student_data s ;

	FILE* fp ;

	fp = fopen ( "stud_db.bin" , "rb+" ) ;

	int len = 0 ;

	if ( fp != NULL )
	{		
		fseek ( fp , 0 , SEEK_END ) ;
		len = ftell ( fp ) ;
	}

	fclose ( fp ) ;
	x = ( len / sizeof ( student_data ) ) ;
	++x ;
	return x ;
}

student_data search_student_file ( int* admno )
{
	student_data s ;
	int y = 1 ;

	if ( *admno >= next_admno ) 
	{
		*admno = -1 ;
		return s ;
	}

	fstream file ;

	file.open ( "stud_db.bin" , ios::in | ios::binary ) ;

	file.seekg ( (*admno-1)*sizeof(student_data) , ios::beg ) ; 

	file.read ((char*)&s , sizeof(student_data) ) ;

	file.close () ;	
	
	return s ;

}

extern int show_student_data_brief ( int admno , int* lp ) 
{
	static int clean = 0 ;

	student_data s ;

	if ( admno )
	{
		s = search_student_file ( &admno ) ;
		student_global = s ;
	}

	if ( clean == 1 )
	{
		gotoxy ( 70 , 17 ) ;
		printf ("                             ") ;
		if ( admno == 0 ) clean = 0 ;		
	}
	if ( clean == 2 )
	{
		gotoxy ( 6 , 16 ) ;
		printf ("                                                                                       ") ;
		gotoxy ( 6 , 18 ) ;
		printf ("                                  ") ;
		gotoxy ( 6 , 20 ) ;
		printf ("                                      ") ;
		gotoxy ( 90 , 18 ) ;
		printf ("                                                   ") ;
		if ( admno == 0 ) clean = 0 ;
	}

	if ( admno == 0 ) return 0 ;



	if ( admno == -1 ) 
	{
		threadFinishPoint = false ;
		_beginthread ( blink_text , 0 , (char*)"***** STUDENT NOT FOUND *****" ) ;		
		clean = 1 ;
		return 0 ;
	}
	else
	{
		gotoxy ( 6 , 16 ) ;
		cout << "** NAME :                  " << s.student_name << endl ;
		gotoxy ( 6 , 18 ) ;
		cout << "** CLASS :                 " << s.class_admitted << endl ;
		gotoxy ( 6 , 20 ) ;
		cout << "** DATE OF ADMISSION :     " << s.date_admitted << endl ;

		if ( !strcmp ( s.class_admitted , "1" ) || !strcmp ( s.class_admitted , "2" ) || !strcmp ( s.class_admitted , "3" ) || !strcmp ( s.class_admitted , "4" ))	
			*lp = 1 ;
		else
			*lp = 0 ;	
		clean = 2 ;
		return 1 ;
	}

}

extern string get_student_name ( int admno ) 
{
	string name = "" ;
	student_data s ;
	fstream file ;
	file.open ( "stud_db.bin" , ios::in | ios::binary ) ;

	file.seekg ( (admno-1)*sizeof(student_data) , ios::beg ) ; 

	file.read ((char*)&s , sizeof(student_data) ) ;

	file.close () ;

	name = s.student_name ;
	return name ;
}

extern string get_student_class ( int admno ) 
{
	string Class = "" ;
	student_data s ;
	fstream file ;
	file.open ( "stud_db.bin" , ios::in | ios::binary ) ;

	file.seekg ( (admno-1)*sizeof(student_data) , ios::beg ) ; 

	file.read ((char*)&s , sizeof(student_data) ) ;

	file.close () ;

	Class = s.class_admitted ;
	return Class ;	
}

void create_sorted_file ( char type[] )
{
	int z = 1 , i = 0 , size = 0 ;
	fstream newfile , oldfile ;
	newfile.open ( "temp.bin" , ios::out | ios::binary ) ;
	oldfile.open ( "stud_db.bin" , ios::in | ios::binary ) ;

	student_data x , y ;

	char list[][5] = { "1" , "2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"11" ,"12" } ;

	if ( !strcmp ( type , "name") )
	{
		char names[next_admno][50] ;

		z = 1 ;
		i = 0 ;

		while ( z < next_admno )
		{
			oldfile.read ((char*)&x , sizeof ( student_data )) ;
			strcpy ( names[i++] , x.student_name ) ;
			++z ;
		}		

		size = i ;

		lexi_sort ( names , size ) ; 

		i = 0 ;

		while ( i < size )
		{
			oldfile.seekg( 0 , ios::beg ) ;
			z = 1 ;
			while ( z < next_admno )
			{
				oldfile.read ((char*)&x , sizeof ( student_data )) ;
				if ( !strcmp ( x.student_name , names[i] ))
				{
					newfile.write ((char*)&x , sizeof ( student_data )) ;
					break ;
				}
				++z ;
			}
			++i ;

		}

		newfile.close () ;
		oldfile.close () ;
	}

	else if ( !strcmp ( type , "class") )
	{
		int i = 0 ;
		while ( i < 12 )
		{
			oldfile.seekg( 0 , ios::beg ) ;
			z = 1 ;
			while ( z < next_admno )
			{
				oldfile.read ((char*)&x , sizeof ( student_data )) ;

				if ( !strcmp ( x.class_admitted , list[i]))
					newfile.write ((char*)&x , sizeof ( student_data )) ;

				++z ;
			}

			++i ;
		}
		newfile.close () ;
		oldfile.close () ;
	}
}