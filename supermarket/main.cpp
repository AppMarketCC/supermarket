#include"supermarket.h"
#include<iostream>

#include<string>
void main()
{
	string menu, salemenu, savemenu, buymenu, moneymenu;
	menu = "==������===\n";
	menu += "1.���۹���\n";
	menu += "2.������\n";
	menu += "3.�ɹ�����\n";
	menu += "4.�������\n0.�˳�\n����������ѡ��";
	form f(menu);
	f.input();
}
