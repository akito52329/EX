
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// ���̂̒�`
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
	/// Box�̃R���X�g���N�^
	/// </summary>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	/// <param name="depth">���s</param>
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
	/// �~���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	/// <param name="height">����</param>
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
	/// �~���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	/// <param name="height">����</param>
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
	/// ���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
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

	cout << "Box�@�̐�:" << box.GetVolume() << "�\�ʐ�:" << box.GetSurface() << endl;
	cout << "�~���@�̐�:" << cylinder.GetVolume() << "�\�ʐ�:" << cylinder.GetSurface() << endl;
	cout << "�~���@�̐�:" << cone.GetVolume() << "�\�ʐ�:" << cone.GetSurface() << endl;
	cout << "���@�̐�:" << sphere.GetVolume() << "�\�ʐ�:" << sphere.GetSurface() << endl;
}