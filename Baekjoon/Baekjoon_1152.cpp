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
		if (i == 0 and list[i] == gap) //문자열이 공백으로 시작했을 시 count값 증가X
			continue;
		else if (list[i] == gap) //문자열 중간에 공백이 나올 시 단어 구분, count값 증가
			count++;
		else if (i == lenght - 1 and list[i] != gap) //공백이 아닌 값으로 문자열이 끝난 경우 마지막 단어 구분. count값 증가.
			count++;
	}
	cout << count << endl;
}