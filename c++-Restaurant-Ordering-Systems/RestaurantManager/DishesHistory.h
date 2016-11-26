#pragma once
#include "DishesOrder.h"
#include <vector>
using namespace std;

class DishesHistory
{
private:
	CListCtrl* m_historyList;
	CListCtrl* m_historyOrder;
	vector<DishesOrder> orders;
public:
	DishesHistory(CListCtrl* , CListCtrl*);
	~DishesHistory();
	void addOrder(DishesOrder);
	void showOrder(int index);
};

