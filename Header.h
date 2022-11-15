#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <math.h>
using namespace std;


class  Coord {
private:
	double X;
	double Y;
public:
	Coord(double _X, double _Y);
	Coord();
	double GetX();
	double GetY();
};

class  Coord3D {
private:
	double X;
	double Y;
	double Z;
public:
	double GetAxisX();
	double GetAxisY();
	double GetAxisZ();
	Coord3D();
	Coord3D(double _x, double _y, double _z);
	Coord CamView(Coord3D root);
	Coord3D RotateX(double Angle);
	Coord3D RotateY(double Angle);
	Coord3D RotateZ(double Angle);
	
	Coord3D MoveAxis(double OffsetX, double OffsetY, double OffsetZ);


};

//Coord3D operator + (Coord3D c1, Coord3D c2) {
//	return Coord3D(c1.GetAxisX() + c2.GetAxisX(), c1.GetAxisY() + c2.GetAxisY(), c1.GetAxisZ() + c2.GetAxisZ());
//}


class Cube {
public:
	Coord3D root;

	Coord3D A1;
	Coord3D B1;
	Coord3D C1;
	Coord3D D1;

	Coord3D A2;
	Coord3D B2;
	Coord3D C2;
	Coord3D D2;
	Cube();
	void CubeRotateX(double Angle);
	void CubeRotateY(double Angle);
	void CubeRotateZ(double Angle);

	void CubeMoveAxis(double OffsetX, double OffsetY, double OffsetZ);

};

class Drawer {
public:
	void DrawDot(HDC dc, Coord pos);
	void Drawline(HDC dc, Coord pos);
	
};
#pragma once
