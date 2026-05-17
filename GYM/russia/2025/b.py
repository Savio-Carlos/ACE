import sys

def check(t):
    if t == 0:
        return 0
    full = t // 5
    rem = t % 5

    s = 50 * full * (full - 1) + 70 * full

    k = full
    levels = [2*k, 2*k, 2*k, 2*k+1, 2*k+1]
    for j in range(rem):
        s += 10 * (levels[j] + 1)
    return s

def solve():
    x = int(input().strip())
    if x == 0:
        print(0, 0)
        return

    l, r = 1, 1
    while check(r) < x:
        r *= 2
    while l < r:
        mid = (l + r) // 2
        if check(mid) >= x:
            r = mid
        else:
            l = mid + 1
    t = l
    total = check(t)

    level = (2 * t) // 5
    print(level, total)

solve()