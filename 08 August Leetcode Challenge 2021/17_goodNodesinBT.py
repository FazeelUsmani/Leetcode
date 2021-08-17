class Solution:
    def __init__(self):
        self.count = 0

    def goodNodes(self, root):
        for child in filter(None, [root.left, root.right]):
            self.count += child.val >= root.val
            child.val = max(child.val, root.val)
            self.goodNodes(child)
  
        return self.count + 1
