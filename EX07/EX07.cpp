
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

};

class Box : public Solid
{
private:
	double width;
	double height;
	double depth;

public:
	/// <summary>
	/// Boxのコンストラクタ
	/// </summary>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	/// <param name="depth">奥行</param>
	Box(double width, double height, double depth)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
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

};

class Cylinder : public Solid
{
private:
	double radius;
	double height;

public:
	/// <summary>
	/// 円柱のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	Cylinder(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
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

};

class Cone : public Solid
{
private:
	double radius;
	double height;

public:
	/// <summary>
	/// 円錐のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	Cone(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
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
};

class Sphere : public Solid
{
private:
	double radius;

public:
	/// <summary>
	/// 球のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	Sphere(double radius)
	{
		this->radius = radius;
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
};



void DisplayVolumeSurface(Solid* solid)
{
	cout << "体積:" <<solid -> GetVolume() << "表面積:" << solid->GetSurface() << endl;
}

void GetPacckage(double length)
{
	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	int packageSize = 0;

	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << "箱のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この箱は宅急便では送れません" << endl;
	}
}


int main()
{
	Box box(10, 5, 2);
	Cylinder cylinder(50, 2);
	Cone cone(2, 100);
	Sphere sphere(9);

	const int TABLE = 4;
	Solid* solid[TABLE] = {&box,&cylinder,&cone,&sphere};
	for (int i = 0; i < TABLE; i++)
	{
		DisplayVolumeSurface(solid[i]);
		GetPacckage(solid[i]->GetPackageLength());
	}
}

