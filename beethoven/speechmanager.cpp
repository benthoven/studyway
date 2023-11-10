#include"speechmanager.h"

//���캯��
speechmanager::speechmanager()
{
	//��ʼ����������
	v1.clear();
	v2.clear();
	victor.clear();
	m_record.clear();
	m_gamer.clear();
	dex = 1;
}
//�˵�ҳ��
void speechmanager::showmenu()
{
	cout << "******************************" << endl;
	cout << "******* ��ӭ�μ��ݽ����� *******" << endl;
	cout << "******* 1.��ʼ�ݽ����� *******" << endl;
	cout << "******* 2.�鿴������¼ *******" << endl;
	cout << "******* 3.��ձ�����¼ *******" << endl;
	cout << "******* 0.�˳�����ϵͳ *******" << endl;
}
//����12��ѡ��
void speechmanager::creatgamer()//�ַ���ƴ��
{
	string nameseed = "abcdefghijkl";
	//����12������
		for (int i = 0; i < 12; i++)
		{
			//��ʼ������
			string tempname = "ѡ��_";
			tempname += nameseed[i];
			//��������
			gamer g1;
			g1.name = tempname;
			//��ʼ������
			for (int i = 0; i < 2; i++)
			{
				//������ֵ����Ϊ0
				g1.score[i] = 0;
			}
			//�������
			v1.push_back(i + 10001);//����ҡ��
			//��ź�ѡ�� ��ŵ�map����
			m_gamer.insert(make_pair(v1[i], g1));//map��������ɶԴ��
		}
}
void speechmanager::myprintf()
{
	for (map<int, gamer>::const_iterator it = m_gamer.begin(); it != m_gamer.end(); it++)
	{
		cout << "ѡ�ֱ��Ϊ  " << (*it).first << "  ���� " << (*it).second.name << "  �ɼ�Ϊ " << (*it).second.score[0] << endl;;
	}
}
//��ǩ
void speechmanager::getrank()
{
	cout << "ѡ�����ڳ�ǩ" << endl;
	if (dex == 1)
	{//��������Ԫ��˳��
		random_shuffle(v1.begin(), v1.end());
		cout << "��ǩ���Ϊ:" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	else
	{
		//���ǵڶ���
		random_shuffle(v2.begin(), v2.end());
		cout << "��ǩ���Ϊ:" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	cout << "**********" << endl;
	system("pause");
}
//��ʽ��������
void speechmanager::speechcontest()
{
	//������ʱ�������������������
	vector<int>temp;
	//�ڴ���һ����ʱ�������з���
	multimap<double, int, greater<double>>groupscore;//greater��map��������ʱ���趨����ʽ������Ϊ����  map���������ݼ�ֵ�Զ����򣬱����˺����Է���������
	int num = 0;//ͳ������������һ��

	if (dex == 1)//��һ�ֱ���
	{
		temp = v1;
	}
	else//�ڶ���
	{
		temp = v2;
	}
	//��������Ԫ�ؽ��б���
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		num++;//������
		//�����������
		deque<double>dq;
		for (int i = 0; i < 10; i++)//10����ί���
		{
			double givescore =(double)  (rand() % 401 + 600)/ 10;//����0-100�ĸ���������
			//����
			//cout << "��ί��������Ϊ" << givescore << "  ";

			dq.push_back(givescore);
		}
		cout << endl;
		//����ȥ���ߵͷ�
		sort(dq.begin(), dq.end(), greater<double>());//���� greater ���ܺ���
		dq.pop_back();
		dq.pop_front();
		//����ƽ����
		double ave = accumulate(dq.begin(), dq.end(),0.0)/(double)dq.size();//0.0Ϊ��ֵ  �����������ദ��������������Ҫת��
		//����map����
		m_gamer[*it].score[dex - 1] = ave;//*itΪkeyֵ  dex-Ϊ�ڼ��ַ���
		//����ƽ����
		//cout << ave;
		//��������ݷ�����ʱС����
		groupscore.insert(make_pair(ave, *it));//key�ǵ÷֣�value�Ǳ��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������Ϊ" << endl;
			//���� ��ʾ���г�Ա����
			for (multimap<double, int, greater<double>>::iterator it1 = groupscore.begin(); it1 != groupscore.end(); it1++)
			{
				cout << "��� " << (*it1).second << " ���� " << m_gamer[(*it1).second].name << " ���� ��" << m_gamer[(*it1).second].score[dex - 1] << endl;
			}
			//ȡ��ǰ����
			int count =0;
			for (multimap<double, int, greater<double>>::iterator it2 = groupscore.begin(); it2 != groupscore.end() && count < 3; it2++,count++)
			{
				if (dex == 1)
				{
					v2.push_back((*it2).second);//��Ŵ����������
			    }
				else
				{
					victor.push_back((*it2).second);
				}
			}
			groupscore.clear();//�������������ǰһ������ݸ���
			
		}
		
	}
	cout << "����������������������" << dex << "�ֱ�����ϡ�����������������������" << endl;;
}
void speechmanager::showscore()
{
	cout << "��  " << dex << "�ֽ���ѡ��Ϊ" << endl;
	vector<int>tempvector;//��������
	if(dex==1)
	{
		tempvector = v2;
	}
	else
	{
		tempvector = victor;
	}
	//����
	for (vector<int>::iterator it = tempvector.begin(); it != tempvector.end(); it++)
	{
		cout << " ѡ�ֱ�� " << *it << " ���� " << m_gamer[*it].name << " �ɼ� " << m_gamer[*it].score[dex-1] << endl;
	}
	system("pause");
	system("cls");
	showmenu();
}
//�����ļ�
void speechmanager::saverecord()
{
	fstream frs;
	frs.open("speech.csv", ios::in | ios::app);//��׷�ӵķ�ʽд���ļ�
	//��ѡ����Ϣд��
	for (vector<int>::iterator it = victor.begin(); it != victor.end(); it++)
	{
		frs << "ѡ�ֱ��Ϊ " << *it << " ѡ������ " << m_gamer[*it].name << " ѡ�ֳɼ�  " << m_gamer[*it].score[1] << ",";
	}
	frs << endl;
	frs.close();
	cout << "�ļ�����ɹ�" << endl;
	system("pause");
	system("cls");
	showmenu();
}
//��ȡ����
void speechmanager::loadrecord()
{//����һ����ȡ���� ����ȡ����ȫ����������  ֱ�Ӷ�ȡҲ����
	vector<string>s;
	//��������
	int m_dex = 1;
	fstream frs;
	
	frs.open("speech.csv", ios::in);//���ļ����������򲻴����ļ�

	if (!frs)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������
	string data;
	while (frs >> data)//��λ���ƶ�ȡ
	{
		//cout << data << "  " << "\t";
		int pos = 0;
		int start = 0;//����λ��

		while (1)
		{
			pos = data.find(",", start);//�����±� startΪ��ʲôλ�ÿ�ʼ��û�����0��ʼ
			if (pos == -1)
			{
				cout << "δ�ҵ�ָ���ַ�" << endl;
				break;
			}
			string temp = data.substr(start, pos - start);//start���ҿ�ʼλ��  pos-start��ȡ����  substr�����ַ�
			//cout << temp <<"  ";
			//��������
			s.push_back(temp);

			start = pos + 1;//�����
		
		}
		m_record.insert(make_pair(m_dex, s));
		m_dex++;
	}
	
	frs.close();

	for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++)
	{
		cout << "��" << (*it).first << "�� ��һ�����"<< (*it).second.at(1) << "  " << "����" << (*it).second.at(2) << endl;
	}
	
}
void speechmanager::showrecord()
{
	if (m_record.size() == 0)
	{
		cout << "�ļ�������" << endl;
	}
	for (int i = 1; i < m_record.size(); i++)
	{
		
		cout << "��" << i + 1 << "��" << "�ھ����" <<this-> m_record[i][0] << " �÷� " << m_record[i][1] << endl;
	
	}
}
//��ʼ����
void speechmanager::startspeech()
{
	//��һ�ֿ�ʼ����
	cout << "��" << dex << "�ֱ�����ʼ��";
	cout << "**************" << endl;
//2.��ǩ��ʼ
	getrank();
//3.����
	speechcontest();
//4.��ʾ�������
	showscore();
//�ڶ��ֱ�����ʼ(����������һ��������)
	dex++;
//1.��ǩ
	getrank();
//2.����
	speechcontest();
//3.��ʾ���ս��
	showscore();
//4.����������ļ���
	saverecord();

	cout << "��������" << endl;
}
//�����¼
void speechmanager::clearrecord()
{
	cout << "�Ƿ���ռ�¼" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		fstream frs;

		frs.open("speech.csv", ios::trunc);
		frs.close();

		//��ʼ����������
		v1.clear();
		v2.clear();
		victor.clear();
		m_record.clear();
		dex = 1;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		return;
	}
}
//�˳�ϵͳ
void speechmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(1);//�����˳������൱��return

}
//��������
speechmanager::~speechmanager()
{

}