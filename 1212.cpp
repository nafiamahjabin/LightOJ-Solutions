#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    char s[100];
    int t,n,x, i=0, l, test;
    scanf("%d", &test);
    while(test--)
    {
        i++;
        l=0;
        scanf("%d%d", &n,&t);
        getchar();
        printf("Case %d:\n", i);
        while(t--)
        {

            scanf("%s", s);
            if(strcmp(s, "pushLeft")==0)
            {
                scanf("%d", &x);
                if(n>l)
                {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                    l++;
                }
                else
                {
                    printf("The queue is full\n");
                }
            }
            else if(strcmp(s, "pushRight")==0)
            {
                scanf("%d", &x);
                if(n>l)
                {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                    l++;
                }
                else
                {
                    printf("The queue is full\n");
                }
            }
            else if(strcmp(s, "popLeft")==0)
            {
                if(l>0)
                {
                    cout << "Popped from left: " << dq.front() << '\n';
                    dq.pop_front();

                    l--;
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }
            else
            {
                if(l>0)
                {
                    printf("Popped from right: %d\n", dq.back());
                    dq.pop_back();
                    l--;
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }

        }
        dq.clear();
    }
    return 0;
}
