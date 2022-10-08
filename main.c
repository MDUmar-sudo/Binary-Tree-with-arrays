#include <stdio.h>
#include <stdlib.h>



struct tree{
    int size;
    char *arr;
};

typedef struct tree st;

void root_node(st*,char);
void left_node(st*,char,int);
void right_node(st*,char,int);
void print_tree(st*);
void printPreOrder(st*,int);
void printPostOrder(st*,int);
void printInOrder(st*,int);

int main()
{
    printf("\nENTER THE SIZE OF TREE: ");
    int n;
    scanf("%d",&n);
    st *bt = (st*)malloc(sizeof(st));
    bt->size=n;
    bt->arr = (char *)malloc(bt->size*sizeof(char));

    /*        2
            /  \
           3    4
          / \  / \
         1   67   9
    */
    //PreOrder:2 3 1 6 4 7 9
    //InOrder:1 3 6 2 7 4 9
    //PostOrder:1 6 3 7 9 4 2

    int flag=0;
    for(int i=0;i<n;i++){
        char val;
        int parent=-1;
        if(flag==0){
            printf("\nenter root node: ");
            scanf(" %c",&val);
            flag=1;
            root_node(bt,val);
        }
        else if(i%2!=0){
            printf("\nenter left node (value,parent) : ");
            scanf(" %c %d",&val,&parent);
            left_node(bt,val,parent);
        }
        else{
            printf("\nenter right node (value,parent) : ");
            scanf(" %c %d",&val,&parent);
            right_node(bt,val,parent);
        }

    }
    printf("\nPrinting the binary tree...");
    print_tree(bt);
    printf("\n\nPreOrder: ");
    printPreOrder(bt,0);
    printf("\n\nInOrder: ");
    printInOrder(bt,0);
    printf("\n\nPostOrder:");
    printPostOrder(bt,0);
    getch();
    return 0;
}

void print_tree(st *bt) {
  printf("\n");
  for (int i = 0; i < bt->size; i++) {
    if (bt->arr[i] != '\0')
      printf("%c ",bt->arr[i]);
    else
      printf("-");
  }

}

void printPreOrder(st *bt,int index){
    if(bt->arr[index]!='\0' && index<bt->size){
        printf("%c ",bt->arr[index]);
        printPreOrder(bt,(2*index)+1);
        printPreOrder(bt,(2*index)+2);
    }

}



void printInOrder(st*bt,int index){
    if(bt->arr[index]!='\0' && index<bt->size){
        printInOrder(bt,(2*index)+1);
        printf("%c ",bt->arr[index]);
        printInOrder(bt,(2*index)+2);
    }

}


void printPostOrder(st*bt,int index){
    if(bt->arr[index]!='\0' && index<bt->size){
        printPostOrder(bt,(2*index)+1);
        printPostOrder(bt,(2*index)+2);
        printf("%c ",bt->arr[index]);
    }

}

void root_node(st *bt,char val){

    //if(bt->arr[0]!='\0') printf("root is not empty %d",bt->arr[0]);
     bt->arr[0]=val;
}



void left_node(st *bt,char val,int parent){
    if(bt->arr[parent]=='\0'){
    printf("\nno parent @ %d child can't be set",(2*parent)+1);
    }
    else bt->arr[(2*parent)+1]=val;
}



void right_node(st *bt,char val,int parent){
    if(bt->arr[parent]=='\0'){
    printf("\nno parent @ %d child can't be set",(2*parent)+2);
    }
    else bt->arr[(2*parent)+2]=val;
}



