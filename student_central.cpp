#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std ;

class student_data ;

extern void gotoxy ( int , int ) ;
extern void header () ;
extern int get_next_adm_no () ;
extern void read_date ( string* data , int x , int y , int max_size , int today ) ;
extern void read_data ( string* data , int x , int y , int max_size , int number ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void read_list ( string* data , int x , int y , string list[] , int size ) ;
extern void hit_enter ( int x , int y ) ;
extern int  find_age  ( string data ) ;
extern void fee_student_init ( int admno , char [] ) ;
extern string get_student_name ( int admno ) ;
extern string get_student_class ( int admno ) ;
extern void display_msg_static ( string ) ;
extern int grab_date ( char [] , char [] ) ;

extern int show_student_data_brief ( int admno , int *lp ) ;

extern int next_admno ;

int new_student_entry () ;
int edit_student_entry () ;
int search_student_entry () ;
int student_mark_entry () ;
student_data search_student_file ( int* admno ) ;

extern void convert ( string d , char cnvt[] ) ;
extern char sdate[20] ;

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
			gotoxy ( 35 , 31 ) ; cout << grab_date ( sdate , "year" ) - grab_date ( dob , "year" ) << endl ;			
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
			break ;
		case 3 :
			x = search_student_entry () ;
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

START:
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
		gotoxy ( 35 , 31 ) ;
		printf ( "  " ) ;						
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
		gotoxy ( 124 , 20 ) ;
		printf ( "                  " ) ;
		goto READ_ADDR_PIN;			
	}
	s.set_phone ( data ) ;

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

		fee_student_init ( s.get_admno() , s.date_admitted ) ;

		display_msg_static ( "!!! HIT >> ENTER << TO CONTINUE !!!") ;
		hit_enter ( 0 , 0 ) ;

		return 1 ;
	}
	else
		goto START ;

	return  0 ;
}

int edit_student_entry()
{
	return  0 ;
}

int search_student_entry()
{
	int i = 0 , j = 0 , lp = 0 ;
	int adm = 0 ;

	string data = "" ;

START:
	header();
	gotoxy(74 , 8) ;
	cout<<"SEARCH STUDENT ENTRY"<<endl;
	gotoxy(73,9);
	for ( i = 1 ; i <= strlen ("SEARCH STUDENT ENTRY")+2 ; ++i )
		cout<<char(205);		//11
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

	student_global.full_details_display () ;

	display_msg_static ( "!!! HIT >> ENTER << TO CONTINUE !!!") ;
	hit_enter ( 0 , 0 ) ;

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
		gotoxy ( 70 , 17 ) ;
		cout << "***** STUDENT NOT FOUND *****" ;
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

