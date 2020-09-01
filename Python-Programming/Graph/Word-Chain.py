class vertex:
    def __init__(self, value, visited):
        self.value = value
        self.visited = visited
        self.adj_vertices = []
        self.in_vertices = []

class graph:
    g = []

    def __init__(self, g):
        self.g = g

    def create_graph(self, words_list):
        for i in range(len(words_list)):
            word = words_list[i]
            start_char = word[0]
            end_char = word[len(word) - 1]

            start = self.vertex_exists(start_char)
            if start == None:
                start = vertex(start_char, False)
                self.g.append(start)

            end = self.vertex_exists(end_char)
            if end == None:
                end = vertex(end_char, False)
                self.g.append(end)

            self.add_edge(start, end)

    def vertex_exists(self, value):
        for i in range(len(self.g)):
            if self.g[i].value == value:
                return self.g[i]
        return None

    def all_visited(self):
        for i in range(len(self.g)):
            if self.g[i].visited == False:
                return False
        return True

    def add_edge(self, start, end):
        start.adj_vertices.append(end)
        end.in_vertices.append(start)

    def out_equals_in(self):
        for i in range(len(self.g)):
            out = len(self.g[i].adj_vertices)
            inn = len(self.g[i].in_vertices)
            if out != inn:
                return False
        return True

    def check_cycle_rec(self, node, starting_node):
        node.visited = True
        adj = node.adj_vertices

        if self.all_visited():
            for i in range(len(adj)):
                if adj[i] == starting_node:
                    return True

        for i in range(len(adj)):
            if adj[i].visited == False:
                node = adj[i]
                if self.check_cycle_rec(node, starting_node):
                    return True

        return False

    def check_cycle(self, list_size):
        if list_size < 2: return False
        if len(self.g) > 0:
            if self.out_equals_in():
                return self.check_cycle_rec(self.g[0], self.g[0])
        return False
