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
			// ���������������ˣ�������һ
			iter->addNumber();
			// ˢ������
			m_plistOrder->SetItemText(i, 3, iter->getNumberStr());
			// ˢ�¼۸�
			m_plistOrder->SetItemText(i, 4, iter->getPrice());
			break;
		}
	}
	if (iter == dishes.end()) {
		// �ڵ�������������
		int index = m_plistOrder->GetItemCount();
		m_plistOrder->InsertItem(index, dish.getIdStr());
		m_plistOrder->SetItemText(index, 1, dish.getName());
		m_plistOrder->SetItemText(index, 2, dish.getPerprice());
		m_plistOrder->SetItemText(index, 3, _T("1"));
		m_plistOrder->SetItemText(index, 4, dish.getPrice());
		// �����������
		dishes.push_back(dish);
	}
}

BOOL DishesOrder::deleteDish(int index)
{
	if (index < 0 || index >= dishes.size()) {
		return FALSE;
	}
	Dish *dish = &dishes.at(index);
	// ������һ
	dish->subNumber();
	// ����˵�����Ϊ0���ڵ���б���ɾ��
	if (0 == dish->getNumber()) {
		// ���б���ɾ��
		m_plistOrder->DeleteItem(index);
		// ��������ɾ��
		dishes.erase(dishes.begin() + index);
	}
	else {
		// ˢ������
		m_plistOrder->SetItemText(index, 3, dish->getNumberStr());
		// ˢ�¼۸�
		m_plistOrder->SetItemText(index, 4, dish->getPrice());
	}
	
	return TRUE;
}

void DishesOrder::clearDish()
{
	// �������
	dishes.clear();
	// ����б�
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
