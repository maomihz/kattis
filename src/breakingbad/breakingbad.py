from collections import deque

def main():
    n = int(input())
    words = {input(): set() for _ in range(n)}
    
    m = int(input())
    for _ in range(m):
        a, b = input().split()
        words[a].add(b)
        words[b].add(a)

    colors = {}
    q = deque()
    
    for start in words.keys():
        if start in colors:
            continue
        
        q.append((start, True))
        
        while q:
            curr, color = q.pop()
            if curr in colors and colors[curr] != color:
                print('impossible')
                return
            colors[curr] = color
            for o in words[curr]:
                if o not in colors:
                    q.append((o, not color))
    
    print(*(k for k in colors if colors[k]))
    print(*(k for k in colors if not colors[k]))


if __name__ == '__main__':
    main()