#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    int n;
    std::vector<double> a;
    double mult = 1;

    std::cout << "Enter n number: ";
    std::cin >> n;
    
    a.resize(n);

    std::cout << "Enter massive: ";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        mult *= a[i];
    }

    std::cout << "The result is: " << mult << std::endl;

    return 0;
}