get = lambda: map(int, raw_input().split())
n, m = get()

x = [0] * n
c = [1, 2, 3]
for i in range(m):
    d = map(lambda x: x - 1, get())
    taken = set()
    [taken.add(x[v]) for v in d if x[v] != 0]
    for v in d:
        if x[v] == 0:
            for e in c:
                if not e in taken:
                    taken.add(e)
                    x[v] = e
                    break

print ' '.join(map(str, x))
