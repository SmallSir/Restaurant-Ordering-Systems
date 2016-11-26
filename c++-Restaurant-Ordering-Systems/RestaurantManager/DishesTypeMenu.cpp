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
	// ���ļ�
	_wfopen_s(&fp, path, _T("r"));
	// δ�ܴ򿪣�����FALSE
	if (fp == NULL) {
		return FALSE;
	}
	// ����һ��ȫ���˵�
	DishesMenu dishesMenu(_T("ȫ��"));
	// ��Ӹò˵�
	addType(dishesMenu);
	// ��ȡ�˵�����
	for (int i = 0; !feof(fp); i++) {
		// �˵����ݴ����ʽΪANSI����ȡʱҪת��
		// ���ݲ�ʹ��Unicode���봢�棬��Ϊ��ȡʱ���������
		// ���ַ���ȡ����
		// wchar_t *name = new wchar_t[21], *type = new wchar_t[21];
		// fwscanf_s(fp, _T("#%s %s %lf\n"), name, 20, type, 20, &payment);

		// ���ļ���ȡ����
		switch (fgetc(fp)) {
		case '#':
		{
			// Ϊ��������ϵ�����۴����ڴ�ռ�
			char *cName = new char[21], *cType = new char[21];
			double payment = 0;
			CString name, type;
			if (3 != fscanf_s(fp, "%s %s %lf\n", cName, 20, cType, 20, &payment)) {
				// ��������û��ȫ���ɹ���ֵ��������һ��
				continue;
			}
			// ת��Ϊ���ַ�
			name = cName;
			type = cType;
			// ������
			Dish dish(name, type, payment);
			// ����id
			dish.setId(i + 1);
			// ��ӽ�ȫ���˵�
			menus.at(0).addDish(dish);
			// ���Ҳ�ϵ�Ƿ����
			DishesMenu *pDishMenu = findMenu(type);
			if (pDishMenu == NULL) {
				// ��û�������ϵ�������²˵�
				DishesMenu dishesMenu(type);
				dishesMenu.addDish(dish);
				// ��ӽ���ϵ
				addType(dishesMenu);
			}
			else {
				pDishMenu->addDish(dish);
			}
			break;
		}
		case EOF:
			// ��ȡ����
			break;
		default:
			// ��ȡ����
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
	// �������
	m_plistTypeMenu->InsertItem(menus.size(), dishesMenu.getType());
	// ��ӽ�����
	menus.push_back(dishesMenu);
}

void DishesTypeMenu::showMenu(int index)
{
	if (index < 0 || index >= menus.size()) {
		return;
	}
	// ��ղ˵�
	m_plistMenu->DeleteAllItems();
	// ��ȡ�˵�
	DishesMenu menu = menus.at(index);
	for (int i = 0; i < menu.getCount(); i++) {
		// ����id
		m_plistMenu->InsertItem(i, menu.getDish(i)->getIdStr());
		// ��Ӳ���
		m_plistMenu->SetItemText(i, 1, menu.getDish(i)->getName());
		// ��Ӳ�ϵ
		m_plistMenu->SetItemText(i, 2, menu.getDish(i)->getType());
		// ��ӵ���
		m_plistMenu->SetItemText(i, 3, menu.getDish(i)->getPerprice());
	}
}

void DishesTypeMenu::clear()
{
	menus.clear();
	m_plistTypeMenu->DeleteAllItems();
	m_plistMenu->DeleteAllItems();
}
