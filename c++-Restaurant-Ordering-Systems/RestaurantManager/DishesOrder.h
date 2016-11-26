#pragma once
#include "Dish.h"
#include <vector>
using namespace std;

class DishesOrder
{
private:
	CListCtrl *m_plistOrder;
	vector<Dish> dishes;
public:
	DishesOrder(CListCtrl *);
	~DishesOrder();

	Dish *getDish(int);		// 获取点餐列表中下标位置菜品
	CString getPayment() const;		// 获取价格（字符串）
	double getPaymentNum() const;	// 获取价格（double型）
	int getCount() const;			// 获取点餐列表中的菜品数量

	void orderDish(Dish);		// 添加一道菜到点餐列表
	BOOL deleteDish(int);		// 删除一道菜
	void clearDish();			// 清空点餐列表
};

