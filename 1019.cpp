#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dis[110];
vector<pair<int, int> >v[110];
void dijkstra(int src, int d)
{
    int i;
    bool vis[110]={0};
    set< pair<int, int> >s;
    set< pair<int, int> >:: iterator it;
    vector<pair<int, int> >:: iterator vt;
    for(i=1; i<=d; i++) dis[i]=INT_MAX;
    dis[src]=0;
    s.insert(make_pair(0, src));
    while(s.size())
    {
        it = s.begin();
        s.erase(it);
        int n = it->second;
        vis[n]=1;
        for(vt= v[n].begin(); vt!=v[n].end(); vt++)
        {
            if(dis[vt->first]>dis[n]+vt->second && vis[vt->first]==0)
            {
                if(dis[vt->first]!=INT_MAX)
                {
                    s.erase(s.find(make_pair(dis[vt->first], vt->first)));
                }

                dis[vt->first]= dis[n]+vt->second;
                s.insert(make_pair(dis[vt->first], vt->first));
            }
        }

    }
}
int main()
{
    int t, n, d, e, a, b, c,kase=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(v, 0, sizeof(v));
        scanf("%d %d", &n, &e);
        while(e--)
        {
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back(make_pair(b, c));
            v[b].push_back(make_pair(a, c));
        }
        dijkstra(1, n);

        printf("Case %d: ",kase++ );
        if(dis[n]!=INT_MAX)
        {
            printf("%d\n", dis[n]);
        }
        else printf("Impossible\n");
    }
}

