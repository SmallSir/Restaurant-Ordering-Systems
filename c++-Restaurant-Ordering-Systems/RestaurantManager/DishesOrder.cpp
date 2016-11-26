#include "stdafx.h"
#include "DishesOrder.h"


DishesOrder::DishesOrder(CListCtrl *m_plistOrder)
{
	this->m_plistOrder = m_plistOrder;
}


DishesOrder::~DishesOrder()
{
	dishes.clear();
}

Dish * DishesOrder::getDish(int index)
{
	if (index < 0 || index >= dishes.size()) {
		return nullptr;
	}
	return &dishes.at(index);
}

void DishesOrder::orderDish(Dish dish)
{
	vector<Dish>::iterator iter = dishes.begin();
	for (int i = 0; iter != dishes.end(); iter++, i++) {
		if (iter->getId() == dish.getId()) {
			// 若点餐栏已有这道菜，数量加一
			iter->addNumber();
			// 刷新数量
			m_plistOrder->SetItemText(i, 3, iter->getNumberStr());
			// 刷新价格
			m_plistOrder->SetItemText(i, 4, iter->getPrice());
			break;
		}
	}
	if (iter == dishes.end()) {
		// 在点餐栏加入这道菜
		int index = m_plistOrder->GetItemCount();
		m_plistOrder->InsertItem(index, dish.getIdStr());
		m_plistOrder->SetItemText(index, 1, dish.getName());
		m_plistOrder->SetItemText(index, 2, dish.getPerprice());
		m_plistOrder->SetItemText(index, 3, _T("1"));
		m_plistOrder->SetItemText(index, 4, dish.getPrice());
		// 在容器中添加
		dishes.push_back(dish);
	}
}

BOOL DishesOrder::deleteDish(int index)
{
	if (index < 0 || index >= dishes.size()) {
		return FALSE;
	}
	Dish *dish = &dishes.at(index);
	// 数量减一
	dish->subNumber();
	// 如果菜的数量为0，在点餐列表中删除
	if (0 == dish->getNumber()) {
		// 在列表中删除
		m_plistOrder->DeleteItem(index);
		// 在容器中删除
		dishes.erase(dishes.begin() + index);
	}
	else {
		// 刷新数量
		m_plistOrder->SetItemText(index, 3, dish->getNumberStr());
		// 刷新价格
		m_plistOrder->SetItemText(index, 4, dish->getPrice());
	}
	
	return TRUE;
}

void DishesOrder::clearDish()
{
	// 清空容器
	dishes.clear();
	// 清空列表
	m_plistOrder->DeleteAllItems();
}

CString DishesOrder::getPayment() const
{
	CString str;
	str.Format(_T("%.1lf"), getPaymentNum());
	return str;
}

double DishesOrder::getPaymentNum() const
{
	double payment = 0;
	for (int i = 0; i < dishes.size(); i++) {
		payment += dishes.at(i).getPriceNum();
	}
	return payment;
}


int DishesOrder::getCount() const
{
	return dishes.size();
}
