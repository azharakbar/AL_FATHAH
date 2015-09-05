#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std ;

class fee_details ;

extern void fee_central_control ( int choice ) ;
extern void fee_student_init ( int admno , char date []  ) ;

extern void header () ;
extern void gotoxy ( int , int ) ;
extern void read_data ( string* data , int x , int y , int max_size , int number , int* n = NULL ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_vector ( string* data , int x , int y , vector<string> list , int* pos ) ;

extern int  show_student_data_brief ( int admno ) ;
extern fee_details show_fee_data_brief ( int admno ) ;

extern int grab_date ( char [] , char [] ) ;
extern string convert_month ( int id ) ;
extern void generate_avail_list ( char start[] , char end[] , vector<string>& list ) ;

int fee_pay () ;

extern int read_ctr ;
extern int next_admno ;
extern char sdate[20]  ;

class fee_details
{
public:
	int admno ;
	int fee_init ;
	int months_payed ;
	char date_admitted[15] ;
	char last_payd[20] ;

	fee_details ()
	{
		admno = 0 ;
		fee_init = 0 ;
		months_payed = 0 ;
		strcpy ( date_admitted , "NOT INIT" ) ;
		strcpy ( last_payd , "0" ) ;
	}

	void set_admno ( int d )
	{
		admno = d ;
	}
	int get_admno () 
	{
		return admno ;
	}
	void set_date ( char date[] )
	{
		strcpy ( date_admitted , date ) ;
	}
};


extern void fee_central_control ( int choice )
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
			x = fee_pay () ;
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

fee_details search_fee_file ( int admno )
{
	fee_details x ;
	int y = 1 ;

	fstream file ;

	file.open ( "fee_db.bin" , ios::in|ios::binary ) ;

	while ( y < next_admno )
	{
		file.read((char*)&x , sizeof(fee_details)) ;
		if ( x.get_admno() == admno )
		{
			file.close () ;	
			return x ;	
		}
		++y ;
	}

	file.close () ;
	
	return x ;

}

extern void fee_student_init ( int admno , char date [] )
{
	fee_details f ;
	f.set_admno ( admno ) ;
	f.set_date  ( date ) ;

	FILE *fp ;

	fp = fopen ( "fee_db.bin" , "ab+" ) ;

	if ( fp != NULL )
		fwrite( &f , sizeof(fee_details) , 1 , fp );

	fclose ( fp ) ;	
}

int fee_pay () 
{
	int i = 0 , j = 0 ;
	int adm = 0 ;

	string data = "" ;

	fee_details f ;

	header();
	gotoxy(78 , 8) ;
	cout<<"FEE PAYMENT"<<endl;
	gotoxy(77,9);
	for ( i = 1 ; i <= strlen ("FEE PAYMENT")+2 ; ++i )
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

	while ( data != "done" )
	{
		read_data_continuous ( &data , 30 , 11 , 8 , 1 , &adm ) ;
		if ( data == "-1" )
		{
			return 0 ;
		}

		int found =	show_student_data_brief ( adm ) ;

		if ( found )
			f = show_fee_data_brief ( adm ) ;
		if ( !found )
			data = "" ;
	}


	gotoxy ( 64 , 25 ) ;
	cout << (char)201 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)187 << endl ;

	for ( j = 0 ; j <= 8 ; ++j )
	{	
		gotoxy ( 64 , 26+j ) ;
		cout << (char)186 ;for ( i = 0 ; i <= 40 ; ++i ) cout << ' '	; cout << (char)186 << endl ;
	}
	gotoxy ( 64 , 26+j ) ;
	cout << (char)200 ;
	for ( i = 0 ; i <= 40 ; ++i ) cout << (char)205 	;
	cout << (char)188 << endl ;

	gotoxy ( 65 , 27 ) ; cout << " >>  FEE FROM     : " << endl ;
	gotoxy ( 65 , 29 ) ; cout << " >>  FEE TO       : " << endl ;
	gotoxy ( 65 , 31 ) ; cout << " >>  MONTHS       : " << endl ;
	gotoxy ( 65 , 33 ) ; cout << " >>  AMOUNT       : " << endl ;

	gotoxy ( 88 , 27 ) ; 
	if ( strcmp ( f.last_payd , "0" ))
		cout << f.last_payd ;
	else
		cout << convert_month ( grab_date ( f.date_admitted , "month" ) ) << " " << grab_date ( f.date_admitted , "year" ) <<endl ;	

	std::vector<string> list;
	generate_avail_list ( f.date_admitted , sdate , list ) ;

	data = "" ;
	int no = 0 ;
	read_vector ( &data , 88 , 29 , list , &no ) ;

	gotoxy ( 88 , 31 ) ;
	cout << no+1 << endl ;

	cin.get () ;
	return 0 ;
}

extern fee_details show_fee_data_brief ( int admno ) 
{
	static int clean = 0 ;

	fee_details f ;

	f = search_fee_file ( admno ) ;

	gotoxy ( 90 , 18 ) ;
	if ( strcmp ( f.last_payd , "0" ) )
		cout << "** FEE LAST PAID ON :     " << f.last_payd << endl ;
	else
		cout << "** FEE LAST PAID ON :     " << "ADMISSION FEES NOT PAID" << endl ;

	return f ;
}