#include"ReSuperMarket.h"

#include<iostream>

#include<string>
/*void main()
{
	string menu, salemenu, savemenu, buymenu, moneymenu;
	menu = "==������===\n";
	menu += "1.���۹���\n";
	menu += "2.������\n";
	menu += "3.�ɹ�����\n";
	menu += "4.�������\n0.�˳�\n����������ѡ��";
	form f(menu);
	f.input();
}*/


int main()
{
    char c;
    Supermarket a;
    do {
        cout << "\n****���н��������ϵͳ****\n";
        cout << " 1��������Ʒ\n";
        cout << " 2��ɾ����Ʒ\n";
        cout << " 3���޸���Ʒ\n";
        cout << " 4����ѯ��Ʒ\n";
        cout << " 5��ͳ����Ʒ\n";
        cout << " 6���˳� \t ��ѡ��1��6��:";
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