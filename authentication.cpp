#include<iostream>
#include<fstream>
using namespace std;
class signup
{
    string fname,lname;
    string email;
    string password;
    static int count;
    public:
    signup(string f,string l,string e,string p)
    {
        fname=f;
        lname=l;
        email=e;
        password=p;
        ofstream fout("login_details",ios::out|ios::app);
        fout<<count++<<" "<<fname<<" "<<lname<<" "<<email<<" "<<password<<endl;
    }

};
int signup::count=1;
bool is_valid_email(string e)
{
    int i;
    bool f1=0,f2=0;
    for(i=0;e[i];i++)
    {
        if(e[0]=='@'||e[0]=='.')
        return false;
        if(e[i]=='@')
        {
            if(f1==1)
            return false;
            f1=1;
        }
        else if(e[i]=='.')
        {
            if(f2==1||f1==0)
            return false;
            f2=1;
        }
        else if((e[i]>='A'&&e[i]<='Z')||(e[i]>='a'&&e[i]<='z')||(e[i]>='0'&&e[i]<='9'))
        {
            continue;
        }
        else 
        {
            return false;
        }

    }
    if(f1==1&&f2==1)
    return true;
    else 
    return false;
}
bool is_valid_password(string s)
{
    bool f1=0;//alpha cap
    bool f2=0;//alpha small
    bool f3=0; //numeric
    bool f4=0; //special
    int i;
    for(i=0;s[i];i++)
    {
        if(s[i]==' ')
        return false;
        else if(s[i]>='A'&&s[i]<='Z')
        {
            f1=1;
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            f2=1;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            f3=1;
        }
        else 
        {
            f4=1;
        }
    }
    if(i!=6)
    {
        cout<<"\npassword must be in range of 6"<<endl;
        return false;
    }
    else
    {
        if(f1&f2&f3&f4)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
}
bool is_valid_name(string e)
{
    int i;
    for(i=0;e[i];i++)
    {
        if(e[0]==' '||e[0]=='.')
        {
            return false;
        }
        if((e[i]>='A'&&e[i]<='Z')||(e[i]>='a'&&e[i]<='z'))
        {
        
            continue;
        }
        else 
        {
            return false;
        }
    }
    if(i<=20)
    return true;
    else
    {
        return false;
    }
    
}
/*****************************signup***********************************/
void reset_pass();
bool is_email_exist(string e)
{
     int count;
    string fname,lname,email,password;
    ifstream fin("login_details",ios::in);
    while(fin>>count>>fname>>lname>>email>>password)
    {
        if(email==e)
        {
            return 1;
        }
    }
    return 0;

}
void sign_up()
{
            string fname,lname;
            string email;
            string password;
            int count=0,i;
            cout<<"\nenter your first name:";
            cin.ignore();
            i=0;
            while(1)
            {
                cin>>fname;
                if(is_valid_name(fname))
                break;
                i++;
                 if(i==3)
                 {
                  cout<<"\ntoo many attemp try again";
                  return;
                 }
                cout<<"\nplease enter valid name:";
            }
            cout<<"\nenter your last name:";
            cin.ignore();
            i=0;
            while(1)
            {
                cin>>lname;
                if(is_valid_name(lname))
                break;
                 i++;
                 if(i==3)
                 {
                  cout<<"\ntoo many attemp try again";
                  return;
                 }
                cout<<"\nplease enter valid name:";
            }
            cout<<"\nenter your email:";
            while(1)
            {
                cin>>email;
                if(is_valid_email(email))
                {
                    if(is_email_exist(email))
                    {
                        cout<<"\nemail is already exist type different one ";
                        char choice;
                        email_choice:
                        cout<<"\nif want to reset press y else n:";
                        cin>>choice;
                        if(choice=='y'||choice=='Y')
                        {
                         reset_pass();
                         return;
                        }  
                        else if(choice=='n'||choice=='N')
                        {
                             i++;
                             if(i==3)
                             {
                              cout<<"\ntoo many attemp try again";
                              return;
                             }
                           cout<<"\nenter another email:";
                        }
                       else
                       {
                        goto email_choice;
                       }
                    }
                    else
                    {
                      break;
                    }
                    
                }
                else
                {
                    cout<<"please enter valid email"<<endl;
                }
            }
            cin.ignore();
            cout<<"enter your password"<<endl;
            while(1)
            {
                cin>>password;
                if(is_valid_password(password))
                break;
                cout<<"enter your valid password "<<endl;
            }
            signup s(fname,lname,email,password);
}
/*******************************login****************************************/
bool is_valid_login(string e,string p);
bool log_in()
{
    while(1)
    {
        string e,p;
        int i=0;
        cout<<"email id:";
        cin>>e;
        cout<<"password:";
        cin>>p;
        if(is_valid_login(e,p))
        {
          cout<<"\nlogin success full";
          break;
        }
        else
        {
            cout<<"\neither you email or password is wrong";
            while(1)
            {
                char choice;
                cout<<"type 'y' for re-enter or 'n' for main menu:";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    i++;
                    if(i==3)
                    {
                     cout<<"\ntoo many attemp try again";
                    return 0;
                    }
                    break;;
                }  
                else if(choice=='n'||choice=='N')
                {
                  return 0;
                }
                else
                {
                  continue;
                }
            }
        }

        
    }
    return 1;

}
bool is_valid_login(string e,string p)
{
    int count;
    string fname,lname,email,password;
    ifstream fin("login_details",ios::in);
    while(fin>>count>>fname>>lname>>email>>password)
    {
        cout<<fname<<endl;
        if(email==e&&password==p)
        {
            cout<<"match found"<<endl;
            return 1;
        }
    }
    return 0;


}
void reset_pass()
{
    int pos,count,i;
    string fname,lname,email,password,e;
    i=0;
    while(1)
    {
        pos=0;
        cout<<"\nenter you email:";
        cin>>e;
        i++;
        if(i==3)
        {
            cout<<"\ntoo many attemp try again";
            return;
        }
        if(!is_valid_email(e))
        continue;
        ifstream fin("login_details",ios::in);
        while(fin>>count>>fname>>lname>>email)
        {
          
          if(email==e)
          {
             pos=fin.tellg();
             break;
          }
          fin>>password;
        }
       fin.close();
        if(pos)
        break;
     
    }
    cout<<pos;
    pos=pos+1;
    fstream file("login_details",ios::in|ios::out);
    file.seekp(pos);
    i=0;
    while(1)
    {
        cout<<"\nenter password:";
        cin>>password;
        if(is_valid_password(password))
        break;
        i++;
        if(i==3)
        {
            cout<<"\ntoo many attemp try again";
            return;
        }
        
    }
    file<<password;
    i=20;
    char ch;
    pos=file.tellp();
    while((ch=file.get())!='\n')
    {
        file.seekp(pos);
        file.put(' ');
        pos++;

    }
    file.close();

}
int main()
{
    while(1)
    {
        cout<<"\n********************MAIN MENU***************************";
        cout<<"\n1.login \n2.signup \n3.reset password\n4.exit";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:log_in();
            break;

            case 2:sign_up();
            break;

            case 3:
            reset_pass();
                   break;

            case 4:
                 exit(0);
                 break;
        }

    }
}