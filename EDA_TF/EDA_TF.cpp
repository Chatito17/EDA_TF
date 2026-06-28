#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "MasterControl.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    
    MasterControl* control = new MasterControl();

    control->menu();
    
    delete control;
    return 0;
}