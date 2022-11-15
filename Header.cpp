#include "Header.h"

void Drawer::DrawDot(HDC dc, Coord pos)
{
	MoveToEx(dc, pos.GetX(), pos.GetY(), NULL);
	LineTo(dc, pos.GetX()+1, pos.GetY()+1);
}

void Drawer::Drawline(HDC dc, Coord pos)
{
	LineTo(dc, pos.GetX(), pos.GetY());
}

Coord::Coord(double _X, double _Y)
{
	X = _X;
	Y = _Y;
}

Coord::Coord()
{
	X = 0;
	Y = 0;
}

double Coord::GetX()
{
	return X;
}

double Coord::GetY()
{
	return Y;
}

double Coord3D::GetAxisX()
{
	return X;
}

double Coord3D::GetAxisY()
{
	return Y;
}

double Coord3D::GetAxisZ()
{
	return Z;
}

Coord3D::Coord3D()
{
	X = 0;
	Y = 0;
	Z = 0;
}

Coord3D::Coord3D(double _x, double _y, double _z)
{
	X = _x;
	Y = _y;
	Z = _z;
}

Coord Coord3D::CamView(Coord3D root)
{
	/*
	sx = xSize/2+x*dist/(z+dist),
	sy = ySize/2-y*dist/(z+dist). */

	//double dist = 10;
	//double sx;
	//double sy;
	//sx = X * dist / (Z + dist);
	//sy = Y * dist / (Z + dist);
	
	return Coord(X*root.Z+300+root.X, Y+300+root.Y);
}

Coord3D Coord3D::RotateX(double Angle)
{
	double y = Y*cos(Angle) + Z*sin(Angle);
	double z = -Y*sin(Angle) + Z*cos(Angle);
	return Coord3D(X, y, z);
}
Coord3D Coord3D::RotateY(double Angle)
{
	double x = X * cos(Angle) + Z * sin(Angle);
	double z = -X * sin(Angle) + Z * cos(Angle);
	return Coord3D(x, Y, z);
}

Coord3D Coord3D::RotateZ(double Angle)
{
	double x = X * cos(Angle) - Y * sin(Angle);
	double y = -X * sin(Angle) + Y * cos(Angle);
	return Coord3D(x, y, Z);
}



Coord3D Coord3D::MoveAxis(double OffsetX, double OffsetY, double OffsetZ)
{
	X = OffsetX;
	Y = OffsetY;
	Z = OffsetZ;
	return Coord3D(X, Y, Z);
}

Cube::Cube()
{

	double a = 150;
	A1 = Coord3D(-a, -a, -a);
	B1 = Coord3D(-a, -a, a);
	C1 = Coord3D(a, -a, a);
	D1 = Coord3D(a, -a, -a);

	A2 = Coord3D(-a, a, -a);
	B2 = Coord3D(-a, a, a);
	C2 = Coord3D(a, a, a);
	D2 = Coord3D(a, a, -a);
}

void Cube::CubeRotateX(double Angle)
{
	A1 = A1.RotateX(Angle);
	B1 = B1.RotateX(Angle);
	C1 = C1.RotateX(Angle);
	D1 = D1.RotateX(Angle);

	A2 = A2.RotateX(Angle);
	B2 = B2.RotateX(Angle);
	C2 = C2.RotateX(Angle);
	D2 = D2.RotateX(Angle);
}

void Cube::CubeRotateY(double Angle)
{
	A1 = A1.RotateY(Angle);
	B1 = B1.RotateY(Angle);
	C1 = C1.RotateY(Angle);
	D1 = D1.RotateY(Angle);
				  
	A2 = A2.RotateY(Angle);
	B2 = B2.RotateY(Angle);
	C2 = C2.RotateY(Angle);
	D2 = D2.RotateY(Angle);
}

void Cube::CubeRotateZ(double Angle)
{
	A1 = A1.RotateZ(Angle);
	B1 = B1.RotateZ(Angle);
	C1 = C1.RotateZ(Angle);
	D1 = D1.RotateZ(Angle);
				  
	A2 = A2.RotateZ(Angle);
	B2 = B2.RotateZ(Angle);
	C2 = C2.RotateZ(Angle);
	D2 = D2.RotateZ(Angle);
}

void Cube::CubeMoveAxis(double OffsetX, double OffsetY, double OffsetZ)
{
	root = root.MoveAxis(root.GetAxisX() + OffsetX, root.GetAxisY() + OffsetY, root.GetAxisZ() + OffsetZ);
	//A1 = A1.MoveAxis(A1.GetAxisX() + OffsetX, A1.GetAxisY() + OffsetY, A1.GetAxisZ() + OffsetZ);
	//B1 = B1.MoveAxis(B1.GetAxisX() + OffsetX, B1.GetAxisY() + OffsetY, B1.GetAxisZ() + OffsetZ);
	//C1 = C1.MoveAxis(C1.GetAxisX() + OffsetX, C1.GetAxisY() + OffsetY, C1.GetAxisZ() + OffsetZ);
	//D1 = D1.MoveAxis(D1.GetAxisX() + OffsetX, D1.GetAxisY() + OffsetY, D1.GetAxisZ() + OffsetZ);

	//A2 = A2.MoveAxis(A2.GetAxisX() + OffsetX, A2.GetAxisY() + OffsetY, A2.GetAxisZ() + OffsetZ);
	//B2 = B2.MoveAxis(B2.GetAxisX() + OffsetX, B2.GetAxisY() + OffsetY, B2.GetAxisZ() + OffsetZ);
	//C2 = C2.MoveAxis(C2.GetAxisX() + OffsetX, C2.GetAxisY() + OffsetY, C2.GetAxisZ() + OffsetZ);
	//D2 = D2.MoveAxis(D2.GetAxisX() + OffsetX, D2.GetAxisY() + OffsetY, D2.GetAxisZ() + OffsetZ);
}
