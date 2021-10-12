# by the authority of GOD     author: manhar singh sachdev #

import os,sys


def main():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        arr = [list(map(int,input().split())) for _ in range(n)]
        ans = 0
        for i in range(n//2):
            for j in range(m//2):
                x,y,z,w = arr[i][j],arr[i][-j-1],arr[-i-1][j],arr[-1-i][-j-1]
                a = sorted([x,y,z,w])[1]
                ans += abs(x-a)+abs(y-a)+abs(z-a)+abs(w-a)
        if n%2:
            for i in range(m//2):
                ans += abs(arr[n//2][i]-arr[n//2][-1-i])
        if m%2:
            for i in range(n//2):
                ans += abs(arr[i][m//2]-arr[-1-i][m//2])
        print(ans)



if __name__ == '__main__':
    main()