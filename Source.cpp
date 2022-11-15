#include <iostream>
#include "Header.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <mmsystem.h>


using namespace std;

int main()
{
    //LPCSTR lpszSound,    	// путь и имя WAV файла
    //UINT fuSound      	// параметры проигрования
    HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
    HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
    RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
    HBRUSH brush;
    brush = CreateSolidBrush(RGB(255, 255, 255));
    HPEN PlayerPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HPEN BlankPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(dc, brush); //Выбираем кисть
    SelectObject(dc, PlayerPen);
    Drawer draw;
    PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    Cube cuboid;

    Cube cuboid2;

    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);
    cuboid2.A1 = Coord3D(0, 1, 1);



    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    double aX = 0;
    double aY = 0;
    double aZ = 0;

    double oX = 0;
    double oY = 0;
    double oZ = 0;

    LPCWSTR a;
    a = L"C:\\Users\\petrr\\Downloads\\Skeleton ebat' x SM. - Goodbye, night.mp3";
    //PlaySound(a, NULL, SND_FILENAME);
    //PlaySound("C:\\temp\\sound_test.wav", NULL, SND_FILENAME);
    while (!GetKeyState('Q'))
    {
        elapsed_seconds = end - start;
        while (elapsed_seconds.count() >= 0.01)
        {

            if (GetKeyState('W') & 0x8000)
                aX = -0.017;
            else
                

            if (GetKeyState('S') & 0x8000)
                aX = 0.017;
            else
                aX = 0.0;
            if (GetKeyState('A') & 0x8000)
                aY = -0.017;
            else                           
            if (GetKeyState('D') & 0x8000)
                aY = 0.017;
            else
                aY = 0.0;


            if (GetKeyState('X') & 0x8000)
                aZ = -0.01;
            else
            if (GetKeyState('Z') & 0x8000)
                    aZ = 0.01;
            else
                aZ = 0;
            
           
            if (GetKeyState('H') & 0x8000)
                oX = -0.5;
            else
                if (GetKeyState('K') & 0x8000)
                    oX = 0.5;
                else
                    oX = 0;
            if (GetKeyState('U') & 0x8000)
                oY = -0.5;
            else
                if (GetKeyState('J') & 0x8000)
                    oY = 0.5;
                else
                    oY = 0;
            if (GetKeyState('N') & 0x8000)
                oZ = -0.1;
            else
                if (GetKeyState('M') & 0x8000)
                    oZ = 0.1;
                else
                    oZ = 0;

           

            

            start = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            SelectObject(dc, BlankPen);
            //aX = 0.01;
            //aY = 0.01;
            draw.DrawDot(dc, cuboid.A1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.A1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A2.CamView(cuboid.root));

            
            draw.DrawDot(dc, cuboid.C1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C2.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.D1.CamView(cuboid.root));
            
            draw.DrawDot(dc, cuboid.A2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.B2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.C2.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.D2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D1.CamView(cuboid.root));


            

            cuboid.CubeRotateX(aX);
            cuboid.CubeRotateY(aY);
            cuboid.CubeRotateZ(aZ);
            cuboid.CubeMoveAxis(oX, oY, oZ);

            SelectObject(dc, PlayerPen);
            //cuboid.A1 = Coord3D( 10, 10, 10);
            draw.DrawDot(dc, cuboid.A1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.A1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A2.CamView(cuboid.root));


            draw.DrawDot(dc, cuboid.C1.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.C2.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.D1.CamView(cuboid.root));

            draw.DrawDot(dc, cuboid.A2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.A1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.B2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.B1.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.C2.CamView(cuboid.root));
            draw.DrawDot(dc, cuboid.D2.CamView(cuboid.root));
            draw.Drawline(dc, cuboid.D1.CamView(cuboid.root));

            
            

        }
        end = std::chrono::steady_clock::now();
    }
    //MoveToEx(dc, 0, 0, NULL);
	//LineTo(dc, 100, 100);

}


//
//
//draw.DrawDot(dc, cuboid.A1.CamView());
//draw.Drawline(dc, cuboid.A2.CamView());
//draw.Drawline(dc, cuboid.B1.CamView());
//draw.Drawline(dc, cuboid.B2.CamView());
//draw.Drawline(dc, cuboid.C1.CamView());
//draw.Drawline(dc, cuboid.C2.CamView());
//draw.Drawline(dc, cuboid.D1.CamView());
//draw.Drawline(dc, cuboid.D2.CamView());

//draw.DrawDot(dc, cuboid.A1.CamView());
//draw.Drawline(dc, cuboid.B1.CamView());
//draw.Drawline(dc, cuboid.C1.CamView());
//draw.Drawline(dc, cuboid.D1.CamView());
//draw.DrawDot(dc, cuboid.A1.CamView());
//draw.Drawline(dc, cuboid.A2.CamView());
//draw.Drawline(dc, cuboid.B2.CamView());
//draw.Drawline(dc, cuboid.C2.CamView());
//draw.Drawline(dc, cuboid.D2.CamView());
//
//
//draw.DrawDot(dc, cuboid.C1.CamView());
//draw.DrawDot(dc, cuboid.D1.CamView());
//
//draw.DrawDot(dc, cuboid.A2.CamView());
//draw.DrawDot(dc, cuboid.B2.CamView());
//draw.DrawDot(dc, cuboid.C2.CamView());
//draw.DrawDot(dc, cuboid.D2.CamView());