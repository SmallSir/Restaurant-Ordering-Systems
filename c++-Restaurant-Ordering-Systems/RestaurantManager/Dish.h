#pragma once

class Dish
{
private:
	unsigned int id;// ID
	CString name;	// 菜名
	CString type;	// 菜系
	double perprice;// 单价
	double price;	// 价格
	int number;		// 数量

public:
	Dish(LPCTSTR name, LPCTSTR type, double payment);

	unsigned int getId() const;		// 获取ID的unsigned int类型
	CString getIdStr() const;		// 获取ID的字符串类型
	CString getName() const;
	CString getType() const;
	CString getPerprice() const;	// 获取单价的字符串类型
	double getPerpriceNum() const;	// 获取单价的double类型
	CString getPrice() const;
	double getPriceNum() const;
	int getNumber() const;
	CString getNumberStr() const;

	void addNumber();		// 数量加一
	void subNumber();		// 数量减一

	void setId(unsigned int id);
	void setName(LPCTSTR name);
	void setType(LPCTSTR type);
	void setPerprice(double perprice);
};

