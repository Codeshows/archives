import fractions
def f(x):
    l,r = max(0, int(x ** 0.5 - 10)), int(x ** 0.5 + 10)
    while r-l != 1:
        t = (l+r) // 2
        if t * t <= x:
            l = t
        else:
            r = t
    return l
x,y,r = map(lambda x:int(fractions.Fraction(x) * 10000), input().split())
r = r ** 2
cnt = 0
for i in range(-200000, 200001):
    try:
        t = f(r - (x - i * 10000) ** 2)
        cnt += (y+t) // 10000
        #print(i, t, cnt)
        cnt -= (y-t-1) // 10000
        #print(i, t, cnt)
    except TypeError:
        pass

print(cnt)