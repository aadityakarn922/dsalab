def input_graph():
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))

    with open("graph.txt", "w") as file:
        file.write(f"{vertices} {edges}\n")

        print("enter graph details:\n")

        for i in range(edges):
            print(f"Edge {i+1}")

            u = int(input("Enter first vertex: "))
            v = int(input("Enter second vertex: "))
            weight = int(input("Enter weight: "))

            file.write(f"{u} {v} {weight}\n")

    print("\ngraph saved successfully.")


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

    print("\nminimum spanning tree\n")

    print("edge\tweight")

    for u, v, weight in mst:
        print(f"{u} -- {v}\t{weight}")

    print("\nTotal Cost =", total_cost)


input_graph()

vertices, edge_list = read_graph()

kruskal(vertices, edge_list)