def bfs(start, adjList):
    queue = []
    queue.append(start)
    distance[start-1] = 0

    while queue:  # queue not equals to empty
        u = queue.pop(0)

        for i in range(len(adjList[u-1])):

            v = adjList[u-1][i]

            if distance[v-1] == -1:
                queue.append(v)
                parent[v-1] = u
                distance[v-1] = distance[u-1] + 6


# driver code / Global code

t = int(input())

for tc in range(t):
    nodes, edges = map(int, input().split())

    parent = [-1 for _ in range(nodes)]
    distance = [-1 for _ in range(nodes)]

    adjList = [[] for _ in range(nodes)]

    for i in range(edges):
        a, b = map(int, input().split())
        adjList[a-1].append(b)
        adjList[b-1].append(a)

    start = int(input())

    bfs(start, adjList)

    for i in range(nodes):
        if distance[i] == 0:
            continue
        print(f'{distance[i]}', end=" ")
    print("")
