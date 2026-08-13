def create_graph():
    with open("graph1.txt", "w") as file:
        vertices = int(input("enter the number of vertices: "))
        edges = int(input("enter the number of edges: "))

        file.write(f"{vertices} {edges}\n")
        print("enter the starting vertex,ending vertex and weight")

        for i in range(edges):
            u, v, weight = input().split()
            weight = int(weight)

            u = ord(u.upper()) - 65
            v = ord(v.upper()) - 65

            file.write(f"{u} {v} {weight}\n")

        print("\ngraph saved successfully.")


def read_graph():
    with open("graph1.txt", "r") as file:
        firstline = file.readline()

        vertices, edges = map(int, firstline.split())

        print("vertices", vertices)
        print("edges", edges)

        graph = [[] for j in range(vertices)]

        for i in range(edges):
            line = file.readline()

            u, v, weight = map(int, line.split())

            print(f"edge: {u} -> {v}, weight: {weight}")

            graph[u].append((v, weight))
            graph[v].append((u, weight))

        return vertices, graph


def min_key(key, visited, vertices):
    min_index = 0

    for i in range(vertices):
        if visited[i] == False:
            min_index = i
            break

    for j in range(vertices):
        if visited[j] == False and key[j] < key[min_index]:
            min_index = j

    return min_index


def prim(vertices, graph):

    key = [999] * vertices
    parent = [-1] * vertices
    visited = [False] * vertices

    key[0] = 0

    for i in range(vertices):

        u = min_key(key, visited, vertices)

        visited[u] = True

        for j in range(len(graph[u])):

            v = graph[u][j][0]
            weight = graph[u][j][1]

            if visited[v] == False and weight < key[v]:
                key[v] = weight
                parent[v] = u

    print("\nminimum spanning tree")

    total = 0

    for i in range(1, vertices):
        print(f"{chr(65 + parent[i])}--{chr(65 + i)}, weight={key[i]}")
        total += key[i]

    print(f"total minimum cost: {total}")


create_graph()

vertices, graph = read_graph()

prim(vertices, graph)