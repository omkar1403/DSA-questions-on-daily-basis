/*here if we reach the null then we will simply return the ceil value else we will keep updated it if it is greater than input
if there is root->data which is equal to input then we will return the input and if the it is greater than input then we will move it to 
the left else we will move it to the right*/



int func1(Node* root,int input,int &ceil1){
    if(root==NULL){
        return ceil1;
    }
    if(root->data>input){
        ceil1=root->data;
    }
    if(root->data==input){
        return input;
    }else if(root->data<input){
        return func1(root->right,input,ceil1);
    }else if(root->data>input){
        return func1(root->left,input,ceil1);
    }
}



int findCeil(Node* root, int input) {
    int ceil1=-1;
   if(func1(root,input,ceil1)==input){
       return input;
   }
   return func1(root,input,ceil1);
}