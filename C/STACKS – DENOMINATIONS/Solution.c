#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;string.h&gt;
#include&lt;math.h&gt;
#define SIZE 100
struct stack
{
    int coin[SIZE];
    int top;
};
void push(struct stack *sptr, int num);
void pop_count_display(struct stack *sptr);
int main()
{
    struct stack * sptr;
    struct stack s;
    sptr=&amp;s;
    sptr-&gt;top=-1;
    int c,n,i;
    scanf("%d",&amp;n);
    if(n&lt;0)
    {
        printf("Invalid number of coins");
        exit(0);
    }
    for(i=0;i&lt;n;i++)
{
scanf("%d",&amp;c);
push(sptr,c);
}
pop_count_display(sptr);
 }
void push(struct stack *sptr, int num)
 {
if(sptr-&gt;top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr-&gt;top++;
        sptr-&gt;coin[sptr-&gt;top]=num;
    }
}
void pop_count_display(struct stack *sptr)
{
        int i,c1=0,c2=0,c5=0,c10=0,c=0;
        for(i=sptr-&gt;top;i&gt;=0;i--)
        {
            if(sptr-&gt;coin[i]==1)
            {
               c1++;
            }
            else if(sptr-&gt;coin[i]==2)
            {
               c2++;
            }
            else if(sptr-&gt;coin[i]==5)
            {
               c5++;
            }
            else if(sptr-&gt;coin[i]==10)
            {
               c10++;
            }
            else
            {
                c++;
            }
            sptr-&gt;top--;
        }
        printf("Coins of 1 re = %d\n",c1);
        printf("Coins of 2 rs = %d\n",c2);
        printf("Coins of 5 rs = %d\n",c5);
        printf("Coins of 10 rs = %d\n",c10);
    printf("Coins of invalid denominations = %d",c);
}
