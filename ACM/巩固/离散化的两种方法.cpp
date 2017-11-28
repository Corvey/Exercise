1. 三倍内存
for(int i=0; i<n; ++i)
{
    scanf("%d", a+i);
    pos[i] = i;
}
sort(pos, pos+n, cmp);
b[pos[0]] = 1;
for(int i=1, num=1; i<n; ++i)
    b[pos[i]] = a[pos[i]] == a[pos[i-1]] ? b[pos[i-1]] : ++num;

2. 两倍内存
for(int i=0; i<n; ++i)
    scanf("%d", a+i);
memcpy(b, a, sizeof(b));
sort(b, b+n);
int SIZE = unique(b, b+n) - b;
for(int i=0; i<n; ++i)
    a[i] = lower_bound(b, b+SIZE, a[i]) - b + 1;