
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
template <class T> class Solid
{
public:
    virtual T GetVolume() = 0;
	virtual T GetSurface() = 0;
};

template <class T> class Box : public Solid <T>
{
private:
	T width;
	T height;
	T depth;

public:
	/// <summary>
	/// Boxのコンストラクタ
	/// </summary>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	/// <param name="depth">奥行</param>
	Box(T width, T height, T depth)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
	}

	T GetVolume()
	{
		return width * height * depth;
	}

	T GetSurface()
	{
		return (width * height + height * width + width * depth) * 2;
	}

};

template <class T> class Cylinder : public Solid <T>
{
private:
	T radius;
	T height;

public:
	/// <summary>
	/// 円柱のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	Cylinder(T radius, T height)
	{
		this->radius = radius;
		this->height = height;
	}

	T GetVolume()
	{
		return radius * radius * M_PI * radius;
	}

	T GetSurface()
	{
		return (radius * radius * M_PI * 2) + (radius * 2 * M_PI * radius);
	}

};

template <class T> class Cone : public Solid <T>
{
private:
	T radius;
	T height;

public:
	/// <summary>
	/// 円錐のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	/// <param name="height">高さ</param>
	Cone(T radius, T height)
	{
		this->radius = radius;
		this->height = height;
	}

	T GetVolume()
	{
		return radius * radius * M_PI * height / 3;
	}

	 T GetSurface()
	 {
		 return (radius * M_PI) * (sqrt(radius * radius + height * height) * radius);
	 }

};

template <class T> class Sphere : public Solid <T>
{
private:
	T radius;

public:
	/// <summary>
	/// 球のコンストラクタ
	/// </summary>
	/// <param name="radius">半径</param>
	Sphere(T radius)
	{
		this->radius = radius;
	}

	T GetVolume()
	{
		return radius * radius * radius * M_PI * 4 / 3;
	}

	 T GetSurface()
	 {
		 return radius * radius * M_PI * 4;
	 }

};

int main()
{
	Box<double> box(0.5, 5, 2);
	Cylinder<int> cylinder(2, 2);
	Cone<float> cone(2, 3);
	Sphere<double> sphere(2);

	cout << "Box　体積:" << box.GetVolume() << "表面積:" << box.GetSurface() << endl;
	cout << "円柱　体積:" << cylinder.GetVolume() << "表面積:" << cylinder.GetSurface() << endl;
	cout << "円錐　体積:" << cone.GetVolume() << "表面積:" << cone.GetSurface() << endl;
	cout << "球　体積:" << sphere.GetVolume() << "表面積:" << sphere.GetSurface() << endl;
}