# The illustrated graph is represented using an adjacency list.
graph = {
  'A' : ['B','C'],
  'B' : ['D', 'E'],
  'C' : ['F'],
  'D' : [],
  'E' : ['F'],
  'F' : []
}

visited = [] # a list that is used to keep track of visited nodes.
queue = [] # a list that is used to keep track of nodes currently in the queue.

def bfs(visited, graph, node):
    # checks and appends the starting node to the visited list and the queue
    visited.append(node)
    queue.append(node)

    # This continues until the queue is empty.
    while queue:
        # Take out nodes fromt the queue
        s = queue.pop(0)
        print (s, end = " ")

        # Append the neighbors of that node to the queue if they are unvisited
        # Mark them as visited
        for neighbour in graph[s]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

# Driver Code
bfs(visited, graph, 'A')
