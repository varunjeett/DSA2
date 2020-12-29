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


//437. path sum 3

// At every point ,consider two ways, either a solution will come with considering the current node and without , for the without part 
// call recursively, for the with part find it by subtracting along the downward journey, 
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return 0;
        
        return find(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    
    int find(TreeNode* root,int csum) {
        if(root==nullptr)
            return 0;
        
        int total=0;
        if((csum-root->val)==0)
            total++;    //as it may happen that , there could be more redundant path downwards and we need to consider all of the paths.
        
        return total+find(root->left,csum-root->val)+find(root->right,csum-root->val);
    }
};



// 1376. Time Needed to Inform All Employees

//Consider a tree as graph , make graph using adjacency list, use recursion to 
// find the max time to inform all the subordinates of the head and add the inform time for the root
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& t) {
        vector<vector<int>> arr(n,vector<int>());
        for(int i=0;i<manager.size();i++) {
            if(manager[i]!=-1)          // i ka manager is manager[i]
            {
                arr[manager[i]].push_back(i);
            }
        }
        
        //Just to check the contents of the tree
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout<<i<<"->";
        //     for(int j=0;j<arr[i].size();j++)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }  
        
        return find(headID,arr,t);
    }
    
    
    int find(int n,vector<vector<int>>& arr,vector<int>& t)
    {
        if(arr[n].size()==0)
            return 0;
        
        int mx=-1e9;
        for(int i=0;i<arr[n].size();i++)
        {
            mx=max(mx,find(arr[n][i],arr,t));
        }
        return mx+t[n];
    }
};