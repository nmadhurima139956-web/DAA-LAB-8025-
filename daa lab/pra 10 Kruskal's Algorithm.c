# Kruskal's Algorithm

def kruskal(vertices, edges):
    parent = {v: v for v in vertices}

    def find(v):
        if parent[v] != v:
            parent[v] = find(parent[v])
        return parent[v]

    def union(u, v):
        parent[find(u)] = find(v)

    edges.sort(key=lambda x: x[2])
    total_cost = 0

    print("Minimum Spanning Tree:")

    for u, v, weight in edges:
        if find(u) != find(v):
            union(u, v)
            print(u, "-", v, ":", weight)
            total_cost += weight

    print("Total cost:", total_cost)


vertices = ['A', 'B', 'C', 'D']

edges = [
    ('A', 'B', 2),
    ('A', 'C', 3),
    ('B', 'C', 1),
    ('B', 'D', 4),
    ('C', 'D', 5)
]

kruskal(vertices, edges)
