#include <iostream>
#include "prostokat.h"
#include <GL/freeglut.h>
using namespace std;
void prostokat::rysuj()
{
	glPushMatrix();
	glColor3d(m_r, m_g, m_b);
	glTranslated(m_x, m_y, 0.0);
	glBegin(GL_POLYGON);
	{
		
		glVertex3d(m_r1, m_r2, 0);
		glVertex3d(m_r1, -m_r2, 0);
		glVertex3d(-m_r1, -m_r2, 0);
		glVertex3d(-m_r1, m_r2, 0);

	}
	glEnd();
	glPopMatrix();
}

prostokat::prostokat(double r1, double r2, double xx, double yy, double rr, double gg, double bb) :
figura(xx, yy, rr, gg, bb, 1), m_r1(r1), m_r2(r2)
{}

bool prostokat::kon_pro(double xx, double yy)
{
	if ((xx <= (m_r1+m_x)&&xx >= (-m_r1+m_x)) && (yy >= (-m_r2+m_y)&&yy <= (m_r2+m_y)))
		return true;
	else
		return false;
}

void prostokat::rozmiar(double x, double y)
{
	m_r1 = x;
	m_r2 = y;
}

double prostokat::ramie()
{
	return m_r1;
}