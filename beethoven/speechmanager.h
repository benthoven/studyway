#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"gamer.h"
#include<algorithm>
#include<deque>
#include<numeric>//accumulateͷ�ļ�
#include<fstream>
#include<ctime>
//����ϵͳ������
//1.�ṩ�˵������û�����
//2.���ݽ��������̽��п���||��װ
//3.�ļ��Ķ�д����

class speechmanager
{
public:
	//���캯��
	speechmanager();
	//�˵�ҳ��
	void showmenu();
	//����ѡ��
	void creatgamer();
	//�˳�
	void exitsystem();
	//��������
	~speechmanager();
	//��ӡ���Ժ���
	void myprintf();

	//��ʼ��������
	void startspeech();
	//��ǩ����
	void getrank();
	//��������
	void speechcontest();
	//��ʾ�ɼ�
	void showscore();
	//�������
	void saverecord();
	//��ȡ����
	void loadrecord();
	
	//��ʾ�����¼
	void showrecord();
	//����ļ�
	void  clearrecord();

	//��Ա����
	//��һ�ֱ���ѡ�ֱ��
	vector<int>v1;
	//����ѡ�ֱ��
	vector<int>v2;
	//ʤ��ѡ�ֱ��
	vector<int>victor;
	//��ű�źͶ�Ӧѡ�ֵ�����
	map<int, gamer>m_gamer;
	//����������ݵ�����
	map<int, vector<string>>m_record;
	//��������
	int dex;
};
