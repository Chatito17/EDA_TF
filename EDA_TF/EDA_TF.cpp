#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "ItemControl.h"
#include "UsuarioControl.h"
using namespace std;

int main()
{
    srand(time(nullptr));
    UsuarioControl* control = new UsuarioControl;
    //ItemControl* control = new ItemControl;

    control->menu();
    
    delete control;
    return 0;
}