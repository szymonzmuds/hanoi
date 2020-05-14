#include <iostream>
#include "figura.h"
#include "prostokat.h"
#include <cmath>
#define NDEBUG
#include <GL/freeglut.h>
#include <vector>

using namespace std;
vector<prostokat> baza;
vector<prostokat> prety;

int i = -1;
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

bool kolor()
{
	int z = 0;
	for (int o = 0; o < baza.size(); o++)
	{
		if (baza[o].x() == 0)
			z++;
	}
	if (baza.size() == z)
		return true;
	else
		return false;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (kolor()==true)
		glClearColor(1, 1, 0, 1);
	glPushMatrix();
	{
		
		for (int j = 0; j < baza.size(); j++)
		{
			baza[j].rysuj();
		}
		for (int o = 0; o < prety.size(); o++)
		{
			prety[o].rysuj();
		}
	}
	glPopMatrix();

	glutSwapBuffers();
}

double nowy_x(double x)
{
	if (abs(x - 2) < 1) return 2;
	if (abs(x) <= 1) return 0;
	if (abs(x + 2) < 1) return -2;
}

double najmniej(double t)
{
	double wynik = 1;
	for (int o = 0; o < baza.size(); o++)
	{
		if (baza[o].x() == t)
		{
			if (wynik > baza[o].ramie())
				wynik = baza[o].ramie();
		}
	}
	return wynik;
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

double nowy_y(double x)
{
	int z=0;
	for (int o = 0; o < baza.size(); o++)
	{
		if (baza[o].x() == x)
		{
			z++;
		}
	}
	double nowy_y = -1.7 + (z*0.5);
	return nowy_y;
}

bool czy_mozna(double x, double r)
{
	double ramie = 2;
	int z = 0;
	for (int o = 0; o < baza.size(); o++)
	{
		if (baza[o].x() == x)
		{
			if (ramie>baza[o].ramie())
			{
				ramie = baza[o].ramie();
				z++;
			}
		}
	}
	if (z == 0)
		return true;
	if (ramie > r)
		return true;
	else
		return false;
}

void mysz(int b, int s, int x, int y)
{
	double x1 = ((double)x - 400) / 800 * 6.68;
	double y1 = (-((double)y - 300) / 600 * 5);
	if (b == GLUT_LEFT_BUTTON && s == GLUT_UP)
	{
		switch (i)
		{
		case -1:
			{
				for (int j = 0; j < baza.size(); j++)
				{
					if (baza[j].kon_pro(x1, y1) == true)
					{
						if (najmniej(baza[j].x()) == baza[j].ramie())
						{
							i = j;
						}
						break;
					}

				}
			}
			break;
		default:
			{
			    double xz = nowy_x(x1);
				double yy = nowy_y(xz);
				if (czy_mozna(xz, baza[i].ramie()) == true)
				{
					baza[i].ustaw(xz, yy);
					i = -1;
				}
			}
			
		}
		
		
	}
}


void aktywna_mysz(int x, int y)
{
	if (i > -1){
		double x1 = ((double)x - 400) / 800 * 6.68;
		double y1 = (-((double)y - 300) / 600 * 5);
		baza[i].ustaw(x1, y1);
	}
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMouseFunc(mysz);
	glutPassiveMotionFunc(aktywna_mysz);
}

void scena()
{
	prostokat n1;
	n1.ustaw(-2, -0.2);
	n1.rozmiar(0.1, 1.5);
	n1.kolor();
	n1.kolor();
	prostokat n2;
	n2.ustaw(0, -0.2);
	n2.rozmiar(0.1, 1.5);
	n2.kolor();
	n2.kolor();
	prostokat n3;
	n3.ustaw(2, -0.2);
	n3.kolor();
	n3.kolor();
	n3.rozmiar(0.1, 1.5);
	prety.push_back(n1);
	prety.push_back(n2);
	prety.push_back(n3);
}

int main(int argc, char *argv[])
{
	scena();
	int n  = 3;
	//cin >> n;
	double xx = 0.5;
	double yy = -1.5;
	for (int i = 0; i < n; i++)
	{
		prostokat nn;
		baza.push_back(nn);
		baza[baza.size() - 1].ustaw(-2, yy);
		yy = yy + 0.5;
		baza[baza.size() - 1].rozmiar(xx, 0.17);
		xx = xx*0.85;
	}
	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();
	glutMainLoop();
    return 0;
}
