class Node:
    def __init__(self, d):
        self.data = d
        self.neighbors = []

def clone_rec(root, nodes_completed):
    if root == None: return None

    pNew = Node(root.data)
    nodes_completed[root] = pNew

    for p in root.neighbors:
        x = nodes_completed.get(p)
        if x == None:
            pNew.neighbors += [clone_rec(p, nodes_completed)]
        else:
            pNew.neighbors += [x]
    return pNew

def clone(root):
    nodes_completed = {}
    return clone_rec(root, nodes_completed)
