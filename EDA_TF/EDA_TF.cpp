#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "ItemControl.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    
    ItemControl* control = new ItemControl;

    control->menu();
    
    delete control;
    return 0;
}