#include <iostream>
#include <iomanip>
#include "GetBmi.h"
#include "GetObesit.h"
using namespace std;

string Obesit(int drees)
{
	switch (drees)
	{
	case -1:
		return "低体重(痩せ型)";
	case 0:
		return "普通体重";
	case 1:
		return  "肥満(1度)";
	case 2:
		return  "肥満(2度)";
	case 3:
		return "肥満(3度)";
	case 4:
		return "肥満(4度)";
	}
}

int main()
{
	double height;//身長
	double weight;//体重
	double bmi;//BMI
	int obesitDrees;//肥満度
	string obesit;//肥満度文字
	cout << "身長(㎝)で入力してください：";
	cin >> height;

	cout << "体重(kg)で入力してください：";
	cin >> weight;

	bmi = GetBmi(height, weight);
	obesitDrees = GetObesit(bmi);
	obesit = Obesit(obesitDrees);
	
	cout << "あなたのBMIは" << fixed << setprecision(1) << bmi << "です" << endl;
	cout << "肥満度は" << obesit << "です。" << endl;
	return 0;
}




