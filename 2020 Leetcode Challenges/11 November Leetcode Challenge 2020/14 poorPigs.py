class Solution:
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        return ceil(log(buckets)/log(minutesToTest//minutesToDie + 1))
