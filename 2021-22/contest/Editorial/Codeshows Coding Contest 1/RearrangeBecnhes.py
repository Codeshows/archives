Method 1:

def Rearrange(a,p,q):
    m=len(a)
    n=len(a[0])
    b=[[0]*q for _ in range(p)]
    x=0
    y=0
    for i in range(m):
        for j in range(n):
            b[x][y]=a[i][j]
            y=y+1
            if y==q:
                y=0
                x=x+1
    return b

m,n,p,q=map(int,input().split())
l=[]
for i in range(m):
    x=list(map(int,input().split()))
    l.append(x)
s=m*n
rearrange_size=p*q
if s!=rearrange_size:
    for i in range(m):
        print(*l[i])
else:
    b=Rearrange(l,p,q)
    for i in range(p):
        print(*b[i])

Method 2:


def Rearrange(a,p,q):
    m=len(a)
    n=len(a[0])
    b=[[0]*q for _ in range(p)]
    x=0
    y=0
    for i in range(m*n):
          b[i // q][i % q] = a[i // n][i % n];
    return b

m,n,p,q=map(int,input().split())
l=[]
for i in range(m):
    x=list(map(int,input().split()))
    l.append(x)
s=m*n
rearrange_size=p*q
if s!=rearrange_size:
    for i in range(m):
        print(*l[i])
else:
    b=Rearrange(l,p,q)
    for i in range(p):
        print(*b[i])



