#ifndef PROSTOKAT_h
#define PROSTOKAT_h
#include "figura.h"
class prostokat : public figura
{
private:
	double m_r1;
	double m_r2;
public:
	prostokat(double r1 = 0.25, double r2= 0.1, double xx = 0, double yy = 0, double rr = 1.0, double gg = 0, double bb = 0);

	void rysuj();

	bool kon_pro(double xx, double yy);

	void rozmiar(double x, double y);

	double ramie();

	
};



#endif