#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
void Print(Node* root){
    if(!root)
        return ;
    Print(root->left);
    cout<<root->data<<"|";
    Print(root->right);
}
void delete_deep(Node* root, Node* d_node){
        queue<Node*> q;
        q.push(root);
        Node* temp;
        while(q.empty() == false){
            temp = q.front();
            q.pop();
             cout<<"d_node::"<<temp->data<<endl;
            if(temp == d_node ){
                cout<<"inside cond. check::"<<temp->data<<endl;
                temp = NULL;
                delete (d_node);
                return;
            }
             
            if(temp->right){
                cout<<"temp->right->data::"<<temp->right->data<<endl;
                     if(temp->right == d_node){
                         cout<<"temp->right::"<<temp->data<<endl;
                        temp->right = NULL;
                        delete (d_node); return;
                    }
                else
                    q.push(temp->right);  
            }
          
            if(temp->left){
                cout<<"temp->letft->data::"<<temp->left->data<<endl;
                    if(temp->left == d_node){
                        cout<<"temp->left:"<<temp->data<<endl;
                        temp->left = NULL;
                        delete (d_node); return;
                    }
                else
                    q.push(temp->left);
            }
           
            
        }
}
Node*  Deletion(Node*  root, int key){
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL){
                if(root->data == key)
                    return NULL;
                else
                    return root;
        }
         queue<Node*>  q;
        Node* temp , *key_node = NULL;
        q.push(root);
        while(q.empty() == false){
           temp =q.front();
            q.pop();
            if((temp->data)  == key)
                key_node = temp;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }    
        if(key_node != NULL){
            int x = temp->data;
            delete_deep(root,temp);
            key_node->data = x;
        }
       return root; 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4 );
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Print(root); cout<<endl;
    root = Deletion(root,3);
    Print(root); cout<<endl;
    return 0;
}
