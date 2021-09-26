#include "tree_node.h"
#include <iostream>
#include <queue>
#include <list>
#include <random>
#include <sstream>
using namespace std;
void levelOrderTraversal(TreeNode *root)
{
    std::queue<TreeNode*> q;
    if(root != nullptr)
    {
        q.push(root);
    }
    while(q.empty() == false)
    {
        std::cout << q.front()->data << " -> ";
        if(q.front()->left != nullptr)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right != nullptr)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
}
/*
digraph G {
    nodesep=0.3;
    ranksep=0.2;
    margin=0.1;
    node [shape=circle];
    edge [arrowsize=0.8];
    6 -> 4;
    6 -> 11;
    4 -> 2;
    4 -> 5;
    2 -> 1;
    2 -> 3;
    11 -> 8;
    11 -> 14;
    8 -> 7;
    8 -> 10;
    10 -> 30[style=invis];
    10 -> 9;
    30[style=invis];
    14 -> 13;
    14 -> 16;
    13 -> 12;
    16 -> 15;
    16 -> 17;
*/
std::string levelOrderPrintToDot(TreeNode *root)
{
    stringstream ss;
    ss << "digraph G {" << endl;
    ss << "    nodesep=0.3;" << endl ;
    ss << "    ranksep=0.2;" << endl;
    ss << "    margin=0.1;" << endl;
    ss << "    node [shape=circle];" << endl ;
    ss << "    edge [arrowsize=0.8];" << endl;
    ss << endl;
    std::queue<TreeNode*> q;
    if(root != nullptr)
    {
        q.push(root);
    }
    std::default_random_engine e;
    while(q.empty() == false)
    {
        //cout << q.front()->data << " -> ";
        TreeNode *node = q.front();
        int child_dat = 0;
        string child_str;
        if(node->left != nullptr)
        {
            child_dat =  node->left->data;
            //child_str = "    "    +  "  ->  ";
            ss << "    " <<  node->data  << "  ->  " <<  child_dat <<endl;
        }
        else //add an invisable node
        {
            child_dat = e()%1000+200;
            ss << "    " <<  node->data  << "  ->  " <<  child_dat  << " [style=invis]"<<endl;
            ss << "    " << child_dat <<  " [style=invis]"<< endl;
        }
        if(node->right != nullptr)
        {
            child_dat =  node->right->data;
            //child_str = "    "    +  "  ->  ";
            ss << "    " <<  node->data  << "  ->  " <<  child_dat <<endl;
        }
        else //add an invisable node
        {
            child_dat = e()%1000+200;
            ss << "    " <<  node->data  << "  ->  " <<  child_dat  << " [style=invis]"<<endl;
            ss << "    " << child_dat <<  " [style=invis]"<< endl;
        }

        if(q.front()->left != nullptr)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right != nullptr)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
    ss << "}" << endl;
    return ss.str();
 }