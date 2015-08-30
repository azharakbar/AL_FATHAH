#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std ;

class fee_details
{
private:
	int admno ;
	int fee_init ;
	string date_admitted ;
	string last_payd ;
public:
	fee_details ()
	{
		admno = 0 ;
		fee_init = 0 ;
		date_admitted = "" ;
		last_payd = "" ;
	}
};


extern void fee_central_control ( int choice )
{
	int x = 0 ;
	switch ( choice )
	{
		case 1 :
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