#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../testing_main.h"
//------------------------------------------------------------------------------------------
using namespace std;
/* SUITE Test : first @param is flag to display error messages - second @param is 
*   a return value for function called as a parameter. We return this value. 
*/

bool TEST_STUB(bool debug, bool (*func)(bool) ); //SUITE 
/* Test : @param is a flag to display error messsages - main testing occurs here. If
*        andthing goes wrong in expected results - quit function and return 
*       with EXIT_FAILURE. SUITE test will look at EXIT_FAILURE and fail itself.
*/
bool Test_Stub(bool debug = false); //SINGLE TEST

bool TEST_CLASS(bool debug, bool (*func)(bool) ); 
bool Test_Class_Subtask_One(bool debug = false);
bool Test_Class_Subtask_Two(bool debug = false);
int RUN_ALL_TESTS()
{
    bool debug = true;
    if ( TEST_STUB(debug, Test_Stub) == EXIT_FAILURE )
        return EXIT_FAILURE;
    if ( TEST_CLASS(debug, Test_Class_Subtask_One)  == EXIT_FAILURE) 
        return EXIT_FAILURE;
    if ( TEST_CLASS(debug, Test_Class_Subtask_Two)  == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
int main(int argc, char **argv) {
    std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;

    if (RUN_ALL_TESTS() == EXIT_FAILURE)
        cout << "\nTEST FAILED!\n\n";
    return EXIT_SUCCESS;
}
bool TEST_STUB(bool debug,  bool (*func)(bool) )
{
    if (debug) cout << "Calling TEST_STUB().\n\n";

    return func(debug);
}
bool Test_Stub(bool debug)
{   
    if (debug) cout << "Calling Test_Stub().\nmain testing goes here...\n";
    return EXIT_SUCCESS;
}

bool TEST_CLASS(bool debug, bool (*func)(bool))
{
    if (debug) cout << "Calling TEST_CLASS().\n\n";
    return func(debug);
}
bool Test_Class_Subtask_One(bool debug)
{
    if (debug) cout << "Calling Test_Class_Subtask_One().\nmain testing goes here...";
    cout << endl;
    return EXIT_SUCCESS;
}
bool Test_Class_Subtask_Two(bool debug)
{
      if (debug) cout << "Calling Test_Class_Subtask_Two().\nmain testing goes here...";
      cout << endl;
      return EXIT_SUCCESS;
}