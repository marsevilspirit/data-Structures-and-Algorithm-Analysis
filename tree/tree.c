typedef struct TreeNode *PtrToNode;

struct TreeNode
{
    ElementType Element;
    PtrToNode   Firstchild;
    PtrToNode   NextSibling;
}
