#pragma once

class IGeoFig 
{
public:
	virtual double square() const = 0;
	virtual double perimeter() = 0;
};

class CVector2D 
{
public:
	double x, y;
};

class IPhysObject 
{
public:
	virtual double mass() const = 0;
	virtual CVector2D position() = 0;
	virtual bool operator== (const IPhysObject& ob) const = 0;
	virtual bool operator< (const IPhysObject& ob) const = 0;
};

class IPrintable 
{
public:
	// Отобразить на экране
	// (выводить в текстовом виде параметры фигуры).
	virtual void draw() = 0;
};

class IDialogInitiable 
{
	// Задать параметры объекта с помощью диалога с пользователем.
	virtual void initFromDialog() = 0;
};

class BaseCObject
{
public:
	// Имя класса (типа данных).
	virtual const char* classname() = 0;
	// Размер занимаемой памяти.
	virtual unsigned int size() = 0;
};