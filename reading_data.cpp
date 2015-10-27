#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <vector>

using namespace std ;

extern void gotoxy ( int , int ) ;
extern void read_data ( char data[] , int x , int y , int max_size , int special ) ;
extern void read_data ( string* data , int x , int y , int max_size , int number , int skip = 0 ) ;
extern void read_data_continuous ( string* d , int x , int y , int max_size , int number ) ;
extern void read_date ( string* data , int x , int y , int max_size , int today ,int skip ) ;
extern void read_char ( char* d , int x , int y , char items[] , int size ) ;
extern void read_list ( string* data , int x , int y , string list[] , int size ) ;
extern void read_vector ( string* data , int x , int y , vector<string> list , int* pos ) ;
extern void hit_enter () ;

extern char sdate[20] ;
extern int read_ctr = 0 ;
extern bool threadFinishPoint ;

int date_validation ( string , int i , char ch ) ;
int is_available ( char items[] , int size , char d ) ;

extern void read_data ( char data[] , int x , int y , int max_size , int special ) 
{
		int i = 0 ;
		
		strcpy ( data , "" ) ;
		char data_ = 8 ;

		i = 0 ;

		while ( (int)data_  != 13 )
		{
			gotoxy ( x+i , y ) ;
			data_ = _getch();
			
			if ( !i && (int)data_  == 13 ) 
			{	
				data_  = 8 ;
				continue ;
			}

			if ( (int)data_ == 27 )
			{
				strcpy ( data , "-1" ) ;
				gotoxy ( x , y ) ;
				for ( int j = 0 ; j <= i ; ++j )
					printf(" ") ;
				return ;
			}			
			
			if ( (int)data_  != 8 && (int)data_  != 13 ) 
				if ( i != max_size-2 )
				{
					data[i++] = data_  ;
				}
				
			if ( (int)data_  == 8 )
				if ( i != 0 )
				{
						--i ;
						gotoxy ( x+i , y ) ; 
						cout << " " ;
				}
				else
						i = 0 ;		
		
			if ( i>=0 && (int)data_ != 13 ) 
			{
				gotoxy ( x , y ) ;
				for ( int j=0 ; j<i ; ++j)
				{
					if ( !special )
						printf("%c",data[j]);

					else if ( special == 1 )
						printf("*");
				}
			}
			
		}
		data[i] = '\0';
}

extern void read_date ( string* d , int x , int y , int max_size , int today , int skip ) 
{
		int i = 0 , t =  0 ;
		
		string data = "azhar" ;

		char data_ = 8 ;

		i = 0 ;

		gotoxy ( x , y ) ;

		while ( (int)data_  != 13 )
		{
			data_ = _getch();
			
			if ( (int)data_ == 13 && ( (!t && i == 8) || ( t && i == 10 ) ) )
				break ;

			else if ( (int)data_ == 13 && ( (!t && i != 8) || ( t && i != 10 ) ) )
			{	
				data_  = 8 ;
				continue ;
			}

			if ( !i && (int)data_ == 9 && skip )
			{
				*d = "-2" ;
				gotoxy ( x , y ) ;
				for ( int j = 0 ; j <= i ; ++j )
					printf(" ") ;
				return ;				
			}
			
			if ( (int)data_ == 27 )
			{
				*d = "-1" ;
				gotoxy ( x , y ) ;
				for ( int j = 0 ; j <= i ; ++j )
					printf(" ") ;
				return ;
			}

			if ( !i && ( (int)data_ == 84 || (int)data_ == 116 ) && today )
			{
				data = (string)sdate ;
				i = strlen ( sdate ) - 1 ;
				t = 1 ;
			}			
			
			else if ( (int)data_  != 8 && (int)data_  != 13 && isdigit(data_) )
			{	
				if ( i != max_size - 2  && date_validation ( data , i , data_ ) )
				{
					data[i++] = data_  ;
				}
			}

			if ( (int)data_  == 8 )
				if ( i != 0 && !t )
				{
					--i ;
					gotoxy ( x , y ) ; printf("          ");
				}
				else if ( t )
				{
					t = 0 ;
					i = 0 ;
					data = "azhar" ;
					gotoxy ( x , y ) ; printf("          ");
				}

				else
						i = 0 ;		
		
			if ( i>=0 && (int)data_ != 13 ) 
			{
				gotoxy ( x , y ) ;
				for ( int j=0 ; j<i ; ++j)
				{
						printf("%c",data[j]);
						if ( !t && ( j == 1 || j == 3 ) ) printf("/") ;
				}
			}
			
		}
		data[i] = '\0';	

		string new_str = "" ;

		if ( !t )
		for ( int i = 0 ; data[i] != '\0' ; ++i )
		{
			new_str += data[i] ;
			if ( (i == 1 || i == 3) ) new_str += '/' ;
		}

		else new_str = data ;

		*d = new_str ;
}

int date_validation ( string data , int i , char ch ) 
{
	if ( i == 0 )
	{
		if ( ch == '0' || ch == '1' || ch == '2' || ch == '3' )
			return 1 ;
		else
			return 0 ;
	}
	else if ( i == 1 )
	{
		if ( ch == '0' && data[i-1] == '0' )
			return 0 ;
		if ( ( data[i-1] == '3' && ( ch == '0' || ch == '1' ) ) || (data[i-1] != '3' && ch >= 48 && ch <= 57)  )
			return 1 ;
		else
			return 0 ;
	}
	else if ( i == 2 )
	{
		if ( ch == '0' || ch == '1' )
			return 1 ;
		else
			return 0 ;
	}
	else if ( i == 3 )
	{
		if ( data[i-3] == '3' && data[i-2] == '1' && data[i-1] == '1' &&  ( ch == '0' || ch == '2' ) )
			return 1 ;

		if ( data[i-3] == '3' && data[i-2] == '1' && data[i-1] == '0' &&  ( ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '8' ) )
			return 1 ;

		if ( data[i-3] == '3' && data[i-2] == '0' && data[i-1] == '0' &&  ( ch == '1' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' ) )
			return 1 ;		

		if ( data[i-3] == '3' && data[i-2] == '0' && data[i-1] == '1' &&  ( ch == '0' || ch == '1' || ch == '2' ) )
			return 1 ;		

		if ( data[i-3] != '3' && data[i-1] == '1' &&  ( ch == '0' || ch == '1' || ch == '2' ) )
			return 1 ;		

		if ( data[i-3] != '3' && data[i-1] == '0' &&  ( ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' ) )
			return 1 ;				

		return 0 ;

	}
	else if ( i == 4 )
	{
		if ( ch == '2') 
			return 1 ;
		else
			return 0 ;
	}
	else if ( i == 5 )
	{
		if ( ch == '0') 
			return 1 ;
		else
			return 0 ;		
	}
	else if ( i == 6 )
	{
		if ( ch >= 48 && ch <= 57 ) 
			return 1 ;
		else
			return 0 ;		
	}
	else if ( i == 7 )
	{
		if ( ch >= 48 && ch <= 57 ) 
			return 1 ;
		else
			return 0 ;				
	}						
	return 1 ;
}

extern void read_data ( string* d , int x , int y , int max_size , int number , int skip ) 
{
		int i = 0 ;
		
		string data = "a" ;
		data.reserve( max_size ) ;
		char data_ = 8 ;

		i = 0 ;

		gotoxy ( x , y ) ;
		while ( (int)data_  != 13 )
		{
			data_ = _getch();
			
			if ( !i && (int)data_  == 13 ) 
			{	
				data_  = 8 ;
				continue ;
			}

			if ( !i && (int)data_ == 9 && skip )
			{
				*d = "-2" ;
				gotoxy ( x , y ) ;
				for ( int j = 0 ; j <= i ; ++j )
					printf(" ") ;
				return ;				
			}

			if ( (int)data_ == 27 )
			{
				*d = "-1" ;
				gotoxy ( x , y ) ;
				for ( int j = 0 ; j <= i ; ++j )
					printf(" ") ;
				return ;
			}			

			if ( (int)data_  != 8 && (int)data_  != 13 ) 
				if ( (data_ == ' ' && data[i-1] != ' ' && i != 0) || data_ != ' ' )
					if ( number == 2 || ( number == 1 && isdigit(data_) ) || ( !number &&  ( isalpha(data_) || data_ == ' ' ) ) )
						if ( i != max_size-2 )
						{
							data[i++] = toupper(data_)  ;
						}
				
			if ( (int)data_  == 8 )
				if ( i != 0 )
				{
						--i ;
						gotoxy ( x+i , y ) ; 
						cout << " " ;
				}
				else
						i = 0 ;		
		
			if ( i>=0 && (int)data_ != 13 ) 
			{
				gotoxy ( x , y ) ;
				for ( int j=0 ; j<i ; ++j)
				{
						printf("%c",data[j]);
				}
			}
			
		}
		data[i] = '\0';

		for ( i = 0 ; data[i] != '\0' ; ++i )
		{
			*d += data[i] ;
		}

}



extern void read_char ( char* d , int x , int y , char items[] , int size ) 
{
		int i = 0 ;
		
		char data = *d ;
		char data_ = 8 ;

		i = 0 ;

		while ( (int)data_  != 13 )
		{
			gotoxy ( x , y ) ;
			data_ = _getch();

			*d = data_ ;
			if ( is_available ( items , size , toupper(*d) ) )
			{
				break ;			
			}
			
			if ( !i && (int)data_  == 13 ) 
			{	
				data_  = 8 ;
				continue ;
			}

			if ( (int)data_ == 27 )
			{
				*d = '0' ;
				return ;
			}			

			if ( (int)data_  != 8 && (int)data_  != 13 ) 
				if ( is_available ( items , size , toupper(data_) ) )
					*d = toupper(data_) ;
				
			if ( (int)data_  == 8 )
			{
				gotoxy ( x , y ) ;
				cout << "      " ;
				*d = ' ' ;
				data_ = ' ' ;
			}

			if ( data_ != ' ' && (int)data_ != 13 ) 
			{
				gotoxy ( x , y ) ;

			}

			
		}
	
}

int is_available ( char items[] , int size , char d )
{
	for ( int i = 0 ; i < size ; ++i )
	{
		if ( items[i] == d )
		{
			return 1 ;
		}
	}

	return 0 ;
}

extern void read_list ( string* data , int x , int y , string list[] , int size )
{
	string str = "" ;
	string a = "" ;
	char ch  ;
	
	char s[5] = "" ;
	int b = 1 ;

	int pos = 0 ;

	while ( a != "13" )
	{
		gotoxy ( x , y ) ;
		cout << "       " ;
		gotoxy ( x , y ) ;
		cout << list[pos] ;

		b = 1 ;
		while ( b )
		{
			ch=_getch();

			if ( b ) b = 0 ;
			if ( ch == -32 || ch == 0 ) b = 1 ;

			str += itoa(ch,s,10) ;

			a = str ;

			if ( b == 1  && ch != -32 && ch != 0 ) { b = 0 ; str = "" ; }

			if ( ch != -32 && ch != 0 ) str = "" ;

		}

		if ( a == "27" )
		{
			*data = "-1" ;
			gotoxy ( x , y ) ;
			for ( int j = 0 ; j <= list[pos].length() ; ++j )
				printf(" ") ;			
			return ;
		}

		if ( a == "-3272" )							// UP KEY
		{
			if ( pos-1 < 0 ) pos = size - 1 ;
			else --pos ;						
		}
		if ( a == "-3280" )							// DOWN KEY
		{				
			if ( pos + 1 >= size ) pos = 0 ;
			else ++pos ;
		}
	}
	*data = list[pos] ;	
}

extern void read_vector ( string* data , int x , int y , vector<string> list , int* p )
{
	string str = "" ;
	string a = "" ;
	char ch  ;
	
	char s[5] = "" ;
	int b = 1 ;

	int pos = 0 ;

	while ( a != "13" )
	{
		gotoxy ( x , y ) ;
		cout << "                " ;
		gotoxy ( x , y ) ;
		cout << list[pos] ;

		b = 1 ;
		while ( b )
		{
			ch=_getch();

			if ( b ) b = 0 ;
			if ( ch == -32 || ch == 0 ) b = 1 ;

			str += itoa(ch,s,10) ;

			a = str ;

			if ( b == 1  && ch != -32 && ch != 0 ) { b = 0 ; str = "" ; }

			if ( ch != -32 && ch != 0 ) str = "" ;

		}

		if ( a == "27" )
		{
			*data = "-1" ;
			gotoxy ( x , y ) ;
			for ( int j = 0 ; j <= list[pos].length() ; ++j )
				printf(" ") ;			
			return ;
		}

		if ( a == "-3272" )							// UP KEY
		{
			if ( pos-1 < 0 ) pos = list.size() - 1 ;
			else --pos ;						
		}
		if ( a == "-3280" )							// DOWN KEY
		{				
			if ( pos + 1 >= list.size() ) pos = 0 ;
			else ++pos ;
		}
	}
	*data = list[pos] ;	
	*p = pos ;
}

extern void read_data_continuous ( string* d , int x , int y , int max_size , int number , int* n ) 
{
		
		if (!(*n)) { read_ctr = 0 ; gotoxy ( x , y ) ; }

		string data = *d ;
		data.reserve( max_size ) ;
		char data_ = 8 ;

		if ( read_ctr == max_size-2 )
		{
			gotoxy ( x+(max_size-3) , y ) ;
		}
		else gotoxy ( x+(read_ctr) , y ) ;


			data_ = _getch();
			threadFinishPoint = true ;

			if ( *n && (int)data_ == 13 )
			{
				*d = "done" ;
				return ;
			}
			
			if ( !(*n) && (int)data_  == 13 ) 
			{	
				data_  = 8 ;
				return ;
			}

			if ( (int)data_ == 27 )
			{
				*d = "-1" ;
				read_ctr = 0 ;
				*n = 0 ;
				return ;
			}

			if ( !((data_ >= (int)'0' && data_ <= (int)'9') || data_ == 8 || data_ == 13 ) )
			return ;			

			if ( (int)data_  != 8 && (int)data_  != 13 ) 
				if ( (data_ == ' ' && data[read_ctr-1] != ' ' && read_ctr != 0) || data_ != ' ' )
					if ( number == 2 || ( number == 1 && isdigit(data_) ) || ( !number &&  ( isalpha(data_) || data_ == ' ' ) ) )
						if ( read_ctr != max_size-2 )
						{
							data[read_ctr++] = toupper(data_)  ;
							*d = data ;
						}

			if ( read_ctr == max_size-2 && (int)data_  != 8 )
			{
				return ;
			}
				
			if ( (int)data_  == 8 )
			{
				if ( read_ctr != 0 )
				{
						--read_ctr ;
						*n /= 10 ;
						gotoxy ( x , y ) ; 
						cout << "     " ;
						gotoxy ( x , y ) ;
						if(*n)cout << *n ;		
						else cout <<" " ;
				}
				else
						read_ctr = 0 ;
				return ;
			}
			
		data[read_ctr] = '\0';

	if ( n != NULL )
	{
		*n *= 10 ;
		*n += ( data_ - 48 ) ;
		gotoxy ( x , y ) ;
		if(*n)cout << *n ;		
		else cout <<" " ;
	}
	*d = data ;

}

extern void hit_enter ( int x , int y ) 
{
	char ch = NULL ;
	while ( ch != 13 )
	{
		ch = _getch () ;
		printf(" ");
		gotoxy ( x , y ) ;
	}
}