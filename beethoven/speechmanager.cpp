#include"speechmanager.h"

//构造函数
speechmanager::speechmanager()
{
	//初始化所有容器
	v1.clear();
	v2.clear();
	victor.clear();
	m_record.clear();
	m_gamer.clear();
	dex = 1;
}
//菜单页面
void speechmanager::showmenu()
{
	cout << "******************************" << endl;
	cout << "******* 欢迎参加演讲比赛 *******" << endl;
	cout << "******* 1.开始演讲比赛 *******" << endl;
	cout << "******* 2.查看比赛记录 *******" << endl;
	cout << "******* 3.清空比赛记录 *******" << endl;
	cout << "******* 0.退出比赛系统 *******" << endl;
}
//创建12名选手
void speechmanager::creatgamer()//字符串拼接
{
	string nameseed = "abcdefghijkl";
	//创建12个人物
		for (int i = 0; i < 12; i++)
		{
			//初始化姓名
			string tempname = "选手_";
			tempname += nameseed[i];
			//创建对象
			gamer g1;
			g1.name = tempname;
			//初始化分数
			for (int i = 0; i < 2; i++)
			{
				//两个初值均赋为0
				g1.score[i] = 0;
			}
			//创建编号
			v1.push_back(i + 10001);//用来摇号
			//编号和选手 存放到map容器
			m_gamer.insert(make_pair(v1[i], g1));//map容器必须成对存放
		}
}
void speechmanager::myprintf()
{
	for (map<int, gamer>::const_iterator it = m_gamer.begin(); it != m_gamer.end(); it++)
	{
		cout << "选手编号为  " << (*it).first << "  姓名 " << (*it).second.name << "  成绩为 " << (*it).second.score[0] << endl;;
	}
}
//抽签
void speechmanager::getrank()
{
	cout << "选手正在抽签" << endl;
	if (dex == 1)
	{//打乱容器元素顺序
		random_shuffle(v1.begin(), v1.end());
		cout << "抽签结果为:" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	else
	{
		//则是第二轮
		random_shuffle(v2.begin(), v2.end());
		cout << "抽签结果为:" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "   ";
		}
		cout << endl;
	}
	cout << "**********" << endl;
	system("pause");
}
//正式比赛函数
void speechmanager::speechcontest()
{
	//创建临时容器帮助后续步骤进行
	vector<int>temp;
	//在创建一个临时容器进行分组
	multimap<double, int, greater<double>>groupscore;//greater在map容器创建时就设定排序方式，否则为升序  map容器会依据键值自动排序，避免了后续对分数的排序
	int num = 0;//统计人数，六人一组

	if (dex == 1)//第一轮比赛
	{
		temp = v1;
	}
	else//第二轮
	{
		temp = v2;
	}
	//遍历所有元素进行比赛
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		num++;//数人数
		//创建打分数组
		deque<double>dq;
		for (int i = 0; i < 10; i++)//10个评委打分
		{
			double givescore =(double)  (rand() % 401 + 600)/ 10;//生成0-100的浮点型数字
			//测试
			//cout << "评委给定分数为" << givescore << "  ";

			dq.push_back(givescore);
		}
		cout << endl;
		//排序，去除高低分
		sort(dq.begin(), dq.end(), greater<double>());//降序 greater 功能函数
		dq.pop_back();
		dq.pop_front();
		//计算平均分
		double ave = accumulate(dq.begin(), dq.end(),0.0)/(double)dq.size();//0.0为初值  浮点与整数相处还是整数，所以要转换
		//放入map容器
		m_gamer[*it].score[dex - 1] = ave;//*it为key值  dex-为第几轮分数
		//测试平均分
		//cout << ave;
		//将打分数据放入临时小组中
		groupscore.insert(make_pair(ave, *it));//key是得分，value是编号
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次为" << endl;
			//遍历 显示所有成员分数
			for (multimap<double, int, greater<double>>::iterator it1 = groupscore.begin(); it1 != groupscore.end(); it1++)
			{
				cout << "编号 " << (*it1).second << " 姓名 " << m_gamer[(*it1).second].name << " 分数 ：" << m_gamer[(*it1).second].score[dex - 1] << endl;
			}
			//取走前三名
			int count =0;
			for (multimap<double, int, greater<double>>::iterator it2 = groupscore.begin(); it2 != groupscore.end() && count < 3; it2++,count++)
			{
				if (dex == 1)
				{
					v2.push_back((*it2).second);//编号存入晋级容器
			    }
				else
				{
					victor.push_back((*it2).second);
				}
			}
			groupscore.clear();//清空容器，避免前一组的数据干扰
			
		}
		
	}
	cout << "——————————第" << dex << "轮比赛完毕————————————" << endl;;
}
void speechmanager::showscore()
{
	cout << "第  " << dex << "轮晋级选手为" << endl;
	vector<int>tempvector;//辅助容器
	if(dex==1)
	{
		tempvector = v2;
	}
	else
	{
		tempvector = victor;
	}
	//遍历
	for (vector<int>::iterator it = tempvector.begin(); it != tempvector.end(); it++)
	{
		cout << " 选手编号 " << *it << " 姓名 " << m_gamer[*it].name << " 成绩 " << m_gamer[*it].score[dex-1] << endl;
	}
	system("pause");
	system("cls");
	showmenu();
}
//保存文件
void speechmanager::saverecord()
{
	fstream frs;
	frs.open("speech.csv", ios::in | ios::app);//用追加的方式写入文件
	//将选手信息写入
	for (vector<int>::iterator it = victor.begin(); it != victor.end(); it++)
	{
		frs << "选手编号为 " << *it << " 选手姓名 " << m_gamer[*it].name << " 选手成绩  " << m_gamer[*it].score[1] << ",";
	}
	frs << endl;
	frs.close();
	cout << "文件保存成功" << endl;
	system("pause");
	system("cls");
	showmenu();
}
//读取函数
void speechmanager::loadrecord()
{//创建一个读取容器 将读取内容全部放入容器  直接读取也可以
	vector<string>s;
	//创建届数
	int m_dex = 1;
	fstream frs;
	
	frs.open("speech.csv", ios::in);//读文件。不存在则不创建文件

	if (!frs)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	string data;
	while (frs >> data)//逐位右移读取
	{
		//cout << data << "  " << "\t";
		int pos = 0;
		int start = 0;//查找位置

		while (1)
		{
			pos = data.find(",", start);//返回下标 start为从什么位置开始，没有则从0开始
			if (pos == -1)
			{
				cout << "未找到指定字符" << endl;
				break;
			}
			string temp = data.substr(start, pos - start);//start查找开始位置  pos-start截取长度  substr复制字符
			//cout << temp <<"  ";
			//放入容器
			s.push_back(temp);

			start = pos + 1;//向后移
		
		}
		m_record.insert(make_pair(m_dex, s));
		m_dex++;
	}
	
	frs.close();

	for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++)
	{
		cout << "第" << (*it).first << "届 第一名编号"<< (*it).second.at(1) << "  " << "分数" << (*it).second.at(2) << endl;
	}
	
}
void speechmanager::showrecord()
{
	if (m_record.size() == 0)
	{
		cout << "文件不存在" << endl;
	}
	for (int i = 1; i < m_record.size(); i++)
	{
		
		cout << "第" << i + 1 << "届" << "冠军编号" <<this-> m_record[i][0] << " 得分 " << m_record[i][1] << endl;
	
	}
}
//开始比赛
void speechmanager::startspeech()
{
	//第一轮开始比赛
	cout << "第" << dex << "轮比赛开始了";
	cout << "**************" << endl;
//2.抽签开始
	getrank();
//3.比赛
	speechcontest();
//4.显示晋级结果
	showscore();
//第二轮比赛开始(除了轮数加一其他不变)
	dex++;
//1.抽签
	getrank();
//2.比赛
	speechcontest();
//3.显示最终结果
	showscore();
//4.保存分数到文件中
	saverecord();

	cout << "比赛结束" << endl;
}
//清除记录
void speechmanager::clearrecord()
{
	cout << "是否清空记录" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		fstream frs;

		frs.open("speech.csv", ios::trunc);
		frs.close();

		//初始化所有容器
		v1.clear();
		v2.clear();
		victor.clear();
		m_record.clear();
		dex = 1;
		cout << "删除成功" << endl;
	}
	else
	{
		return;
	}
}
//退出系统
void speechmanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(1);//内置退出函数相当于return

}
//析构函数
speechmanager::~speechmanager()
{

}