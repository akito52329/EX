#include <iostream>
#include "getVolumeSurface.h"
using namespace std;

int main() {
	double x, y, z;
	cout << "�������:";
	cin >> x;
	cout << "���������:";
	cin >> y;
	cout << "���s�����:";
	cin >> z;
	double volume, surface;
	volume = GetVolumeSurface(x, y, z, &surface);
	cout << "�̐ς́A" << volume << endl << "�\�ʐς́A" << surface << endl;
	return 0;
}