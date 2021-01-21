#include<iostream>
#include<cstring>
using namespace std;

struct hashTable{
    string key;
    int64_t value;
    bool isEmpty=true;
    hashTable *next;
};

class Contacts{
    int num;        //number of entries
    hashTable *phoneBook;
public:
    Contacts():phoneBook(NULL){
    }
    void ins(){
        int index;
        int64_t phoneNumber;
        string name;
        cout<<"enter number of entries: ";
        cin>>num;
        phoneBook=new hashTable[num];
        cout<<"Enter name and phone number respectively:"<<endl;
        for(int i=0;i<num;i++){
            cin>>name>>phoneNumber;
            index=hashing(name,num);
            if(phoneBook[index].isEmpty){        //if the slot is empty(no collision)...
                phoneBook[index].key=name;
                phoneBook[index].value=phoneNumber;
                phoneBook[index].isEmpty=false;     //it is now filled...
                phoneBook[index].next=NULL;
            }
            else{           //in case of collision...
                hashTable *temp=&(phoneBook[index]);
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=new hashTable;
                temp->next->key=name;
                temp->next->value=phoneNumber;
                temp->next->isEmpty=false;
                temp->next->next=NULL;
            }
        }
    }
    int hashing(string name,int n){
        int len,sum=0;
        //converting string into char array...
        len=name.length();
        char temp[len+1];
        strcpy(temp,name.c_str());
        //calculating hash value...
        for(int i=0;i<len;i++){
            sum=sum+temp[i];
        }
        return (sum%n);
    }
    void searchContact(string name){
        int check;
        check=hashing(name,num);

        if(phoneBook[check].next==NULL){        //if there is no collision seen in the current block..
            if(phoneBook[check].key==name){
                cout<<"Name: "<<phoneBook[check].key<<endl;
                cout<<"Phone number: "<<phoneBook[check].value<<endl;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }

        else{                                   //if collision is seen in the current block...
            hashTable *temp=&(phoneBook[check]);
            while(temp!=NULL){
                if(temp->key==name){
                    cout<<"Name: "<<temp->key<<endl;
                    cout<<"Phone number: "<<temp->value<<endl;
                    break;
                }
                else
                    temp=temp->next;
            }
            if(temp==NULL)
                cout<<"Not found"<<endl;
        }
    }
    ~Contacts(){
        delete []phoneBook;
    }
};
int main(){
    string name;
    int n;
    Contacts d1;
    d1.ins();
    cout<<"Enter number of names you want to search: ";
    cin>>n;
    cout<<"Enter names: "<<endl<<endl;
    for(int i=1;i<=n;i++){
        cin>>name;
        d1.searchContact(name);
        cout<<endl;
    }
}