
#include<stdio.h>
#define max 200
#define initial 1
#define waiting 2
#define visit 3

int state[max];

int adj[max][max];
int visited[max];
int n,e;

void add_edge(int u ,int v)
{
    adj[u][v]=1;
}
void read_from_file()
{
    FILE *in_file;
    int n,m;

    in_file = fopen("e:\\tgraph.txt","r");

    if(in_file == NULL)
    {
        printf("error\n");
    }
    while(fscanf(in_file,"%d %d",&n,&m) != EOF)
    {
       add_edge(n,m);
    }
    fclose(in_file);
}

void DFS(int i)
	{
	    int j;
	    printf("%d ",i);
	    visited[i]=1;
	    for(j=0;j<n;j++)
	    {
	        if(!visited[j] && adj[i][j]==1)
	        {
	           DFS(j);
	        }
	    }
	}

void Display()
{
    float ps;
    int e,i,j,origin,dest;
    for(i=0;i<=7;i++)
    {
        int indeg=0,outdeg=0;
        for(j=0;j<=7;j++)
        {
            if(adj[j][i] == 1)
            {
                indeg++;
            }
        }
        for(j=0;j<n;j++)
        {
            if(adj[i][j] == 1)
            {
                outdeg++;
            }
        }

        ps=(float)indeg/outdeg;
        if(ps == 2.0)
        {
            printf("person : [ %d ]\t Popular\t Popularity Score : %.2f\t Followed : [ %d ] \tFollows : [ %d ]\t\n",i,ps,indeg,outdeg);
        }
        else if(ps == 3.0)
            printf("person : [ %d ]\t Popular\t Popularity Score : %.2f\t Followed : [ %d ] \tFollows : [ %d ]\t\n",i,ps,indeg,outdeg);
        else if(indeg == 2 && outdeg == 0)
        {
            ps=0;
            printf("person : [ %d ]\t Not Popular\t Popularity Score : %.2f\t Followed : [ %d ] \tFollows : [ %d ]\t\n",i,ps,indeg,outdeg);
        }
        else if(indeg == 3 && outdeg == 0)
        {
            ps=0;
            printf("person : [ %d ]\t Popular\t Popularity Score : %.2f\t Followed : [ %d ] \tFollows : [ %d ]\t\n",i,ps,indeg,outdeg);
        }
        else
            printf("person : [ %d ]\t Not Popular\t Popularity Score : %.2f\t Followed : [ %d ] \tFollows : [ %d ]\t\n",i,ps,indeg,outdeg);
    }
}
int main()
{
    read_from_file();

    int e;
    printf("Enter no of nodes :");
    scanf("%d",&n);
    printf("Enter no of edgs ");
    scanf("%d",&e);
    printf("\n\n");

    printf("DFS Traversal : ");
    DFS(0);
    printf("\n\n");
    printf("\n\n");
    Display();
	return 0;
}
