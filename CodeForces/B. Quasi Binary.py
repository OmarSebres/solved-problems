n = [int(ch) for ch in raw_input()]
k = max(n)

ls = [0] * k
for i in range(len(n)):
	for j in range(k):
		ls[j] *= 10
		if j < n[i]:
			ls[j] += 1

print k
print ' '.join(map(str, ls))
