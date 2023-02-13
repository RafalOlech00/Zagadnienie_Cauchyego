#include <iostream>
using namespace std;

double RownanieRozniczkowe(double x, double y)
{
	//return x * x + y;
	return x + y;
}


void MetodaEulera(int n, double h, double (*f)(double, double))
{
	double x = 0;
	double y = 0.1;

	for (int i = 0; i < n; i++)
	{
		y = y + h * RownanieRozniczkowe(x, y);
		x = x + h;
	}
	cout << "Rozwiazanie metoda Eulera: " << y << endl;
}

void Kutty2(int n, double h, double(*f)(double, double))
{
	double k1, k2;
	double x = 0;
	double y = 0.1;
	double F;
	for (int i = 0; i < n; i++)
	{
		k1 = RownanieRozniczkowe(x, y);
		k2 = RownanieRozniczkowe(x + h, y + h * k1);
		F = (k1 + k2) / 2;
		y = y + h * F;
		x = x + h;

	}
	cout << "Rozwiazanie metoda Rungego-Kutty rzedu 2: " << y << endl;
}

void Kutty4(int n, double h, double (*f)(double, double))
{
	double k1, k2, k3, k4;
	double x = 0;
	double y = 0.1;
	double F;
	for (int i = 0; i < n; i++)
	{
		k1 = RownanieRozniczkowe(x,y);
		k2 = RownanieRozniczkowe(x + h / 2, y + h * k1 / 2);
		k3 = RownanieRozniczkowe(x + h / 2, y + h * k2 / 2);
		k4 = RownanieRozniczkowe(x + h, y + h * k3);
		F = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y = y + h * F;
		x = x + h;

	}
	cout << "Rozwiazanie metoda Rungego-Kutty rzedu 4: " << y << endl;
}





int main()
{
	cout << "Rownanie rozniczkowe: x + y" << endl;
	//cout << "Rownanie rozniczkowe: x * x + y" << endl;
	cout << "Warunek poczatkowy: y(0) = 0.1" << endl;
	cout << "Punkt koncowy: 1" << endl;
	cout << "Liczba krokow obliczen: 10" << endl;
	MetodaEulera(10, 0.1, RownanieRozniczkowe);
	Kutty2(10, 0.1, RownanieRozniczkowe);
	Kutty4(10, 0.1, RownanieRozniczkowe);
	return 0;
}












