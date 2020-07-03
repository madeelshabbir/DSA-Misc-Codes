#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int sOD(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += ((s[i]%26));
	return sum;
}
int hashFunc(string s)
{
	int a = (sOD(s) + s.length() - s[0] + s[1]) % 40;
	if (a == 5)
		return s.length() % 2 == 0 ? a : 7;
	else if (a == 27)
		return s.length() % 2 == 0 ? a : 8;
	else if (a == 30)
		return s[0] % 2 == 0 ? a : 10;
	else if (a == 34)
		return s[1] % 2 == 0 ? a : 11;
	else if (a == 35)
		return s[1] % 2 == 0 ? a : 12;
	else
		return a ;
}
int main()
{
	string arr[32] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned","void", "volatile", "while" };
	int str[32];
	for (int i = 0; i < 32; i++)
		str[i] = hashFunc(arr[i]);
	qsort(str, 32, sizeof(int), compare);
	for (int i = 0; i < 32; i++)
		cout << str[i] << endl;
	system("pause");
}