#include <iostream>

using namespace std ;

extern void x ( int t , int a = 2 ) ;

extern void y ( )
{
	x (2) ;
}