import math

n = raw_input()
ns = sorted(int(_) ** 2 for _ in raw_input().split())

print math.pi * (sum(ns[::-2]) - sum(ns[-2::-2]))