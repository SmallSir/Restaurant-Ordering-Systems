#include "stdafx.h"
#include "Dish.h"
#include "string.h"

Dish::Dish(LPCTSTR name, LPCTSTR type, double perprice)
{
	this->id = 0;
	this->name = name;
	this->type = type;
	this->perprice = perprice;
	this->number = 1;
}


CString Dish::getName() const
{
	return name;
}

CString Dish::getType() const
{
	return type;
}

CString Dish::getPerprice() const
{
	CString str;
	str.Format(_T("%.1lf"), perprice);
	return str;
}

double Dish::getPerpriceNum() const
{
	return perprice;
}

CString Dish::getPrice() const
{
	CString str;
	str.Format(_T("%.1lf"), perprice * number);
	return str;
}

double Dish::getPriceNum() const
{
	return perprice * number;
}

int Dish::getNumber() const
{
	return number;
}

CString Dish::getNumberStr() const
{
	CString str;
	str.Format(_T("%d"), number);
	return str;
}

void Dish::addNumber()
{
	number++;
}

void Dish::subNumber()
{
	number--;
}

unsigned int Dish::getId() const
{
	return id;
}

CString Dish::getIdStr() const
{
	CString str;
	str.Format(_T("%03d"), id);
	return str;
}

void Dish::setId(unsigned int id)
{
	this->id = id;
}

void Dish::setName(LPCTSTR name)
{
	this->name = name;
}

void Dish::setType(LPCTSTR type)
{
	this->type = type;
}

void Dish::setPerprice(double perprice)
{
	this->perprice = perprice;
}
