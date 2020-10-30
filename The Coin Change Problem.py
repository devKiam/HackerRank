def rec(i, sum):
    if m.get((i, sum), "NONE") != "NONE":
        return m[(i, sum)]
    if sum == target:
        return 1
    if sum > target:
        return 0
    if i >= len(v):
        return 0

    m[(i, sum)] = rec(i, sum + v[i]) + rec(i + 1, sum)
    return m[(i, sum)]


target, n = map(int, input().split())
v = list(map(int, input().split()))
m = {}

print(f'{rec(0, 0)}')
