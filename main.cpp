#include <iostream>
#include "hello.h"
#include "world.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    cout << "Say Main" << endl;
    say_Hello();
    say_World();

    return 0;
}