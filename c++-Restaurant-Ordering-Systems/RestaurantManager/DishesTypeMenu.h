#pragma once
#include "Dish.h"
#include "DishesMenu.h"
#include <vector>
using namespace std;

class DishesTypeMenu
{
private:
	CListCtrl *m_plistMenu;
	CListCtrl *m_plistTypeMenu;
	vector<DishesMenu> menus;
public:
	DishesTypeMenu(CListCtrl*, CListCtrl*);
	~DishesTypeMenu();

	BOOL readData(CString path);
	DishesMenu *findMenu(CString);
	DishesMenu *getMenu(int);
	void addType(DishesMenu);
	void showMenu(int);
	void clear();
};

