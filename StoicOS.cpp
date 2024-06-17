/// Opensource MihneaTs1 2024

#include <Windows.h>
#include "boot_mgr.h"
#include "terminal.h"

using namespace std;

int main()
{
    system("pause");
    system("CLS");

    /// This is where everything begins...
    boot_mgr::startup();
    terminal::init();

    return 0;
}
