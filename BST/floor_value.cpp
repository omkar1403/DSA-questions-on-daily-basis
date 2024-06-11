/*isme maine first floor1 ko maintain karna hai agar NULL ayega to floor ko return karunga and me update karta rahunga if it is less than the value
and if data equal to input then i will return the value else 
agar data se bada hai to i will move to the right 
else i will move to the left */

class Solution{
    int func1(Node*root,int x,int &floor1){
        if(root==NULL){
            return floor1;
        }
        if(root->data<x){
            floor1=root->data;
        }
        if(root->data==x){
            return x;
        }else if(root->data>x){
            return func1(root->left,x,floor1);
        }else if(root->data<x){
            return func1(root->right,x,floor1);
        }
    }

public:
    int floor(Node* root, int x) {
        int floor1=-1;
        return func1(root,x,floor1);
    }
};