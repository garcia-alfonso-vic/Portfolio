#include <iostream>
using namespace std;

int invoke(int (*f) (int) , int arg);
int add(int arg);
int sub(int arg);
// int main()
// {
//     cout << invoke(add, 10) << endl;
//     cout<< invoke(sub, 121) << endl;
//     return 0;
// }
int invoke(int (*f) (int) , int arg)
{
    return f(arg);
}
int add(int arg)
{
    return  arg + arg - arg;
}
int sub(int arg)
{
    return arg - arg + arg;
}
