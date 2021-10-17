#include <iostream>
#include <string>
#include "xstring.h"

using namespace std;

int main()
{
	xstring a;
    cin >> a;
    cout << a.b64encode() << endl;
	return 0;
}