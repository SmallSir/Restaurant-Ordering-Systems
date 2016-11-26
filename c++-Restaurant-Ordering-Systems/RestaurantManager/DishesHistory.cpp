#include "stdafx.h"
#include "DishesHistory.h"


DishesHistory::DishesHistory(CListCtrl* historyList, CListCtrl* historyOrder)
{
	m_historyList = historyList;
	m_historyOrder = historyOrder;
}

DishesHistory::~DishesHistory()
{
	orders.clear();
}


void DishesHistory::addOrder(DishesOrder dishesOrder)
{
	// 获取当前时间
	CTime t = CTime::GetCurrentTime();
	CString listName = t.Format(_T("%Y-%m-%d %H:%M:%S订单"));
	// 插入该项
	m_historyList->InsertItem(orders.size(), listName);
	// 添加进容器
	orders.push_back(dishesOrder);
}

void DishesHistory::showOrder(int index)
{
	// 清空列表
	m_historyOrder->DeleteAllItems();
	if (index < 0 || index >= orders.size()) {
		return;
	}
	// 取出点餐列表
	DishesOrder order = orders.at(index);
	// 显示点餐列表所有点餐信息
	for (int i = 0; i < order.getCount(); i++) {
		Dish *dish = order.getDish(i);
		m_historyOrder->InsertItem(i, dish->getIdStr());
		m_historyOrder->SetItemText(i, 1, dish->getName());
		m_historyOrder->SetItemText(i, 2, dish->getPerprice());
		m_historyOrder->SetItemText(i, 3, dish->getNumberStr());
		m_historyOrder->SetItemText(i, 4, dish->getPrice());
	}
	// 在列表尾加入总价
	int nCount = m_historyOrder->GetItemCount();
	m_historyOrder->InsertItem(nCount, _T("总价"));
	m_historyOrder->SetItemText(nCount, 1, order.getPayment());
}
