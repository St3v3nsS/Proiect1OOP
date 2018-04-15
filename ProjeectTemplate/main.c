#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

ifstream in("date.in");
ofstream out("date.out");

bool solve(Matrix<int>& matrix, Vector<int>& x, Vector<int>& y) {
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
	int n,x, nr;
	cout << "Se vor citi cele N obiecte din fisier. Asemenea si obiectul de tip matrice,\n" <<
		"dar si cele doua obiecte de tip vector folosite pentru verificarea ecuatiei.\n" <<
		"*****************************************************************************\n" <<
		"Se citeste N(nr de obiecte), dimensiunea fiecarui obiect si elementele obiectului.\n" <<
		"Se citesc nr de linii si de coloane ale matricei, elementele matricei si cele doua obiecte.\n";
	in >> n;
	Vector<int> *arrey = new Vector<int>[n + 1];
	for (int i = 1; i <= n; i++) {
		in >> x;
		arrey[i].init(x);
		in >> arrey[i];
	}
	arrey[1].sortare();
	out << arrey[1] << "\n" << arrey[2] << '\n';
	out << arrey[1] * arrey[2] << "\n";
	int lin, col;
	in >> lin >> col;
	Matrix<int> M(lin, col);
	in >> M;
	out <<'\n' << M;
	int a, b;
	in >> a >> b;
	Vector<int> arr1(a), arr2(b);
	in >> arr1 >> arr2;
	if (solve(M, arr1, arr2) == 1) {
		out << "\nEcuatia este corecta!\n";
	}
	else {
		out << "\nEcuatia nu este corecta!\n";
	}

	int option, num, pos = 0, elem;
	Vector<int> temp;
	bool sortat = 0;
	do {
		cout << "********************MENIU****************\n"
			<< "1. Aflati maximul dintr-un obiect!\n"
			<< "2. Aflati suma vectorului\n"
			<< "3. Sortati un obiect\n"
			<< "4. Sortati obiectele descrescator\n"
			<< "5. Afisati obiectele\n"
			<< "6. Exit!\n";
		cin >> option;
		if (option < 1 || option > 6) {
			cout << "Numar gresit!\n";
		}
		switch (option)
		{
		case 1: cout << "Introduceti un numar: ";

			cin >> num;
			try
			{
				elem = arrey[num].findMax(pos);
			}
			catch (...)
			{
				cout << "Error!\n";
			}
			cout << "Elementul maxim este: " << elem << " si se afla pe pozitia " << pos << "\n";
			break;
		case 2: cout << "Introduceti un numar: ";

			cin >> num;
			try
			{
				cout << arrey[num].getSum() << '\n';
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
			}
			break;
		case 3: cout << "Introduceti un numar: ";

			cin >> num;
			try
			{
				arrey[num].sortare();
			}
			catch (const exception& e)
			{
				cout << e.what() << " ";
			}
			cout << arrey[num] << '\n';
			break;
		case 4:
			do {
				sortat = 1;
				for(int i = 1; i < n; i++)
					if (arrey[i] < arrey[i + 1]) {

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

