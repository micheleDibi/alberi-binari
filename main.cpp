#include <iostream>

#include "binTreeVettori.h"
#include "binTreePuntatori.h"

using namespace std;

int main()
{
    linkedBinTree<int> alberoPunt;

	alberoPunt.insRoot();
	alberoPunt.write(alberoPunt._root(), 10);
	alberoPunt.insSX(alberoPunt._root(), 20);

	alberoPunt.previsita(alberoPunt._root());
	cout << "Hello world!" << endl;
    return 0;
}
