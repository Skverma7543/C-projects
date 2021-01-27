//#include "stack.cpp"
#include<iostream>
#include<fstream>
#include "stack_header.h"
using namespace std;
/*int main()
{
cout<<"welcome to stack operation"<<endl;
stack <int> s1;
while(1)
{
    cout<<"enter your choice"<<endl;
    cout<<"\n1.push\n2.pop\n3.exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"enter number"<<endl;
                int num;
                cin>>num;
                s1.push(num);
                break;
        case 2:int n;
              n=s1.pop();
            if(n!=-1)
            cout<<"pop item is num-->"<<n<<endl;
            break;
        case 3:
                 s1.get_all();
    }
}
return 0;
}*/
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        cout<<"usage:./a.out file name"<<endl;
        return 0;
    }
    //ifstream fin(argv[1],ios::in);
    ofstream fout(argv[1],ios::out|ios::app);
    stack <string> s1,s2;
    while(1)
    {
       cout<<"enter your option:"<<endl;
       cout<<"1.write\n2.read\n3.save\n4.undo\n5.redo\n6.close"<<endl;
       int choice;
       cin>>choice;
       switch(choice)
       {
         case 1:
                my_write(s1);
                break;
                
         case 2:
                my_read(s1,s2,argv[1]);
                break;
         case 3:
                my_save(s1,argv[1]);
                break;
         case 4:
                my_undo(s1,s2);
                break;
         case 5:
                my_redo(s1,s2);
                break;
         case 6:
                my_exit(s1,argv[1]);
                break;
       }
       cin.ignore();
    }
}
//***************write*****************//
void my_write(stack <string> &s1)
{
  string s;
  string c("closew");
  cin.ignore();
  while(1)
  {
      
      getline(cin,s);
      if(s==c)
      return;
      s1.push(s);
  }
}

//****************read*******************//
void my_read(stack <string> &s1,stack <string> &s2,char *file)
{
    string s;
    ifstream fin;
    fin.open(file,ios::in);
while(getline(fin,s))
cout<<s<<endl;
stack<string> temp;
while(!(s1.is_empty()))
temp.push(s1.pop());
string ch;
while(!(temp.is_empty()))
{
    ch=temp.pop();
    s1.push(ch);
    cout<<ch<<endl;
}
fin.close();
}


//**************************save**************************//
void my_save(stack <string> &s1,char *file)
{
    ofstream fout(file,ios::out|ios::app);
    stack<string> temp;
while(!s1.is_empty())
temp.push(s1.pop());
while(!temp.is_empty())
fout<<temp.pop()<<endl;
fout.close();
}


//****************undo**********************************//
void my_undo(stack <string> &s1,stack <string> &s2)
{
if(!s1.is_empty())
s2.push(s1.pop());
}


//********************redo*************************//
void my_redo(stack <string> &s1,stack <string> &s2)
{
    if(!s2.is_empty())
    s1.push(s2.pop());
}

//********************exit********************//
void my_exit(stack <string> &s1,char *file)
{
    while(1)
   {
       cout<<"do you want to save then press y else n"<<endl;
       char ch;
       cin>>ch;
       if(ch=='y'||ch=='Y')
       {
           ofstream fout(file,ios::out|ios::app);
           my_save(s1,file);
           fout.close();

       }
       if(ch=='n'||ch=='N'||ch=='y'||ch=='Y')
       {
        exit(0);

       }
   }

}