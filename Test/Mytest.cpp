/**
*cpp file of assignment 4 Unit-Test
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//libraries
#include <boost/test/minimal.hpp>
#include "CircularInt.hpp"
using namespace std;
//main 
int test_main( int, char *[ ] ) // note the name! 
{
    CircularInt hour {1, 12};
    CircularInt tmp=hour;
    //before operator
	BOOST_CHECK( hour.getPos()==1);
    //operator '+='
	hour += 4;  
    BOOST_CHECK(hour.getPos()==5);
    //operators '+=' and '++'
	(hour+=2)++;
    BOOST_CHECK(hour.getPos()==8);
    //operator '+='
    hour += 18;
    BOOST_REQUIRE(hour.getPos()==2);
    //operator '-'
    -hour;
    BOOST_REQUIRE(hour.getPos()==10);
    //operators '=' and int '+' CircularInt
	hour= 1-hour;
    BOOST_REQUIRE(hour.getPos()==3);            //BOOST_REQUIRE(hour.getPos()==11);
    //operator CircularInt '+' CircularInt
    tmp=hour+hour; 
    if( tmp.getPos()== 3 )
         BOOST_FAIL( "Ouch..." ); 
	// cout << hour+hour << endl;                // 10 (11 hours after 11)
    hour += 8;
    //operator '*='
    hour *= 2; 
    if (!(hour.getPos()== 10))
        BOOST_FAIL( "Ouch..." );
    //operator '/'
    tmp=hour/2;
    if (!(tmp.getPos()==5 || tmp.getPos()==11))  // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).
        BOOST_FAIL( "Ouch..." );	
	return 0;                                    // #returns error code 
}
