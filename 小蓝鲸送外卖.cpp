#include<iostream>
using namespace std;

struct node
{
	int ID;
    int length;
	node* next;
};
node* branch[50001];
int path[50001][2];//0:sum    1:fruit
int cut(int num,int max)
{
	/*path[num][0] = path[num][1];
	if (max < path[num][0])max = path[num][0];
	for (node* p = branch[num]; p != NULL; p = p->next)
	{
		max = cut(p->ID, max);
		path[num][0] += (0 > path[p->ID][0]) ? 0 : path[p->ID][0];
		if (max < path[num][0])max = path[num][0];
	}
	return max;*/
    
}

int main()
{
	int N; int first; int check = 0;
	cin >> N;
	for (int i = 1; i <= N - 1; i++)
	{
		int m, n,len;
		cin >> m >> n >> len;
		if (check == 0)
		{
			first = m;
			check = 1;
		}
		if (branch[m] == NULL)
		{
			branch[m] = (node*)malloc(sizeof(node));
			branch[m]->ID = n;
            branch[m]->length=len;
			branch[m]->next = NULL;
		}
		else
		{
			node* p = branch[m];
			for (; p ->next!= NULL; p = p->next);
			p->next= (node*)malloc(sizeof(node));
			p = p->next;
			p->ID = n;
            p->length=len;
			p->next = NULL;
		}
	}
	int answer =cut(first,0);
	cout << answer;
	return 0;
}