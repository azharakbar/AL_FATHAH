#include <windows.h>
#include <process.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std ;

extern void gotoxy ( int x , int y ) ;
extern void display_time ( void* params ) ;
extern void header () ;
extern void draw_msg_box_static () ;
extern void exit_screen () ;
extern void convert ( string d , char cnvt[] ) ;
extern int  find_age ( string data ) ;
extern int grab_date ( char [] , char [] ) ;
extern string convert_month ( int mnth ) ;
extern void generate_avail_list ( char start[] , char end[] ) ;

extern char sdate[20] = "" ;
extern char stime[20] = "" ;

extern bool logged_in ;

extern void gotoxy (int x, int y)
{
    COORD coord; // coordinates

    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


extern void display_time ( void* params )
{
	char temp_time[20] = "" ;
	char temp_date[20] = "" ;
	int flag = 0 ;

	while ( 1 )
	{

		if ( logged_in )
		{
			strcpy (temp_time , "" ) ;
			strcpy (temp_date , "" ) ;
			strcpy (sdate , "" ) ;
			strcpy (stime , "" ) ;
			flag = 1 ;
			logged_in = false ;
		}

		system ( "time /T > time.txt" ) ;
		system ( "date /T > date.txt" ) ;

		fstream file ;
		file.open ( "time.txt" , ios::in );
		file.getline ( temp_time , 20 ) ;
		file.close () ;

		file.open ( "date.txt" , ios::in );
		file.getline ( temp_date , 20 ) ;
		file.close () ;

		if ( !strcmp ( sdate , "" ) )
		{
			strcpy ( sdate , temp_date ) ;
			strcpy ( stime , temp_time ) ;

			if ( !flag )
			{
				gotoxy ( 3 , 29 ) ;  cout << sdate << endl ;
				gotoxy ( 158 , 29 ) ; cout << stime << endl ;
			}
			else
			{
				gotoxy ( 3 , 7 ) ;  cout << sdate << endl ;
				gotoxy ( 158 , 7 ) ; cout << stime << endl ;				
			}
		}
		else
		{
			if ( !flag )
			{
				if ( strcmp ( sdate , temp_date ) )
				{
					strcpy ( sdate , temp_date ) ;
					gotoxy ( 3 , 29 ) ;  cout << sdate << endl ;
				}
				if ( strcmp ( stime , temp_time ) )
				{
					strcpy ( stime , temp_time ) ;
					gotoxy ( 158 , 29 ) ;  cout << stime << endl ;
				}
			}
			else
			{
				if ( strcmp ( sdate , temp_date ) )
				{
					strcpy ( sdate , temp_date ) ;
					gotoxy ( 3 , 7 ) ;  cout << sdate << endl ;
				}
				if ( strcmp ( stime , temp_time ) )
				{
					strcpy ( stime , temp_time ) ;
					gotoxy ( 158 , 7 ) ;  cout << stime << endl ;
				}
			}
		}

		//Sleep ( 500 ) ;
	}
	_endthread() ;
}

extern void convert ( string d , char cnvt[] ) 
{
	int i = 0 ;
	strcpy ( cnvt , "" ) ;
	for ( i = 0 ; d[i] != '\0' ; ++i )
		cnvt[i] = d[i] ;

	cnvt[i] = '\0' ;

}

extern int  find_age ( string data ) 
{
	char dob_year[5] = "" , present_year[5] = "" ;
	int  i = 0 , j = 0 ;

	dob_year[0] = data[6] ; 
	dob_year[1] = data[7] ; 
	dob_year[2] = data[8] ; 
	dob_year[3] = data[9] ; 
	dob_year[4] = '\0' ;

	j = 0 ;	
	for ( i = 6  ; sdate[i] != '\0' ; ++i )
	{
		present_year[j++] = sdate[i] ;
	}		
	present_year[j] = '\0' ;
	
	dob_year[0] = data[6] ; 

	return atoi (present_year) - atoi (dob_year) ;	
}

extern int grab_date ( char d[] , char what[] ) 
{
	int i = 0 ;
	char temp[6] = "" ;
	char data[20] ;

	strcpy ( data , d ) ;

	if ( !strcmp ( what , "day" ) )
	{
		for ( i = 0 ; data[i] != '/' ; ++i )
			temp[i] = data[i] ;
		temp[i] = '\0' ;
		return atoi (temp) ;
	}
	else if ( !strcmp ( what , "month" ) )
	{
		for ( i = 3 ; data[i] != '/' ; ++i )
			temp[i-3] = data[i] ;
		temp[i-3] = '\0' ;
		return atoi (temp) ;		
	}
	else if ( !strcmp ( what , "year" ) )
	{
		for ( i = 6 ; data[i] != '\0' ; ++i )
			temp[i-6] = data[i] ;
		temp[i-6] = '\0' ;
		return atoi (temp) ;		
	}		

	return 0 ;
}

extern string convert_month ( int id )
{
	if ( id == 1 )
		return "JANUARY" ;
	else if ( id == 2 )
		return "FEBRUARY" ;	
	else if ( id == 3 )
		return "MARCH" ;	
	else if ( id == 4 )
		return "APRIL" ;	
	else if ( id == 5 )
		return "MAY" ;	
	else if ( id == 6 )
		return "JUNE" ;	
	else if ( id == 7 )
		return "JULY" ;
	else if ( id == 8 )
		return "AUGUST" ;	
	else if ( id == 9 )
		return "SEPTEMBER" ;	
	else if ( id == 10 )
		return "OCTOBER" ;	
	else if ( id == 11 )
		return "NOVEMBER" ;															
	else if ( id == 12 )
		return "DECEMBER" ;	
}

extern void generate_avail_list ( char start[] , char end[] , vector<string>& list ) 
{
	 ;
	list.clear () ;


	int yrs = grab_date ( end , "year" ) - grab_date ( start , "year" ) ;

	char years[yrs+1][5] ;
	char temp[6] = "" ;
	string comb = "" ;
	char mnth[11] ;
	int i = 0 ;
	int ctr = 0 ;

	for ( i = 0 ; i <= yrs ; ++i )
	{
		itoa ( grab_date ( start , "year" ) + i , temp , 10 ) ;
		strcpy ( years[i] , temp ) ;
	}

	gotoxy ( 0,0 ) ;
	for ( i = 0 ; i <= yrs ; ++i )
	{

		if ( atoi ( years[i] ) == grab_date ( start , "year" ) && atoi ( years[i] ) == grab_date ( end , "year" ) )
		{
			for ( int j = grab_date ( start , "month") ; j <= grab_date ( end , "month") ; ++j )
			{
				comb = "" ;
				comb = convert_month (j) ;
				comb += " " ;
				comb += years[i] ;
				list.push_back ( comb ) ;
			}
			return ;
		}

		else if ( atoi ( years[i] ) == grab_date ( start , "year" ) && atoi ( years[i] ) != grab_date ( end , "year" ) )
		{
			for ( int j = grab_date ( start , "month") ; j <= 12 ; ++j )
			{
				comb = "" ;
				comb = convert_month (j) ;
				comb += " " ;
				comb += years[i] ;
				list.push_back ( comb ) ;
			}
		}
		else if ( atoi ( years[i] ) == grab_date ( end , "year" ) )
		{
			for ( int j = 1 ; j <= grab_date ( end , "month") ; ++j )
			{
				comb = "" ;
				comb = convert_month (j) ;
				comb += " " ;
				comb += years[i] ;
				list.push_back ( comb ) ;
			}
		}		
		else
		{
			for ( int j = 1 ; j <= 12 ; ++j )
			{
				comb = "" ;
				comb = convert_month (j) ;
				comb += " " ;
				comb += years[i] ;
				list.push_back ( comb ) ;
			}
		}
	}

}


extern void header ()
{
	system ( "cls" ) ;
	logged_in = true ;
	Sleep (100) ;
	gotoxy ( 59 , 1 );
	cout << " ____ ____ _________ ____ ____ ____ ____ ____ ____ "<<endl ;
	gotoxy ( 59 , 2 );
	cout << "||A |||L |||       |||F |||A |||T |||H |||A |||H ||"<<endl ;
	gotoxy ( 59 , 3 );
	cout << "||__|||__|||_______|||__|||__|||__|||__|||__|||__||"<<endl ;
	gotoxy ( 59 , 4 );
	cout << "|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|"<<endl ;

	gotoxy ( 58 , 5 ) ;
	for ( int i = 0 ; i <= 52 ; ++i )
		cout << (char)220 ;

	draw_msg_box_static() ;
}

extern void exit_screen()
{
	int i=0;
	system("cls");
	for(i=0;i<=18;++i)
		cout<<'\n';
	cout<<"\n\t\t\t\t\t\t\t\t";
	for(i=0;i<53;++i)
	cout<<(char)220;
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(219);cout<<"                                                   "<<char(219);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"            COMPUTERISED BILLING SYSTEM            "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"                                                   "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"              PROGRAMMED & DESIGNED BY             "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"            ";for(i=0;i<28;++i)cout<<char(205);cout<<"           "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"                                                   "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"             MOHAMMED AZHAR PADARIYAKAM            "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"                                                   "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"             COMPUTER SCIENCE DEPARTMENT           "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(186);cout<<"                azharakbar@gmail.com               "<<char(186);
	cout<<"\n\t\t\t\t\t\t\t\t"<<char(219);cout<<"                                                   "<<char(219);

	cout<<"\n\t\t\t\t\t\t\t\t";
	for(i=0;i<53;++i)
	cout<<(char)223;
	cout<<endl;
	getchar();
	system("cls");
	exit(0);
}