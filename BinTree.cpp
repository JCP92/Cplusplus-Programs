//
//  main.cpp
//  BinTree
//
//  Created by Joshua Peckham on 12/8/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//

#include <iostream>
using namespace std;

template<class T>
class BinTree{
private:
    struct TreeNode{
        TreeNode *left;
        TreeNode *right;
        T variable;
    };
    TreeNode *TreePntr;
    void makeDeletion(TreeNode *&pntr);//done-------------------------
    void deleteNode(T item, TreeNode *&pntr);//-----------------------
    void insertLeaf(TreeNode *&leafNode, TreeNode *&pntr); //done-------
    void deleteSubTree(TreeNode *&pntr);// done
    void inOrder(TreeNode *pntr)const;// done
    void preOrder(TreeNode *pntr)const;
    void postOrder(TreeNode *pntr)const;
    bool search(T item, TreeNode *pntr);
public:
    BinTree(){ TreePntr = nullptr; }//done
    ~BinTree(){ deleteSubTree(TreePntr); }
    bool search(T item)const{ return search(item, TreePntr); }
    void deleteNode(T item){ deleteNode (item, TreePntr); }
    void insertLeaf(T item);//done
    void inOrder()const { inOrder(TreePntr); }
    void preOrder()const { preOrder(TreePntr); }
    void postOrder()const { postOrder(TreePntr); }
    
};
//__________________________________________________________
int main() {
    BinTree<int> m;
    m.insertLeaf(0);
    m.insertLeaf(10);
    m.insertLeaf(5);
    m.insertLeaf(20);
    m.insertLeaf(15);
    m.insertLeaf(30);
    m.insertLeaf(25);
    m.insertLeaf(-1);
    m.insertLeaf(-2);
    m.insertLeaf(-7);
    m.insertLeaf(-6);
    m.insertLeaf(-3);
    m.insertLeaf(-4);
    m.insertLeaf(-5);
    m.inOrder();
    cout << endl;
    m.preOrder();
    cout << endl;
    m.postOrder();
    cout << endl;
    m.deleteNode(10);
    m.inOrder();
    cout << endl << "Deleted: 10" << endl;
    m.deleteNode(-5);
    m.inOrder();
    cout << endl << "Deleted: -5" << endl;    cout << endl;
    m.deleteNode(2);
    m.inOrder();
    cout << endl << "Deleted: 2" << endl;
    m.deleteNode(0);
    m.inOrder();
    cout << endl << "Deleted: 0" << endl;
    m.deleteNode(-1);
    m.inOrder();
    cout << endl << "Deleted: -1" << endl;

    return 0;
}
//__________________________________________________________
template<class T>
void BinTree<T>::deleteSubTree(TreeNode *&pntr){
    if(pntr){
        if(pntr->left) // navigate through tree to end delete from bottom to top left side
            deleteSubTree(pntr->left);
        if(pntr->right) //navigate through tree to end delete from bottom to top right side
            deleteSubTree(pntr->right);
        delete pntr;
    }
}
template<class T>
void BinTree<T>::insertLeaf(T item){
    TreeNode *newLeaf = new TreeNode;
    newLeaf->right = newLeaf->left = nullptr;
    newLeaf->variable = item;
    insertLeaf(newLeaf, TreePntr);
}
template<class T>
void BinTree<T>::insertLeaf(TreeNode *&leaf, TreeNode *&pntr){
    if(pntr == nullptr) // replace pointer with leaf
        pntr = leaf;
    else if(leaf->variable < pntr->variable)// leaf value is lower so continue going to the left
        insertLeaf(leaf, pntr->left);
    else
        insertLeaf(leaf, pntr->right);//leaf value greater so go to right
}
template<class T>
void BinTree<T>::deleteNode(T item, TreeNode *&pntr){
    if(pntr){
    if(item < pntr->variable)
        deleteNode(item, pntr->left);
    else if(item > pntr->variable)
        deleteNode(item, pntr->right);
    else
        makeDeletion(pntr);
    }
}
template<class T>
void BinTree<T>::makeDeletion(TreeNode *&pntr){
    if(pntr){
        TreeNode *Temp = nullptr;
        if(pntr->left == nullptr){
            Temp = pntr;// store value to be deleted
            pntr = pntr->right; // override pntr with pntr's right child
            delete Temp;
        }
        else if(pntr->right == nullptr){
            Temp = pntr;
            pntr = pntr->left;
            delete Temp;
        }
        else{
            Temp = pntr->right; //storeTemp right node to promote
            while(Temp->left) // find child nodes end left branch
                Temp = Temp->left;
            Temp->left = pntr->left; // connects tbdeleted nodes left node to bottom tbds right node
            Temp = pntr; //temp = node to be deleted
            pntr = pntr->right; //overrides ptrwith right child
            delete Temp;// deletes temp
        }
    }
}
template<class T>
void BinTree<T>::inOrder(TreeNode *pntr)const{
    if(pntr){
        inOrder(pntr->left);
        cout << pntr->variable << " ";
        inOrder(pntr->right);
    }
}
template<class T>
void BinTree<T>::preOrder(TreeNode *pntr)const{
    if(pntr){
        cout << pntr->variable << " ";
        preOrder(pntr->left);
        preOrder(pntr->right);
    }
}
template<class T>
void BinTree<T>::postOrder(TreeNode *pntr)const{
    if(pntr){
        postOrder(pntr->left);
        postOrder(pntr->right);
        cout << pntr->variable << " ";
    }
}
template<class T>
bool BinTree<T>::search(T item, TreeNode *pntr){
    if(pntr){
    if(pntr->variable == item)
        return true;
    else if(item < pntr->variable)
        search(item, pntr->left);
    else if(item > pntr->variable)
        search(item, pntr->right);
    else
        return false;
    }
}



























































