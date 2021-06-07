#include"ReSuperMarket.h"

#include<iostream>

#include<string>
/*void main()
{
	string menu, salemenu, savemenu, buymenu, moneymenu;
	menu = "==进销存===\n";
	menu += "1.销售管理\n";
	menu += "2.库存管理\n";
	menu += "3.采购管理\n";
	menu += "4.财务管理\n0.退出\n请输入您的选择：";
	form f(menu);
	f.input();
}*/


int main()
{
    char c;
    Supermarket a;
    do {
        cout << "\n****超市进销存管理系统****\n";
        cout << " 1—增加商品\n";
        cout << " 2—删除商品\n";
        cout << " 3—修改商品\n";
        cout << " 4—查询商品\n";
        cout << " 5—统计商品\n";
        cout << " 6—退出 \t 请选择（1—6）:";
        cin >> c;
        switch (c)
        {
        case '1':a.Add(); a.Save(); break;
        case '2':a.Load(); a.Delete(); a.Save(); break;
        case '3':a.Load(); a.Modify(); a.Save(); break;
        case '4':a.Load(); a.Query(); break;
        case '5':a.Load(); a.Add_up(); break;
        }
    } while (c != '6');
    return 0;
}