import math
G={
    'P':{'M'},
    'M':{'P','Q','S','T'},
    'Q':{'M'},
    'S':{'M','A'},
    'T':{'M','A'},
    'A':{'S','T','Z'},
    'Z':{'A'}


}
def BFS(G,start):
    queue=[]
    visited=[]
    queue.append(start)
    while(queue):
        current=queue.pop(0)
        visited.append(current)
        for neighbor in G[current]:
            if neighbor not in visited and neighbor not in queue:
                queue.append(neighbor)
    print(visited)            

start='A'
BFS(G,start)