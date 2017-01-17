#pragma once
#include "Dish.h"
#include <vector>
using namespace std;

class DishesOrder
{
private:
	CListCtrl *m_plistOrder;
	CListCtrl *m_client;
	vector<Dish> dishes;
public:
	DishesOrder(CListCtrl *, CListCtrl *m_client);
	~DishesOrder();

	Dish *getDish(int);		// ��ȡ����б����±�λ�ò�Ʒ
	CString getPayment() const;		// ��ȡ�۸��ַ�����
	double getPaymentNum() const;	// ��ȡ�۸�double�ͣ�
	int getCount() const;			// ��ȡ����б��еĲ�Ʒ����

	void orderDish(Dish);		// ���һ���˵�����б�
	BOOL deleteDish(int);		// ɾ��һ����
	void clearDish();			// ��յ���б�
};

