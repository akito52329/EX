
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// ���̂̒�`
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
	/// ���̃R���X�g���N�^
	/// </summary>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	/// <param name="depth">���s</param>
	/// <param name="name">���̖̂��O</param>
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
	/// �~���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	/// <param name="height">����</param>
	/// <param name="name">���̖̂��O</param>
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
	/// �~���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	/// <param name="height">����</param>
	/// <param name="name">���̖̂��O</param>
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
	/// ���̃R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	/// <param name="name">���̖̂��O</param>
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
	cout << "�̐�:" <<solid -> GetVolume() << "�\�ʐ�:" << solid->GetSurface() << endl;
}

void GetPacckage(double length, string name)
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
		cout << name << "�̃T�C�Y��" << kuronekoSize[i] << "�T�C�Y�ł�" << endl;
	}
	else {
		cout << "����"<< name <<"���͑�}�ւł͑���܂���" << endl;
	}

}


int main()
{
	Box box(10, 5, 2 , "��");
	Cylinder cylinder(2, 2, "�~��");
	Cone cone(50, 100, "�~��");
	Sphere sphere(9, "��");

	const int TABLE = 4;
	Solid* solid[TABLE] = {&box,&cylinder,&cone,&sphere};
	for (int i = 0; i < TABLE; i++)
	{
		DisplayVolumeSurface(solid[i]);
		GetPacckage(solid[i]->GetPackageLength(), solid[i]->GetName());

	}
}

string Solid::GetName()
{
	return string();
}
