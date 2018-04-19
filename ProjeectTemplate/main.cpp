// Proiect1.cpp : Defines the entry point for the console application.
//Morosan Ionut - Mihai

#include <iostream>
#include <fstream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include <string>

using namespace std;

ifstream in("date.in");
ofstream out("date.out");


bool solve(Matrix<double>& matrix, Vector<double>& x, Vector<double>& y) {
	int result = 1;
	bool ok = 1;
	for(int i = 1; i <= matrix.getLinii(); i++){
		result = matrix[i] * x;
		if (result != y[i])
			return false;
	}
	return true;
}

int main()
{

	int n, x, nr;
	cout << "Se vor citi cele N obiecte din fisier. Asemenea si obiectul de tip matrice,\n" <<
		"dar si cele doua obiecte de tip vector folosite pentru verificarea ecuatiei.\n" <<
		"*****************************************************************************\n" <<
		"Se citeste N(nr de obiecte), dimensiunea fiecarui obiect si elementele obiectului.\n" <<
		"Se citesc nr de linii si de coloane ale matricei, elementele matricei si cele doua obiecte.\n";
	in >> n;
	Vector <double>*arrey = new Vector<double>[n + 1];
	for (int i = 1; i <= n; i++) {
		in >> x;
		arrey[i].init(x);
		in >> arrey[i];
	}
	int lin, col;
	in >> lin >> col;
	Matrix<double> M(lin, col);
	in >> M;
	int a, b;
	in >> a >> b;
	Vector<double> arr1(a), arr2(b);
	in >> arr1 >> arr2;
	if (solve(M, arr1, arr2) == 1) {
		out << "\nEcuatia este corecta!\n";
	}
	else {
		out << "\nEcuatia nu este corecta!\n";
	}

	int option, pos = 0, elem, num;
	string num1, option1;
	Vector<double> temp;
	bool sortat = 0;
	do {
		cout << "********************MENIU****************\n"
			<< "1. Aflati maximul dintr-un obiect!\n"
			<< "2. Aflati suma vectorului\n"
			<< "3. Sortati un obiect\n"
			<< "4. Sortati obiectele crescator\n"
			<< "5. Afisati obiectele\n"
			<< "6. Exit!\n";
		cin >> option1;
		option = atoi(option1.c_str());
		if (option < 1 || option > 6 || !isdigit(option1[0])) {
			cout << "Numar gresit!\n";

		}
		switch (option)
		{
		case 1: cout << "Introduceti un numar: ";
			try
			{
				cin >> num1;
				num = atoi(num1.c_str());
				if (num > n || !isdigit(num1[0]))
					throw "error";
				elem = arrey[num].findMax(pos);
			}
			catch (...)
			{
				cout << "Error!\n";
				break;
			}
			cout << "Elementul maxim este: " << elem << " si se afla pe pozitia " << pos << "\n";
			break;
		case 2: cout << "Introduceti un numar: ";

			try
			{
				cin >> num1;
				num = atoi(num1.c_str());
				if (num > n || !isdigit(num1[0]))
					throw "error";
				cout << arrey[num].getSum() << '\n';
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
				break;
			}
			break;
		case 3: cout << "Introduceti un numar: ";

			try
			{
				cin >> num1;
				num = atoi(num1.c_str());
				if (num > n || !isdigit(num1[0]))
					throw "error";
				arrey[num].sortare();
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
				break;
			}
			cout << arrey[num] << '\n';
			break;
		case 4:
			do {
				sortat = 1;
				for (int i = 1; i < n; i++)
					if (arrey[i] < arrey[i + 1]) {
						;
					}
					else {
						temp = arrey[i];
						arrey[i] = arrey[i + 1];
						arrey[i + 1] = temp;
						sortat = 0;
					}
			} while (sortat == 0);
			break;
		case 5: for (int i = 1; i <= n; i++)
			cout << arrey[i] << '\n';
			break;
		case 6: exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}
	} while (option <= 6);
	return 0;
}



