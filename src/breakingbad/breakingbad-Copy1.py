from collections import deque

def main():
    n = int(input())
    words = {input() for _ in range(n)}
    
    m = int(input())
    group = {}
    
    for _ in range(m):
        x, y = input().split()
        if (x in group and y in group and group[x] == group[y]):
            print('impossible')
            return
        if x in group:
            group[y] = not group[x]
        elif y in group:
            group[x] = not group[y]
        else:
            group[x] = True
            group[y] = False
    
    group_a = {k for k in group if group[k]}
    group_b = words - group_a
    
    print(*group_a)
    print(*group_b)

if __name__ == '__main__':
    main()