#include<iostream>
using namespace std;

struct node
{
	int ID;
    int length;
	node* next;
};
node* branch[50001];

int maxx=0;
int path[50001];

int DeepSearch(int ID,int check)
{
    long int number=0;
    for (node* p = branch[ID]; p != NULL; p = p->next)
	{
		int temp=DeepSearch(p->ID,0);
        temp+=p->length;
        number+=temp;       
        if(check)maxx=(maxx>temp?maxx:temp);
	}
    return number;
}

int main()
{
    for(int i=1;i<=50001;i++)path[i]=0;
	int N; 
	cin >> N;
	for (int i = 1; i <= N - 1; i++)
	{
		int m, n,len;
		cin >> m >> n >> len;
        if(n==1||path[n])
        {
            int temp=n;
            n=m;
            m=temp;
        }
        path[m]++;
        path[n]++;
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
    long int answer;
	if(path[1]!=1) 
    {
        answer=DeepSearch(1,1);
        answer=(answer-maxx)*2+maxx;
    }
    else 
    {
        answer=DeepSearch(branch[1]->ID,1);
        answer=(answer-maxx)*2+maxx;
        answer+=branch[1]->length;
    }
	cout << answer;
	return 0;
}