#include<vector>

#ifndef BOARD
#define BOARD


namespace Chen_Yan_Yu_Board
{
	using std::vector;
	class board
	{
	public:
		//board();//We do not use it.
		board(int arr[10][9]);//constructor
		static void set(int arr[10][9]);//�]�w�ѽL�\�]
		static char checkColor(int row, int col);
		static int piece[10][9];
		static int getBoard(vector<int> v);//�^��board::piece[r][c]
	};
}

#endif
