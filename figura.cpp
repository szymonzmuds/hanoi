#include "figura.h"
#include <iostream>

using namespace std;

void figura::gora()
{
	m_y = m_y + 0.25;
}
void figura::dol()
{
	m_y = m_y - 0.25;
}
void figura::prawo()
{
	m_x = m_x + 0.25;
}
void figura::lewo()
{
	m_x = m_x - 0.25;
}

void figura::ak()
{
	m_r = 1;
	m_g = 1;
	m_b = 1;
}
void figura::nak()
{
	m_r = 0;
	m_g = 0;
	m_b = 1;
}

figura::figura(double x, double y, double r, double g, double b, int ser, int kolor) :
m_x(x), m_y(y), m_r(r), m_g(g), m_b(b), m_k(0), m_ser(ser)
{};

void figura::kolor()
{
	switch (m_k)
	{
	case 0:
	{
			  m_r = 1.0;
			  m_g = 0.0;
			  m_b = 0.0;
			  m_k = 1;
			  break;
	}
	case 1:
	{
			  m_r = 1.0;
			  m_g = 0.0;
			  m_b = 1.0;
			  m_k = 2;
			  break;
	}
	case 2:
	{
			  m_r = 1.0;
			  m_g = 1.0;
			  m_b = 0.0;
			  m_k = 3;
			  break;
	}
	case 3:
	{
			  m_r = 0.0;
			  m_g = 0.0;
			  m_b = 1.0;
			  m_k = 0;
			  break;
	}
	}
}

void figura::ustaw(double x, double y)
{
	m_x = x;
	m_y = y;
}

void figura::wypisz()
{
	cout << m_x << " " << m_y << endl;
}

double figura::x()
{
	return m_x;
}

void figura::ustaw_x(double x)
{
	m_x = x;
}

double figura::y()
{
	return m_y;
}