#include"supermarket.h"
#include<iostream>

#include<string>
void main()
{
	string menu, salemenu, savemenu, buymenu, moneymenu;
	menu = "==进销存===\n";
	menu += "1.销售管理\n";
	menu += "2.库存管理\n";
	menu += "3.采购管理\n";
	menu += "4.财务管理\n0.退出\n请输入您的选择：";
	form f(menu);
	f.input();
}
