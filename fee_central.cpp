#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <process.h>

using namespace std ;

class fee_details ;

extern void fee_central_control ( int choice ) ;
extern void fee_student_init ( int admno , char date [] , char special[]  ) ;

extern void header () ;
extern int general_tasks ( string type , int* data = 0 ) ; 
extern void gotoxy ( int , int ) ;
extern void read_data ( string* data , int x , int y , int max_size , int number , int* n = NULL ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n = NULL )  ;
extern void read_vector ( string* data , int x , int y , vector<string> list , int* pos ) ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void convert ( string d , char cnvt[] ) ;
extern string next_month ( int , int ) ;
extern int convert_month ( string mnth = "" , char mnt[] = "" ) ;
extern int calc_date_diff ( char start[] , char end[] ) ;
extern string get_student_name ( int admno ) ;
extern string get_student_class ( int admno ) ;
extern string get_last_payed ( int admno ) ;
extern void display_msg_static ( string ) ;
extern void hit_enter ( int x , int y ) ;
extern void set_news ( string news , int id ) ;

extern int  show_student_data_brief ( int admno , int* lp ) ;
extern fee_details show_fee_data_brief ( int admno , int* status ) ;

extern int grab_date ( char [] , char [] ) ;
extern string convert_month ( int id ) ;
extern void generate_avail_list ( char start[] , char end[] , vector<string>& list ) ;
extern void blink_text ( void* text ) ;
extern bool news_control ;

int  fee_pay () ;
int  view_fee_defaulters () ;
void view_fee_stats () ;

extern int read_ctr ;
extern int next_admno ;
extern char sdate[20]  ;
extern bool threadFinishPoint ;

class fee_details
{
public:
	int admno ;
	int fee_init ;
	int months_payed ;
	char date_admitted[15] ;
	char last_payd[20] ;
	char to_pay[20] ;
	char special_encode[15] ;

	fee_details ()
	{
		admno = 0 ;
		fee_init = 0 ;
		months_payed = 0 ;
		strcpy ( date_admitted , "NOT INIT" ) ;
		strcpy ( last_payd , "0" ) ;
		strcpy ( to_pay , "0" ) ;
		strcpy ( special_encode , "0" ) ;		
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
	void set_to_pay ( char lst_pyd[] )
	{
		int i = 0 ;
		string month ;
		int yr = 0 ;
		char temp[6] = "" , t[6] = "" ;

		for ( i = 0 ; lst_pyd[i] != '\0' ; ++i )
		{
			if ( lst_pyd[i] != ' ' )
			{
				if ( isalpha ( lst_pyd[i] ))
					month = month + lst_pyd[i] ;
				else
				{
					yr *= 10 ;
					yr = ( yr + lst_pyd[i] - 48 ) ; 
				}
			}
		}

		if ( month == "DECEMBER" )
		{
			month = "01/01/";
			++yr ;
			itoa ( yr , temp , 10 ) ;
			month = month + temp ;	
		}
		else 
		{
			int x  = convert_month ( month ) ;
			++x ;
			month = "01/";
			if ( x == 10 || x == 11 || x == 12 )
			{
				itoa ( x , temp , 10 ) ;
			}
			else
			{
				itoa ( x ,t ,10 ) ;
				strcpy ( temp , "0" ) ;
				strcat ( temp , t ) ;				
			}
			month = month + temp ;
			month = month + "/" ;			
			itoa ( yr , temp , 10 ) ;
			month = month + temp ;				
		}

		convert ( month , to_pay ) ;
	}

	void show_fee_defaulter ( int entry ) 
	{
		gotoxy ( 12 , 18+entry ) ;
		cout << setw(5) << admno << endl ;

		gotoxy ( 25 , 18+entry ) ;
		cout << get_student_name ( admno ) << endl ;

		gotoxy ( 80 , 18+entry ) ;
		cout << get_student_class ( admno ) << endl ;

		gotoxy ( 100 , 18+entry ) ;
		if ( strcmp ( last_payd , "0" ) )
			cout << last_payd << endl ;
		else
			cout << "ADM FEES NT PD" << endl ;

		gotoxy ( 125 , 18+entry ) ;
		if ( strcmp ( last_payd , "0" ) )
			cout << setw(8) << calc_date_diff ( to_pay , sdate ) << endl ;			
		else
			cout << setw(8) << calc_date_diff ( date_admitted , sdate ) << endl ;
	}
	void set_special ( char data[] )
	{
		strcpy ( special_encode , data ) ;
	}	
}fee_global;


extern void fee_central_control ( int choice )
{
	int x = 0 , admno = 0 , y = 0 ;
	switch ( choice )
	{
		case 1 :
			admno = fee_pay () ;

			if ( admno > 0 )
			{
				fee_details x ;
				y = 1 ;

				fstream oldfile ;
				fstream newfile ;
				oldfile.open ( "fee_db.bin" , ios::in | ios::binary ) ;
				newfile.open ( "temp.bin" , ios::out | ios::binary ) ;

				while ( y < next_admno )
				{
					oldfile.read (( char* ) &x , sizeof(fee_details) ) ;
					if ( x.admno == fee_global.admno )
					{
						x = fee_global ;
					}
					newfile.write (( char* ) &x , sizeof ( fee_details ) ) ;
					++y ;
				}
				oldfile.close() ;
				newfile.close() ;

				remove ( "fee_db.bin" );
				system ( "rename temp.bin fee_db.bin" );

			}

			break ;
		case 2 :
			x = view_fee_defaulters () ;
			break ;
		case 3 :
			view_fee_stats () ;
			break ;
		case 4 :
			return ;

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

extern void fee_student_init ( int admno , char date [] , char special[] )
{
	fee_details f ;
	char m[5] = "" , temp [20] = "" , d[15] = "01/" ;

	f.set_admno ( admno ) ;
	f.set_date  ( date ) ;
	f.set_special ( special ) ;

	if ( special[0] == '1' && special[2] == '0' && !f.fee_init )
	{	
		f.fee_init = 1 ;

		string asd = convert_month ( grab_date ( sdate , "month") ) ;
		asd += " " ;
		strcpy ( temp , "" ) ;
		itoa ( grab_date ( sdate , "year" ) , temp , 10 ) ;
		asd += temp ;

		convert ( asd , temp ) ;

		strcpy  ( f.last_payd , temp ) ;
		int mnth = grab_date ( sdate , "month" ) ;
		int yr  = grab_date ( sdate , "year" ) ;
		if ( mnth == 12 ) { mnth = 1 ; ++yr ; }
		else ++mnth ;
		if ( mnth >= 1 && mnth <= 9 ) strcpy ( m , "0" ) ;
		itoa ( mnth , temp , 10 ) ;
		strcat ( m , temp ) ;
		strcat ( d , m ) ; 
		strcat ( d , "/" ) ;
		strcpy ( temp , "" ) ;
		strcpy ( m , "" ) ;
		itoa ( yr , temp , 10 ) ;
		strcat ( d, temp ) ;
		strcpy ( f.to_pay , d ) ;
	}


	FILE *fp ;

	fp = fopen ( "fee_db.bin" , "ab+" ) ;

	if ( fp != NULL )
		fwrite( &f , sizeof(fee_details) , 1 , fp );

	fclose ( fp ) ;	
}

int fee_pay () 
{
	int i = 0 , j = 0 , lp = 0 ;
	int adm = 0 ;
	int total = 0 , status = 0 ;

	string data = "" ;

	fee_details f ;

START_FEE_PAY:
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

	data = "" ;
	adm = 0 ;
	lp = 0 ;
	total = 0 ;
	status = 0 ;

	while ( data != "done" )
	{
		read_data_continuous ( &data , 30 , 11 , 8 , 1 , &adm ) ;
		if ( data == "-1" )
		{
			return 0 ;
		}

		int found =	show_student_data_brief ( adm , &lp ) ;

		if ( found )
			f = show_fee_data_brief ( adm , &status ) ;
		if ( !found )
			data = "" ;

		if ( data == "done" && status == 0 )
		{
			data = "" ;
		}

	}
	threadFinishPoint = true ;
	Sleep ( 200 ) ;	
	fee_global = f ;

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
		cout << convert_month ( grab_date ( f.to_pay , "month" ) ) << " " << grab_date ( f.to_pay , "year" ) <<endl ;	
	else
		cout << convert_month ( grab_date ( f.date_admitted , "month" ) ) << " " << grab_date ( f.date_admitted , "year" ) <<endl ;	

	std::vector<string> list;

	if ( strcmp ( f.last_payd , "0" ))
		generate_avail_list ( f.to_pay , sdate , list ) ;
	else
		generate_avail_list ( f.date_admitted , sdate , list ) ;		

	data = "" ;
	int no = 0 ;
	read_vector ( &data , 88 , 29 , list , &no ) ;

	if ( data == "-1" )
		goto START_FEE_PAY ;

	gotoxy ( 88 , 31 ) ;
	cout << no+1 << endl ;

	if ( f.special_encode[0] == '0' )
	{
		if ( strcmp ( f.last_payd , "0" ) )
		{
			if (lp)
				general_tasks ( "get_lp_fee" ,  &total) ;
			else
				general_tasks ( "get_up_fee" , &total ) ;

			total = total * ( no+ 1 ) ;
		}
		else
		{
			general_tasks ( "get_adm_fee" , &total ) ;

		}
	}

	else
	{
		if ( strcmp ( f.last_payd , "0" ) )
		{
			int val = 0 , k = 0 ;

			for ( k = 2 ; f.special_encode[k] != '-' ; ++k ) ;

			for ( ++k ; f.special_encode[k] != '\0' ; ++k )
				val = ( val*10 ) + ( f.special_encode[k] - 48 ) ;

			total = total + ( val * ( no + 1 ) ) ;
		}
		else
		{
			int val = 0 , k = 0 ;

			for ( k = 2 ; f.special_encode[k] != '-' ; ++k )
				val = ( val*10 ) + ( f.special_encode[k] - 48 ) ;

			total += val ;
		}		
	}

	gotoxy ( 88 , 33 ) ;
	cout << total ;

	display_msg_static ( "!! CONFIRM ?? [ Y / N ] !!") ;
	char decision = ' ' ;
	char items[] = { 'Y' , 'N' } ;
	read_char ( &decision , 0 , 0 , items , 2 ) ;

	if ( decision == 'Y' || decision == 'y' ) 
	{
		fee_global.fee_init = 1 ;
		fee_global.months_payed += (no+1) ;
		char d[20] = "" ;
		convert ( data , d ) ;
		strcpy  ( fee_global.last_payd , d ) ;
		fee_global.set_to_pay ( fee_global.last_payd ) ;
		general_tasks ( "set_fee_collexn" , &total ) ;
		return adm ;
	}
	else goto START_FEE_PAY ;

	return 0 ;
}

extern fee_details show_fee_data_brief  ( int admno , int *status ) 
{
	static int clean = 0 ;

	fee_details f ;

	f = search_fee_file ( admno ) ;

	gotoxy ( 90 , 18 ) ;
	if ( strcmp ( f.last_payd , "0" ) )
	{
		cout << "** FEE LAST PAID ON :     " << f.last_payd << endl ;
		
		string str = convert_month ( grab_date ( sdate , "month" ) ) ;
		str = str + " " ;
		char temp[20] = "" ;
		itoa ( grab_date ( sdate , "year" ) , temp , 10 ) ;
		str = str + temp ;

		convert ( str , temp ) ;

		if ( !strcmp ( temp , f.last_payd ))
			*status = 0 ;
		else
			*status = 1 ;

	}
	else
	{
		cout << "** FEE LAST PAID ON :     " << "ADMISSION FEES NOT PAID" << endl ;
		*status = 1 ;
	}

	if ( f.special_encode[0] == '1' )
	{
		threadFinishPoint = false ;
		_beginthread ( blink_text , 0 , (char*)"!!! SPECIAL FEES !!!" ) ;
	}

	return f ;
}

int view_fee_defaulters () 
{
	fee_details x ;
	int y = 1 , i = 0 ;
	int no = 0 ;

	fstream file ;

	HANDLE h ;

START :
	header();
	gotoxy(76 , 8) ;
	cout<<"FEE DEFAULTERS"<<endl;
	gotoxy(75,9);
	for ( i = 1 ; i <= strlen ("FEE DEFAULTERS")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;

	gotoxy ( 9 , 12 ) ;
	for ( i = 1 ; i <= 149 ; ++i )
		cout << (char)196 ;
	cout << endl ;

	gotoxy ( 9 , 16 ) ;
	for ( i = 1 ; i <= 149 ; ++i )
		cout << (char)196 ;
	cout << endl ;	

	gotoxy ( 12 , 14 ) ;
	cout << "ADM NO." << endl ;

	gotoxy ( 25 , 14 ) ;
	cout << "NAME" << endl ;

	gotoxy ( 80 , 14 ) ;
	cout << "CLASS" << endl ;	

	gotoxy ( 100 , 14 ) ;
	cout << "FEE LAST PAYED" << endl ;

	gotoxy ( 125 ,14 ) ;
	cout << "FEE PENDING MONTHS" << endl ;

	file.open ( "fee_db.bin" , ios::in|ios::binary ) ;

	while ( y < next_admno )
	{
		file.read((char*)&x , sizeof(fee_details)) ;

		if ( (grab_date ( x.to_pay , "year" ) < grab_date ( sdate , "year" )) || ( grab_date ( x.to_pay , "year" ) == grab_date ( sdate , "year" ) ) && ( grab_date ( x.to_pay , "month" ) <= grab_date ( sdate , "month" )  )  )
		{
			x.show_fee_defaulter ( no*2 ) ;	
			++no;
		}

		++y ;

		if ( y % 16 == 0  && y < next_admno ) 
		{
			threadFinishPoint = false ;
			char text[] = "!!! HIT >> ENTER << TO VIEW MORE !!!" ;
			h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
			hit_enter ( 0 , 0 ) ;
			threadFinishPoint = true ;			
			goto START ;
		}		
	}
	if ( no )
	{
		char temp[5] = "" , text[100] = "" ;
		itoa ( no , temp , 10 ) ;
		strcpy ( text , "<< ** >> FEE DEFAULTERS :: " ) ;
		strcat ( text , temp ) ;
		strcat ( text ,  " << ** >>" ) ;

		threadFinishPoint = false ;
		h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
		hit_enter ( 0 , 0 ) ;
		threadFinishPoint = true ;

	}
	else
	{
		threadFinishPoint = false ;
		char text[] = "***** NO FEE DEFAULTERS *****" ;
		h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;
		hit_enter ( 0 , 0 ) ;
		threadFinishPoint = true ;
	}

	file.close () ;

	return 0 ;
}

void view_fee_stats () 
{
	int i = 0 , j = 0 , val = 0 ;
	HANDLE h ;

	header();
	gotoxy( 74 , 13 ) ;
	cout<<"FEE COLLECTION STATS"<<endl;
	gotoxy( 73,  14 );
	for ( i = 1 ; i <= strlen ("FEE COLLECTION STATS")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;

	gotoxy(58,16);
	for(i=0;i<51;++i)cout<<(char)220;
	cout<<endl;
	
	gotoxy(58,17); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	general_tasks ( "get_collexn_day" , &val ) ;
	gotoxy(58,18); cout<<(char)186<<"   >> FEE COLLECTED TODAY     "<<setw(15)<< val <<"    "<<(char)186<<endl;
	gotoxy(58,19); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	general_tasks ( "get_collexn_month" , &val ) ;
	gotoxy(58,20); cout<<(char)186<<"   >> FEE COLLECTED THIS MONTH"<<setw(15)<< val <<"    "<<(char)186<<endl;
	gotoxy(58,21); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,22);
	for(i=0;i<51;++i)
		cout<<(char)223;
	cout<<endl;	

	threadFinishPoint = false ;
	char text[] = "!!! HIT >> ENTER << TO CONTINUE OR HIT >> M << TO VIEW DAILY COLLECTION !!!" ;
	h = (HANDLE)_beginthread ( blink_text , 0 , &text ) ;

	char decision = ' ' ;
	char items[] = { 13 , 'M' } ;
	read_char ( &decision , 0 , 0 , items , 2 ) ;

	if ( decision == 'M' || decision == 'm' ) 
	{
		system ("fee_stats.txt") ;
	}
	
	threadFinishPoint = true ;	
}

extern string get_last_payed ( int admno ) 
{
	fee_details f = search_fee_file ( admno ) ;
	string last = f.last_payd ;
	if ( !strcmp ( f.last_payd , "0" ) ) last = "ADM FEES NT PAID" ;
	return last ;
}

extern void change_date_admitted ( int admno , string data ) 
{
		fee_details x ;
		int y = 1 ;

		fstream oldfile ;
		fstream newfile ;
		oldfile.open ( "fee_db.bin" , ios::in | ios::binary ) ;
		newfile.open ( "temp.bin" , ios::out | ios::binary ) ;

		while ( y < next_admno )
		{
			oldfile.read (( char* ) &x , sizeof(fee_details) ) ;
			if ( x.admno == admno )
			{
				char temp[50] = "" ;
				convert ( data , temp ) ;
				x.set_date ( temp ) ;
			}
			newfile.write (( char* ) &x , sizeof ( fee_details ) ) ;
			++y ;
		}
		oldfile.close() ;
		newfile.close() ;

		remove ( "fee_db.bin" );
		system ( "rename temp.bin fee_db.bin" );	
}