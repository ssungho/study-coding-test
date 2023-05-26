#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	string answer;
	while (true)
	{

		string temp;
		stack<char> s;
		answer = "yes";
		getline(cin, temp);

		if (temp == ".") 
		{
			break;
		}

		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '[' || temp[i] == '(')
				s.push(temp[i]);
			else if (temp[i] == ']' && !s.empty())
			{
				if (s.top() == '[')
					s.pop();
				else
				{
					answer = "no";
					break;
				}
			}
			else if (temp[i] == ')' && !s.empty())
			{
				if (s.top() == '(')
					s.pop();
				else
				{
					answer = "no";
					break;
				}
			}
			else if (temp[i] == ']' && s.empty())
			{
				answer = "no";
				break;
			}
			else if (temp[i] == ')' && s.empty())
			{
				answer = "no";
				break;
			}
		}

		if (!s.empty())
		{
			answer = "no";
		}

		std::cout << answer << '\n';
	}

	return 0;
}