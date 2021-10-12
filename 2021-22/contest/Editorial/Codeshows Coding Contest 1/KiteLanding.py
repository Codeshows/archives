for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.reverse()
    ans,j=[],0
    for i in range(n+1):
        while j<n and a[j]<=i-j-1:
            j+=1
        ans.append(n+1-j)
    print(*ans)
    