#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
    int data;
    struct bst* left,*right;
}tree;
 
tree* create(tree* root){
 tree* temp,*p,*t;
 int f=0;
 temp=(tree*)malloc(sizeof(tree));
 printf("\n Enter data = ");
 scanf("%d",&temp->data);
 temp->left=NULL;
 temp->right=NULL;
 if(root==NULL){
    root=temp;
    f=1;
 }else{
    p=root;
    while(p!=NULL){
        t=p;
     if(temp->data > p->data){
        p=p->right;
     }else if(temp->data < p->data){
        p=p->left;
     }else{
       printf("\n Duplicates elements are not allowed");
       break;
       }
    }
    if(temp->data < t->data){
        f=1;
        t->left=temp;
    }else if(temp->data > t->data){
        f=1;
        t->right=temp;
    }
 }
 if(f==1){
    printf("\n 1 node inserted");
 }
 return (root);
}
 
void preorder(tree* root){
  if(root!=NULL){
    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(tree* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("\t%d",root->data);
    }
}

void inorder(tree* root){
    if(root!=NULL){
        inorder(root->left);
        printf("\t%d",root->data);
        inorder(root->right);
    }
}
 
int countNode(tree* root,int ctr){
    if(root!=NULL){
        ctr++;
       ctr =  countNode(root->left,ctr);
       ctr =  countNode(root->right,ctr);
    }
    return ctr;
}

int countLeafNode(tree* root,int ctr){
    if(root!=NULL){
            if(root->left==NULL && root->right==NULL){
            ctr++;
        }
      ctr = countLeafNode(root->left,ctr);
      ctr = countLeafNode(root->right,ctr);
    }
    return ctr;
}

int countNonLeafNode(tree* root,int ctr){
    if(root!=NULL){
        if(root->left!=NULL || root->right!=NULL){
            ctr++;
        }
        ctr = countNonLeafNode(root->left,ctr);
        ctr = countNonLeafNode(root->right,ctr);
    }
    return ctr;
}
int maxVal(tree* root){
    int max = 0;
if(root==NULL){
    printf("\n Tree is empty");
}else{
    while(root->right!=NULL){
        root=root->right;
    }
    max = root->data;
}
return max;
}

int minVal(tree* root){
    int min = 0;
    if(root==NULL){
        printf("\nTree is empty");
        return -1;
    }else{
        while(root->left!=NULL){
            root = root->left;
        }
        min = root->data;
    }
    return min;
}
// large is also part of height finding function
int large(int a , int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int height(tree* root){
    if(root==NULL){
       return 0;
    }else{
        return large(height(root->left),height(root->right))+1; // due to counting the main root node also.
    }
}
//  

int search(tree* root,int searchVal){
        if(root==NULL){
          printf("\n tree is empty or value not found"); 
          return -1;
        }else{
             if(root->data>searchVal){
              return  search(root->left,searchVal);
            }else if(root->data<searchVal){
             return  search(root->right,searchVal);
            }else{
                return 1;
            }
        }
    return -1;
}

void main(){
    int n,num,ctr=0,searchVal;
    tree* root=NULL;
    do{
        printf("\n 1. create");
        printf("\n 2. preorder");
        printf("\n 3. postorder");
        printf("\n 4. inorder");
        printf("\n 5. count total no. of nodes");
        printf("\n 6. count total no. of leaf nodes");
        printf("\n 7. count total no. of non-leaf nodes");
        printf("\n 8. max value");
        printf("\n 9. min value");
        printf("\n 10. height of the tree");
        printf("\n 11. search");
        printf("\n 12. exit");
        printf("\n Enter choice number = ");
        scanf("%d",&n);
        switch(n){
            case 1:
            root =  create(root);
            break;
            case 2:
            preorder(root);
            break;
            case 3:
            postorder(root);
            break;
            case 4:
            inorder(root);
            break;
            case 5:
            num = countNode(root,ctr);
            printf("\n Total number of node is = %d",num);
            break;
            case 6:
             num =  countLeafNode(root,ctr);
             if(num!=-1){
                printf("\n Number of leaf node = %d",num);
             }
             break;
             case 7:
             num = countNonLeafNode(root,ctr);
             if(num!=-1){
             printf("\n non leaf node is = %d",num);
             }
             break;
             case 8:
             num = maxVal(root);
             if(num!=-1){
                 printf("\n Maximum value is = %d",num);
             }
             break;
             case 9:
             num = minVal(root);
             if(num!=-1){
                printf("\n min value is = %d",num);
             }
             break;
             case 10:
             num = height(root);
             if(num==0){
                printf("\n tree is empty");
             }else{
                printf("\n height of the tree is  =  %d",num);
             }
             break;
             case 11:
                 printf("\n Enter search value = ");
                  scanf("%d",&searchVal);
             num = search(root,searchVal);
             if(num!=-1){
              printf("\n Search value found");
             }
             break;
            default :
            printf("\n Invalid choice number");
        }
    }while(1);
}