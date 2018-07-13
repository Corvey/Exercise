bool Find(int from)
{
    for(int x=first[from]; ~x; x=Next[x])
    {
        if(!vis[v[x]])
        {
            vis[v[x]] = true;
            if(match[v[x]] == -1 || Find(match[v[x]]))
            {
                match[from] = v[x];
                match[v[x]] = from;
                return true;
            }
        }
    }
    return false;
}
memset(match, -1, sizeof(match));
ans = 0;
for(int i=0; i<n; ++i)
{
	memset(vis, 0, sizeof(vis));
	if(match[i] == -1)
		ans += Find(i);
}
