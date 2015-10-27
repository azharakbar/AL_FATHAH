#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>

using namespace std ;

extern int menu_control ( int , int , int , int esc = 0 ) ;
extern void gotoxy ( int , int ) ;

extern int menu_control ( int  x , int start_y , int end_y , int esc )
{

	string str = "" ;
	string a = "" ;
	char ch  ;
	
	char s[5] = "" ;
	int b = 1 ;

	int pos = 0 ;

	while ( a != "13" )
	{
		gotoxy ( x , start_y + pos ) ;
		cout << " >> " ;

		b = 1 ;
		while ( b )
		{
			ch=_getch();

			if ( b ) b = 0 ;
			if ( ch == -32 || ch == 0 ) b = 1 ;
			if ( esc && ch == 27 ) 
			{
				a = "27" ;
				break ;
			}

			str += itoa(ch,s,10) ;

			a = str ;

			if ( b == 1  && ch != -32 && ch != 0 ) { b = 0 ; str = "" ; }

			if ( ch != -32 && ch != 0 ) str = "" ;

		}

		if ( esc && a == "27" )
		{
			return -1 ;
		}	

		if ( a == "-3272" )							// UP KEY
		{
			gotoxy ( x , start_y + pos ) ;
			cout << "    " ;			
			if (  (start_y + pos) - 2 < start_y ) pos = ( end_y - start_y ) ;
			else pos -= 2 ;
		}
		if ( a == "-3280" )							// DOWN KEY
		{
			gotoxy ( x , start_y + pos ) ;
			cout << "    " ;						
			if ( start_y + pos + 2 > end_y ) pos = 0 ;
			else pos += 2 ;
		}
	}

	return pos ;

}

