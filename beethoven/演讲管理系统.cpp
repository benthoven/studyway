#include"speechmanager.h"

int main()
{
	srand((unsigned int)time(NULL));
	//1.创建管理系统对象
	speechmanager sm;
	int choice = 0;

	while (1)
	{
		//2.页面展示
		sm.showmenu();
		sm.creatgamer();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		;
		//sm.myprintf(sm);
		
		switch (choice)
		{
		case 1://开始比赛
			sm.startspeech();
			break;
		case 2://查看记录
			sm.loadrecord();
			break;
		case 3://清空记录
			sm.clearrecord();
			break;
		case 0://退出系统
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	



	system("pause");
	return 0;
}