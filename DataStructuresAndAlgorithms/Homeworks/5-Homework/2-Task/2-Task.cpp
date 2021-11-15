
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void reverseStack(stack<int>& st)
{
	stack<int> tempStack;
	while (!st.empty())
	{
		tempStack.push(st.top());
		st.pop();
	}

	st = tempStack;
	return;
}

int main()
{
    int num;
    cin >> num;

	queue<int> badGuys;
	stack<int> goodGuys;
	
	vector<int> warriorsPassed;

	/*-1
		- 2
		4
		5
		6
		- 3
		- 6
		- 7
		- 8
		2
		3*/
	for(int i = 0; i < num; i++)
	{
		int currWarrior;
		cin >> currWarrior;

		if (currWarrior >= 0)
		{
			if (badGuys.empty())
			{
				goodGuys.push(currWarrior);
				continue;
			}

			//fight
			while (true)
			{
				if (goodGuys.empty() && !badGuys.empty())
				{
					while (!badGuys.empty())
					{
						warriorsPassed.push_back(badGuys.front());
						badGuys.pop();
					}
					break;
				}
				else if (!goodGuys.empty() && badGuys.empty())
				{
					break;
				}
				else if (goodGuys.empty() && badGuys.empty())
				{
					break;
				}

				int currGoodGuy = goodGuys.top();
				int currBadGuy = badGuys.front();

				if (currGoodGuy > (- 1) * currBadGuy)
				{
					badGuys.pop();
				}
				else if (currGoodGuy < (-1) * currBadGuy)
				{
					goodGuys.pop();
				}
				else
				{
					goodGuys.pop();
					badGuys.pop();
				}
			}

			goodGuys.push(currWarrior);
		}
		else
		{
			if (goodGuys.empty())
			{
				warriorsPassed.push_back(currWarrior);
				continue;
			}

			badGuys.push(currWarrior);

			if (i == num - 1)
			{
				//fight
				while (true)
				{
					if (goodGuys.empty() && !badGuys.empty())
					{
						while (!badGuys.empty())
						{
							warriorsPassed.push_back(badGuys.front());
							badGuys.pop();
						}
						break;
					}
					else if (!goodGuys.empty() && badGuys.empty())
					{
						break;
					}
					else if (goodGuys.empty() && badGuys.empty())
					{
						break;
					}

					int currGoodGuy = goodGuys.top();
					int currBadGuy = badGuys.front();

					if (currGoodGuy > (-1) * currBadGuy)
					{
						badGuys.pop();
					}
					else if (currGoodGuy < (-1) * currBadGuy)
					{
						goodGuys.pop();
					}
					else
					{
						goodGuys.pop();
						badGuys.pop();
					}
				}
			}
		}
	}

	reverseStack(goodGuys);
	while (!goodGuys.empty())
	{
		warriorsPassed.push_back(goodGuys.top());
		goodGuys.pop();
	}
	
	/*goodGuys.size();
	badGuys.size();
	warriorsPassed.size();*/

	if (warriorsPassed.size() == 0)
	{
		cout << "\n";
	}
	else
	{
		for (size_t i = 0; i < warriorsPassed.size(); i++)
		{
			cout << warriorsPassed[i] << " ";
		}
	}

	return 0;
}


