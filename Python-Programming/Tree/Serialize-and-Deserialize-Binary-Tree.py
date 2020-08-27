import sys
import pickle

MARKER = sys.maxsize

def serialize(node, stream):
    if node == None:
        stream.dump(MARKER)
        return
    stream.dump(node.data)
    serialize(node.left, stream)
    serialize(node.right, stream)

def deserialize(stream):
    try:
        data = pickle.load(stream)
        if data == MARKER:
            return None

        node = BinaryTreeNode(data)
        node.left = deserialize(stream)
        node.right = deserialize(stream)

        return node

    except pickle.UnpicklingError:
        return None
