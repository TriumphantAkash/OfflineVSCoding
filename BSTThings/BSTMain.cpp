#include<iostream>
#include<queue>
#include<stack>

using namespace std;
class A
{
    public:
    void A_func()
    {
        cout<<"In A func()"<<endl;
    }
};
class B : public A
{
    public:
    void B_func()
    {
        cout<<"in B func"<<endl;
    }
};
typedef struct  Node
{
    int data;
    Node* left;
    Node* right;
} Node;

void LevelOrder(Node* root)
{
    queue<Node*> q;
    if(root == NULL)
        return;
    q.push(root);

    Node* ptr = NULL;
    while(!q.empty())
    {
        ptr = q.front();
        if(ptr->left)
        {q.push(ptr->left);}
        if(ptr->right)
        {q.push(ptr->right);}
        cout<<ptr->data<<endl;
        q.pop();
        
    }
    
}

bool isBSTUtil(Node* root, int min, int max)
{
    if(root == NULL){return true;}
    if(root->data > min && root->data < max && isBSTUtil(root->left, min, root->data) && 
    isBSTUtil(root->right, root->data, max))
    {return true;}
    else{return false;}
}

bool isBST(Node* root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void InOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" "<<endl;
    InOrderTraversal(root->right);
}

void IterativeInOrderTraversal(Node* root)
{
    Node* cur = root;
    stack<Node*> st;
    Node* top = NULL;

    cout<<"Iterative InOrderTraversal.."<<endl;
    while(cur != NULL || !st.empty())
    {
        if(cur == NULL)
        {
            //1) pop from stack and print that
            top = st.top();
            cout<<top->data<<" ";
            st.pop();
            //2) point current to popped item's right
            cur = top->right;
        }
        else{
            //1) push cur to stack
            st.push(cur);
            //2) cur = cur->left
            cur = cur->left;
        }
    }
}

int func(Node* root)
{
    Node* cur = root;
    Node* top = root;
    stack<Node*> st;
    int prev = 0;
    int minDiff = 10000;
    while(cur != NULL)
    {
        st.push(cur);
        cur = cur->left;
    }
    prev = st.top()->data;
    cur = st.top()->right;
    st.pop();

    while(cur != NULL || !st.empty())
    {
        if(cur == NULL)
        {
            //1) pop from stack and print that
            top = st.top();
            if(top->data - prev < minDiff)
            {minDiff = top->data - prev; }
            st.pop();
            prev = top->data;
            //2) point current to popped item's right
            cur = top->right;
        }
        else{
            //1) push cur to stack
            st.push(cur);
            //2) cur = cur->left
            cur = cur->left;
        }
    }

    return minDiff;
}

void print(int i)
{
    cout<<"red"<<endl;
}

void print(int *p)
{
    cout<<"yellow"<<endl;
}

int main()
{
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = 6;
    Node* temp2 = (Node*)malloc(sizeof(Node));
    temp2->data = 2;
    Node* temp3 = (Node*)malloc(sizeof(Node));
    temp3->data = 10;
    Node* temp4 = (Node*)malloc(sizeof(Node));
    temp4->data = 3;
    Node* temp5 = (Node*)malloc(sizeof(Node));
    temp5->data = 8;

    temp1->left = temp2;
    temp1->right = temp3;
    temp2->left = NULL;
    temp2->right = temp4;

    temp3->left = temp5;
    temp3->right = NULL;

    temp4->left = NULL;
    temp4->right = NULL;

    temp5->left = NULL;
    temp5->right = NULL;

    /*
            3
           / \
          1   5
           \ /
           2 4
    */

    cout<<"Level order Traversal: "<<endl;
    LevelOrder(temp1);
    cout<<"In order Traversal: "<<endl;
    InOrderTraversal(temp1);

    IterativeInOrderTraversal(temp1);

    cout<<"MINIMUM ABSOLUTE DIFFERENCE: "<<func(temp1)<<endl;

    cout<< "is this BST ? : "<<(isBST(temp1)?("Yes"):("No"));

    A a_obj;
    a_obj.A_func();

    B *b_obj = new B();
    b_obj->A_func();

   print(NULL);
    print(nullptr);
    return 0;
}