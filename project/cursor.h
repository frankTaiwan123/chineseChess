#include<vector>

#ifndef CURSOR_H
#define CURSOR_H

using std::vector;

class cursor
{
public:
	cursor();
	void changePos(int r, int c);
	void changeRow(int i);
	vector<int> getCursorPos();
private:
	int rowPos, colPos;//�o�O�b�ѽL�̥Ϊ�
	int row;//�C�����̥Ϊ�
};

#endif // !CURSOR_H


