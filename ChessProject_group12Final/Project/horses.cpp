#include"horses.h"
#include"chessboard.h"
#include"cursor.h"
#include<vector>

using namespace Chen_Yan_Yu_Board;
using std::vector;

horses::horses()
{

}
horses::horses(int row, int column, char camp)
	:chess(row, column)
{
	color = camp;
}

vector<vector<int> > horses::canMove()
{
	vector<vector<int> > valid;
	if (colPos - 2 >= 0 && board::piece[rowPos][colPos - 1] == 0)//����S�Ѥl
	{
		if (rowPos + 1 <= 9 && color == 'b' && board::checkColor(rowPos + 1, colPos - 2) != 'b')//���U
		{
			valid.push_back(vector<int>{rowPos + 1, colPos - 2});
		}
		if (rowPos + 1 <= 9 && color == 'r' && board::checkColor(rowPos + 1, colPos - 2) != 'r')//���U
		{
			valid.push_back(vector<int>{rowPos + 1, colPos - 2});
		}
		if (rowPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 1, colPos - 2) != 'b')//���W
		{
			valid.push_back(vector<int>{rowPos - 1, colPos - 2});
		}
		if (rowPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 1, colPos - 2) != 'r')//���W
		{
			valid.push_back(vector<int>{rowPos - 1, colPos - 2});
		}
	}
	if (colPos + 2 <= 8 && board::piece[rowPos][colPos + 1] == 0)//�k��S�Ѥl
	{
		if (rowPos + 1 <= 9 && color == 'b' && board::checkColor(rowPos + 1, colPos + 2) != 'b')//�k�U
		{
			valid.push_back(vector<int>{rowPos + 1, colPos + 2});
		}
		if (rowPos + 1 <= 9 && color == 'r' && board::checkColor(rowPos + 1, colPos + 2) != 'r')//�k�U
		{
			valid.push_back(vector<int>{rowPos + 1, colPos + 2});
		}
		if (rowPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 1, colPos + 2) != 'b')//�k�W
		{
			valid.push_back(vector<int>{rowPos - 1, colPos + 2});
		}
		if (rowPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 1, colPos + 2) != 'r')//�k�W
		{
			valid.push_back(vector<int>{rowPos - 1, colPos + 2});
		}
	}
	if (rowPos - 2 >= 0 && board::piece[rowPos - 1][colPos] == 0)//�W��S�Ѥl
	{
		if (colPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos - 2, colPos - 1) != 'b')//�W��
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 1});
		}
		if (colPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos - 2, colPos - 1) != 'r')//�W��
		{
			valid.push_back(vector<int>{rowPos - 2, colPos - 1});
		}
		if (colPos + 1 <= 8 && color == 'b' && board::checkColor(rowPos - 2, colPos + 1) != 'b')//�W�k
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 1});
		}
		if (colPos + 1 <= 8 && color == 'r' && board::checkColor(rowPos - 2, colPos + 1) != 'r')//�W�k
		{
			valid.push_back(vector<int>{rowPos - 2, colPos + 1});
		}
	}
	if (rowPos + 2 <= 9 && board::piece[rowPos + 1][colPos] == 0)//�U��S�Ѥl
	{
		if (colPos - 1 >= 0 && color == 'b' && board::checkColor(rowPos + 2, colPos - 1) != 'b')//�U��
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 1});
		}
		if (colPos - 1 >= 0 && color == 'r' && board::checkColor(rowPos + 2, colPos - 1) != 'r')//�U��
		{
			valid.push_back(vector<int>{rowPos + 2, colPos - 1});
		}
		if (colPos + 1 <= 8 && color == 'b' && board::checkColor(rowPos + 2, colPos + 1) != 'b')//�U�k
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 1});
		}
		if (colPos + 1 <= 8 && color == 'r' && board::checkColor(rowPos + 2, colPos + 1) != 'r')//�U�k
		{
			valid.push_back(vector<int>{rowPos + 2, colPos + 1});
		}
	}

	return valid;
}

void horses::eatMove(vector<int> v)
{
	rowPos = v[0];
	colPos = v[1];
}

void horses::setStatus(int row, int column, char camp, bool die)
{
	rowPos = row;
	colPos = column;
	color = camp;
	dead = die;
}