#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stdexcept>
#include <fstream>
#include <array>
#include <sstream>
#include <cstring>
using namespace std;


struct node {
    struct node *left;
    string data;
    int height;
    int ss;
    struct node *right;
    struct node *parent;

};

class AVL
{
private:
    
public:
    struct node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){
            if(p->left && p->right){
            return  max(p->right->height +1,p->left->height + 1);
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;
    }

    int bf(struct node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    struct node * llrotation(struct node *n){
        //cout << "running ll" << endl;
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }


    struct node * rrrotation(struct node *n){
      //cout << "running rr" << endl;
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }


    struct node * rlrotation(struct node *n){
      //cout << "running rl" << endl;
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

    struct node * lrrotation(struct node *n){
      //cout << "running lr" << endl;
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }


    struct node* insert(struct node *r,string data){
        //cout << "inserting" << data << endl;
        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            r->ss = 1;
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;            
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline(struct node *v){
        queue <struct node *> q;
        struct node *cur;
        q.push(v);
        q.push(NULL);      

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
                cout<<"\n" ;
                
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" "<<cur->data << "(" << cur->height << ")";

                if (cur->left!=NULL){
                q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            
            
        }
        cout<<"\n";
    }
 
    struct node * deleteNode(struct node *p,string data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct node *t;
        struct node *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data >data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }                  
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

        
        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }
    int range(struct node* start, string one1, string two2){
      if(start == NULL){
        //cout << "no values" << endl;
        return 0;
      }
    //cout << "at com1: " << com1 << endl;
      if(start->data == one1 && start->data == two2){
        //cout << "don't recur" << endl;
        return 1;
      }
      if(start->data <= two2 && start->data >= one1){
        //cout << "recurring left and right" << endl;
        return 1 + range(start->left,one1,two2) + range(start->right, one1, two2);
      }
      else if (start->data < one1){
        //cout << "recur right" << endl;
        return range(start->right, one1, two2);
      }
      else {
        //cout << "recur left" << endl;
        return range(start->left,one1, two2);
        }
      }


    ~AVL(){

    }
};


int main(int argc, char** argv){
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./avl <INPUT FILE> <OUTPUT FILE>"); // throw error
    }

    ifstream input; // stream for input file
    ofstream output; // stream for output file

    input.open(argv[1]); // open input file
    output.open(argv[2]); // open output file

    string command; // to store the next command and operation
    char *com, *dummy, *valstr, *valstr2, *op; // for using with strtok, strtol
    string val,val2; // the value from the command
    
    AVL b;
  

    while(getline(input,command)) // get next line of input, store as repeat
    {
        if (command.length() == 0) // command is empty
            continue;
        com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string
        op = strtok(com, " \t"); //tokenize command on whitespace, first token is operation

         // next token is value, as string (check out documentation on strtok, to understand the parsing)
        valstr = strtok(NULL, " \t");
        if(valstr != NULL) // first check if there is actually anything to convert into int
            val = valstr; // convert initial portion of valstr into an integer val, with base 10. Check out documentation on strtol for more details.
        valstr2 = strtok(NULL, " \t");
        if(valstr2 != NULL) // first check if there is actually anything to convert into int
            val2 = valstr2; // convert initial portion of valstr into an integer val, with base 10. Check out documentation on strtol for more details.
        
    
        if(strcmp(op,"i") == 0) // insert into list
        {
            //cout << "Insert "+ val << endl;
            b.root = b.insert(b.root,val);
        }
        if(strcmp(op,"d") == 0) // delete from list
        {
            //cout << "Delete "+ val << endl;
            b.root = b.deleteNode(b.root,val); // delete the value, and free the memory
        }
        if(strcmp(op,"pin") == 0) // print tree in order
        {
            //output << myBST.printInOrder() << endl; // write printed tree to file, and add new line
            //cout << "Print In Order" << endl;
            b.levelorder_newline(); // printing to console
            continue; // move on to next command
        }
        if(strcmp(op,"ppre") == 0) // print tree pre order
        {
            //output << myBST.printPreOrder() << endl; // write printed tree to file, and add new line
            cout << "completed inserts" << endl;
            //cout << myBST.printPreOrder() << endl; // printing to console
            continue; // move on to next command
        }
        if(strcmp(op,"ppost") == 0) // print tree post order
        {
            //output << myBST.printPostOrder() << endl; // write printed tree to file, and add new line
            //cout << "Print Post Order" << endl;
            //cout << myBST.printPostOrder() << endl; // printing to console
            continue; // move on to next command
        }
        if(strcmp(op,"r") == 0) // print tree post order
        {
            int m = b.range(b.root,val,val2);
            output << m << endl;
            //cout << "there are " << m << " between 10 and 20"<< endl;
	}
     }
  
}