import math
G={
    'A':{'B':3,'C':1},
    'B':{'A':3,'C':7,'D':5,'E':1},
    'C':{'A':1,'B':7,'D':2},
    'D':{'B':5,'C':2,'E':7},
    'E':{'B':5,'D':7},

}
def initialize(G,start):
    cost={}
    prev={}
    for vertex in G.keys():
        cost[vertex]=math.inf
        prev[vertex]=None
    cost[start]=0
    return cost,prev
    
def relax(u,v,G,cost,prev):
    if cost[v]>cost[u]+G[u][v]:
        cost[v]=cost[u]+G[u][v]
        prev[v]=u
    return cost,prev

def DJ(G,start):
    cost,prev=initialize(G,start)
    PQ={}
    visited=set()
    for vertex in G.keys():
        PQ[vertex]=cost[vertex]
    while(PQ):
        current=min(PQ,key=PQ.get)
        visited.add(current)
        del PQ[current]
        for neighbor in G[current].keys():
            if neighbor not in visited:
                old_cost=cost[neighbor]
                cost,prev=relax(current,neighbor,G,cost,prev)
                if cost[neighbor]<old_cost:
                    PQ[neighbor]=cost[neighbor]

        # print(f"current vertex={current}") 
        # print(cost)
        # print(prev)
    return cost,prev    

def construct_path(node1,node2,prev):
    path=[node2]
    while(prev[node1]!=None):
        path.append(prev[node2])
        node2=prev[node2]
    path.reverse()
    return '->'.join(path)
    

start='A'
cost,prev=DJ(G,start)
for vertex in G.keys():
    print(f"shortest path from {start} to {vertex} is {construct_path(start,vertex,prev)} cost={cost[vertex]}")


