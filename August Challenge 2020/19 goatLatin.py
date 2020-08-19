class Solution:
    def toGoatLatin(self, s: str) -> str:
        
        s = s.split()
        
        vowel = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'}

        res = []
        cnt = 1
        for i in s:
            if i[0] in vowel:
                txt = i+"ma"+ "a"*cnt

            else:
                txt = i[1:] + i[0] + "ma" + "a"*cnt

            cnt += 1
            res.append(txt)

        return " ".join(res)
        
