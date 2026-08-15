def input_graph():
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))

    with open("graph.txt", "w") as file:
        file.write(f"{vertices} {edges}\n")

        print("\nEnter graph details:\n")

        for i in range(edges):
            print(f"Edge {i + 1}")

            u = input("Enter first vertex: ").upper()
            v = input("Enter second vertex: ").upper()
            weight = int(input("Enter weight: "))

            # Convert alphabet to number
            u = ord(u) - ord('A')
            v = ord(v) - ord('A')

            file.write(f"{u} {v} {weight}\n")

    print("\nGraph saved successfully.")


def read_graph():

    with open("graph.txt", "r") as file:

        vertices, edges = map(int, file.readline().split())

        edge_list = []

        for line in file:
            u, v, weight = map(int, line.split())
            edge_list.append((u, v, weight))

    return vertices, edge_list


def make_set(vertices):

    parent = []

    for i in range(vertices):
        parent.append(i)

    return parent


def find(parent, vertex):

    if parent[vertex] != vertex:
        parent[vertex] = find(parent, parent[vertex])

    return parent[vertex]


def union(parent, u, v):

    root_u = find(parent, u)
    root_v = find(parent, v)

    parent[root_v] = root_u


def kruskal(vertices, edge_list):

    edge_list.sort(key=lambda x: x[2])

    parent = make_set(vertices)

    mst = []
    total_cost = 0

    for u, v, weight in edge_list:

        if find(parent, u) != find(parent, v):

            mst.append((u, v, weight))
            total_cost += weight

            union(parent, u, v)

    print("\nMinimum Spanning Tree\n")

    print("Edge\tWeight")

    for u, v, weight in mst:

        # Convert number back to alphabet
        u = chr(u + ord('A'))
        v = chr(v + ord('A'))

        print(f"{u} -- {v}\t{weight}")

    print("\nTotal Cost =", total_cost)


input_graph()

vertices, edge_list = read_graph()

kruskal(vertices, edge_list)