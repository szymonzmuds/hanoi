#ifndef FIGURA_h
#define FIGURA_h

class figura
{
protected:
	double m_x;
	double m_y;
	double m_r;
	double m_g;
	double m_b;
	int m_k;
	int m_ser;
public:
	figura(double x=0, double y=0, double r=1, double g=0, double b=1, int ser=0,int kolor=0);
	virtual void rysuj()=0;
	virtual bool kon_pro(double xx, double yy)=0;
	void gora();
	void dol();
	void prawo();
	void lewo();
	void ak();
	void nak();
	void kolor();
	void ustaw(double x, double y);
	virtual void rozmiar(double x, double y) = 0;
	void wypisz();
	double x();
	double y();
	void ustaw_x(double x);
	virtual double ramie() = 0;
};

#endif