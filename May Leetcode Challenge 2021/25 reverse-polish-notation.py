class Solution:
    def evalRPN(self, tokens):
        stack = []
        def f(a, b, c):
            if c == "+": return a+b
            if c == "-": return b-a
            if c == "*": return a*b
            if c == "/": return int(b/a)
            
        for token in tokens:
            if token in "*/+-":
                stack.append(f(stack.pop(), stack.pop(), token))
            else:
                stack.append(int(token))
        return stack[-1]
