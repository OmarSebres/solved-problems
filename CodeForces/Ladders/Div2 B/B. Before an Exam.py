d, t = map(int, raw_input().split())

mn = []
mx = []
for _ in range(d):
    m, n = map(int, raw_input().split())
    mn += [m]
    mx += [n]

total = sum(mn)
need = t - total

if need < 0:
    print "NO"
else:
    for i in range(d):
        delta = min(need, mx[i] - mn[i])
        mn[i] += delta
        need -= delta

    if need != 0:
        print "NO"
    else:
        print "YES"
        print " ".join([str(_) for _ in mn])