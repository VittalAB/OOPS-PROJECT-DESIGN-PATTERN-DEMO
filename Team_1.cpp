#include<iostream>
#include<bits/stdc++.h>
#include<exception>
using namespace std;

class game{
    public:
    friend class football;
    vector<string>a,b;
    string lname;
    int goal1,goal2;

    virtual void start()=0;
    virtual void sim(int)=0;
    virtual void half_time()=0;
    virtual void end()=0;
    int r=1;

    void play(vector<string>t1,vector<string>t2)
    {
        for(int i=0;i<t1.size();i++)
        {
            a.push_back(t1[i]);
            b.push_back(t2[i]);
        }
        start();
        sim(r);
        half_time();
        end();
    }
};

class practice : public game{
    public:
    void start()
    {
        cout << "team members are :- \n" ;
        for(int i=0;i<a.size();i++)
        {
            cout <<"  TEAM 1. "<< a[i] << " \t " <<"  TEAM 2. "<<b[i] << endl;
        }
        cout << "practice match started \n";
    }
    void sim(int remove_name)
    {
        goal1=0;
        goal2=0;
        cout<<"\n\n     MATCH STARTED  "<<endl<<endl;
        int count=0;
        int x;
        while(count!=5)
        {

            cout << "1. goal a   2. goal b" << endl;
            cin >> x;
            if(x==1)
            {
                cout << "Team1 made a goal \n";
                goal1++;
            }
            else if(x==2)
            {
                cout << "Team 2 made a goal \n";
                goal2++;
            }
            else
            {
                break;
            }
            count++;
        }
    }

    void half_time()
    {
        cout << "\n\nHalf time given team should change side \n\n";
        cout << "Current minutes passed :- 45 min \n";
        cout << "\n\n\nHALF TIME RESULTS ARE :- \n"<<endl;
        cout << "NUMBER OF GOALS BY TEAM 1---- " << goal1 <<endl;
        cout << "NUMBER OF GOALS BY TEAM 2---- " << goal2 << endl<<endl<<endl<<endl;
        cout<<  "HALF TIME OVER "<<endl;
    }
    void end()
    {
        int g1,g2;
        g1=goal1;
        g2=goal2;
        int r;
        sim(r);
        cout << "\n\n\nEND RESULTS OF THE MATCH IS :- " << endl;
        cout << "\n\nNO OF GOALS BY TEAM 1  :-   " << g1+goal1;
        cout << "\n\nNO OF GOALS BY TEAM 2  :-   " << g2+goal2 << endl;
        if(g1+goal1 > g2+goal2){
        cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n      ******  TEAM 1 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;}
        else if(g1+goal1 == g2+goal2){
        cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^OOPS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n              ******  MATCH DRAWN  ******* \n";
        }


        else
        {
            cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
            cout << "\n      ******  TEAM 2 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;


        }

    }
};


class league : public game{
    public:
    void start()
    {
        cout << "league match started \n";
    }
    void sim(int remove_name)
    {
        goal1=0;
        goal2=0;
        if(!remove_name)
        {


        cout << "Enter league name " << endl;
        lname;
        cin >> lname;}

        int count=0;
        int x;
        while(count!=5)
        {
            cout << "1. goal a   2. goal b" << endl;
            cin >> x;
            if(x==1)
            {
                cout << "Team1 made a goal \n";
                goal1++;
            }
            else if(x==2)
            {
                cout << "Team 2 made a goal \n";
                goal2++;
            }
            else
            {
                break;
            }
            count++;

        }
    }
    void half_time()
    {
         cout << "\n\nHalf time given team should change side \n\n";
        cout << "Current minutes passed :- 45 min \n";
        cout << "\n\n\nHALF TIME RESULTS ARE :- \n"<<endl;
        cout << "NUMBER OF GOALS BY TEAM 1---- " << goal1 <<endl;
        cout << "NUMBER OF GOALS BY TEAM 2---- " << goal2 << endl<<endl<<endl<<endl;
        cout<<  "HALF TIME OVER "<<endl;
        cout<<"   MATCH STARTED AGAIN"<<endl<<endl<<endl;
    }
    void end()
    {
        int g1,g2;
        g1=goal1;
        g2=goal2;
        int remove_name=1;
        sim(remove_name);

        cout << "END RESULTS OF THE MATCH IS :- " << endl;
        cout << "\n\nNO OF GOALS BY TEAM 1  :-   " << g1+goal1 << endl;
        cout << "\n\nNO OF GOALS BY TEAM 2  :-   " << g2+goal2 << endl;
        if(g1+goal1 > g2+goal2){
        cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n       ******  TEAM 1 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;}
        else if(g1+goal1 == g2+goal2){
        cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^OOPS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n              ******  MATCH DRAWN  ******* \n";
        cout<<"LET'S HAVE A PENALTY KICK MATCH"<<endl;
            penalty();
        }
        else
        {
            cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
            cout << "\n      ******  TEAM 2 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;


        }

    }
    void penalty()
    {
        goal1=0;
        goal2=0;
        int count=0;
        int x;

        while(count!=3)
        {

            cout << "1. goal a   2. goal b" << endl;
            cin >> x;
            if(x==1)
            {
                cout << "Team1 made a goal \n";
                goal1++;
            }
            else if(x==2)
            {
                cout << "Team 2 made a goal \n";
                goal2++;
            }
            else
            {
                break;
            }
            count++;

        }
        end_penalty();
    }
    void end_penalty()
    {
        int g1,g2;
        g1=goal1;
        g2=goal2;
       cout << "END RESULTS OF THE MATCH IS :- " << endl;
        cout << "\n\nNO OF GOALS BY TEAM 1  :-   " << g1 << endl;
        cout << "\n\nNO OF GOALS BY TEAM 2  :-   " << g2 << endl;
        if(g1 > g2){
        cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n      ******  TEAM 1 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;
        }
        else if(g1==g2)
        {
            cout<<"Match drawn"<<endl;
        }
        else{
        cout<< "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^HURRAYY!!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n      ******  TEAM 2 HAS WON THE MATCH  ******* \n"<<endl<<endl<<endl;}
    }

};

class win{
    public:
    string tname,name;
    int year;
    void read(string n,string m,int d)
    {
        tname=n;
        name=m;
        year=d;
    }
    void display()
    {
        cout<<"          ****  DISPLAYING WINNER DETAILS  ****\n"<<endl;
        cout << "team name :- " << tname << endl;
        cout << "League name :- " << name << endl;
        cout << "year :- " << year << endl;
    }
};

class ground{
    public:
    string name,loc;
    int cap,size;
    void read(string n,string m,int d,int d1)
    {
        name=n;
        loc=m;
        cap=d;
        size=d1;
    }
    void display()
    {
        cout<<"          ****  DISPLAYING  STADIUM DETAILS  ****\n"<<endl;
        cout << "Stadium name :- " << name << endl;
        cout << "Stadium location :- " << loc << endl;
        cout << "Stadium size :- " << size << endl;
        cout << "Stadium capacity  :- " << cap << endl;

    }
};


class chairman{
    public:
    string name,sex;
    int age;
    void read(string name,string sex,int age)
    {
        this->name=name;
        this->sex=sex;
        this->age=age;
    }
    void display()
    {
        cout<<"          **** CHAIRMAN DETAILS ****\n"<<endl;
        cout << "Name :- " << name << endl;
        cout << "\nSex :- " << sex << endl;
        cout << "\nAge :- " << age << endl<<endl;
    }
};

class atagar{
    public:
    string name,tname;
    float h;
    int gol,age;
    void read(string name,string tname,float h,int gol,int age)
    {
        this->name=name;
        this->tname=tname;
        this->h=h;
        this->gol=gol;
        this->age=age;
    }
    void display()
    {
        cout<<"          ****  DISPLAYING PLAYER DETAILS  ****\n"<<endl;
        cout << "Player name :- " << name << endl<<endl;
        cout << "Team name :- " << tname << endl<<endl;
        cout << "Height of player :- " << h << endl<<endl;
        cout << "Number of goals in domestic matches :- " <<gol << endl<<endl;
        cout << "Age of player :- " << age << endl<<endl;
    }
};
    vector<win>w;
    vector<ground>g;
    vector<chairman>p;
    vector<atagar>player_arr;
    vector<string>t1,t2;

class X_FootballClub{
    public:

    virtual void add()=0;
    virtual void display()=0;
};

class yearexception:public exception
{
public:
    const char* what()  const throw()
    {
        return "Year is negative\n";
    }
};

class choiceexception:public exception
{
public:
    const char* what()  const throw()
    {
        return "You have entered wrong choice\n                                               Please enter choice between 1 to 11";
    }
};

class ageexception:public exception
{
    public:
        const char* what()  const throw()
        {
            return "Age is negative\n";

        }

};


class Winner:public X_FootballClub{
      void add()
      {
          win w1;
          string t1,t2;
          int d;
          cout<<"          ****  ADDING WINNER DETAILS  ****\n"<<endl;

          cout << "enter team name"<<endl;
           cin >> t1;
          cout<<"league name"<<endl;
          cin>> t2 ;
          cout<<"year " << endl;
          cin >> d;
          if(d<0)
            throw yearexception();

          w1.read(t1,t2,d);
          w.push_back(w1);
      }
      void display()
      {
          for(int i=0;i<w.size();i++)
          {

              w[i].display();
          }
      }
};
class stadium:public X_FootballClub{
    void add(){
        ground g1;
        string n1,n2;
        int d1,d2;
        cout<<"          ****  ADDING STADIUM DETAILS  ****\n"<<endl;
        cout << "Enter stadium name"<<endl;
        cin>>n1;
        cout<<"Enter stadium location"<<endl;
        cin>>n2;
        cout<<"Enter stadium size"<<endl;
        cin>>d1;
        cout<<"Enter stadium capacity" << endl;
        cin >>  d2;
        g1.read(n1,n2,d1,d2);
        g.push_back(g1);
    }
    void display()
    {
        for(int i=0;i<g.size();i++)
          {
              g[i].display();
          }
    }
};

class president : public X_FootballClub{
    void add(){
        chairman c1;
        string name,sex;
        int age;
        cout<<"          ****  ADDING CHAIRMAN DETAILS  ****\n"<<endl;
        cout << "enter name "<<endl;
        cin >> name;
        cout<<"\nsex"<<endl;
        cin >> sex;
        cout<<"\nage" << endl;
        cin >> age;
        if(age<0)
    throw ageexception();


        c1.read(name,sex,age);
        p.push_back(c1);
    }
    void display()
    {
        for(int i=0;i<p.size();i++)
        p[i].display();
    }
};

class player : public X_FootballClub{

    void add(){
        string name,t_name;
         int no_of_goals,age,c=3;
         atagar a;
cout<<"          ****  ADDING PLAYER DETAILS  ****\n"<<endl;
         cout << "Enter name :" << endl;
cin >> name;

cout << "Enter height :- " << endl;
float h;
cin >> h;
cout << "Enter team he plays:" << endl;
cin >> t_name;
if(t_name=="argentina")
{
    t1.push_back(name);
}
else if(t_name=="barcelona")
{
    t2.push_back(name);
}
cout << "Enter his age:" << endl;
cin >> age;
if(age<0)
    throw ageexception();

cout << "Number of goals in domestic matches:" << endl;
cin >> no_of_goals;

cout <<  "   ***************  SKILL TEST  ***************** \n" << endl;

cout << "~~~~~~~~~~~~~~~~~ TEST 1  :- GOAL AT LEAST 3 TIMES ~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
cout<<"______________________________________________________________________________"<<endl<<endl;
int count=5;
while(count--)
{
cout << "1 goal     2.duck " << endl;
int x;
cin >> x;
if(x==1)
{
    c--;
    if(c<=0)
    {
       cout<<" '''''''''''''''''''  GOAL TEST COMPLETED  ''''''''''''''''''''''"<<endl;
       break;
    }
    else{
     cout << "Bingo you made a goal, "<< c << " goals away" << endl;
    }

}
else if(x==2)
cout << "Hard time , try next " << endl;
else
{
cout<<"GOAL TEST FAILED"<<endl;
break;
}
}
cout<<"\n\n\n";
cout << "       *************  FITNESS TEST  *************** " << endl;

cout << "Do you have motor skill " << endl;
int x;
cin >> x;
cout << "Do you have cognitive skill "<< endl;
int y;
cin >> y;

cout << "Do you have good perception skills " << endl;
int z;
cin >> z;



if(x&&y&&z)
cout << " #######################################  EXCELENT SKILL SET  ############################################ " << endl<<endl<<endl;
else
cout << "########################################  AVERAGE SKILL SET  ############################################ " << endl;

    a.read(name,t_name,h,no_of_goals,age);
    player_arr.push_back(a);
    }


    void display()
    {
        for(int i=0;i<player_arr.size();i++)
        player_arr[i].display();
    }
};


class football{
    public:
    friend class game;

    X_FootballClub *ptr;
    football(){}
    football(X_FootballClub *s)
    {
        ptr=s;
    }
    void add()
    {
        ptr->add();
    }
    void display()
    {
        ptr->display();
    }
    void display_team()
    {
        cout<<"       ******  DISPLAYING TEAM  *******"<<endl<<endl;
        cout << "team 1 details \n"<<endl;

        for(int i=0;i<t1.size();i++)
        cout << i+1<<"\t"<<t1[i] << endl;

        cout << "\n\nTeam 2 details \n"<<endl;
        for(int i=0;i<t2.size();i++)
        cout <<i+1<<"\t"<< t2[i] << endl;


    }
    void play_game()
    {
        game *g;
        cout << "         *******  WELCOME TO GAME  *******" << endl;
        for(;;)
        {
        cout << " 1.Practice match  \t  2.League match   \t  3.Quit\n";
        int x;
        cin >> x;
        if(x==1)
        {
            g=new practice;
            g->play(t1,t2);
        }
        else if(x==2)
        {
            g=new league;
            g->play(t1,t2);
        }
        else
        break;
        }

    }

};

int main()
{
    football *ptr;
    string s;
    s="vittal";
    t1.push_back(s);
    s="prasanna";
    t1.push_back(s);
     s="manish";
    t1.push_back(s);
    s="suresh";
    t1.push_back(s);
     s="mahesh";
    t1.push_back(s);
    s="ramesh";
    t1.push_back(s);
     s="david";
    t1.push_back(s);
    s="raj   ";
    t1.push_back(s);
     s="abhishek";
    t1.push_back(s);
    s="anil   ";
    t1.push_back(s);
    s="sunil  ";
    t1.push_back(s);

    s="gayle";
    t2.push_back(s);
    s="klrahul";
    t2.push_back(s);
    s="anand";
    t2.push_back(s);
    s="jayant";
    t2.push_back(s);
    s="rajesh";
    t2.push_back(s);
    s="krishna";
    t2.push_back(s);
    s="prasad";
    t2.push_back(s);
    s="raghu";
    t2.push_back(s);
    s="ravi";
    t2.push_back(s);
    s="sumukh";
    t2.push_back(s);
    s="kartick";
    t2.push_back(s);

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t---------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t|                       FOOTBALL                         |"<<endl;
    cout<<"\t\t\t\t\t|                       MANAGEMENT                       |"<<endl;
    cout<<"\t\t\t\t\t|                       CLUB                             |"<<endl;
    cout<<"\t\t\t\t\t|                       SYSTEM                           |"<<endl;
    cout<<"\t\t\t\t\t|                       IN C++                           |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------------------------"<<endl;
    cout<<"\n\n\n\n";
    cout<<"\t\t*************************************************************************************************************\n";
    cout<<"\t\t*************************************************************************************************************\n";
    cout<<"\t\t*************************                                               *************************************\n";
    cout<<"\t\t*************************     WELCOME TO FOOTBAL MANAGEMENT SYSTEM      *************************************\n";
    cout<<"\t\t*************************                                               *************************************\n";
    cout<<"\t\t*************************************************************************************************************\n";
    cout<<"\t\t*************************************************************************************************************\n"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    while(1){


        cout<<"\n\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           1.ADD STADIUM                        |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           2.DISPLAY STADIUM                    |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           3.ADD CHAIRMAN                       |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           4.DISPLAY CHAIRMAN                   |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           5.PLAY A GAME                        |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           6.ADD  PLAYER                        |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           7.DISPLAY PLAYER                     |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           8.GET TEAM                           |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           9.ADD WINNER LIST                    |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           10.GET WINNER LIST                   |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"\t\t\t             |                           11.QUIT                              |\n";
        cout<<"\t\t\t              ================================================================\n";
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

        cout<<"\n\n\t\t\t                                      ENTER CHOICE:----                         \n";

        int x;
        cin>>x;
 try{


        if(x==1)
        {
            ptr=new football(new stadium);
            ptr->add();
        }
        else if(x==2)
        {
            football *p1;
            p1=new football(new stadium);
            p1->display();

        }
        else if(x==3)
        {
            football *p2;
            p2=new football(new president);
            p2->add();

        }
        else if(x==4)
        {
            ptr=new football(new president);
            ptr->display();

        }
        else if(x==5)
        {
            ptr=new football;
            ptr->play_game();
        }
        else if(x==6)
        {
            ptr=new football(new player);
            ptr->add();
        }
        else if(x==7)
        {
            ptr=new football(new player);
            ptr->display();
        }
        else if(x==8)
        {
            ptr=new football;
            ptr->display_team();
        }
        else if(x==9)
        {
            ptr=new football(new Winner);
            ptr->add();
        }
         else if(x==10)
        {
            ptr=new football(new Winner);
            ptr->display();
        }

         else if(x==11)
        {
           exit(333);
        }

        else
        {
            if(x<=0 || x>11)
               throw choiceexception();
        }

    }

     catch(choiceexception &c)
    {
        cout<<"\n                         !!!!!!!!!! EXCEPTION:  "<<c.what()<<endl;
    }

    catch(ageexception &a)
    {
       cout<<"\n                         !!!!!!!!!! EXCEPTION:  "<<a.what()<<endl;
    }

    catch(yearexception &y)
    {
        cout<<"\n                         !!!!!!!!!! EXCEPTION:  "<<y.what()<<endl;
    }
    }



    return 0;
}

