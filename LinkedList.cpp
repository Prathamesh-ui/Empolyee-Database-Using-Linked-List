#include<iostream>
#include<string.h>
#include<iomanip.h>
#include<stdlib.h>
using namespace std;

struct node{
    char name[20];
    char dpt[20];
    int id;
    int sal;
    struct node *next;
};

struct node *head=NULL;


void create()
{
    struct node *new_node, *temp;
    new_node = new node;
    cout<<"\nEnter Employee ID: ";
    cin>>new_node->id;
    cout<<"\nEnter Employee Name: ";
    cin>>new_node->name;
    cout<<"\nEnter Employee Department: ";
    cin>>new_node->dpt;
    cout<<"\nEnter Employee Salary: ";
    cin>>new_node->sal;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new_node;
    }
    
}

void display()
{
    int i=1;
    struct node *temp;
    if(head==NULL)
    cout<<"\n List is empty";
    else
    {
        temp=head;
        cout<<"\nSr.No\t\tEmpolyee ID\t\tName of Empolyee\t\tDepartment of Empolyee\t\tEmpolyee Salary\n";
        while(temp!=NULL)
        {
           cout<<"\n";
           cout<<i<<setw(20)<<temp->id<<setw(30)<<temp->name<<setw(35)<<temp->dpt<<setw(30)<<temp->sal<<"\n";
           temp=temp->next;
            i++;
        }
    }
    
}

void insert_beginning()
{
    struct node *new_node;
    new_node=new node;
    cout<<"\nEnter Employee ID: ";
    cin>>new_node->id;
    cout<<"\nEnter Employee Name: ";
    cin>>new_node->name;
    cout<<"\nEnter Employee Department: ";
    cin>>new_node->dpt;
    cout<<"\nEnter Employee Salary: ";
    cin>>new_node->sal;
    new_node->next=NULL;
    new_node->next=head;
    head=new_node;
}

void insert_end()
{
    struct node *new_node, *temp;
    new_node=new node;
    cout<<"\nEnter Employee ID: ";
    cin>>new_node->id;
    cout<<"\nEnter Employee Name: ";
    cin>>new_node->name;
    cout<<"\nEnter Employee Department: ";
    cin>>new_node->dpt;
    cout<<"\nEnter Employee Salary: ";
    cin>>new_node->sal;
    new_node->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}

void insert_loc()
{
    struct node *new_node, *temp;
    temp=head;
    int pos,i=1,count=1;
    new_node=new node;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"\nEnter the position for Insertion: ";
    cin>>pos; 
    if(pos>count)
        cout<<"\nInvalid Position!!\n";
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        cout<<"\nEnter Employee ID: ";
        cin>>new_node->id;
        cout<<"\nEnter Employee Name: ";
        cin>>new_node->name;
        cout<<"\nEnter Employee Department: ";
        cin>>new_node->dpt;
        cout<<"\nEnter Employee Salary: ";
        cin>>new_node->sal;
        new_node->next=NULL;
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void search()
{
    struct node *temp;
    temp=head;
    int b,ID,flag=0;
    char s[20];
    cout<<"\nHow do you want to Search? ";
    cout<<"\n1. By Empolyee ID\n2. By Empolyee Name\n3. Exit";
    cout<<"\nEnter the choice: ";
    cin>>b;
    switch(b)
    {
        case 1:
            cout<<"\nEnter the ID: ";
            cin>>ID;
            while(temp!=NULL)
            {   
                if((temp->id)==ID)
                {
                    cout<<"\nRecord Found!!\n";
                    cout<<"\nEmpolyee ID: "<<temp->id;
                    cout<<"\nName of Empolyee: "<<temp->name;
                    cout<<"\nDepartment of Empolyee: "<<temp->dpt;
                    cout<<"\nSalary of Empolyee: "<<temp->sal;  
                    cout<<"\n"; 
                    flag=1;
                }
                 temp=temp->next;
            }
            if(flag!=1)
            {
                cout<<"\nRecord Not Found!!\n";
            }          
            break;
        case 2:
            cout<<"\nEnter the Name: ";
            cin>>s;
            while(temp!=NULL)
            {
                if(strcmp(s,temp->name)==0)
                {
                    cout<<"\nRecord Found!!\n";
                    cout<<"\nEmpolyee ID: "<<temp->id;
                    cout<<"\nName of Empolyee: "<<temp->name;
                    cout<<"\nDepartment of Empolyee: "<<temp->dpt;
                    cout<<"\nSalary of Empolyee: "<<temp->sal;
                    cout<<"\n";
                    flag=1;
                }
                 temp=temp->next;
            }
            if(flag!=1)
            {
                cout<<"\nRecord Not Found!!\n";
            }           
            break;
        case 3:
            break;
        default:
            cout<<"\nWrong choice!!\n";
                        
    }
}

void modify()
{
    struct node *temp;
    int pos,i=1,count=1;
    temp=head;
    if(head==NULL)
    {
        cout<<"\nList is Empty!!\n";
    }
    cout<<"\nEnter Empolyee ID to modify: ";
    cin>>pos;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==pos)
        {
            cout<<"\nEnter Empolyee new ID: ";
            cin>>temp->id;
            cout<<"\nEnter new Name of Empolyee: ";
            cin>>temp->name;
            cout<<"\nEnter new Department of Empolyee: ";
            cin>>temp->dpt;
            cout<<"\nEnter new Salary of Empolyee: ";
            cin>>temp->sal;  
            cout<<"\n";
            count=0;
        }
        temp=temp->next;
    }
    if(count==1)
        {
            cout<<"\nRecord not Found!!\n";
        }
}

void delete_beginning()
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    cout<<"\nRecord Deleted Successfully!!\n";
    
    
}

void delete_end()
{
        struct node *temp, *prevnode;
        temp=head;
        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        if(temp==head)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            prevnode->next=NULL;
            free(temp);
        }
        cout<<"\nRecord deleted Successfully!!\n";

}

void delete_loc()
{
    struct node *temp, *next_node;
    int pos,i=1,count=1;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"\nEnter the position for Delete: ";
    cin>>pos; 
    if(pos>count)
        cout<<"\nInvalid Position!!\n";
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        next_node=temp->next;
        temp->next=next_node->next;
        free(next_node);
        cout<<"\nRecord Deleted Successfully!!\n";
    }
    
    
}

int main()
{
    int choice;
    int cho,a,b;
    cout<<"\t\t\t************Empolyee Data**************\n";
    do{
    cout<<"\n\t1. Create new Data\n\t2. Display Data\n\t3. Insert new Data\n\t4. Search Data\n\t5. Modify Data\n\t6. Delete Data\n\t7. Exit\n";
    cout<<"\tEnter the Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
                cout<<"\nWhere Do You Insert new Data? ";
                cout<<"\n1. At Beginning\n2. At End\n3. After given location\n4. Exit";
                cout<<"\nEnter the choice: ";
                cin>>a;
                if(a==1)
                {
                    insert_beginning();
                }
                else if(a==2)
                {
                    insert_end();
                }
                else if(a==3)
                {
                    insert_loc();
                }
                else if(a==4)
                {
                    break;
                }
                else
                {
                    cout<<"\nWrong Choice!!!\n";
                }
                break;
        case 4:
                search();
                break;
        case 5:
                modify();
                break;
        case 6:
            cout<<"\n Which element do you want to Delete? ";
            cout<<"\n1. At Beginning\n2. At End\n3. At given location\n4. Exit";
            cout<<"\nEnter the choice: ";
            cin>>b;
            if(b==1)
                {
                    delete_beginning();
                }
            else if(b==2)
                {
                    delete_end();
                }
             else if(b==3)
                {
                    delete_loc();
                }
            else if(b==4)
            {
                exit(0);
            }
            else
                {
                    cout<<"\nWrong Choice!!!\n";
                }
                break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"\nWrong choice!!\n";           
        }
    cout<<"\nDo you want to countinue: ";
    cout<<"\n1. Yes\t2. No";
    cout<<"\nEnter the choice: ";
    cin>>cho;
    }while(cho==1);

}