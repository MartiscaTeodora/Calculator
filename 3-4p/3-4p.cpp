// 3-4p.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>
#include<vector>
#include<cstring>


using namespace std;

int n;
stack <char> ops;
vector<char> polish;
string str;
string c;
int k;

int  prioritate(char c)
{
	//int p;
	switch (c)
	{
	case'(':
		return 0;
	case ')':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case'*':
		return 2;
	case'/':
		return 2;
	default:-1;
	}
}
void citire()
{
	getline(cin, str);
}
void fpol(  )
{
	
	for (char& c : str)
	{if (c >= '0' && c <= '9')
		{
			
		polish.push_back(c);
		}
		else
			if (c == '(')
			ops.push(c);
		else  
			if (c == ')')
		{
			while (ops.empty() != true && ops.top() != '(')
			{
				polish.push_back(ops.top());
				/*k++;
				polish[k] = ops.top();
				
				cout << polish[k]<<" ";*/
				ops.pop();

			}
			if (ops.empty() != true)
				ops.pop();
		}
		else
		{
			while (ops.empty() != true && prioritate(ops.top()) >= prioritate(c))
			{
				polish.push_back(ops.top());
				/*k++;
				polish[k] = ops.top();
				
				cout << polish[k]<<" ";*/
				ops.pop();

			}
			ops.push(c);

		 
		}

	}

	while (ops.empty() != true)
	{
		polish.push_back(ops.top());
		/*k++;
		polish[k] = ops.top();

		cout << polish[k]<<" ";*/
		ops.pop();
	}
}

int main()
{
	//stack <char> ops;
	//int polish[100]{};
	citire();
	fpol();
	
	for (int i = 0; i < polish.size(); i++)
		cout << polish[i] << " ";


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
