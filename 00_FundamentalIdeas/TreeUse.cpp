#include <iostream>
#include <queue>
using namespace std;
#include "TreeNode.h"

// Function is little complicated to give input
// Because User requires Recursion Knowledge to give Input
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter num of children of " << rootData << " ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
// Take input LevelWise
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter num of children of " << frontNode->data << " ";
        cin >> numChild;
        for (int i = 0; i < numChild; i += 1)
        {
            int childData;
            cout << "Enter " << i << "th child of " << frontNode->data << " ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            frontNode->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
// Print LevelWise
void printLevelWise(TreeNode<int> *root)
{
    // edge case
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *frontNode = pendingNodes.front();
        cout << frontNode->data << " : ";
        pendingNodes.pop();
        for (int i = 0; i < frontNode->children.size(); i += 1)
        {
            cout << frontNode->children[i]->data << " , ";
            pendingNodes.push(frontNode->children[i]);
        }
        cout << endl;
    }
}

void printTree(TreeNode<int> *root)
{
    // edge case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
// Count Nodes in a Tree
int numNodes(TreeNode<int> *root)
{
    if(root == NULL) return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}
//Height of Tree 
int heightTree(TreeNode<int>* root){
    //base case 
    if(root == NULL){
        return 0;
    }
    int maxChildHeight = 0;
    for(int i = 0;i<root->children.size();i++){
        maxChildHeight = max(maxChildHeight,heightTree(root->children[i]));
    }
    return maxChildHeight + 1;
}
//Depth Of a Node defined is how far it is from a Root 
//Print All Nodes at depth 'd' 
void printAtLevelK(TreeNode<int> * root,int k){
    //Edge Case 
    if(root == NULL){
        return ;
    }
    if(k == 1){
        cout<<root->data<<endl;
    }
    for(int i = 0;i < root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}
//Count Leaf Nodes 
int countLeafNodes(TreeNode<int> * root){
    //edge case 
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0;i < root->children.size();i++){
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}
//There are few Ways to Traverse a Tree 
//PreOrder PostOrder in Generic Tree 
void preOrder(TreeNode<int> * root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    for(int i = 0;i < root->children.size();i +=1){
        preOrder(root->children[i]);
    }
}
//PostOrder Traversal 
void postOrder(TreeNode<int> * root){
    if(root == NULL) return ;
    for(int i = 0;i < root->children.size();i +=1){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
//So 1 think I have realise is If we want to delete any Node than we have to delete its children first 
// Because if we simply delete root than vector having TreeNode* of child . this vector will be deleted 
//And We lost the way to access the childrens
//Perfect Example of Post Order Traversal 
void deleteTree(TreeNode<int> * root){
    for(int i = 0;i < root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << numNodes(root) << endl;
    cout<<heightTree(root)<<endl;
    printAtLevelK(root,2);
    cout<<countLeafNodes(root)<<endl;
    // TODO Delete a Tree
    delete root; //Doing this destructor is called
    return 0;
}