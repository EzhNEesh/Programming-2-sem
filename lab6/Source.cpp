#include <iostream>
#include <vector>
#include "template.h"
#include "point.h"
#include "predicate.h"

using namespace std;

int main()
{
	//Task with floats
	vector<float> mass;
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter a variable: ";
		float a;
		cin >> a;
		mass.push_back(a);
	}
	//Task 1 for floats
	if (all_of(mass.begin(), mass.end(), predicateFloat))
		cout << "All floats are satisfing the condition\n";
	else
		cout << "Not all floats are satisfing the condition\n";
	//Task 5 for points
	if (is_sorted(mass.begin(), mass.end(), compareFloat))
		cout << "Floats are sorted\n";
	else
		cout << "Floats aren't sorted\n";
	//Tsk 8 for floats
	float des;
	cout << "Enter desired float: ";
	cin >> des;
	if (find_backward(mass.begin(), mass.end(), des, eqFloat) == mass.end())
		cout << "Float isn't desiring\n";
	else
		cout << "Number of desired float: " << find_backward(mass.begin(), mass.end(), des, eqFloat) - mass.begin() + 1 << "\n\n";

	//Task with points
	vector<cPoint> points;
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter a coordinates of point: ";
		float a, b;
		cin >> a >> b;
		points.push_back(cPoint(a, b));
	}
	//Task 1 for points
	if (all_of(points.begin(), points.end(), predicatePoint))
		cout << "All points are satisfing the condition\n";
	else
		cout << "Not all points are satisfing the condition\n";
	//Task 5 for points
	if (is_sorted(points.begin(), points.end(), comparePoints))
		cout << "Points are sorted\n";
	else
		cout << "Points aren't sorted\n";
	//Task 8 for points
	float xx, yy;
	cout << "Enter desired point: ";
	cin >> xx >> yy;
	cPoint desired(xx, yy);
	if (find_backward(points.begin(), points.end(), desired, eqPoints) == points.end())
		cout << "Point isn't desiring\n";
	else
		cout << "Number of desired point: " << find_backward(points.begin(), points.end(), desired, eqPoints) - points.begin() + 1 << endl;
	return 0;
}