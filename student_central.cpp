#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std ;

extern void gotoxy ( int , int ) ;
extern void header () ;
extern int get_next_adm_no () ;
extern void read_date ( string* data , int x , int y , int max_size , int today ) ;
extern void read_data ( string* data , int x , int y , int max_size , int special ) ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void read_list ( string* data , int x , int y , string list[] , int size ) ;
extern int  find_age  ( string data ) ;

extern int next_admno ;

int new_student_entry () ;
int edit_student_entry () ;
int search_student_entry () ;
int student_mark_entry () ;

struct address
{
	string hname ;
	string place ;
	string post ;
	string pin ;
};

class student_data 
{
		int adm_no ;
		string date_admitted ;
		string skul_name ;

		string student_name ;
		string father_name ;
		string mother_name ;
		string guard_name ;
		char gender ;
		char relation ;

		address addr ;
		string phone ;

		string dob ;
		int age ;

		string class_admitted ;
	
	public :		
		student_data () 
		{
			adm_no = 0 ;
			gender = 'M' ;
			relation = 'P' ;
			age = 0 ;
			date_admitted = "NT ASSIGNED" ;
			skul_name = "NT ASSIGNED" ;
			student_name = "NT ASSIGNED" ;
			father_name = "NT ASSIGNED" ;
			mother_name = "NT ASSIGNED" ;
			guard_name = "NT ASSIGNED" ;
			phone = "NT ASSIGNED" ;
			dob = "NT ASSIGNED" ;
			class_admitted = "NT ASSIGNED" ;
			addr.hname = "NT ASSIGNED";
			addr.place = "NT ASSIGNED";
			addr.post = "NT ASSIGNED";
			addr.pin = "010101" ;
			date_admitted.reserve(12) ;
			skul_name.reserve(30) ;
			student_name.reserve(50) ;
			father_name.reserve(50) ;
			mother_name.reserve(50) ;
			guard_name.reserve(50) ;
			phone.reserve(15) ;
			dob.reserve(12) ;
			class_admitted.reserve(5) ;	
			addr.hname.reserve (30) ;
			addr.place.reserve (20) ;
			addr.post.reserve (20)  ;
			addr.pin.reserve(10) ;
		}
		void set_admno ( int d )
		{
			adm_no = d ;
		}
		void set_date_admitted ( string d )
		{
			date_admitted.assign(d) ;
		}
		void set_skul_name ( string d )
		{
			skul_name.assign (d) ;
		}		
		void set_student_name ( string d )
		{
			student_name.assign(d) ;
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
			father_name.assign(d) ;
		}
		void set_mother_name ( string d )
		{
			mother_name.assign(d) ;
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
			guard_name.assign(d) ;
		}							
		void set_dob ( string d )
		{
			dob.assign(d) ;
		}
		void set_class_admitted ( string d )
		{
			class_admitted.assign(d) ;
		}
		void set_addr_hname ( string d )
		{
			addr.hname.assign(d) ;
		}		
		void set_addr_place ( string d )
		{
			addr.place.assign(d) ;
		}		
		void set_addr_post ( string d )
		{
			addr.post.assign(d) ;
		}		
		void set_addr_pin ( string d )
		{
			addr.pin = d ;
		}			
		void set_age ( int d )
		{
			age = d ;
		}		
		void set_phone ( string d )
		{
			phone.assign ( d ) ;
		}	
};


extern void student_central_control ( int choice )
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
			x = new_student_entry () ;
			break ;
		case 2 :

			break ;
		case 3 :
			break ;
		case 4 :
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
	data.reserve ( 50 ) ;

	header();
	gotoxy(75 , 8) ;
	cout<<"NEW STUDENT ENTRY"<<endl;
	gotoxy(74,9);
	for ( i = 1 ; i <= strlen ("NEW STUDENT ENTRY")+1 ; ++i )
		cout<<char(205);		//11
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


	gotoxy ( 35 , 14 ) ;
	if ( next_admno < 10 ) cout << "0000" ;
	else if ( next_admno < 100 ) cout << "000" ;
	else if ( next_admno < 10000) cout << "00" ;
	cout << next_admno << endl ;

	s.set_admno ( next_admno ) ;

READ_DATE_ADMITTED :
	data = "" ;
	read_date ( &data , 35 , 16 , 10 , 1 ) ;
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
	s.set_student_gender ( data ) ;

READ_DOB:
	data = "" ;
	read_date ( &data , 35 , 29 , 10 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 27 ) ;
		printf ( "       " ) ;			
		goto READ_STUDENT_GENDER;		
	}
	s.set_dob ( data ) ;
	s.set_age ( find_age ( data ) ) ;
	gotoxy ( 35 , 31 ) ; cout << find_age ( data ) << endl ;

READ_SKUL:
	data = "" ;
	read_data ( &data , 35 , 33 , 32 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 29 ) ;
		printf ( "          " ) ;			
		goto READ_DOB ;			
	}
	s.set_skul_name ( data ) ;

READ_FATHER_NAME:
	data = "" ;
	read_data ( &data , 35 , 40 , 52 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 33 ) ;
		printf ( "                                  " ) ;			
		goto READ_SKUL;			
	}
	s.set_father_name ( data ) ;

READ_MOTHER_NAME:
	data = "" ;
	read_data ( &data , 35 , 42 , 52 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 40 ) ;
		printf ( "                                            " ) ;			
		goto READ_FATHER_NAME;			
	}
	s.set_mother_name ( data ) ;		

READ_GUARD_NAME:
	data = "" ;
	read_data ( &data , 35 , 44 , 52 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 42 ) ;
		printf ( "                                            " ) ;			
		goto READ_MOTHER_NAME;			
	}
	s.set_guard_name ( data ) ;	

READ_GUARD_RLTN:
	data = "" ;
	string rltn_list[] = { "FATHER" , "MOTHER" , "BROTHER" , "SISTER" , "UNCLE" , "AUNTY" , "OTHER" } ;
	read_list ( &data , 35 , 46 , rltn_list , 7 ) 	;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 44 ) ;
		printf ( "                                             " ) ;			
		goto READ_GUARD_NAME;		
	}
	s.set_student_relation ( data ) ;	

READ_ADDR_HNAME:
	data = "" ;
	read_data ( &data , 124 , 14 , 32 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 35 , 46 ) ;
		printf ( "         " ) ;			
		goto READ_GUARD_RLTN;			
	}
	s.set_addr_hname( data ) ;

READ_ADDR_PLACE:
	data = "" ;
	read_data ( &data , 124 , 16 , 22 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 14 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_HNAME;			
	}
	s.set_addr_place ( data ) ;

READ_ADDR_POST:
	data = "" ;
	read_data ( &data , 124 , 18 , 22 , 0 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 16 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_PLACE;			
	}
	s.set_addr_post ( data ) ;						

READ_ADDR_PIN:
	data = "" ;
	read_data ( &data , 124 , 20 , 8 , 1 ) ;
	if ( data == "-1" )
	{
		gotoxy ( 124 , 18 ) ;
		printf ( "                              " ) ;			
		goto READ_ADDR_POST;			
	}
	s.set_addr_pin ( data ) ;

READ_PHONE:
	data = "" ;
	read_data ( &data , 124 , 22 , 13 , 1 ) ;
	if ( data == "-1" )
	{

		goto READ_ADDR_PIN;			
	}
	s.set_phone ( data ) ;

	// cout << data << endl ;




//	cout << " in main " << data ;

	FILE* fp ;

	fp = fopen ( "stud_db.bin" , "ab+" ) ;

	if ( fp != NULL )
	{
			fwrite( &s , sizeof(student_data) , 1 , fp );
			++next_admno ;
	}

	fclose ( fp ) ;

	cin.get () ;

	return  0 ;
}

int edit_student_entry()
{
	return  0 ;
}

int search_student_entry()
{
	return  0 ;
}

int student_mark_entry()
{
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