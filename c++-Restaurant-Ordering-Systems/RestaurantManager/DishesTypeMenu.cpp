#include "stdafx.h"
#include "DishesTypeMenu.h"
#include <string.h>


DishesTypeMenu::DishesTypeMenu(CListCtrl *m_listMenu, CListCtrl *m_listTypeMenu)
{
	this->m_plistMenu = m_listMenu;
	this->m_plistTypeMenu = m_listTypeMenu;
}

DishesTypeMenu::~DishesTypeMenu()
{
	menus.clear();
}

BOOL DishesTypeMenu::readData(CString path)
{
	FILE* fp = NULL;
	// 打开文件
	_wfopen_s(&fp, path, _T("r"));
	// 未能打开，返回FALSE
	if (fp == NULL) {
		return FALSE;
	}
	// 创建一个全部菜单
	DishesMenu dishesMenu(_T("全部"));
	// 添加该菜单
	addType(dishesMenu);
	// 读取菜单数据
	for (int i = 0; !feof(fp); i++) {
		// 菜单数据储存格式为ANSI，读取时要转化
		// 数据不使用Unicode编码储存，因为读取时会出现乱码
		// 宽字符读取代码
		// wchar_t *name = new wchar_t[21], *type = new wchar_t[21];
		// fwscanf_s(fp, _T("#%s %s %lf\n"), name, 20, type, 20, &payment);

		// 从文件读取数据
		switch (fgetc(fp)) {
		case '#':
		{
			// 为菜名、菜系、单价创建内存空间
			char *cName = new char[21], *cType = new char[21];
			double payment = 0;
			CString name, type;
			if (3 != fscanf_s(fp, "%s %s %lf\n", cName, 20, cType, 20, &payment)) {
				// 三个变量没有全部成功赋值，跳过这一项
				continue;
			}
			// 转化为宽字符
			name = cName;
			type = cType;
			// 创建菜
			Dish dish(name, type, payment);
			// 设置id
			dish.setId(i + 1);
			// 添加进全部菜单
			menus.at(0).addDish(dish);
			// 查找菜系是否存在
			DishesMenu *pDishMenu = findMenu(type);
			if (pDishMenu == NULL) {
				// 若没有这个菜系，创建新菜单
				DishesMenu dishesMenu(type);
				dishesMenu.addDish(dish);
				// 添加进菜系
				addType(dishesMenu);
			}
			else {
				pDishMenu->addDish(dish);
			}
			break;
		}
		case EOF:
			// 读取结束
			break;
		default:
			// 读取错误
			return FALSE;
		}
	}

	fclose(fp);
	return TRUE;
}

DishesMenu* DishesTypeMenu::findMenu(CString type)
{
	vector<DishesMenu>::iterator iter = menus.begin();
	for (int i = 0; iter != menus.end(); iter++, i++) {
		if (StrCmpW((*iter).getType(), type) == 0) {
			return &*iter;
		}
	}
	return NULL;
}

DishesMenu *DishesTypeMenu::getMenu(int index)
{
	return &menus.at(index);
}

void DishesTypeMenu::addType(DishesMenu dishesMenu)
{
	// 插入该项
	m_plistTypeMenu->InsertItem(menus.size(), dishesMenu.getType());
	// 添加进容器
	menus.push_back(dishesMenu);
}

void DishesTypeMenu::showMenu(int index)
{
	if (index < 0 || index >= menus.size()) {
		return;
	}
	// 清空菜单
	m_plistMenu->DeleteAllItems();
	// 获取菜单
	DishesMenu menu = menus.at(index);
	for (int i = 0; i < menu.getCount(); i++) {
		// 插入id
		m_plistMenu->InsertItem(i, menu.getDish(i)->getIdStr());
		// 添加菜名
		m_plistMenu->SetItemText(i, 1, menu.getDish(i)->getName());
		// 添加菜系
		m_plistMenu->SetItemText(i, 2, menu.getDish(i)->getType());
		// 添加单价
		m_plistMenu->SetItemText(i, 3, menu.getDish(i)->getPerprice());
	}
}

void DishesTypeMenu::clear()
{
	menus.clear();
	m_plistTypeMenu->DeleteAllItems();
	m_plistMenu->DeleteAllItems();
}
