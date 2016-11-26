#pragma once

class Dish
{
private:
	unsigned int id;// ID
	CString name;	// ����
	CString type;	// ��ϵ
	double perprice;// ����
	double price;	// �۸�
	int number;		// ����

public:
	Dish(LPCTSTR name, LPCTSTR type, double payment);

	unsigned int getId() const;		// ��ȡID��unsigned int����
	CString getIdStr() const;		// ��ȡID���ַ�������
	CString getName() const;
	CString getType() const;
	CString getPerprice() const;	// ��ȡ���۵��ַ�������
	double getPerpriceNum() const;	// ��ȡ���۵�double����
	CString getPrice() const;
	double getPriceNum() const;
	int getNumber() const;
	CString getNumberStr() const;

	void addNumber();		// ������һ
	void subNumber();		// ������һ

	void setId(unsigned int id);
	void setName(LPCTSTR name);
	void setType(LPCTSTR type);
	void setPerprice(double perprice);
};

