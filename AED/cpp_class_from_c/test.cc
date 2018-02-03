#include <iostream>
#include "test.hh"

using namespace std;

Test::Test(int i) {
        this->testint = i;
}

void Test::testfunc() {
        cout << "test " << this->testint << endl;
}
