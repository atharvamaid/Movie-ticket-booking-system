#include<iostream>
#include<fstream>
#include<algorithm>


using namespace std;

struct node
{
    int id;
    char state;
    string name;
    struct node *next;
    struct node *prev;
};


class movie
{
public:

    struct node *head[10],*temp,*cn;
    movie()
    {
        for(int i=0;i<10;i++)
        {
            head[i]=NULL;
        }
        temp=NULL;

    }
    void create()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<7;j++)
            {
                temp=new node();
                temp->state='U';
                temp->next=NULL;
                temp->prev=NULL;

                if(head[i]==NULL)
                {
                    temp->next=temp;
                    temp->prev=temp;
                    head[i]=temp;
                }
                else
                {
                    cn=head[i];
                    while(cn->next!=head[i])
                    {
                        cn=cn->next;
                    }

                    cn->next=temp;
                    temp->prev=cn;
                    temp->next=head[i];
                    head[i]->prev=temp;
                }
            }

        }
    }
    void book()
    {
        cout<<"enter row and column at which you want to book seat "<<endl;
        int r,c;
        cin>>r>>c;

        if(r<11&&c<7)
        {
            cn=head[r-1];
            for(int i=1;i<c;i++)
            {
                cn=cn->next;
            }
            cn->state='B';

            cout<<"enter movie id "<<endl;
            cin>>cn->id;
            cout<<"enter your name"<<endl;
            cin>>cn->name;

            cout<<"ticket Booked !! Enjoy movie "<<endl;
        }
        else
            cout<<"enter valid row and column "<<endl;
    }

    void cancel()
    {
        cout<<"enter row and column at which you want to cancel your seat "<<endl;
        int r,c;
        cin>>r>>c;
        if(r<11&&c<7)
        {
            cn=head[r-1];
            for(int i=1;i<c;i++)
            {
                cn=cn->next;

            }
            cn->state='U';
            cn->id=0;
            cn->name="";

            cout<<"ticket canceled successfully "<<endl;
        }
        else
            cout<<"enter valid row and column "<<endl;
    }
    void display()
    {
        cout<<"                           Screen                          "<<endl;
        for(int i=0;i<10;i++)
        {
            cn=head[i];
            for(int j=0;j<7;j++)
            {
               cout<<"    "<<cn->state<<"    ";
               cn=cn->next;
            }
            cout<<endl;
        }




    }

    void details()
    {
        cout<<"enter row and column to view the details of the seat "<<endl;
        int r,c;
        cin>>r>>c;
        cn=head[r-1];

        for(int i=1;i<c;i++)
        {
            cn=cn->next;

        }
         cout<<"seat details "<<endl;
         cout<<"seat status :"<<cn->state<<endl;
         cout<<"seat booked by :"<<cn->name<<endl;
         cout<<"movie id:"<<cn->id<<endl;
    }
};

int main()
{
   movie x;
   int i=1,ch;
   cout<<"!!!!!!!!!!!!!!!!!!!!!!!! Movie Ticket Booking System !!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

   cout<<endl<<endl;
   cout<<"                                 Today's Shows                                  "<<endl;
   cout<<"--------------------------------------------------------------------------------"<<endl;
   cout<<"| movie id         | Movie              |  Date             |  Time            |"<<endl;
   cout<<"| 12               | Titanic            |  12-12-19         |  3:00 PM         |"<<endl;
   cout<<"| 15               | The Avengers       |  13-12-19         |  6:00 PM         |"<<endl;
   cout<<"| 16               | X-Men              |  15-12-19         |  9:00 PM         |"<<endl;
   cout<<"--------------------------------------------------------------------------------"<<endl;
    x.create();
   while(i)
   {
       cout<<"          Enter 1 to Book tickets         "<<endl;
       cout<<"          Enter 2 to view booking status         "<<endl;
       cout<<"          Enter 3 to cancel booked tickets         "<<endl;
       cout<<"          Enter 4 to view details of seats         "<<endl;
       cout<<"          Enter 5 to exit           "<<endl;
       cin>>ch;
       switch(ch)
       {
       case 1:
        x.book();
        break;
       case 2:
        x.display();
        break;
       case 3:
        x.cancel();
        break;
       case 4:
        x.details();
       case 5:
        i=0;
       }

   }
}


