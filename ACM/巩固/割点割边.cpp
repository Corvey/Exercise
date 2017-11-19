void DFS(int from)
{
    int to, children = 0;
    low[from] = dfn[from] = ++counter;  //��¼DFS����
    vis[from] = true;
    for(int x=first[from]; ~x; x=Next[x])
    {
        to = v[x];
        if(!vis[to])
        {
            ++children;
            dad[to] = from;
            DFS(to);
            low[from] = MIN(low[from], low[to]);
            if(!~dad[from] && children > 1) //���1
                gd[from] = true;
            if(~dad[from] && low[to] >= dfn[from])  //���2
                gd[from] = true;
            if(low[to] > dfn[from]) //���
                gb[ngb++] = x;
        }
        else if(to != dad[from])    //�ر�
            low[from] = MIN(low[from], dfn[to]);
    }
}