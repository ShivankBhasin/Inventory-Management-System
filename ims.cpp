#include<iostream>
#include <string.h>
#include <sstream>
using namespace std;

string check(int);
int display1();
int search(int);

struct node{
node *prev;
node* next;
int data;
string name;
string h;
int x,y,sum;
};


struct node *start=NULL;

node* create(){
    node *n = new node;
    cout<<"ENTER PRODUCT ID: "<<endl;
    cin>>n->data;
    cout<<"ENTER PRODUCT NAME: "<<endl;
    cin>>n->name;
    cout<<"ENTER QUANTITY: "<<endl;
    cin>>n->x;
    cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
    cin>>n->y;
    n->next = NULL;
    n->prev = NULL;
    return n;
}


void insert_node(){
    node *temp;
    temp = create();
    if(start == NULL){
        start = temp; }
    else{
        node *traverse;
        traverse = start;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next=temp;
        temp->prev=traverse;
    }
}


void add_begin(){
    node *temp;
    temp = create();
    temp->next = start;
    start->prev = temp;
    start=temp;
}

void display(){
    node *traverse;
    traverse = start;
    cout<<"\n\n\t\t\t****ALL MART STORE***"<<endl;
    cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
    while(traverse!=NULL){
        cout<<traverse->data<<"\t\t";
        cout<<traverse->name<<"\t\t";
        cout<<traverse->x<<"\t\t";
        cout<<traverse->y<<"\n";
        traverse = traverse->next;
        }
}


void del_b(){
    node *temp;
    temp = start;
    start = start->next;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);
}

void del_a(){
    int value;
    cout<<"Enter the product after which the node has to be deleted"<<endl;
    cin>>value;
    node *traverse;
    traverse = start;
    while(traverse->data != value){
        traverse = traverse->next;
    }
    node *temp;
    temp = traverse->next;
    traverse->next = temp->next;
    temp->next->prev = traverse;
    cout<<temp->data<<" has been deleted"<<endl;
    delete(temp);
}


 void buy(){
    string products[20];
    int pay=0,no,c=0,price,id,i=1;
    if(start==NULL) {
        cout<<"\n<<<<There is no items to buy>>>>\n\n";
    }
    else{
        cout<<"How many items you wanna to buy!\n";
        cin>>no;
    int count= display1();
    while (i<=no){
        struct node *cur=start;
        int quant,cho;
        cout<<"Enter id of item that you want to buy: \n";
        int id,pos=0;
        cin>>id;
        pos=search(id);
        if(pos<=count){
            while(cur->data!=id){ cur=cur->next;
            }
            cout<<"How many quantities you want: \n";
            cin>>quant;
            products[c]=cur->name;
            c++;
            pay=pay+(cur->y*quant);
            cur->x=cur->x-quant;
            i++;
        }
        else{
            cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
        }
    }
    cout<<"\n\n\n\t\t\tYou have bought : ";
    for(int i=0;i<no;i++){
        cout<<products[i]<<","; }
    price=pay*(0.95);
    cout<<"\n\nOriginal price : "<<pay;
    cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n"; }
}


int search(int id){
    int count=1;
    struct node *p=start;
    while(p!=NULL){
        if(p->data==id) {
        break;
        }
        else
        count++;
    p=p->next;
    }
    return count;
}


int display1(){
    int c=0;
    struct node *p=start;
    cout<<"Existing products are:\n";
    cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    while(p!=NULL){
        cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<check(p->x)<<"\n";
        p=p->next;
        c=c+1;
    }
    cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
    return c;
}

string check(int quant){
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();
    if(quant<=0)
        return "out of stock!";
    else
        return quantity;
}


void srch() {
    cout<<"\n\n\t\t\t****ALL MART STORE***\n\n\n"<<endl;
    string h;
    cout<<"Enter Product Name "<<endl;
    cin>>h;
    int f=0;
    struct node *p=start;
    while(p!=NULL){
        if(h==p->name){
            f=1;
            break;
        }
        p=p->next;
    }
    if(f==1){
        cout<<"Product is available"<< endl;
    }
    else{
        cout<<"Out of stock"<< endl;
    }
 }



int main(){
    int option;
    do{ cout<<"---------------------------------"<<endl;
        cout<<"1 ADD PRODUCT"<<endl;
        cout<<"2 ADD PRODUCT AT FIRST POSITION"<<endl;
        cout<<"3 DELETE PRODUCT AT FIRST POSITION"<<endl;
        cout<<"4 DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
        cout<<"5 DISPLAY"<<endl;
        cout<<"6 BUY"<<endl;
        cout<<"7 SEARCH"<<endl;
        cout<<"0 to terminate"<<endl;

        cin>>option;
        switch(option){
        case 1:insert_node();
                break;
        case 2: add_begin();
                break;
        case 3: del_b();
                break;
        case 4: del_a();
                break;
        case 5: display();
                break;
        case 6: buy();
                break;
        case 7: srch();
                break;
        }
    }
    while(option != 0);
    return 0;

}
