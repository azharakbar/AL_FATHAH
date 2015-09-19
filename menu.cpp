#include <iostream>
#include <windows.h>

using namespace std ;

extern int main_menu () ;
extern int student_menu () ;
extern int fee_menu () ;
extern int admin_menu () ;

extern void gotoxy ( int , int ) ;
extern void header () ;
extern int  menu_control ( int , int , int , int esc = 0 ) ;

extern int main_menu ()
{
	int i=0;

	header();
	gotoxy(0,0);cout<<endl;
	gotoxy(79 , 13) ;
	cout<<"MAIN MENU"<<endl;
	gotoxy(78,14);
	cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<endl;			//11
	
	gotoxy(58,16);
	for(i=0;i<51;++i)cout<<(char)220;
	cout<<endl;
	
	gotoxy(58,17); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,18); cout<<(char)186<<"     1.  STUDENT DATABASE CENTRAL                "<<(char)186<<endl;
	gotoxy(58,19); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,20); cout<<(char)186<<"     2.  FEE COLLECTION CENTRAL                  "<<(char)186<<endl;
	gotoxy(58,21); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,22); cout<<(char)186<<"     3.  ADMIN TOOLS                             "<<(char)186<<endl;
	gotoxy(58,23); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,24); cout<<(char)186<<"     4.  LOG OFF                                 "<<(char)186<<endl;
	gotoxy(58,25); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,26); cout<<(char)186<<"     5.  EXIT                                    "<<(char)186<<endl;
	gotoxy(58,27); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,28);
	for(i=0;i<51;++i)
		cout<<(char)223;
	cout<<endl;	

	int pos = menu_control ( 60 , 18 , 26 ) ;

	pos = (pos+2)/2 ;

	return pos ;

}

extern int student_menu ()
{

	int i=0;

	header();
	gotoxy(72 , 13) ;
	cout<<"STUDENT DATABASE CENTRAL"<<endl;
	gotoxy(71,14);
	for ( i = 1 ; i <= strlen ("STUDENT DATABASE CENTRAL")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;
	
	gotoxy(58,16);
	for(i=0;i<51;++i)cout<<(char)220;
	cout<<endl;
	
	gotoxy(58,17); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,18); cout<<(char)186<<"     1.  NEW STUDENT ENTRY                       "<<(char)186<<endl;
	gotoxy(58,19); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,20); cout<<(char)186<<"     2.  EDIT STUDENT ENTRY                      "<<(char)186<<endl;
	gotoxy(58,21); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,22); cout<<(char)186<<"     3.  SEARCH STUDENT ENTRY                    "<<(char)186<<endl;
	gotoxy(58,23); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,24); cout<<(char)186<<"     4.  STUDENT MARK ENTRY                      "<<(char)186<<endl;
	gotoxy(58,25); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,26); cout<<(char)186<<"     5.  MAIN MENU                               "<<(char)186<<endl;
	gotoxy(58,27); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,28);
	for(i=0;i<51;++i)
		cout<<(char)223;
	cout<<endl;	
	
	int pos = menu_control ( 60 , 18 , 26 ) ;

	pos = ( pos + 2 ) / 2 ;

	return pos ;
}



extern int fee_menu ()
{

	int i=0;

	header();
	gotoxy(73 , 13) ;
	cout<<"FEE COLLECTION CENTRAL"<<endl;
	gotoxy(72,14);
	for ( i = 1 ; i <= strlen ("FEE COLLECTION CENTRAL")+2 ; ++i )
		cout<<char(205);		//11
	cout << endl ;
	
	gotoxy(58,16);
	for(i=0;i<51;++i)cout<<(char)220;
	cout<<endl;
	
	gotoxy(58,17); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,18); cout<<(char)186<<"     1.  FEE PAYMENT                             "<<(char)186<<endl;
	gotoxy(58,19); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,20); cout<<(char)186<<"     2.  FEE DEFAULTERS                          "<<(char)186<<endl;
	gotoxy(58,21); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,22); cout<<(char)186<<"     3.  FEE COLLECTION STATISTICS               "<<(char)186<<endl;
	gotoxy(58,23); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,24); cout<<(char)186<<"     4.  MAIN MENU                               "<<(char)186<<endl;
	gotoxy(58,25); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,26);
	for(i=0;i<51;++i)
		cout<<(char)223;
	cout<<endl;	
	
	int pos = menu_control ( 60 , 18 , 24 ) ;

	pos = ( pos + 2 ) / 2 ;

	return pos ;
}

extern int admin_menu () 
{

	int i=0;

	header();
	gotoxy(0,0);cout<<endl;
	gotoxy(79 , 13) ;
	cout<<"ADMIN MENU"<<endl;
	gotoxy(78,14);
	cout<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<endl;			//11
	
	gotoxy(58,16);
	for(i=0;i<51;++i)cout<<(char)220;
	cout<<endl;
	
	gotoxy(58,17); cout<<(char)219<<"                                                 "<<(char)219<<endl;
	gotoxy(58,18); cout<<(char)186<<"     1.  CHANGE LOGIN CREDENTIALS                "<<(char)186<<endl;
	gotoxy(58,19); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,20); cout<<(char)186<<"     2.  CHANGE FEE STRUCTURE                    "<<(char)186<<endl;
	gotoxy(58,21); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,22); cout<<(char)186<<"     3.  MAIN MENU                               "<<(char)186<<endl;
	gotoxy(58,23); cout<<(char)186<<"                                                 "<<(char)186<<endl;
/*	gotoxy(58,24); cout<<(char)186<<"     4.  LOG OFF                                 "<<(char)186<<endl;
	gotoxy(58,25); cout<<(char)186<<"                                                 "<<(char)186<<endl;
	gotoxy(58,26); cout<<(char)186<<"     5.  EXIT                                    "<<(char)186<<endl;
	gotoxy(58,27); cout<<(char)219<<"                                                 "<<(char)219<<endl;*/
	gotoxy(58,24);
	for(i=0;i<51;++i)
		cout<<(char)223;
	cout<<endl;	

	int pos = menu_control ( 60 , 18 , 22 ) ;

	pos = (pos+2)/2 ;

	return pos ;


}