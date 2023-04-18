namespace LowestCommonAncestorOfABinaryTree
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }

    public class Solution
    {
        public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
        {
            // root가 null이라면 null을 반환(base case)
            if (root is null)
                return null;

            // 이진트리에 대해 재귀로 접근
            TreeNode left = LowestCommonAncestor(root.left, p, q);
            TreeNode right = LowestCommonAncestor(root.right, p, q);

            // 만약 root가 p거나 q라면 root 반환 -> 중복 조상 노드
            if ((root == p) || (root == q))
                return root;
            // 양쪽 노드가 null이 아니라면 root 반환 -> 중복 조상 노드
            else if (left != null && right != null)
                return root;
            // 한쪽이 null일 경우 null이 아닌 값 반환.
            return (left ?? right);
        }
    }
}
