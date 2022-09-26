#include<iostream>
using namespace std;

string name[10000];
int age[10000];
double salary[10000];
char gender[10000];
int added=0;

void read_employee()
{
    cout<<"enter name:";
    cin>>name[added];

    cout<<"enter age:";
    cin>>age[added];

    cout<<"enter salary:";
    cin>>salary[added];

    cout<<"enter gender:";
    cin>>gender[added];

    added++;

}

void print_employee()
{
    for(int i=0;i<added;i++)
    {
        if(age[i]!=-1)
        {
            cout<<name[i]<<" "<<age[i]<<" "<<salary[i]<<" "<<gender[i]<<endl;
        }
    }
}

void delete_by_age()
{
    cout<<"enter start and end age: ";
    int start,end;
    cin>>start>>end;
    for(int i=0;i<added;i++)
    {
        if(age[i]>=start&&age[i]<=end)
        {
            age[i]=-1;
        }
    }
}

void update_salary_by_name()
{
    cout<<"enter the name and salary: ";
    string nam;
    double sal;
    cin>>nam>>sal;
    bool is_found=false;
    for(int i=0;i<added;i++)
    {
        if(age[i]!=-1&&name[i]==nam)
        {
            is_found=true;
            salary[i]=sal;
            break;
        }
    }
    if(is_found==false)
    {
        cout<<"no employee with this name\n";
    }
}

int menue()
{
    int ch=-1;
    while(ch==-1)
    {
        cout<<"enter your choice:"<<endl;
        cout<<"1) add new employee"<<endl;
        cout<<"2) print all employees"<<endl;
        cout<<"3) delete by age"<<endl;
        cout<<"4) update salary by name"<<endl;
        cout<<"5) exit"<<endl;
        cin>>ch;
        if(!(ch>=1||ch<=5))
           {
               cout<<"invalid choice,try again"<<endl<<endl;
               ch=-1;
           }
    }
    return ch;
}

void employee_system()
{
    while(true)
    {
        int choice=menue();
        if(choice==1)
        {
            read_employee();
        }
        else if(choice==2)
        {
            print_employee();
        }
        else if(choice==3)
        {
            delete_by_age();
        }
        else if(choice==4)
        {
            update_salary_by_name();
        }
        else
        {
            cout<<"thank you";
            break;
        }
    }
}

int main() {
	employee_system();
	return 0;
}
