// preorder iterative traversal tree bst
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left = NULL;
    struct Node* right = NULL;
};

Node* creatNode(int data){
    Node* temp = new Node();
    temp->data = data;
    return temp;
}

Node* insertBST(Node* Root,int data){
    if(Root == NULL){
        Root = creatNode(data);
        return Root;
    }

    Node* temp = Root;
    while(1){
        if(data <= temp->data){
            if(temp->left == NULL){
                temp->left = creatNode(data);
                return temp->left;
            }
            else{
                temp = temp->left;
            }
        }
        else if(data >= temp->data){
            if(temp->right == NULL){
                temp->right = creatNode(data);
                return temp->right;
            }
            else{
                temp = temp->right;
            }
        }   
    }
}

int Max(int left, int right){
    return (left > right)?left:right;
}

int MaxHeight(Node* temp){

    if(temp == NULL){
        return 0 ;
    }

    return 1 + Max(MaxHeight(temp->left),MaxHeight(temp->right));

// 10 5 15 3 8 12 18 7 9 
}

bool PrintCurrentLevel(Node* temp,int level){
    
    if(temp == NULL){
        return false;
    }
    if(level == 1){
        cout<<temp->data<<" ";
        return true;
    }
    else{
        if(PrintCurrentLevel(temp->left,level-1) == true){
            return true;
        };
        if(PrintCurrentLevel(temp->right,level-1) == true){
            return true;
        };
    }
    return false;
}

void LevelOrderTraversal(Node* temp ,int height){

    for(int i=1;i<=height;i++){
        PrintCurrentLevel(temp,i);
        cout<<endl;
    }
}

int main (){

    //initialize
    Node* Root = NULL; 

    int N;
    cin>>N;
    int numbers[N];

    Node* temp;
    cin>>numbers[0];
    Root = insertBST(Root,numbers[0]);
    temp = Root;

    for(int i=1;i<N;i++){
        cin>>numbers[i];
        temp = insertBST(Root,numbers[i]);
    }

    // cout<<MaxHeight(Root)<<endl;
    LevelOrderTraversal(Root , MaxHeight(Root));

    return 0;
}

