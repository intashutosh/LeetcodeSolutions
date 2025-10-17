#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void generate(Node* root, vector<int>& v){
        int left = 0;
        int right = 0;
        stack<int> leftmost;
        queue<int> rightmost;
        queue<pair<Node*, int>> q;
        if(root){
            q.push({root, 0});
        }
        while(!q.empty()){
            int n = q.size();
            int x = n;
            while(x--){
                Node* node = q.front().first;
                int col = q.front().second;
                q.pop();
                    if(col > left){
                        leftmost.push(node->data);
                        left = col;
                    }
                    if(col < right){
                        rightmost.push(node->data);
                        right = col;
                    }
                if(node->left){
                    q.push({node->left, col+1});
                }
                if(node->right){ 
                    q.push({node->right, col-1});
                }
            }
        }
        while(!leftmost.empty()){
            v.push_back(leftmost.top());
            leftmost.pop();
        }
        if(root){
            v.push_back(root->data);
        }
        while(!rightmost.empty()){
            v.push_back(rightmost.front());
            rightmost.pop();
        }
    }
    vector<int> topView(Node *root) {
        // code here
        vector<int> v;
        generate(root, v);
        return v;
        
    }
};