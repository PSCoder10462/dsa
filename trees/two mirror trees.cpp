int areMirror(Node* a, Node* b) {
    // Your code here
        if (!a and !b) return true;
        
        if ((a and !b) or (b and !a)) return false;
        
        if (a->data != b->data) return false;
        
        return areMirror(a->right, b->left) and areMirror(a->left, b->right);
    }
