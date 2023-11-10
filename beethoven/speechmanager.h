#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"gamer.h"
#include<algorithm>
#include<deque>
#include<numeric>//accumulate头文件
#include<fstream>
#include<ctime>
//创建系统管理类
//1.提供菜单界面用户交互
//2.对演讲比赛流程进行控制||封装
//3.文件的读写操作

class speechmanager
{
public:
	//构造函数
	speechmanager();
	//菜单页面
	void showmenu();
	//创建选手
	void creatgamer();
	//退出
	void exitsystem();
	//析构函数
	~speechmanager();
	//打印测试函数
	void myprintf();

	//开始比赛函数
	void startspeech();
	//抽签函数
	void getrank();
	//比赛函数
	void speechcontest();
	//显示成绩
	void showscore();
	//保存分数
	void saverecord();
	//读取分数
	void loadrecord();
	
	//显示往届记录
	void showrecord();
	//清空文件
	void  clearrecord();

	//成员属性
	//第一轮比赛选手编号
	vector<int>v1;
	//晋级选手编号
	vector<int>v2;
	//胜利选手编号
	vector<int>victor;
	//存放编号和对应选手的容器
	map<int, gamer>m_gamer;
	//存放往届数据的容器
	map<int, vector<string>>m_record;
	//比赛轮数
	int dex;
};
