#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    //Ideally it will take by default assume T for children
    vector<TreeNode*> children;

    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        //When delete root is run than destructor is called 
        //Jb tk destructor khtm nhi hoga root delete nhi hoga 
        //So we got the best time to delete the children inside the destructor 
        //here we can delete the childrens here 
        for(int i = 0;i < children.size();i +=1){
            delete children[i];
        }
    }
};