#include <vector>
#include "header.h"

// Импортируем только нужные типы
using std::vector;

using namespace ArrayFuncs;
using namespace print_array_operations;

int main(int argc, char *argv[])
{   
    vector<double> a;
    process_array_operations(a);

    return 0;
}