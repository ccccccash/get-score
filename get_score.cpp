#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include <vector>

class Player
{
public:
	Player(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};

void Creat_player(vector<Player>&v)
{
	string nameseed = "ABCDEFG";
	for (int i = 0; i < 5; i++)
	{
		string player = "ѡ��";
		player += nameseed[i];
		
		int score = 0;
		Player p(player, score);
		v.push_back(p);
	}
}

void Get_score(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//�������60-100
			d.push_back(score);
		}

		cout << it->m_name << "��� ";//��ʾ������
		for (deque<int>::iterator itor = d.begin(); itor != d.end(); itor++)
		{
			cout <<  *itor <<" ";
		}
		

		sort(d.begin(), d.end());//����
		d.pop_back();//ȥ����߷�
		d.pop_front();//ȥ����ͷ�

		int sum_score = 0;//�ܷ�
		for (deque<int>::iterator itor = d.begin(); itor != d.end(); itor++)
		{
			sum_score += *itor;
		}

		int avg_score = sum_score / size(d);//��ȡƽ����

		it->m_score = avg_score;//��ֵ��ѡ��

		cout << "���ƽ����Ϊ " << it->m_score << endl;
	}
	

}
/*
ʮ����ί��5��ѡ�ִ��,ȥ����߷���ͷ���ƽ����
*/

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	
	//1.����5��ѡ��
	vector<Player>v;
	Creat_player(v);
		
	//2.���
	Get_score(v);

	

	system("pause");
	return 0;
}