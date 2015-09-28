#include <fstream>
#include <iostream>
#include <process.h>
#include <windows.h>
#include <stdio.h>
#include <ctime>

using namespace std ;

class login_credentials
{
public:
	char username[100] ;
	char password[100] ;
} login_main ;

void login_box_top (void *param ) ;
void login_box_bottom ( void *param ) ;
void gotoxy ( int ,int ) ;
extern void retrieve_login_details ( void* param ) ;
extern void write_login_details ( char user[] , char pwd[] ) ;
void decode ( char[] , char[] ) ;
void encode ( char[] ) ;
extern void blink_text ( void* ) ;
extern void display_msg ( void* ) ;
extern void authenticate ( void* ) ;
extern void  authenticate ( char login_details[] ) ;


extern bool threadFinishPoint ;



extern void login_module ( void* params )
{

	HANDLE h1 = (HANDLE)_beginthread ( retrieve_login_details , 0 , NULL ) ;
	HANDLE h2 = (HANDLE)_beginthread ( login_box_top , 0 , NULL ) ;
	HANDLE h3 = (HANDLE)_beginthread ( login_box_bottom , 0 , NULL ) ;

	WaitForSingleObject ( h2 , INFINITE ) ;
	WaitForSingleObject ( h3 , INFINITE ) ;
	WaitForSingleObject ( h1 , INFINITE ) ;

}


extern void retrieve_login_details ( void* param )
{
	int i = 0 ;

	login_credentials login ;

	FILE* fp ;

	fp = fopen ( "log_crd.bin" , "rb+" ) ;

	if ( fp == NULL )
	{
		fclose ( fp ) ;

		char user[100] , pwd[100] ;

		strcpy ( user , "admin" ) ;
		strcpy ( pwd , "map54321" ) ;

		write_login_details ( user , pwd ) ;
	}

	else
	{
		fread( &login , sizeof(login_credentials) , 1 , fp );

		decode((login).username,(login).password);

		fclose ( fp ) ;
	}
	login_main = login ;

	_endthread () ;
}


void encode ( char user [] )
{

	int i = 0 , j = 0 ;
	char temp[100] = "" , t[5] = "";

	for ( i = 0 ; user[i] != '\0' ; ++i )
	{
			if ( (int) user[i] >= 100 ) { temp[j] = '3' ; j = j + 4 ; }
			else if ( (int) user[i] >= 10 ) { temp[j] = '2' ; j = j + 3 ; }
			else { temp[j] = '1' ; j = j + 2 ; }
			itoa ( (int)user[i] , t , 10 ) ;
			strcat( temp , t ) ;
			
	}
	
	strcpy ( user , "" ) ;
	strcpy ( user , temp );
	
}



void decode ( char user [] , char pwd [] )
{
	int i = 0 , j = 0 , z = 0 ,  val = 0 ; 
	char temp[100] = "" , temp_[100] = "" , t[5] = "" ;
	char ch = ' ' ;
	int flag = 0 ;
	
	for ( i = 0 ; user[i] != '\0' ; ++i )
	{
		j = 0 ;
		strcpy(t,"");
		int times = (int)(user[i]) - 48 ;
		
		for ( z = 1 ; z <= times ; ++z )
		{
			++i ;
			t [j++] = user[i] ;
			if ( user[i+1] == '\0' ) break ;
		}
		t[j]='\0';
		
		val = atoi (t) ;
		temp[flag++] = (char)val ;
				
		if ( user[i+1] == '\0' ) break ;
	}
	
	strcpy ( user , temp ) ;
	strcpy ( temp , ""  ) ;
	strcpy ( temp_ , ""  ) ;
	flag = 0 ; 
	
	for ( i = 0 ; pwd[i] != '\0' ; ++i )
	{
		j = 0 ;
		strcpy(t,"");
		int times = (int)(pwd[i]) - 48 ;
		
		for ( z = 1 ; z <= times ; ++z )
		{
			++i ;
			t [j++] = pwd[i] ;
			if ( pwd[i+1] == '\0' ) break ;
		}
		t[j]='\0';
		
		val = atoi (t) ;
		temp_[flag++] = (char)val ;
				
		if ( pwd[i+1] == '\0' ) break ;
	}
	
	strcpy ( pwd , temp_ ) ;	
	
}

void login_box_top (void *param )
{

	for (int i = 0; i < 3; ++i)
	{

		for (int j = 0; j < 50; ++j)
		{
			gotoxy(58+j,33-i) ;
			cout<<(char)220<<endl;
		}	
		for (int j = 0; j < 50; ++j)
		{
			if ( j ==0 || j == 49 )
			{
				gotoxy(58+j ,34-i);
				cout<<(char)219<<endl;
			}
			else
			{
				gotoxy(58+j,34-i);
				cout<<' '<<endl;
			}
		}
		if ( i )
		{
			for (int j = 0; j < 50; ++j)
			{
				if ( j ==0 || j == 49 )
				{
					gotoxy(58+j ,35-i);
					cout<<(char)186<<endl;
				}
				else
				{
					gotoxy(58+j,35-i);
					cout<<' '<<endl;
				}
			}			

		}
		Sleep ( 250 ) ;
			/* code */
	}
	Sleep ( 250 );

    srand(time(NULL));

    int x = rand() % 8 ;

    int swap = 0 ;

	char user[] = ">> USERNAME      :";

	for (int i = 0; user[i]!='\0' ; ++i)
	{
		gotoxy(65+i,33);
		cout<<user[i]<<endl;

		if ( i >= 3 && i <= 10 )
		{
	    	swap = 0 ;
		    while ( user[x] != user[i] )
		    {
		    	x = (rand() % 8 ) ;
		    	gotoxy(65+i,33);
		    	cout <<  user[x] ;
		    	++swap ;
		    	if ( swap > 5 ) break ;
		    	Sleep(30) ;
			}
			gotoxy(65+i,33);
			cout <<  user[i] ;
		}

		if ( i == 10 ) i = strlen (user) -2 ;
		Sleep ( 100 ) ;
	}
    
    _endthread();
}

void login_box_bottom (void *param)
{
	Sleep(200);

	for (int i = 0; i < 2; ++i)
	{
		if ( i )
		{
			for (int j = 0; j < 50; ++j)
			{
				if ( j ==0 || j == 49 )
				{
					gotoxy(58+j ,34+i);
					cout<<(char)186<<endl;
				}
				else
				{
					gotoxy(58+j,34+i);
					cout<<' '<<endl;
				}
			}			
		}	


		for (int j = 0; j < 50; ++j)
		{
			if ( j ==0 || j == 49 )
			{
				gotoxy(58+j ,35+i);
				cout<<(char)219<<endl;
			}
			else
			{
				gotoxy(58+j,35+i);
				cout<<' '<<endl;
			}
		}


		for (int j = 0; j < 50; ++j)
		{
			gotoxy(58+j,36+i) ;
			cout<<(char)223<<endl;
		}	
		Sleep ( 425 ) ;
	}

    srand(time(NULL));

    int x = rand() % 8 ;

    int swap = 0 ;	

	char pwd[] = ">> PASSWORD      :";

	for (int i = 0; pwd[i]!='\0' ; ++i)
	{
		gotoxy(65+i,35);
		cout<<pwd[i]<<endl;

		if ( i >= 3 && i <= 10 )
		{
	    	swap = 0 ;
		    while ( pwd[x] != pwd[i] )
		    {
		    	x = (rand() % 8 ) ;
		    	gotoxy(65+i,35);
		    	cout <<  pwd[x] ;
		    	++swap ;
		    	if ( swap > 5 ) break ;
		    	Sleep(30) ;
			}
			gotoxy(65+i,35);
			cout <<  pwd[i] ;
		}

		if ( i == 10 ) i = strlen (pwd) -2 ;
		Sleep ( 100 ) ;
	}

    _endthread();
}

extern void  authenticate ( void* text ) 
{
	char* login_details = (char*)text ;

	char usr[50] = "" , pwd[50] = "" ;

	int j = 0 , i = 0 ;

	for ( i = 0 ; login_details[i] != ' ' ; ++i )
		usr[j++] = login_details[i] ;
	usr[j] ='\0' ;

	j = 0 ;

	for ( ++i ; login_details[i] != '\0' ; ++i )
		pwd[j++] = login_details[i] ;

	pwd[j] = '\0' ;
	
	if ( !strcmp ( usr , login_main.username ) && !strcmp ( pwd , login_main.password )) strcpy ((char*)text , (char*)"success" ) ;
	else strcpy ((char*)text , (char*)"not success" ) ;

	_endthread () ;

}

extern void  authenticate ( char login_details[] ) 
{
	char usr[50] = "" , pwd[50] = "" ;

	int j = 0 , i = 0 ;

	for ( i = 0 ; login_details[i] != ' ' ; ++i )
		usr[j++] = login_details[i] ;
	usr[j] ='\0' ;

	j = 0 ;

	for ( ++i ; login_details[i] != '\0' ; ++i )
		pwd[j++] = login_details[i] ;

	pwd[j] = '\0' ;

	if ( !strcmp ( usr , login_main.username ) && !strcmp ( pwd , login_main.password )) strcpy ( login_details , "success" ) ;
	else strcpy ( login_details , "not success" ) ;
}

extern void blink_text ( void* text )
{
	int i = 0 ;
	int x = 84 - ( strlen ((char*)text) / 2 ) ;

	while ( 1 )
	{
		if (  threadFinishPoint == true  ) 
		{
			gotoxy ( x , 52 ) ;
			cout << "                                                                               " <<endl ;
			break ;
		}
		gotoxy ( x , 52 ) ;
		cout << (char*)text << endl ; 
		if (  threadFinishPoint == true  ) 
		{
			gotoxy ( x , 52 ) ;
			cout << "                                                                               " <<endl ;
			break ;
		}
		Sleep(500) ;
		if (  threadFinishPoint == true  ) 
		{
			gotoxy ( x , 52 ) ;

			cout << "                                                                               " <<endl ;
			break ;
		}
		gotoxy ( x , 52 ) ;
		cout << "                                                                                   " <<endl ;
		if (  threadFinishPoint == true  ) 
		{
			gotoxy ( x , 52 ) ;
			cout << "                                                                               " <<endl ;
			break ;
		}
		Sleep ( 500 ) ;	
	}
	
	_endthread () ;
}

extern void write_login_details ( char user[] , char pwd[] )
{
	FILE* fp ;
	login_credentials login ;

	encode ( user ) ;
	encode ( pwd ) ;

	strcpy ( login.username , user ) ;
	strcpy ( login.password , pwd ) ;

	fp = fopen ( "log_crd.bin" , "wb+" ) ;

	fwrite( &login , sizeof(login_credentials) , 1 , fp );
	fclose ( fp ) ;

	decode ( login.username , login.password ) ;

}