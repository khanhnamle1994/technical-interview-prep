class vertex:
    def __init__(self, id, visited):
        self.id = id
        self.visited = visited

class edge:
    def __init__(self, weight, visited, src, dest):
        self.weight = weight
        self.visited = visited
        self.src = src
        self.dest = dest

class graph:
    g = []  # vertices
    e = []  # edges

    def __init__(self, g, e):
        self.g = g
        self.e = e

    def vertex_exists(self, id):
        for i in range(len(self.g)):
            if self.g[i].id == id:
                return self.g[i]
        return None

    def generate_graph(self, vertices, edges):
        for i in range(vertices):
            v = vertex(i + 1, False)
            self.g.append(v)

        for i in range(len(edges)):
            src = self.vertex_exists(edges[i][1])
            dest = self.vertex_exists(edges[i][2])
            e = edge(edges[i][0], False, src, dest)
            self.e.append(e)

    def find_min_spanning_tree(self):
        vertex_count = 0
        weight = 0
        current = self.g[0]
        current.visited = True
        vertex_count += 1

        while vertex_count < len(self.g):
            smallest = None
            for i in range(len(self.e)):
                if self.e[i].visited == False and self.e[i].dest.visited == False:
                    smallest = self.e[i]
                    break

            for i in range(len(self.e)):
                if self.e[i].visited == False:
                    if self.e[i].src.visited == True and self.e[i].dest.visited == False:
                        if smallest == None or self.e[i].weight < smallest.weight:
                            smallest = self.e[i]

            smallest.visited = True
            smallest.dest.visited = True
            weight += smallest.weight
            vertex_count += 1

        return weight
