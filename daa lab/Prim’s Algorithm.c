import heapq

def prim(graph, start):
    visited = set()
    min_heap = [(0, start, None)]
    total_cost = 0

    while min_heap:
        weight, node, parent = heapq.heappop(min_heap)

        if node in visited:
            continue

        visited.add(node)

        if parent is not None:
            print(parent, "-", node, ":", weight)
            total_cost += weight

        for neighbour, cost in graph[node]:
            if neighbour not in visited:
                heapq.heappush(
                    min_heap, (cost, neighbour, node)
                )

    print("Total cost:", total_cost)


graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('A', 2), ('C', 1), ('D', 4)],
    'C': [('A', 3), ('B', 1), ('D', 5)],
    'D': [('B', 4), ('C', 5)]
}

print("Minimum Spanning Tree:")
prim(graph, 'A')
