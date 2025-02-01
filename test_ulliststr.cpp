#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr ullist = ULListStr();
    // tesing push_back
    ullist.push_back("4");
    ullist.push_back("5");
    ullist.push_back("6");
    // 4,5,6
    cout << "testing push_back...\n";
    for (size_t i = 0; i < ullist.size(); i++) {
        cout << ullist.get(i) << endl;
    }
    // tesing push_front
    ullist.push_front("3");
    ullist.push_front("2");
    ullist.push_front("1");

    cout << "\ntesing push_front...\n";
    for (size_t i = 0; i < ullist.size(); i++) {
        cout << ullist.get(i) << endl;
    }

    ullist.pop_front();
    cout << "\ntesting pop_front...\n";
    for (size_t i = 0; i < ullist.size(); i++) {
        cout << ullist.get(i) << endl;
    }

    ullist.pop_back();
    cout << "\ntesting pop_back...\n";
    for (size_t i = 0; i < ullist.size(); i++) {
        cout << ullist.get(i) << endl;
    }

    cout << "\ntesting front...\n";
    cout << ullist.front();

    cout << "\ntesting back...\n";
    cout << ullist.back();
}
