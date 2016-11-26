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

	Dish *getDish(int);		// ��ȡ����б����±�λ�ò�Ʒ
	CString getPayment() const;		// ��ȡ�۸��ַ�����
	double getPaymentNum() const;	// ��ȡ�۸�double�ͣ�
	int getCount() const;			// ��ȡ����б��еĲ�Ʒ����

	void orderDish(Dish);		// ���һ���˵�����б�
	BOOL deleteDish(int);		// ɾ��һ����
	void clearDish();			// ��յ���б�
};

