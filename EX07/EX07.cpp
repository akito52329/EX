
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid
{
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
	virtual double GetPackageLength() = 0;
	virtual string GetName();
};

class Box : public Solid
{
private:
	double width;
	double height;
	double depth;
	string name;

public:
	/// <summary>
	/// 箱のコンストラクタ
	/// </summary>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	/// <param name="depth">奥行</param>
	/// <param name="name">物体の名前</param>
	Box(double width, double height, double depth , string name)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
		this->name = name;
	}

	double GetVolume()
	{
		return width * height * depth;
	}

	double GetSurface()
	{
		return (width * height + height * depth + width * depth) * 2;
	}

	double GetPackageLength()
	{
		return this->width + this->height + this->depth;
	}

	string GetName()
	{
		return this->name;
	}
};

class Cylinder : public Solid
{
private:
	double radius;
	double height;
	string name;

public:
	/// <summary>
	/// 円柱のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	/// <param name="name">物体の名前</param>
	Cylinder(double radius, double height, string name)
	{
		this->radius = radius;
		this->height = height;
		this->name = name;
	}

	double GetVolume()
	{
		return radius * radius * M_PI * height;
	}

	double GetSurface()
	{
		return (radius * radius * M_PI * 2) + (radius * 2 * M_PI * height);
	}

	double GetPackageLength()
	{
		return this->radius * 4 + this->height;
	}

	string GetName()
	{
		return this->name;
	}

};

class Cone : public Solid
{
private:
	double radius;
	double height;
	string name;

public:
	/// <summary>
	/// 円錐のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	/// <param name="name">物体の名前</param>
	Cone(double radius, double height, string name)
	{
		this->radius = radius;
		this->height = height;
		this->name = name;
	}

	double GetVolume()
	{
		return radius * radius * M_PI * height / 3;
	}

	double GetSurface()
	{
		return (radius * M_PI) * (sqrt(radius * radius + height * height) * radius);
	}

	double GetPackageLength()
	{
		return this->radius * 4 + this->height;
	}

	string GetName()
	{
		return this->name;
	}
};

class Sphere : public Solid
{
private:
	double radius;
	string name;


public:
	/// <summary>
	/// 球のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="name">物体の名前</param>
	Sphere(double radius , string name)
	{
		this->radius = radius;
		this->name = name;
	}

	double GetVolume()
	{
		return radius * radius * radius * M_PI * 4 / 3;
	}

	double GetSurface()
	{
		return radius * radius * M_PI * 4;
	}

	double GetPackageLength()
	{
		return this->radius * 6;
	}

	string GetName()
	{
		return this->name;
	}
};



void DisplayVolumeSurface(Solid* solid)
{
	cout << solid->GetName() << "→体積:" << solid->GetVolume() << "表面積:" << solid->GetSurface() << endl;
}

void GetPacckage(Solid* solid)
{
	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	int packageSize = 0;
	double length = solid->GetPackageLength();
	string name = solid->GetName();

	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << name << "のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この"<< name <<"箱は宅急便では送れません" << endl;
	}
}


int main()
{
	Box box(10, 5, 2 , "箱");
	Cylinder cylinder(2, 2, "円柱");
	Cone cone(50, 100, "円錐");
	Sphere sphere(9, "球");

	const int TABLE = 4;
	Solid* solid[TABLE] = {&box,&cylinder,&cone,&sphere};
	for (int i = 0; i < TABLE; i++)
	{
		DisplayVolumeSurface(solid[i]);
		GetPacckage(solid[i]);
	}
}

string Solid::GetName()
{
	return string();
}
