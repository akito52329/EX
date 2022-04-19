#include <iostream>
#include <iomanip>
#include "GetBmi.h"
#include "GetObesit.h"
using namespace std;

int main()
{
	double height;//身長
	double weight;//体重
	double bmi;//BMI
	int obesitDrees;//肥満度

	cout << "身長(㎝)で入力してください：";
	cin >> height;

	cout << "体重(kg)で入力してください：";
	cin >> weight;

	bmi = GetBmi(height, weight);
	obesitDrees = GetObesit(bmi);

	string obesit;

	switch (obesitDrees)
	{
	case -1:
		obesit = "低体重(痩せ型)";
		break;
	case 0:
		obesit = "普通体重";
	case 1:
		obesit = "肥満(1度)";
		break;
	case 2:
		obesit = "肥満(2度)";
		break;
	case 3:
		obesit = "肥満(3度)";
		break;
	case 4:
		obesit = "肥満(4度)";
		break;
	}

	cout << "あなたのBMIは" << fixed << setprecision(1) << bmi << "です" << endl;
	cout << "肥満度は" << obesit << "です。" << endl;
	return 0;
}




