#include"speechmanager.h"

int main()
{
	srand((unsigned int)time(NULL));
	//1.��������ϵͳ����
	speechmanager sm;
	int choice = 0;

	while (1)
	{
		//2.ҳ��չʾ
		sm.showmenu();
		sm.creatgamer();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		;
		//sm.myprintf(sm);
		
		switch (choice)
		{
		case 1://��ʼ����
			sm.startspeech();
			break;
		case 2://�鿴��¼
			sm.loadrecord();
			break;
		case 3://��ռ�¼
			sm.clearrecord();
			break;
		case 0://�˳�ϵͳ
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