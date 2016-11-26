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
	// ��ȡ��ǰʱ��
	CTime t = CTime::GetCurrentTime();
	CString listName = t.Format(_T("%Y-%m-%d %H:%M:%S����"));
	// �������
	m_historyList->InsertItem(orders.size(), listName);
	// ��ӽ�����
	orders.push_back(dishesOrder);
}

void DishesHistory::showOrder(int index)
{
	// ����б�
	m_historyOrder->DeleteAllItems();
	if (index < 0 || index >= orders.size()) {
		return;
	}
	// ȡ������б�
	DishesOrder order = orders.at(index);
	// ��ʾ����б����е����Ϣ
	for (int i = 0; i < order.getCount(); i++) {
		Dish *dish = order.getDish(i);
		m_historyOrder->InsertItem(i, dish->getIdStr());
		m_historyOrder->SetItemText(i, 1, dish->getName());
		m_historyOrder->SetItemText(i, 2, dish->getPerprice());
		m_historyOrder->SetItemText(i, 3, dish->getNumberStr());
		m_historyOrder->SetItemText(i, 4, dish->getPrice());
	}
	// ���б�β�����ܼ�
	int nCount = m_historyOrder->GetItemCount();
	m_historyOrder->InsertItem(nCount, _T("�ܼ�"));
	m_historyOrder->SetItemText(nCount, 1, order.getPayment());
}
