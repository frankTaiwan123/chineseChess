#include"chariots.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

chariots::chariots()
{

}

chariots::chariots(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > chariots::canMove()
{
	vector<vector<int> > valid;
	for (int i = 1; colPos - i >= 0; i++)//������
	{
		if (board::piece[rowPos][colPos - i] == 0)//�p�G����S�Ѥl
		{
			valid.push_back(vector<int>{rowPos, colPos - i});
		}
		else
		{
			if (color == 'b' && board::checkColor(rowPos, colPos - i) == 'r')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos, colPos - i});
			}
			if (color == 'r' && board::checkColor(rowPos, colPos - i) == 'b')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos, colPos - i});
			}
			break;
		}
	}
	for (int i = 1; colPos + i <= 8; i++)//���k��
	{
		if (board::piece[rowPos][colPos + i] == 0)//�p�G�k��S�Ѥl
		{
			valid.push_back(vector<int>{rowPos, colPos + i});
		}
		else
		{
			if (color == 'b' && board::checkColor(rowPos, colPos + i) == 'r')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos, colPos + i});
			}
			if (color == 'r' && board::checkColor(rowPos, colPos + i) == 'b')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos, colPos + i});
			}
			break;
		}
	}
	for (int i = 1; rowPos - i >= 0; i++)//���W��
	{
		if (board::piece[rowPos - i][colPos] == 0)//�p�G�W��S�Ѥl
		{
			valid.push_back(vector<int>{rowPos - i, colPos});
		}
		else//��ܤW��i�H����
		{
			if (color == 'b' && board::checkColor(rowPos - i, colPos) == 'r')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos - i, colPos});
			}
			if (color == 'r' && board::checkColor(rowPos - i, colPos) == 'b')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos - i, colPos});
			}
			break;
		}
	}
	for (int i = 1; rowPos + i <= 9; i++)//���U��
	{
		if (board::piece[rowPos + i][colPos] == 0)//�p�G�U�観�Ѥl
		{
			valid.push_back(vector<int>{rowPos + i, colPos});
		}
		else//��ܤU��i�H����
		{
			if (color == 'b' && board::checkColor(rowPos + i, colPos) == 'r')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos + i, colPos});
			}
			if (color == 'r' && board::checkColor(rowPos + i, colPos) == 'b')//�O�ĤH
			{
				valid.push_back(vector<int>{rowPos + i, colPos});
			}
			break;
		}
	}

	return valid;
}

void chariots::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void chariots::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}