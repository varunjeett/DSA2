// itertative inorder traversal
// 94. Binary Tree Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return {};
        
        vector<int> ans;
        stack< pair<TreeNode*,int> > st;
        st.push({root,-2});
        
        while(st.size()!=0)
        {
            pair<TreeNode*, int> rvtx=st.top();
            st.pop();
            
            TreeNode* node=rvtx.first;
            int ch=rvtx.second;
            if(ch==-2)
            {
                st.push({node,-1});
                if(node->left!=nullptr)
                {
                    st.push({node->left,-2});
                }
            }
            else if(ch==-1)
            {
                st.push({node,0});
                ans.push_back(node->val);
            }
            
            else if(ch==0)
            {
                st.push({node,1});
                if(node->right!=nullptr)
                {
                    st.push({node->right,-2});
                }
            }
            
            else if(ch==1)
            {
                //do nothing
            }
        }
        
        return ans;
    }
};


//513. Find Bottom Left Tree Value

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int d=0;
        int l=0;
        int val=0;
        find(root,0,0,d,l,val);
        return val;
    }
    void find(TreeNode* root,int od,int ol,int &d,int &l,int& val) {
        if(root==nullptr) 
            return;
        
        find(root->left,od+1,ol-1,d,l,val);
        
        if(od > d) {
            val=root->val;
            d=od;
            l=ol;
        }
        
        if(od == d && ol <= l) {
            val=root->val;
            d=od;
            l=ol;
        }
        
        
        find(root->right,od+1,ol+1,d,l,val);
        
        return;
    } 
};


