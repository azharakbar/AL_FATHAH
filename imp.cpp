#include <windows.h>
#include <process.h>
#include <fstream>
#include <iostream>

using namespace std ;

extern void gotoxy ( int x , int y ) ;
extern void display_time ( void* params ) ;
extern void header () ;
extern void draw_msg_box_static () ;
extern void exit_screen () ;
extern int  find_age ( string data ) ;

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