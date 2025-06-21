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
};