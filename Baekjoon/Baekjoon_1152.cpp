#include <iostream>
#include <string>
using namespace std;

void wordCount(string);

int main()
{
	string List;
	cout << "Enter a sentence: ";
	getline(cin, List, '\n');
	wordCount(List);

	return 0;
}

void wordCount(string list)
{
	int count = 0;
	int lenght = list.size();
	char gap = ' ';
	for (int i = 0; i < lenght; i++) {
		if (i == 0 and list[i] == gap) //���ڿ��� �������� �������� �� count�� ����X
			continue;
		else if (list[i] == gap) //���ڿ� �߰��� ������ ���� �� �ܾ� ����, count�� ����
			count++;
		else if (i == lenght - 1 and list[i] != gap) //������ �ƴ� ������ ���ڿ��� ���� ��� ������ �ܾ� ����. count�� ����.
			count++;
	}
	cout << count << endl;
}