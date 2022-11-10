#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int shifr = 1;
	int len;
	int x;
	int endcharsmall = 122;
	int endcharbig = 90;
	char *arr = new char[1];
	
	while (true)
	{
		cout << "\nChoose operation:\n" << "1 - encryption\n" << "0 - decryption\n" << "-1 - exit\n";
		cin >> shifr;
		if (shifr == -1)
		{
			break;
		}
		cout << "Enter length of word:\n";
		cin >> len;

		char *arr = new char[len];

		cout << "Enter word: ";
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
		cout << "Enter cipher shift: ";
		cin >> x;
		x = x % 26;
		if (shifr == 1)
		{
			for (int i = 0; i < len; i++)
			{
				if (arr[i] + x <= endcharbig && arr[i] >= 65 && arr[i] <= endcharbig)
				{
					arr[i] = arr[i] + x;
				}
				else if (arr[i] + x > endcharbig && arr[i] >= 65 && arr[i] <= endcharbig)
				{
					arr[i] = arr[i] + x - endcharbig + 64;
				}
				else if (arr[i] + x < endcharsmall)
				{
					arr[i] = arr[i] + x;
				}
				else
				{
					arr[i] = arr[i] + x - endcharsmall + 96;
				}
			}
		}
		else if (shifr == 0)
		{
			for (int i = 0; i < len; i++)
			{
				if (arr[i] - x >= 65 && arr[i] >= 65 && arr[i] <= endcharbig || arr[i] - x >= 97)
				{
					arr[i] = arr[i] - x;
				}
				else if (arr[i] - x < 65 && arr[i] >= 65 && arr[i] <= endcharbig)
				{
					arr[i] = arr[i] - x - 64 + endcharbig;
				}
				else
				{
					arr[i] = arr[i] - x - 96 + endcharsmall;
				}
			}
		}
		cout << "Result: ";
		for (int i = 0; i < len; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
	}

	delete[] arr;

	return 0;
}