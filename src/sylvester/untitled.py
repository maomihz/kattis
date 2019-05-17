from sys import stdin

def get(n, x, y):
    if n <= 1:
        return 1
    half = n / 2
    down = get(half, x % half, y % half)
    if x >= half and y >= half:
        return -down
    return down

input()
for line in stdin:
    n, y, x, w, h = map(int, line.strip().split())
    for i in range(h):
        print(' '.join(str(get(n, i+x, j+y)) for j in range(w)))
    print()