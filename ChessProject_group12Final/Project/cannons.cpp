#include"cannons.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

cannons::cannons()
{

}

cannons::cannons(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > cannons::canMove()
{
	vector<vector<int> > valid;
	bool findEnemy = false;
	for (int i = 1; colPos - i >= 0; i++)//������
	{
		if (board::piece[rowPos][colPos - i] != 0)//�p�G���䦳�Ѥl
		{
			for (i = i + 1; colPos - i >= 0; i++)//�h���誺�Ĥ@�ӼĤH�i�H�Y
			{
				if (color == 'b' && board::checkColor(rowPos, colPos - i) == 'r')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos - i});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos, colPos - i) == 'b')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos - i});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//��ܥ���i�H����
		{
			valid.push_back(vector<int>{rowPos, colPos - i});
		}
	}
	findEnemy = false;
	for (int i = 1; colPos + i <= 8; i++)//���k��
	{
		if (board::piece[rowPos][colPos + i] != 0)//�p�G�k�䦳�Ѥl
		{
			for (i = i + 1; colPos + i <= 8; i++)//�h���誺�Ĥ@�ӼĤH�i�H�Y
			{
				if (color == 'b' && board::checkColor(rowPos, colPos + i) == 'r')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos + i});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos, colPos + i) == 'b')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos, colPos + i});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//��ܥk��i�H����
		{
			valid.push_back(vector<int>{rowPos, colPos + i});
		}
	}
	findEnemy = false;
	for (int i = 1; rowPos - i >= 0; i++)//���W��
	{
		if (board::piece[rowPos - i][colPos] != 0)//�p�G�W�観�Ѥl
		{
			for (i = i + 1; rowPos - i >= 0; i++)//�h���誺�Ĥ@�ӼĤH�i�H�Y
			{
				if (color == 'b' && board::checkColor(rowPos - i, colPos) == 'r') //�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos - i, colPos});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos - i, colPos) == 'b') //�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos - i, colPos});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//��ܤW��i�H����
		{
			valid.push_back(vector<int>{rowPos - i, colPos});
		}
	}
	findEnemy = false;
	for (int i = 1; rowPos + i <= 9; i++)//���U��
	{
		if (board::piece[rowPos + i][colPos] != 0)//�p�G�U�観�Ѥl
		{
			for (i = i + 1; rowPos + i <= 9; i++)//�h���誺�Ĥ@�ӼĤH�i�H�Y
			{
				if (color == 'b' && board::checkColor(rowPos + i, colPos) == 'r')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos + i, colPos});
					break;
				}
				if (color == 'r' && board::checkColor(rowPos + i, colPos) == 'b')//�p�G�O�ĤH
				{
					findEnemy = true;
					valid.push_back(vector<int>{rowPos + i, colPos});
					break;
				}
			}
			if (findEnemy == true)
			{
				break;
			}
		}
		else//��ܤU��i�H����
		{
			valid.push_back(vector<int>{rowPos + i, colPos});
		}
	}

	return valid;
}

void cannons::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void cannons::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}