/*
Credits: _aaRPee_

For the number to be divisible by 4,

it should be positive (checked by "num > 0")
it should have a single set bit (checked by " ! (num & (num - 1))")
it's set bit should be at an odd position (checked by "(num & 0x55555555)")

P.S: 0x55555555 is a 32 bit integer with all the odd bits set to 1, whereas 0xAAAAAAAA is a 32 bit integer with all the even bits set to 1.

*/


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 and !(num & (num - 1)) and (num & 0x55555555);
    }
};
