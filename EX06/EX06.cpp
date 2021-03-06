
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// ¨ÌÌè`
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
	/// ~ÌRXgN^
	/// </summary>
	/// <param name="radius">¼a</param>
	/// <param name="height">³</param>
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
		return (radius * radius * M_PI * 2) + (radius * 2 * M_PI * height);
	}

};

class Cone : Solid
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

	double GetVolume()
	{
		return radius * radius * M_PI * height / 3;
	}

	double GetSurface()
	{
		return (radius * M_PI) * (sqrt(radius * radius + height * height) * radius);
	}

};

class Sphere : Solid
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

	double GetVolume()
	{
		return radius * radius * radius * M_PI * 4 / 3;
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

	cout << "Box@ÌÏ:" << box.GetVolume() << "\ÊÏ:" << box.GetSurface() << endl;
	cout << "~@ÌÏ:" << cylinder.GetVolume() << "\ÊÏ:" << cylinder.GetSurface() << endl;
	cout << "~@ÌÏ:" << cone.GetVolume() << "\ÊÏ:" << cone.GetSurface() << endl;
	cout << "@ÌÏ:" << sphere.GetVolume() << "\ÊÏ:" << sphere.GetSurface() << endl;
}