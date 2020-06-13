#include <iostream>
#include <vector>
#include "figures.h"

using namespace std;

int main()
{
	vector<triangle> Tr;
	vector<ellipse> El;
	//IGeoFig* geoFigure;
	cout << "Choose command:\n"
		<< "1. Add figure;\n"
		<< "2. Show all figures;\n"
		<< "3. Sum squares;\n"
		<< "4. Sum perimetres;\n"
		<< "5. Center of mass of the all system;\n"
		<< "6. Sum memory;\n"
		<< "7. Sort by mass;\n"
		<< "8. Exit;\n";
	int k;
	cout << "Enter the command: ";
	cin >> k;
	while (k != 8)
	{
		if (k == 1)
		{
			cout << "Enter the type of figure: ";
			string name;
			cin >> name;
			if (name == "triangle")
			{
				triangle newTr;
				newTr.initFromDialog();
				Tr.push_back(newTr);
			}
			else
			{
				ellipse newEl;
				newEl.initFromDialog();
				El.push_back(newEl);
			}
		}
		else if (k == 2)
		{
			for (int i = 0; i < Tr.size(); i++)
			{
				cout << Tr[i].classname() << ": " << endl;
				Tr[i].draw();
			}
			cout << endl;
			for (int i = 0; i < El.size(); i++)
			{
				cout << El[i].classname() << ": " << endl;
				El[i].draw();
			}
		}
		else if (k == 3)
		{
			double sum = 0;
			for (int i = 0; i < Tr.size(); i++)
			{
				sum += Tr[i].square();
			}
			for (int i = 0; i < El.size(); i++)
			{
				sum += El[i].square();
			}
			cout << "Sum squares of all figures = " << sum << endl;
		}
		else if (k == 4)
		{
			double sum = 0;
			for (int i = 0; i < Tr.size(); i++)
			{
				sum += Tr[i].perimeter();
			}
			for (int i = 0; i < El.size(); i++)
			{
				sum += El[i].perimeter();
			}
			cout << "Sum perimetres of all figures = " << sum << endl;
		}
		else if (k == 5)
		{
			double sum_mass = 0;
			double sum_mass_x = 0;
			double sum_mass_y = 0;
			for (int i = 0; i < Tr.size(); i++)
			{
				sum_mass += Tr[i].mass();
				CVector2D Pos = Tr[i].position();
				sum_mass_x += Tr[i].mass() * Pos.x;
				sum_mass_y += Tr[i].mass() * Pos.y;
			}
			for (int i = 0; i < El.size(); i++)
			{
				sum_mass += El[i].mass();
				CVector2D Pos = El[i].position();
				sum_mass_x += El[i].mass() * Pos.x;
				sum_mass_y += El[i].mass() * Pos.y;
			}
			cout << "Coordinates of center mass: " << sum_mass_x / sum_mass << ' ' << sum_mass_y / sum_mass << endl;
		}
		else if (k == 6)
		{
			int sum_size = 0;
			for (int i = 0; i < Tr.size(); i++)
			{
				sum_size += Tr[i].size();
			}
			for (int i = 0; i < El.size(); i++)
			{
				sum_size += El[i].size();
			}
			cout << "Sum memory: " << sum_size << endl;
		}
		else if (k == 7)
		{
			vector <int> weights_tr(Tr.size());
			vector <int> numbers_tr(Tr.size());
			for (int i = 0; i < numbers_tr.size(); i++)
			{
				numbers_tr[i] = i;
				weights_tr[i] = Tr[i].mass();
			}
			for (int i = 1; i < Tr.size(); i++)
			{
				int j = i;
				while (j > 0 && weights_tr[j] > weights_tr[j - 1])
				{
					swap(weights_tr[j], weights_tr[j - 1]);
					swap(numbers_tr[j], numbers_tr[j - 1]);
					j = j - 1;
				}
			}
			vector <int> weights_el(El.size());
			vector <int> numbers_el(El.size());
			for (int i = 0; i < numbers_el.size(); i++)
			{
				numbers_el[i] = i;
				weights_el[i] = El[i].mass();
			}
			for (int i = 1; i < El.size(); i++)
			{
				int j = i;
				while (j > 0 && weights_el[j] > weights_el[j - 1])
				{
					swap(weights_el[j], weights_el[j - 1]);
					swap(numbers_el[j], numbers_el[j - 1]);
					j = j - 1;
				}
			}
			int m = 0, n = 0;
			for (int i = 0; i < numbers_tr.size() + numbers_el.size(); i++)
			{
				if (m == numbers_tr.size() || n == numbers_el.size())
					break;
				if (weights_tr[m] > weights_el[n])
				{
					cout << Tr[numbers_tr[m]].classname() << endl;
					Tr[numbers_tr[m]].draw();
					cout << endl;
					m++;
				}
				else
				{
					cout << El[numbers_el[n]].classname() << endl;
					El[numbers_el[n]].draw();
					cout << endl;
					n++;
				}
			}
			while (m != numbers_tr.size())
			{
				cout << Tr[numbers_tr[m]].classname() << endl;
				Tr[numbers_tr[m]].draw();
				cout << endl;
				m++;
			}
			while (n != numbers_el.size())
			{
				cout << El[numbers_el[n]].classname() << endl;
				El[numbers_el[n]].draw();
				cout << endl;
				n++;
			}
		}
		cin >> k;
	}
	return 0;
}