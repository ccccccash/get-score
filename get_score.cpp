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
		string player = "选手";
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
			int score = rand() % 41 + 60;//打分区间60-100
			d.push_back(score);
		}

		cout << it->m_name << "打分 ";//显示打分情况
		for (deque<int>::iterator itor = d.begin(); itor != d.end(); itor++)
		{
			cout <<  *itor <<" ";
		}
		

		sort(d.begin(), d.end());//排序
		d.pop_back();//去除最高分
		d.pop_front();//去除最低分

		int sum_score = 0;//总分
		for (deque<int>::iterator itor = d.begin(); itor != d.end(); itor++)
		{
			sum_score += *itor;
		}

		int avg_score = sum_score / size(d);//获取平均分

		it->m_score = avg_score;//赋值给选手

		cout << "最后平均分为 " << it->m_score << endl;
	}
	

}
/*
十个评委给5名选手打分,去掉最高分最低分求平均分
*/

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	
	//1.创建5名选手
	vector<Player>v;
	Creat_player(v);
		
	//2.打分
	Get_score(v);

	

	system("pause");
	return 0;
}