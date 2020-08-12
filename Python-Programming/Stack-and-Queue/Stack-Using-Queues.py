class stack_using_queues:
    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, data):
        self.queue1.append(data)

    def isEmpty(self):
        return len(self.queue1) + len(self.queue2) == 0

    def pop(self):
        if self.isEmpty():
            raise Exception("Stack is empty")

        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())

        value = self.queue1.popleft()
        self.swap_queues()
        return value

    def swap_queues(self):
        self.queue3 = self.queue1
        self.queue1 = self.queue2
        self.queue2 = self.queue3
