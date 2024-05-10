/****************************************************************************
			  HEADER FILES
****************************************************************************/

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
#include<iomanip.h>

/****************************************************************************
			  HEADER FILES
****************************************************************************/

class banking
{
   char name[20], ph_no[15], address[25], add_prf[20], city[30];
   int age, acc_no;
   double amount;
   public:
     void getdata();
     void putdata();
     void showdata();
     void create_acc();
     void update_acc();
     void modify();
     void deposit();
     void withdraw();
     void spec_acc();
     void close();
     void display();
     int getacc()      //accessor function
     {
       return acc_no;
     }
}ob,ob1;

int acc;
char choice;
void menu();
void welcome();
void login();
void last();

void main()
{
  clrscr();
  welcome();         //calling of welcome func
  login();
  menu();
  getch();
}

void welcome()         //func definition of welcome
{
  clrscr();
  int gdriver=DETECT, gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  setcolor(1);
  setcolor(GREEN);
  settextstyle(1,0,6);
  outtextxy(85,40,"Bank Management");
  setcolor(15);
  rectangle(80,170,560,320);
  setcolor(1);
  rectangle(100,180,540,310);
  setcolor(RED);
  settextstyle(1,0,6);
  outtextxy(205,210,"WELCOME");
  settextstyle(6,0,2);
  outtextxy(400,350,"-By Jagrit Goyal");
  outtextxy(425,380,"Class X I I 'B'");
  getch();
  closegraph();
}

void login()       //func definition of login
{
  clrscr();
  int gdriver = DETECT, gmode;

  int i;
  char user[10], pass[10];
  for(i=0;i<2;i++)
  {
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   settextstyle(10,0,3);
   setcolor(3);
   outtextxy(190,50,"LOGIN PAGE");
   setcolor(15);
   rectangle(20,20,600,450);
   rectangle(120,150,480,240);
   rectangle(123,153,477,195);
   settextstyle(7,0,2);
   setcolor(14);
   outtextxy(133,160,"Enter User ID - ");
   gotoxy(40,11);
   cin>>user;
   setcolor(15);
   rectangle(123,197,477,237);
   setcolor(14);
   outtextxy(133,200,"Enter Password - ");
   gotoxy(43,14);
   for(i=0;i<10;i++)
   {
     pass[i]=getch();
     if(int(pass[i])==13)
     {
	pass[i]='\0';
	break;
     }
     cout<<"*";
   }
   if(strcmp(pass,"olopcs")==0 && strcmp(user,"olopcs")==0)
   {
      settextstyle(8,0,2);
      setcolor(11);
      outtextxy(200,270,"Correct");
      getch();
      clrscr();
      menu();
   }
   else
   {
      settextstyle(8,0,2);
      setcolor(11);
      outtextxy(200,270,"Incorrect");

      getch();
      continue;
   }
  closegraph();

  }
  exit(0);
}
void menu()                 //func definition of menu
{
  int choice;
  clrscr();
  int gdriver = DETECT, gmode;

  while(1)
  {
    initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
    rectangle(140,10,490,65);
    setcolor(14);
    rectangle(160,20,470,55);
    setcolor(WHITE);
    settextstyle(1,0,2);
    outtextxy(250,25,"MAIN MENU");

    settextstyle(6,0,1);
    setcolor(15);
    rectangle(30,90,300,130);
    setcolor(4);
    outtextxy(70,95,"1. Create New Account");
    setcolor(15);
    rectangle(305,90,585,130);
    setcolor(5);
    outtextxy(340,95,"2. Update Existing Account");

    setcolor(15);
    rectangle(30,135,300,175);
    setcolor(2);
    outtextxy(120,140,"3. Deposit");
    setcolor(15);
    rectangle(305,135,585,175);
    setcolor(6);
    outtextxy(395,140,"4. Withdraw");

    setcolor(15);
    rectangle(30,180,300,220);
    setcolor(7);
    outtextxy(65,185,"5. Check Specific Account");
    setcolor(15);
    rectangle(305,180,585,220);
    setcolor(4);
    outtextxy(360,185,"6. Display All Accounts");

    setcolor(15);
    rectangle(30,225,300,265);
    setcolor(9);
    outtextxy(95,230,"7. Delete Account");
    setcolor(15);
    rectangle(305,225,585,265);
    setcolor(10);
    outtextxy(420,230,"8. Exit");

    setcolor(14);
    settextstyle(2,0,6);
    outtextxy(100,300,"Enter your choice = ");
    gotoxy(39,20);
    cin>>choice;

    closegraph();
    switch(choice)
    {
      case 1:ob.create_acc();
	     break;
      case 2:ob.update_acc();
	     break;
      case 3:ob.deposit();
	     break;
      case 4:ob.withdraw();
	     break;
      case 5:ob.spec_acc();
	     break;
      case 6:ob.display();
	      getch();
	     break;
      case 7:ob.close();
	     break;
      case 8:last();
	     exit(0);
	     break;
      default:cout<<"\n\t\t\tInvalid Choice";
	      cout<<"\n\n\t\tEnter again = ";
    }
  }
}

void banking:: create_acc()          //func definition of create acc
{
  clrscr();
  ofstream fout("banking.dat",ios::app|ios::binary);
  textattr(15);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t";
  cprintf("   CREATE ACCOUNT FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  ob1.getdata();
  fout.write((char *)&ob1,sizeof(ob1));
  fout.close();
  textattr(2);
  cout<<"\n\n\t";
  cprintf("   Your Account Has Been Created...!!");
  getch();
  textattr(15);
}

void banking:: getdata()
{
  ifstream fin("banking.dat",ios::in|ios::binary);
  if(fin.eof())
    acc_no=1;
  else
  while(fin.read((char *)&ob,sizeof(banking)));
    acc_no=ob.acc_no+1;
  textattr(4);
  cout<<"\n\n\n\n\t";
  cprintf("Account no. = ");
  textattr(1);
  cout<<acc_no;
  textattr(4);
  cout<<"\n\n\t";
  cprintf("Enter Name of the Account Holder= ");
  textattr(1);
  gets(name);
  textattr(4);
  cout<<"\n\t";
  cprintf("Enter Address = ");
  textattr(1);
  gets(address);
  textattr(4);
  cout<<"\n\t";
  cprintf("Enter City = ");
  textattr(1);
  gets(city);
  textattr(4);
  cout<<"\n\t";
  cprintf("Enter Age = ");
  textattr(1);
  cin>>age;
  textattr(4);
  cout<<"\n\t";
  cprintf("Enter Phone no. = ");
  textattr(1);
  cin>>ph_no;
  textattr(4);
  cout<<"\n\t";
  cprintf("Address proof submittied = ");
  textattr(1);
  gets(add_prf);
  textattr(4);
  cout<<"\n\t";
  cprintf("Initial Deposit = ");
  textattr(1);
  cin>>amount;
  fin.close();
}

void banking:: update_acc()             //func definition of update acc
{
  clrscr();
  fstream finout("banking.dat",ios::out|ios::in|ios::binary);
  int found=0;
  long pos;
  textattr(3);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t\t";
  cprintf("UPDATE FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  cout<<"\n\n\tEnter your Account no. = ";
  cin>>acc;
  while(!finout.eof())
  {
    pos=finout.tellg();
     finout.read((char *)&ob,sizeof(banking));
      if(acc==ob.acc_no)
      {
	 cout<<"\n\t\t----Your account details are:----\n\n";
	 ob.putdata();
	 ob.modify();
	 finout.seekg(pos);
	 finout.write((char *)&ob,sizeof(banking));
	 found=1;
	 break;
      }
  }
  if(found)
    cout<<"\n\t\tRecord Updated successfully...!!";
  else
    cout<<"\n\t\tRecord not found...!!\n";
  finout.close();
  getch();
  textattr(15);
}

void banking:: modify()
{
  char nm[25], adrs[30], ct[20], ph[15];
  cout<<"\n\n\tEnter a new Name(Enter '.' to retain the old one) = ";
  gets(nm);
  cout<<"\tEnter a new Address(Enter '.' to retain the old one) = ";
  gets(adrs);
  cout<<"\tEnter a new City(Enter '.' to retain the old one) = ";
  gets(ct);
  cout<<"\tEnter a new Phone no.(Enter '-' to retain the old one) = ";
  cin>>ph;
  if(strcmp(nm,".")!=0)
    strcpy(ob.name,nm);
  if(strcmp(adrs,".")!=0)
    strcpy(ob.address,adrs);
  if(strcmp(ct,".")!=0)
    strcpy(ob.city,ct);
  if(strcmp(ph,"-")!=0)
    strcpy(ob.ph_no,ph);
}

void banking:: deposit()              //func definition of deposit
{
  clrscr();
  fstream finout("banking.dat",ios::in|ios::out|ios::binary);
  int found=0;
  long pos;
  double dep_amt;
  textattr(5);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t";
  cprintf("       DEPOSIT FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  textattr(15);
  cout<<"\n\n\tEnter your Account no. = ";
  cin>>acc;
  while(!finout.eof())
  {
      pos=finout.tellg();
      finout.read((char *)&ob, sizeof(banking));
    if(ob.acc_no==acc)
    {
      found=1;
      cout<<"\n\n\t\t----Your account details are:----\n\n";
      ob.putdata();
      cout<<"\n\n\tEnter the Amount you want to Deposit = ";
      cin>>dep_amt;
      cout<<"\n\n\t\t\tAmount Deposited Successfully...!! ";
      ob.amount+=dep_amt;
      finout.seekg(pos);
      finout.write((char *)&ob, sizeof(banking));
      finout.close();
      cout<<"\n\nYour Balance after Deposit = "<<ob.amount;
      getch();
      textattr(15);
      break;
    }
  }
  if(!found)
  {
     cout<<"\n\n\tWrong Account no.";
     getch();
     textattr(15);
  }
}

void banking:: withdraw()             //func definition of withdraw
{
  clrscr();
  fstream finout("banking.dat",ios::in|ios::out|ios::binary);
  int found=0;
  long pos;
  double draw_amt;
  textattr(12);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t";
  cprintf("     WITHDRAW FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  cout<<"\n\n\tEnter your Account no. = ";
  cin>>acc;
  while(!finout.eof())
  {
    pos=finout.tellg();
    finout.read((char *)&ob, sizeof(banking));
    if(acc_no==acc)
    {
      cout<<"\n\n\t\t----Your account details are:----\n\n";
      ob.putdata();
      cout<<"\n\n\tEnter the Amount you want to Withdraw = ";
      cin>>draw_amt;
      found=1;
      if(draw_amt<=ob.amount)
      {
	ob.amount-=draw_amt;
	finout.seekg(pos);
	finout.write((char *)&ob, sizeof(banking));
	finout.close();
	cout<<"\n\n\t\t\tAmount Withdrawn Successfully...!!";
	cout<<"\n\nYour Balance after withdraw = "<<ob.amount;
	getch();
	textattr(15);
	break;
      }
      else
      {
	cout<<"\nInsufficient Balance...!!";
	getch();
	textattr(15);
	break;
      }
    }
  }
  if(!found)
  {
      cout<<"\n\n\tWrong Account no.";
      getch();
      textattr(15);
  }
}

void banking:: spec_acc()           //func definition of check bal
{
  clrscr();
  int found=0;
  ifstream fin("banking.dat",ios::in|ios::binary);
  textattr(2);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t";
  cprintf("    SPECIFIC FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  textattr(4);
  cout<<"\n\n\t";
  cprintf("Enter your Account no. = ");
  textattr(15);
   cin>>acc;
  while(fin.read((char *)&ob, sizeof(banking)))
  {
    if(acc==ob.acc_no)
    {
      textattr(3);
      cout<<"\n\t\t";
      cprintf("----Your account details are:----");
      cout<<"\n";
      ob.putdata();
      found=1;
      fin.close();
      getch();
      textattr(15);
    }
  }
  if(found==0)
  {
    cout<<"\nWrong Account no.";
    textattr(15);
    getch();
  }
}

void banking:: display()
{
  clrscr();
  ifstream fin("banking.dat",ios::in|ios::binary);
  textattr(2);
  cprintf("*******************************************************************************");
  cout<<"\n\t\t\t";
  cprintf("     DISPLAY FUNCTION");
  cout<<"\n";
  cprintf("*******************************************************************************");
  if(!fin)
  {
    cout<<"\n\nFile could not open\n";
    getch();
    textattr(15);
    menu();
  }
  else
  {
  textattr(14);
  cout<<"\n\n";
  cprintf("--------------------------------------------------------------------------------");
  textattr(4);
  cprintf("| Acc.no. |");
  cout<<setw(10);
  cprintf("   Name   |");
  cout<<setw(13);
  cprintf("   Address   |");
  cout<<setw(11);
  cprintf("   City   |");
  cout<<setw(9);
  cprintf("  Age  |");
  cout<<setw(13);
  cprintf("  Phone no.  |");
  cout<<setw(10);
  cprintf(" Balance  |");
  textattr(14);
  cprintf("--------------------------------------------------------------------------------");

  while(fin.read((char *)&ob,sizeof(banking)))
  {
    ob.showdata();
  }
  }
  fin.close();
  getch();
  textattr(15);
}

void banking:: close()         //func definition of delete acc
{
  clrscr();
  ifstream fin("banking.dat",ios::in|ios::binary);
  ofstream fout("temp.dat",ios::out|ios::binary);
  char ans='y', found='f';
  cout<<"*******************************************************************************";
  cout<<"\n\t\t\t     DELETE FUNCTION";
  cout<<"\n*******************************************************************************";
  textattr(2);
  cout<<"\n\n\t";
  cprintf("Enter your Account no. = ");
  cin>>acc;
  while(fin.read((char *)&ob, sizeof(banking)))
  {
    if(acc==ob.acc_no)
    {
       cout<<"\n\t\t";
       cprintf("----Your account details are:----");
       cout<<"\n";
       ob.putdata();
       found='t';
       cout<<"\n\n\tAre you sure you want to delete your Account ?(Y/N) : ";
       cin>>ans;
       if(ans=='n'||ans=='N')
       {
	 fout.write((char *)&ob, sizeof(banking));
	 cout<<"\n\n\t\tAccount deletion denied...!!";
       }
       else
	 cout<<"\n\n\tAccount deleted successfully..!!";
    }
    else
     fout.write((char *)&ob, sizeof(banking));
  }
  if(found=='f')
    cout<<"\n\n\t\tRecord not found...!!";
  fin.close();
  fout.close();
  remove("banking.dat");
  rename("temp.dat","banking.dat");
  getch();
  textattr(15);
}

void last()         //func definition of last page
{
  clrscr();
  int gdriver=DETECT, gmode;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  setcolor(14);
  rectangle(40,50,580,180);
  setcolor(15);
  rectangle(60,60,560,170);
  setcolor(2);
  settextstyle(1,0,6);
  outtextxy(160,80,"THANK YOU");
  settextstyle(10,0,5);
  setcolor(BLUE);
  outtextxy(80,210,"VISIT");
  outtextxy(170,310,"AGAIN");
  setcolor(RED);
  circle(500,300,60);
  setcolor(WHITE);
  settextstyle(0,0,1);
  outtextxy(473,280,"(') (')");
  outtextxy(492,300,"||");
  outtextxy(482,320,"\\___/");
  getch();
  closegraph();
}

void banking:: putdata()
{
  textattr(14);
  cprintf("Account no = ");
  textattr(15);
  cout<<acc_no;
  cout<<"\n";
  textattr(14);
  cprintf("Name = ");
  textattr(15);
  cout<<name;
  cout<<"\n";
  textattr(14);
  cprintf("Address = ");
  textattr(15);
  cout<<address;
  cout<<"\n";
  textattr(14);
  cprintf("City = ");
  textattr(15);
  cout<<city;
  cout<<"\n";
  textattr(14);
  cprintf("Age = ");
  textattr(15);
  cout<<age;
  cout<<"\n";
  textattr(14);
  cprintf("Phone no = ");
  cout<<ph_no;
  textattr(15);
  cout<<"\n";
  textattr(14);
  cprintf("Balance = ");
  textattr(15);
  cout<<amount;
}

void banking:: showdata()
{
  textattr(15);
  cout<<setw(6)<<acc_no;
  cout<<setw(13)<<name;
  cout<<setw(14)<<address;
  cout<<setw(11)<<city;
  cout<<setw(7)<<age;
  cout<<setw(15)<<ph_no;
  cout<<setw(10)<<amount<<"\n";
}
