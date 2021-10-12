from bisect import bisect_left
from bisect import bisect_right

n=int(input())
L=[]
R=[]
v=[]
for i in range(n):
    a,b=map(int,input().split())
    L.append(a)
    R.append(b)
    v.append([a,b])
L.sort()
R.sort()
ans=n-1
for i in v:
    l=i[0]
    r=i[1]
    left=bisect_left(R,l)
    right=n-bisect_right(L,r)
    ans=min(ans,left+right)
print(ans)