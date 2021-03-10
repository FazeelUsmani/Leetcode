class Solution:
    def intToRoman(self, num: int) -> str:        
        def digit(a,b,c,dig):
            return ["",a,2*a,3*a,a+b,b,b+a,b+2*a,b+3*a,a+c][dig]
        
        l = ["I","V","X","L","C","D","M","!","!"]
        out, i = "", 0

        while num != 0:
            num, last = divmod(num, 10)
            out = digit(l[i], l[i+1], l[i+2], last) + out
            i += 2
        return out
