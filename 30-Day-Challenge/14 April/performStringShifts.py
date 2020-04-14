
def left(A, k):
  xt = A[k:] + A[:k]
  return ''.join([str(ele) for ele in xt])

def right(A, k):
  xt = A[-k:] + A[:-k]
  return ''.join([str(ele) for ele in xt])

class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        
        for i in shift:
            if i[0] == 0:
                s = left(s, i[1])
            else:
                s = right(s, i[1])
                
        return s;
