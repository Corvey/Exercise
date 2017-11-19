void DFS(int from)
{
    int to, children = 0;
    low[from] = dfn[from] = ++counter;  //记录DFS次序
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
            if(!~dad[from] && children > 1) //割点1
                gd[from] = true;
            if(~dad[from] && low[to] >= dfn[from])  //割点2
                gd[from] = true;
            if(low[to] > dfn[from]) //割边
                gb[ngb++] = x;
        }
        else if(to != dad[from])    //回边
            low[from] = MIN(low[from], dfn[to]);
    }
}