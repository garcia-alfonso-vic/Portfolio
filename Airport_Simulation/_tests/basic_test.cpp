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
#include "../includes/linked_list_functions/linkedlistfunctionsTemplated.h"
#include "../includes/node/node.h"
#include "../includes/stack/MyStack.h"
#include "../includes/queue/MyQueue.h"
#include "../includes/airport/simulation.h"

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

/* LINKED LIST TESTS */
bool TEST_LINKED_LIST(bool debug, bool (*func)(bool) ); 
bool Test_Linked_List_Delete(bool debug = false);
bool Test_Linked_List_Copy(bool debug = false);

/* QUEUE TESTS */
bool TEST_QUEUE(bool debug, bool (*func)(bool));
bool Test_Queue(bool debug = false);

/* STACK TESTS */
bool TEST_STACK(bool debug, bool (*func)(bool));
bool Test_Stack(bool debug = false);

bool AIRPORT_TEST(bool debug, bool (*func)(bool));
bool Airport_Test(bool debug = false);
int RUN_ALL_TESTS()
{
    bool debug = true;
    if ( TEST_STUB(debug, Test_Stub) == EXIT_FAILURE )
        return EXIT_FAILURE;
    if ( TEST_LINKED_LIST(debug, Test_Linked_List_Delete)  == EXIT_FAILURE ) 
        return EXIT_FAILURE;
    if ( TEST_LINKED_LIST(debug, Test_Linked_List_Copy)  == EXIT_FAILURE )
        return EXIT_FAILURE;
    if ( TEST_QUEUE(debug, Test_Queue) == EXIT_FAILURE )
      return EXIT_FAILURE;
    if ( TEST_STACK(debug, Test_Stack) == EXIT_FAILURE )
      return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}
int main(int argc, char **argv) {
    std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;

    if ( RUN_ALL_TESTS() == EXIT_FAILURE)
        cout << "\n[ RUN ALL TESTS ]\t: QUIT :\t[ FAILED ]!\n\n";
      
    cout << "\n[ RUN ALL TESTS ]\t: DONE :\t[ SUCCESS ]\n\n"; 
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

bool TEST_LINKED_LIST(bool debug, bool (*func)(bool))
{
    if (debug) cout << "Calling TEST_CLASS().\n\n";
    return func(debug);
}
bool Test_Linked_List_Delete(bool debug)
{
  bool result = false;
	cout << "[Linked List Delete]\t: BEGIN :\t[OK]\n\n";
	cout << "======\tBEGINNING LINKED LIST : DELETE\t========\n\n";
  node<int> *head=nullptr;
  for (int i = 0; i < 10; i++){
    _insert_head(head, (i+1) * 10);
  }
  _print_list(head);
  cout << "======== testing deleting function ======== \n";

  node<int>* middle = head->_next->_next->_next->_next->_next->_next;
  cout << "deleted from middle list: " << _delete_node(head, middle);
  _print_list(head);

  node<int>* front = head;
  cout << "deleted from front list: " << _delete_node(head, front);
  _print_list(head);

  node<int>* last = _search_list(head, 10);
  cout << "deleted from last list: " << _delete_node(head, last);
  _print_list(head);


  node<int>* found_mid = _search_list(head, middle->_item);
  node<int>* found_last = _search_list(head, last->_item);
  
  if (head->_item == 100)
    cout << "Deleting from beginnning FAILED!\n";

  if (found_mid != nullptr)
    cout << "Deleting from middle FAILED\n";

  if (found_last != nullptr)
    cout << "Deleting from last FAILED\n";

  if (head->_item != 100 && found_mid == nullptr && found_last == nullptr) 
    result = true;
  
  if (!result )
  {
		cout << "[Linked List Delete] : FALIED" << endl;
		return EXIT_FAILURE;
  }
    
		cout << "======\tENDING LINKED LIST : DELETE\t========\n\n";
    cout << "[Linked List Delete]\t: END :\t[SUCCESS]\n\n";
  return EXIT_SUCCESS;
}
bool Test_Linked_List_Copy(bool debug)
{
	cout << "[Linked List Copy]\t: BEGIN :\t[OK]\n\n";
	cout << "======\tBEGINNING LINKED LIST : COPY\t========\n\n";
  if (debug){
    cout << "testB:: test_linked_list_copy() entering test_linked_list_copy" << endl;
  }
	
  node<int> *head=nullptr;
  for (int i = 0; i < 10; i++){
    _insert_head(head, (i+1) * 10);
  }
  _print_list(head);

  cout << "======= Testing copying function() =========\n";
  node<int>* copy_list = _copy_list(head);
  cout << "Printing original: \n";
  _print_list(head);

  cout << "Printing copy: \n";
  _print_list(copy_list);

  node<int>* after_this = head->_next;
  node<int>* inserted = _insert_after(head, after_this, 85);

  cout << "====== Copying list again with 85 inserted ======\n";
  node<int>* lastNodeOf = _copy_list(lastNodeOf, head);
  cout << "Printing lastNodeOf :\n";
  _print_list(lastNodeOf);
  cout << "Previous of lastNodeOf : " << *(_previous_node(lastNodeOf)) << endl;
  cout << "======\tENDING LINKED LIST : COPY\t========\n\n";
  cout << "[Linked List Copy]\t: END :\t[SUCCESS]\n\n";
  return EXIT_SUCCESS; 
}
bool TEST_QUEUE(bool debug, bool (*func)(bool))
{
  return func(debug);
}
bool Test_Queue(bool debug)
{
  cout << "[ QUEUE ]\t: BEGIN :\t[OK]\n\n";
	cout << "======\tBEGINNING LINKED LIST : DELETE\t========\n\n";
  //1.  declare an instance of the Stack (Queue) class, in a for 
  //    loop, push 0..9 into the object, print the object
  Queue<int> qHead;
  for (int i = 0; i < 10; i++)
  {
    qHead.push(i);
  } 
  cout << "q:" << qHead << "|||"<< endl;
  cout << endl<< endl;

  //2.  Declare another object using the copy constructor to be a copy 
  //    of this first object.
  Queue<int> qHeadCopy = qHead;

  cout << "q2:" << qHeadCopy << "|||" << endl;
  cout << endl<< endl;

  //3.  while the container is not empty, pop (show the popped item 
  //    in braces { } )and reprint the object
  Queue<int>::Iterator it = qHeadCopy.begin();
  for (;!(qHeadCopy.empty());)
  {
    cout << "{" << qHeadCopy.pop() << "}" << qHeadCopy << "|||" << endl;
  }

  //4. when the object is empty, assign the second object back into the first 
  //and reprint both objects.
  qHeadCopy = qHead;
  cout << "assigning s back to s2: ";
  cout << "s: " << qHead << "|||" << endl;
  cout << "s2: " << qHeadCopy << "|||" << endl;
  
  cout << "pointer of s:\n";
  qHead.print_pointers();

  cout << "pointer of s2:\n";
  qHeadCopy.print_pointers();

  Queue<int>DeepCopy(qHead);
  cout << "pointer of s3:\n";
  DeepCopy.print_pointers();

  Queue<int> queue;
  queue.push(10);
  queue.push(20);
  queue.push(30);

  cout << endl;
  cout << "{ " << queue.size() << " }"<< queue;
  cout << "poppped : " << " { " << queue.size() << " } "<< queue.pop() << " " << queue;
  cout << "poppped : " << " { " << queue.size() << " } "<< queue.pop() << " " << queue;
  cout << "poppped : " << " { " << queue.size() << " } "<< queue.pop() << " " << queue;


  queue.push(50);
  cout << "{ " << queue.size() << " }"<< queue;
  cout << "poppped : " << queue.pop() << " " << queue;
  cout << queue;
  cout << endl << endl;

  cout << qHead << "|||\n";
  

  for (Queue<int>::Iterator it2 = qHead.begin(); it2 != qHead.end(); it2++)
  {
    cout << *it2 << " ";
  }
  for (;!qHead.empty();)
  {
    qHead.pop();
  }
  if (qHead.empty())
    cout << "Queue is empty||||\n\n";
  else 
    cout << "Queue should be empty :||||\n\n";
  cout << "======\tENDING QUEUE\t========\n\n";
  cout << "[ Queue ]\t: END :\t[SUCCESS]\n\n";
  return EXIT_SUCCESS;
}
bool TEST_STACK(bool debug, bool (*func)(bool))
{
  return func(debug);
}
bool Test_Stack(bool debug)
{
  cout << "[ Stack ]\t: BEGIN :\t[OK]\n\n";
	cout << "======\tBEGINNING STACK\t========\n\n";
  Stack<int> s;
  for (int i = 0; i < 10; i++)
  {
    s.push(i);
  }
  cout << "s" << s;

  Stack<int> s2(s);
  cout << "s2" << s2;

  for (;!s2.empty();)
  {
    cout << "{ " << s2.pop() << "} " << s2 << "|||\n";
  }

  s2 = s;
  cout << "assiging s back to s2: s: " << s << "|||\n";
  cout << "s2: " << s2 << "|||\n\n";
  cout << "=========\tENDING STACK\t========\n\n";
  cout << "[ Stack ]\t: END :\t[SUCCESS]\n\n";
  return EXIT_SUCCESS;
}
bool AIRPORT_TEST(bool debug, bool (*func)(bool))
{
  return func(debug);
}
bool Airport_Test(bool debug)
{
  cout<<endl<<endl<<"======================================="<<endl<<endl;
  srand(time(0));
  for (int i=0; i<20; i++){
      cout << "---------------------- [" << i << "] ---------------------------" << endl;
      simulate_airport(debug);
  }
  cout <<endl<<endl<< "========== END SIMULATION ==================" << endl;
  
  return true;
}