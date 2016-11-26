#include "stdafx.h"
#include "DishesMenu.h"


DishesMenu::DishesMenu(CString type)
{
	this->type = type;
}

DishesMenu::~DishesMenu()
{
	dishes.clear();
}


CString DishesMenu::getType()
{
	return type;
}

Dish * DishesMenu::getDish(int index)
{
	if (index < 0 || index >= dishes.size()) {
		return nullptr;
	}
	return &dishes.at(index);
}

void DishesMenu::addDish(Dish dish)
{
	dishes.push_back(dish);
}


int DishesMenu::getCount() const
{
	return dishes.size();
}
