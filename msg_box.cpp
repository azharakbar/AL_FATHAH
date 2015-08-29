#include <iostream>
#include <stdio.h>
#include <process.h>
#include <windows.h>

using namespace std ;

void msg_box_top ( void* ) ;
void msg_box_bottom ( void* ) ;
void welcome_logo () ;

extern void gotoxy ( int , int ) ;
extern void draw_msg_box ( void* ) ;
extern void draw_banner_line ( void* params );
extern void draw_msg_box_static () ;

extern void display_msg ( void* ) ;

extern bool threadFinishPoint ;

struct msg_list_fn
{
	int n ;
	int sleep ;
	char message[5][100];
};

int flag = 0 ;

void msg_box_top ( void* param ) 
{
	flag = 1 ;

	for (int i = 0; i < 150; ++i)
	{
		if ( flag == 1 ) 
		{
			gotoxy ( 9+i , 50 );
			cout<<(char)220<<endl;	
			if ( i )
			{			
				gotoxy ( 9+(i-1) , 50 );
				cout<<(char)220<<endl;
			}
			Sleep ( 5 ) ;
			flag = 2 ;
		}
		else
			--i ;
	}	

	for ( int i = 0 ; i < 3 ; ++i )
	{
		if ( flag == 1 )
		{
			if ( !i )
			{
				gotoxy ( 158 , 51 ); cout<<(char)219<<endl ;
			}
			else if ( i == 1 )
			{
				gotoxy ( 158 , 52 ); cout<<(char)186<<endl ;
			}
			else
			{
				gotoxy ( 158 , 53 ); cout<<(char)219<<endl ;
			}
			Sleep ( 100 ) ;
			flag = 2 ;
		}
		else
			--i ;
	}
	_endthread () ;

}
void msg_box_bottom ( void* param ) 
{
	Sleep ( 100 ) ;
	
	for (int j = 158; j >= 9 ; --j)
	{
		if ( flag == 2 )
		{
			gotoxy ( j , 54 );
			cout<<(char)223<<endl;	
			if ( j < 158 )
			{
				gotoxy ( (j+1) , 54 );
				cout<<(char)223<<endl;
			}
			Sleep ( 5 ) ;
			flag = 1 ;
		}
		else
			++j ;
	}	


	for ( int i = 0 ; i < 3 ; ++i )
	{
		if ( flag == 2 )
		{
			if ( !i )
			{
				gotoxy ( 9 , 53 ); cout<<(char)219<<endl ;
			}
			else if ( i == 1 )
			{
				gotoxy ( 9 , 52 ); cout<<(char)186<<endl ;
			}
			else
			{
				gotoxy ( 9 , 51 ); cout<<(char)219<<endl ;
			}

			Sleep ( 100 ) ;
			flag = 1 ;
		}
		else
			--i ;
	}
	_endthread () ;

}

void banner_top_line (void *param)
{
	cout << endl ;
	gotoxy ( 0 , 11 );
	
	for (int i = 0; i < 85; ++i)
	{
		if ( flag == 1 )
		{
			gotoxy ( 40+i , 11 );
			cout<<(char)220	;
			gotoxy ( 40+(i-1) , 11 );
			cout<<(char)220;
			if ( i+1 >= 85 )
			Sleep ( 6 ) ;
			flag = 2 ;
		}
		else
			--i ;
	}
	cout << endl ;
    
    _endthread();
}

void banner_bottom_line  (void *param)
{
	cout << endl ;
	gotoxy ( 80 , 25 );
	
	for (int i = 84; i >= 0 ; --i)
	{
		if ( flag == 2 )
		{
			gotoxy ( 40+i , 24 );
			cout<<(char)220;
			gotoxy ( 40+(i-1) , 24 );
			cout<<(char)220;
			if ( !(i-1) ) break ;
			Sleep ( 6 ) ;
			flag = 1 ;
		}
		else
			++i ;
	}
	cout<<endl;
    
    _endthread();
}


extern void draw_msg_box ( void* params )
{
	flag = 0 ;

	HANDLE handle_array[2] ;

	handle_array[0]=(HANDLE)_beginthread ( msg_box_top , 0 , NULL );
	handle_array[1]=(HANDLE)_beginthread ( msg_box_bottom , 0 , NULL );
	
	WaitForMultipleObjects ( 2 , handle_array , true , INFINITE );	

	_endthread () ;
}

extern void draw_msg_box_static ()
{
	int i = 0 ;

	gotoxy ( 9 , 50 ) ;
	
	for(i=1;i<=150;++i)
		cout<<(char)220;
	cout<<endl ;
	
	gotoxy ( 9 , 51 ); cout<<(char)219<<endl ;
	gotoxy ( 158 , 51 ); cout<<(char)219<<endl ;
	gotoxy ( 9 , 52 ); cout<<(char)186<<endl ;
	gotoxy ( 158 , 52 ); cout<<(char)186<<endl ;
	gotoxy ( 9 , 53 ); cout<<(char)219<<endl ;
	gotoxy ( 158 , 53 ); cout<<(char)219<<endl ;	
	
	gotoxy ( 9 , 54 ) ;
	
	for(i=1;i<=150;++i)
		cout<<(char)223;
	cout<<endl ;

}


extern void draw_banner_line ( void* params )
{
	flag = 1 ;

	HANDLE handle_array[2] ;

	welcome_logo () ;

	handle_array[0]=(HANDLE)_beginthread ( banner_top_line , 0 , NULL );
	WaitForSingleObject ( handle_array[0] , 50 ) ;
	handle_array[1]=(HANDLE)_beginthread ( banner_bottom_line , 0 , NULL );
	WaitForSingleObject ( handle_array[1] , 1000 ) ;
	WaitForMultipleObjects ( 2 , handle_array , true , INFINITE );	
}

extern void display_msg ( void* msg_param )
{
	int i = 0 ;
	char msg[100] ;
	
	msg_list_fn *m = (msg_list_fn*)(msg_param) ;
	int no = (*m).n ;

	for ( int j = 0 ; j < no ; ++j )
	{
		if ( !strcmp ( (*m).message[no] , "terminate" ) ) { strcpy ( (*m).message[no] , "" ) ; delete m ; return ;}

		int size = strlen( (*m).message[j] ) ;
		
		strcpy ( msg , (*m).message[j] ) ;

		size /= 2 ;
		gotoxy ( 10 , 52 ) ;
		for ( i = 0 ; i < 148 ; ++i ) 
		{
				if ( !strcmp ( (*m).message[no] , "terminate" ) ) { strcpy ( (*m).message[no] , "" ) ; delete m ;  return ;}					
				cout << " " ;
		}
		cout<<endl;

		for ( i = 0 ; msg[i] != '\0' ; ++i )
		{

			gotoxy (( 84 - size )+i , 52 ) ;
			cout<<msg[i]<<endl ;

			if ( !strcmp ( (*m).message[no] , "terminate" ) ) { strcpy ( (*m).message[no] , "" ) ; delete m ;  return ; }

			Sleep ( (*m).sleep ) ;
			if ( !strcmp ( (*m).message[no] , "terminate" ) ) { strcpy ( (*m).message[no] , "" ) ;delete m ; return ; }
		}

		if ( !strcmp ( msg, "--- AUTHENTICATION FAILURE ---" ))
		{ 
			Sleep(500) ; 
			gotoxy ( 84-size , 52 ) ;
			printf("                              ");
			return ; 
		}

		if ( j == no-1 ) threadFinishPoint = true ;


		if ( !strcmp ( (*m).message[no] , "terminate" ) ) { strcpy ( (*m).message[no] , "" ) ; delete m ; return ; }
		Sleep ( 500 ) ;
		if ( j == no-1 ) j = -1 ;
	}

	_endthread () ;
}

void welcome_logo ()
{
	gotoxy ( 40 , 12 );
	cout<<"          .---.                                                                          "<<endl;Sleep(150);
	gotoxy ( 40 , 13 );
	cout<<"          |   |                                       .                     .           "<<endl;Sleep(150);
	gotoxy ( 40 , 14 );
	cout<<"          |   |               _.._                  .'|                   .'|           "<<endl;Sleep(150);
	gotoxy ( 40 , 15 );
	cout<<"          |   |             .' .._|             .| <  |                  <  |           "<<endl;Sleep(150);
	gotoxy ( 40 , 16 );
	cout<<"    __    |   |             | '       __      .' |_ | |             __    | |           "<<endl;Sleep(150);
	gotoxy ( 40 , 17 );
	cout<<" .:--.'.  |   |           __| |__  .:--.'.  .'     || | .'''-.   .:--.'.  | | .'''-.    "<<endl;Sleep(150);
	gotoxy ( 40 , 18 );
	cout<<"/ |   \\ | |   |          |__   __|/ |   \\ |'--.  .-'| |/.'''. \\ / |   \\ | | |/.'''. \\   "<<endl;Sleep(150);
	gotoxy ( 40 , 19 );
	cout<<"`\" __ | | |   |             | |   `\" __ | |   |  |  |  /    | | `\" __ | | |  /    | |   "<<endl;Sleep(150);
	gotoxy ( 40 , 20 );
	cout<<" .'.''| | |   |             | |    .'.''| |   |  |  | |     | |  .'.''| | | |     | |   "<<endl;Sleep(150);


	gotoxy ( 40 , 21 );
	cout<<"/ /   | |_'---'             | |   / /   | |_  |  '.'| |     | | / /   | |_| |     | |   "<<endl;Sleep(150);
	gotoxy ( 40 , 22 );
	cout<<"\\ \\._,\\ '/                  | |   \\ \\._,\\ '/  |   / | '.    | '.\\ \\._,\\ '/| '.    | '.  "<<endl;Sleep(150);
	gotoxy ( 40 , 23 );
	cout<<" `--'  `\"                   |_|    `--'  `\"   `'-'  '---'   '---'`--'  `\" '---'   '---' "<<endl;Sleep(150);

	cout<<endl;Sleep(150);	
}