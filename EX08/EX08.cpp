
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// ¨ÌÌè`
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
	double width;
	double height;
	double depth;

public:
	/// <summary>
	/// BoxÌRXgN^
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height">³</param>
	/// <param name="depth">s</param>
	Box(double width, double height, double depth)
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
	double radius;
	double height;

public:
	/// <summary>
	/// ~ÌRXgN^
	/// </summary>
	/// <param name="radius">¼a</param>
	/// <param name="height">³</param>
	Cylinder(double radius, double height)
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
	double radius;
	double height;

public:
	/// <summary>
	/// ~ÌRXgN^
	/// </summary>
	/// <param name="radius">¼a</param>
	/// <param name="height">³</param>
	Cone(double radius, double height)
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
	double radius;

public:
	/// <summary>
	/// ÌRXgN^
	/// </summary>
	/// <param name="radius">¼a</param>
	Sphere(double radius)
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
	Cylinder<double> cylinder(2, 2);
	Cone<double> cone(2, 3);
	Sphere<double> sphere(2);

	cout << "Box@ÌÏ:" << box.GetVolume() << "\ÊÏ:" << box.GetSurface() << endl;
	cout << "~@ÌÏ:" << cylinder.GetVolume() << "\ÊÏ:" << cylinder.GetSurface() << endl;
	cout << "~@ÌÏ:" << cone.GetVolume() << "\ÊÏ:" << cone.GetSurface() << endl;
	cout << "@ÌÏ:" << sphere.GetVolume() << "\ÊÏ:" << sphere.GetSurface() << endl;
}