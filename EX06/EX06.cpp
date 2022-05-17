
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
};

class Box : Solid 
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

};

class Cylinder: Solid
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
		return radius * radius * M_PI *  height;
	}

	double GetSurface()
	{
		return (radius * radius * M_PI * 2) + (radius * 2 * height);
	}

};

class Cone : Solid
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
		return (radius * radius * M_PI) + (sqrt(radius * radius + height * height) * (radius * 2 * height));
	}

};

class Sphere : Solid
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
		return radius * radius * M_PI * 4 / 3;
	}

	double GetSurface()
	{
		return radius * radius * M_PI * 4;
	}

};

int main()
{
	Box box(0.5, 5, 2);
	Cylinder cylinder(2 , 2);
	Cone cone(2 , 3);
	Sphere sphere(2);

	cout << "Box　体積:" << box.GetVolume() << "表面積:" << box.GetSurface() << endl;
	cout << "円柱　体積:" << cylinder.GetVolume() << "表面積:" << cylinder.GetSurface() << endl;
	cout << "円錐　体積:" << cone.GetVolume() << "表面積:" << cone.GetSurface() << endl;
	cout << "球　体積:" << sphere.GetVolume() << "表面積:" << sphere.GetSurface() << endl;
}