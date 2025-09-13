from sys import stdin


a,b = map(float, list(stdin.readline().split(' ')))

if(b == 0):
    print(0)

else:
    print(a/b)
