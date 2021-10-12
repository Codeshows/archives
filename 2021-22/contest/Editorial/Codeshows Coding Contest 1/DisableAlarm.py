n,x,t=map(int,input().split())
l=list(map(int,input().split()))
i=0
j=0
ans=n+1
su=l[0]
while i<=j and j<n:
    if su>x:
        su=su-l[i]
        ans=min(ans,j-i+1)
        i=i+1
    else:
        j=j+1
        if j<n:
            su=su+l[i]
print(ans*t)                

