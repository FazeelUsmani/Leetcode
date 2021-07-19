class Solution {
public:
    #define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64 
    #define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16) 
    #define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )   
    
    unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) }; 
    
    uint32_t reverseBits(uint32_t num) {
        
        
        int reverse_num = 0; 
  
        reverse_num = lookuptable[ num & 0xff ]<<24 |  

        // second chunk of 8 bits from  right  
        lookuptable[ (num >> 8) & 0xff ]<<16 |  

        lookuptable[ (num >> 16 )& 0xff ]<< 8 | 
        lookuptable[ (num >>24 ) & 0xff ] ; 

        return reverse_num;
    }
};
