#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

struct node {
    ll value=0;
    ll height=0;
    ll size =0;
    node *left = nullptr;
    node *right = nullptr;

    node(ll a, ll b) {
        value = a;
        height = b;
        size = 1;
    }
};

ll left_height(node *a) {
    if (a->left == nullptr)return 0;
    return a->left->height;
}

ll right_height(node *a) {
    if (a->right == nullptr)return 0;
    return a->right->height;
}

ll right_size(node *a) {
    if (a->right == nullptr)return 0;
    return a->right->size;
}

ll left_size(node *a) {
    if (a->left == nullptr)return 0;
    return a->left->size;
}

void set_size(node *a) {
    a->size = left_size(a) + right_size(a) + 1;
}

//left > right, left_left
node *left_rotation(node *a) {
    node *b = a->left;
    ll A = left_height(b), B = right_height(b), C = right_height(a);
    a->left = b->right;
    b->right = a;
    a->height = max(B, C) + 1;
    b->height = max(A, a->height) + 1;
    set_size(a);
    set_size(b);
    return b;
}

//left < right, right_right
node *right_rotation(node *&a) {//a.left,b.left,b.right
    node *b = a->right;
    ll A = right_height(b), B = left_height(b), C = left_height(a);
    a->right = b->left;
    b->left = a;
    a->height = max(B, C) + 1;
    b->height = max(A, a->height) + 1;
    set_size(a);
    set_size(b);
    return b;
}

void balance(node *&a) {
    ll le = left_height(a), ri = right_height(a);
    a->height = max(le, ri) + 1;
    if (le - ri >= 2) {
        ll le_le = left_height(a->left), le_ri = right_height(a->left);
        if (le_le > le_ri)a = left_rotation(a);
        else {
            a->left = right_rotation(a->left);
            a = left_rotation(a);
        }
    } else if (ri - le >= 2) {
        ll ri_le = left_height(a->right), ri_ri = right_height(a->right);
        if (ri_ri > ri_le)a = right_rotation(a);
        else {
            a->right = left_rotation(a->right);
            a = right_rotation(a);
        }
    }
    set_size(a);
}

void insert(node *&root, ll key) {
    if(root== nullptr){
        node*tmp=new node(key,1);
        root=tmp;
        return;
    }
    root->size++;
    if (key < root->value) {
        if (root->left == nullptr) {
            node *tmp = new node(key, 1);
            root->left = tmp;
        } else {
            insert(root->left, key);
        }
    } else {
        if (root->right == nullptr) {
            node *tmp = new node(key, 1);
            root->right = tmp;
        } else {
            insert(root->right, key);
        }
    }
    balance(root);
}

ll each = 0;
bool locate(ll toFind, node *root) {
    if (root == nullptr)
        return false;
    const node*oneBigger =root;
    const node *oneSmaller = root;
    while (true) {
        if (root->value == toFind) {
            each = toFind;
            return true;
        } else if (toFind > root->value) {
            if (root->right == nullptr) {
                ll last_di = abs(toFind - oneBigger->value);
                ll now_di = abs(toFind - root->value);
                if(now_di>last_di){
                    each=oneBigger->value;
                    return true;
                } else{
                    each = root->value;
                    return true;
                }
            } else {
                oneSmaller = root;
                root = root->right;
            }
        } else {
            if (root->left == nullptr) {
                ll last_di = abs(toFind - oneSmaller->value);
                ll now_di = abs(toFind - root->value);
                if (last_di <= now_di) {
                    each = oneSmaller->value;
                    return true;
                } else {
                    each = root->value;
                    return true;
                }
            } else {
                oneBigger=root;
                root = root->left;
            }
        }
    }

}


ll doDeep(node *&root) {
    if (root->left == nullptr) {
        ll tmp = root->value;
        if (root->right == nullptr) {
            delete root;
            root = nullptr;
        } else {
            root = root->right;
        }
        return tmp;
    } else {
        ll tmp = doDeep(root->left);
        balance(root);
        return tmp;
    }
}

void del(ll toDel, node *&root) {
    if (root->value == toDel) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->right == nullptr) {
            root = root->left;
        } else if (root->left == nullptr) {
            root = root->right;
        } else {
            root->value = doDeep(root->right);
        }
    } else {
        if (toDel < root->value)del(toDel, root->left);
        else del(toDel, root->right);
    }
    if (root != nullptr) {
        root->height--;
        balance(root);
    }
}

int main() {
    ll n=0;
    scanf("%lld", &n);
    ll sum = 0;
    node *pet_root = nullptr;
    node *human_root = nullptr;
    for (ll i = 0; i < n; ++i) {
        each = 0;
        ll which;
        scanf("%lld", &which);
        ll val;
        scanf("%lld", &val);
        if (which == 0) {//pet
            if (locate(val, human_root)) {
                sum += abs(val - each);
                del(each, human_root);
            } else  {
                insert(pet_root, val);
            }

        } else {//human
            if (locate(val, pet_root)) {
                sum += abs(val - each);
                del(each, pet_root);
            } else {
                insert(human_root, val);
            }

        }
    }
    printf("%lld", sum);
    return 0;
}