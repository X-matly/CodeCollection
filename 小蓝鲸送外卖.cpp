#include <iostream>
using namespace std;

struct node
{
	int ID;
	int length;
	node *next;
};
node *branch[50001];

int path[50001];
int state[50001];
long long int DeepSearch(int ID, int con)
{
	long long int number = 0;
	int road = 0;
	int id = 0;
	long long int maxx = 0;
	if (path[ID] == 1)
	{
		number = branch[ID]->length;
		return number += DeepSearch(branch[ID]->ID, con);
	}
	else if (!path[ID])
		return 0;
	else
	{
		for (node *p = branch[ID]; p != NULL; p = p->next)
		{

			long long int temp = DeepSearch(p->ID, 0);
			temp += p->length;
			number += temp;
			if (maxx < temp)
			{
				maxx = temp;
				road = p->length;
				id = p->ID;
			}
		}

		if (con)
		{
			number -= maxx;
			number *= 2;
			number += road;
			number += DeepSearch(id, 1);
		}
		//cout << ID << " " << number << " " << con << endl;
		return number;
	}
}
long int maxx = 0;
long int dfs(int ID)
{
	if (!path[ID])
		return 0;
	for (node *p = branch[ID]; p != NULL; p = p->next)
	{
		long int number = p->length;
		number += dfs(p->ID);
		maxx = (maxx > number ? maxx : number);
	}
	return;
}

int main()
{
	for (int i = 1; i <= 50001; i++)
	{
		path[i] = 0;
		state[i] = 0;
	}
	int N;
	cin >> N;
	for (int i = 1; i <= N - 1; i++)
	{
		int m, n, len;
		cin >> m >> n >> len;
		if (n == 1 || state[n])
		{
			int temp = n;
			n = m;
			m = temp;
		}
		path[m]++;
		state[m]++;
		state[n]++;
		if (branch[m] == NULL)
		{
			branch[m] = (node *)malloc(sizeof(node));
			branch[m]->ID = n;
			branch[m]->length = len;
			branch[m]->next = NULL;
		}
		else
		{
			node *p = branch[m];
			for (; p->next != NULL; p = p->next)
				;
			p->next = (node *)malloc(sizeof(node));
			p = p->next;
			p->ID = n;
			p->length = len;
			p->next = NULL;
		}
	}
	dfs(1);
	cout << maxx;
	return 0;
}