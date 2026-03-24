class Solution(object):
    def constructProductMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n=len(grid)
        m=len(grid[0])
        ans = [[0] * m for _ in range(n)]
        prev=1
        N=12345
        for i in range(0,n):
            for j in range(0,m):
                ans[i][j]=prev
                prev=(prev*grid[i][j]%N)%N
        suf=1
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                ans[i][j]=(ans[i][j]*suf%N)%N
                suf=(suf*grid[i][j]%N)%N
        return ans