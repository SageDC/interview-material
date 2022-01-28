#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = new Node();

    if(!newNode) {
        cout << "Memory error" << endl;
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert into a binary tree */
Node* insertNode(Node* root, int data) {
    // if the tree is empty, create a new node
    if(root == NULL) {
        root = createNode(data);
        return root;
    }

    // else do a level order traversal until we find an empty place
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL) {
            q.push(temp->left);
        }
        else {
            temp->left = createNode(data);
            return root;
        }

        if(temp->right != NULL) {
            q.push(temp->right);
        }
        else {
            temp->right = createNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */
void inOrder(Node* temp) {
    if(temp == NULL) {
        return;
    }

    inOrder(temp->left);
    cout << temp->data << ' ';
    inOrder(temp->right);
}

/* function to delete the given deepest node */
void deleteDeepest(struct Node* root, struct Node* d_node) {
    queue<struct Node*> q;
    q.push(root);

    // do level order traversal until last node
    struct Node* temp;
    
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp == d_node) {
            temp == NULL;
            delete(d_node);
            return;
        }

        if(temp->right) {
            if(temp->right == d_node) {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else {
                q.push(temp->right);
            }
        }

        if(temp->left) {
            if(temp->left == d_node) {
                temp->left = NULL;
                delete(d_node);
                return;
            }
            else {
                q.push(temp->left);
            }
        }
    }
}

/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL) {
        if(root->data == key) {
            return NULL;
        }
        else {
            return root;
        }
    }

    queue<struct Node*> q;
    q.push(root);
    struct Node* temp;
    struct Node* key_node = NULL;

    /* do level order traversal to find deepest node and node to be deleted */
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp->data == key) {
            key_node = temp;
        }

        if(temp->left) {
            q.push(temp->left);
        }

        if(temp->right) {
            q.push(temp->right);
        }
    }

    if(key_node != NULL) {
        int x = temp->data;
        deleteDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}

struct Node* betterDeletion(struct Node* root, int key) {
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key)
            return NULL;
        else
            return root;
    }
    Node* key_node=NULL;
    Node* temp;
    Node* last;
    queue<Node*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
      // and parent of deepest node(last)
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
            key_node=temp;
        if(temp->left)
        {
            last=temp;//storing the parent node
            q.push(temp->left);
        }
        if(temp->right)
        {
            last=temp;// storing the parent node
            q.push(temp->right);
        }
             
         
    }
      if(key_node!=NULL)
    {
        key_node->data=temp->data;//replacing key_node's data to deepest node's data
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
        delete(temp);
     }
    return root;
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    
    cout << "Inorder traversal before insertion: ";
    inOrder(root);
    cout << endl;

    int key = 12;
    root = insertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inOrder(root);
    cout << endl;

    key = 7;
    root = deletion(root, key);

    cout << "Inorder traversal after deletion: ";
    inOrder(root);
    cout << endl;

    key = 9;
    root = betterDeletion(root, key);

    cout << "Inorder traversal after better deletion: ";
    inOrder(root);

    return 0;
}