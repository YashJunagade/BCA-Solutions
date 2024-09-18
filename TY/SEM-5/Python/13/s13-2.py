class Queue:
 def __init__(self):
  self.items = []

 def is_empty(self):
  return len(self.items) == 0

 def enqueue(self, item):
  self.items.append(item)

 def dequeue(self):
  if not self.is_empty():
   return self.items.pop(0)
  else:
   return "Queue is empty"

 def front(self):
  if not self.is_empty():
   return self.items[0]
  else:
   return "Queue is empty"

 def size(self):
  return len(self.items)

# Example usage
queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print("Queue:", queue.items)
print("Front item:", queue.front())
print("Dequeue:", queue.dequeue())
print("Queue after dequeue:", queue.items)
print("Queue size:", queue.size())
