# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    ans=0
    def solve(self,root,maxi,mini):
        if not root:
            return
        maxi=max(maxi,root.val)
        mini=min(mini,root.val)
        if(root.left):
            self.solve(root.left,maxi,mini)
        if(root.right):
            self.solve(root.right,maxi,mini)
        self.ans=max(self.ans,maxi-mini)
    def maxAncestorDiff(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        self.solve(root,0,100000)
        return self.ans
        