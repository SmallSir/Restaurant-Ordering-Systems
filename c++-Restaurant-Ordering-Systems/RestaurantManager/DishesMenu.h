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
	
	CString getType();		// ��ȡ�ò˵�������ϵ
	Dish *getDish(int);		// ȡ���˵����±�λ�ò�Ʒ
	void addDish(Dish);		// ���һ����
	int getCount() const;	// ��ȡ�˵��еĲ�Ʒ����
};

