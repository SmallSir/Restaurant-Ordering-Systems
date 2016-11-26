#pragma once
#include "Dish.h"
#include <vector>
using namespace std;

class DishesMenu
{
private:
	vector<Dish> dishes;
	CString type;

public:
	DishesMenu(CString type);
	~DishesMenu();
	
	CString getType();		// 获取该菜单所属菜系
	Dish *getDish(int);		// 取出菜单中下标位置菜品
	void addDish(Dish);		// 添加一道菜
	int getCount() const;	// 获取菜单中的菜品数量
};

