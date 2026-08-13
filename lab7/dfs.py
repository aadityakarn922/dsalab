G={
    'P':['M'],
    'M':['P','Q','S','T'],
    'Q':['M'],
    'S':['M','A'],
    'T':['M','A'],
    'A':['S','T','Z'],
    'Z':['A']


}

visited =[]
def dfs(visited,G,root):
    if root not in visited:
        print(root)
        visited.append(root)
        for neighbour in G[root]:
            dfs(visited,G,neighbour)

dfs(visited,G,'P')
