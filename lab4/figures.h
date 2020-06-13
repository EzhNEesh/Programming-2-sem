#pragma once
#include "abstr_classes.h"

class triangle : public IGeoFig, public CVector2D, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject
{
public:
	triangle();
	double square() const;
	double perimeter();
	double mass() const;
	CVector2D position();
	bool operator== (const IPhysObject& ob) const;
	bool operator< (const IPhysObject& ob) const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();

private:
	CVector2D center, vertex;
	double weight;
};

class ellipse
{
public:
	ellipse();
	double square() const;
	double perimeter();
	double mass() const;
	CVector2D position();
	bool operator== (const IPhysObject& ob) const;
	bool operator< (const IPhysObject& ob) const;
	void draw();
	void initFromDialog();
	const char* classname();
	unsigned int size();
private:
	CVector2D center, HalfShA, HalfShB;
	double weight;
};