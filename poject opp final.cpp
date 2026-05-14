#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
void my_intro()// function for show what type of  hotel system  and our names
{
	    cout << "\n\n";
	cout<<setw(98)<<"HOTEL RESERVATION SYSTEM "<<endl;
	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*"<<endl;
	cout<<setw(20)<<"MADE BY : "<<endl;
	cout<<setw(30)<<"MUNEEB ALI"<<endl;
	cout<<setw(33)<<"ZAID BIN NAEEM"<<endl;
	cout<<setw(32)<<"TAYYAB JAVEID"<<endl;
	cout<<setw(515)<<"*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	 cout << "\n Press any key to continue.....!!";
    cin.ignore();
    cin.get();
}
void start()//function to show hotel name
{
	    cout <<"------------------------------------------------------------------"<< endl;
    cout << " ******" <<setw(75)<<""<<endl;
    cout << "  ****"<<setw(45)<<"  LGU HOTEL " <<setw(30)<<""<< endl;
    cout << "   **"<<setw(75)<<"" << endl;
  	    cout <<"    *   --------------------------------------------------------------------   *"<< endl;
  	    
}
class Hotel {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float price;
public:
    void main_menu();    //to display the main menu
    void add();          //to book a room
    void display();      //to display the customer record
    void rooms();        //to display allotted rooms
    void edit();         //to edit the customer record
    int check(int);      //to check room status
    void modify(int);    //to modify the record
    void delete_rec(int);//to delete the record
    void displaying();
   
};
void Hotel::main_menu()
{
int num=0;
while(num!=5){
	system("cls");
	start();
cout <<setw(27)<< "*"<<endl;
        cout <<setw(37)<<"*** MAIN MENU"<<endl;
        cout <<setw(27)<< "*"<<endl<<endl;;
        cout << "PRESS 1. TO BOOK A ROOM "<<endl;;
        cout << "PRESS 2. TO DISPLAY CUSTOMER RECORD"<<endl;;
        cout << "PRESS 3. TO SHOW ROOMS ALLOCATED"<<endl;
        cout << "PRESS 4. TO EDIT A RECORD"<<endl;
        cout << "PRESS 5. FOR EXIT"<<endl<<endl;
        cout <<setw(55)<< "PRESS A NUMBER(1,2,3,4,5) :  ";
        cin>>num;
        switch(num){
        case 1:
        	add();
        	break;
        	case 2:
        		display();
        		break;
        	case 3:
        		rooms();
        		break;
        	case 4:
        		edit();
        		break;
        		case 5:
        			break;
        	  default: {
                cout << "\n\n\t\t\tWrong choice.....!!!";
                cout << "\n\t\t\tPress any key to continue....!!";
                cin.ignore();
                cin.get();
            }	
        }
}
}
int Hotel::check(int r){
	system("cls");
	start();
    int flag = 0;
    ifstream fin("Record.txt", ios::in | ios::binary);// the file is open in binary mode for reading
    while (fin.read((char*)this, sizeof(Hotel))) //this points to the current hotel object
	{
        if (room_no == r) {
            flag = 1;
            break;
        }
    }
    fin.close();
    return flag;
}
void Hotel::add()//add function is use to add new record for customer
{
	system("cls");
	start();
	int r, checker;
    ofstream fout("Record.txt", ios::app | ios::binary);//new file is open in append mode its mean new data will be added at the end of the file
//the new data is appended to the end of the file in binary form
	cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    int roomtype;
    cout << " select room type from available rooms given below\n\n";
    cout << " 1. ROOM 1 TO ROOM 10 IS A Single Bed Room [900 per night] "<<endl;
	cout<<" 2. ROOM 11 TO ROOM 20 IS A Double Bed Room [1200 per night] \n";
    cout << " 3. ROOM 21 TO ROOM 30 IS  2 Double Bed room whith AC [1500 per night]\n";
    cout<<"press 1,2,3 : ";
    cin >>roomtype;
    cout << "\n\n Room no: ";
    cin >> r;
    checker = check(r);
    if (checker)
        cout << "\n Sorry..!!! Room is already booked";
    else {

        room_no = r;
        cin.ignore();
        if(room_no<10&roomtype == 1){
        cout << " Name: ";
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin.getline(phone, 15);
        cout << " No of Days to Checkout: ";
        cin >> days;
    	price = days * 900;
        cout << "Room charges for single bed room = " << price <<" for "<<days << " days \n\n";
        cout << "Room " <<r<< " is allotted to the respective customer.\n\n";
    }
    else if (room_no<20&roomtype == 2)
    {
    	 cout << " Name: ";
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin.getline(phone, 15);
        cout << " No of Days to Checkout: ";
        cin >> days;
    	price = days * 1200;
        cout << "Room charges for double bed room =" << price<<" for "<<days << "days\n\n";
        cout << "Room " << r<< " is allotted to the respective customer.\n\n";
    }
    else if (room_no<30&roomtype == 3)
    {
    	 cout << " Name: ";
        cin.getline(name, 30);
        cout << " Address: ";
        cin.getline(address, 50);
        cout << " Phone No: ";
        cin.getline(phone, 15);
        cout << " No of Days to Checkout: ";
        cin >> days;
    	price = days * 1500;
        cout << "Room charges for suit bed room =" << price <<" for "<<days << "days\n\n";
        cout << "Room " << r<< " is allotted to the respective customer.\n\n"<<endl;
    }
    else
    {
        cout << "invalid room type\n\n";
    }
     
        fout.write((char*)this, sizeof(Hotel));
        cout << "\n Room is booked...!!!";
    }
    
    cout << "\n Press any key to continue.....!!";
    cin.ignore();
    cin.get();
    fout.close();
}
void Hotel::display() //display function is use to display record whish is enter
{
system("cls");
	start();
    ifstream fin("Record.txt", ios::in | ios::binary);// the file is open in binary mode for reading
    int r, flag = 0;
    cout << "\n Enter room no: ";
    cin >> r;
    while (fin.read((char*)this, sizeof(Hotel))) {
        if (room_no == r) {
          
            cout << "\n Customer Details"<<endl;
            cout << " ----------------"<<endl<<endl;
            cout << " Room no: " << room_no<<endl;
            cout << " Name: " << name<<endl;
            cout << " Address: " << address<<endl;
            cout << " Phone no: " << phone<<endl;
            cout << " Days: " << days<<endl;
            cout << "\n Total ROOM RENT PRICE : " << price<<endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)//0 means room is not found 
        cout << "\n Sorry Room no. not found or vacant....!!";
    cout << "\n\n Press any key to continue....!!";
    cin.ignore();
    cin.get();
    fin.close();
}
void Hotel::rooms() {
    system("cls");
	start();
 
    ifstream fin("Record.txt", ios::in | ios::binary);// the file is open in binary mode for reading
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    ----------------------";
    while (fin.read((char*)this, sizeof(Hotel)))
	 {
        cout << "\n Room no: " << room_no;
         cout << "\n Name: " << name;
        cout << "\n Address: " << address;
        cout << "\n Phone: " << phone;
        cout << "\n Days: " << days;
        cout << "\n Total  ROOM RENT PRICE : " << price;
        cout << "\n**";
        if(room_no<10)
        {
        	cout<<"***** YOU BOOKED Single Bed Room  *****"<<endl;
       
    }
    else if(room_no<20)
    {
    	cout<<"***** YOU BOOKED Double Bed Room ***** "<<endl;
	}
	else if(room_no<30)
	{
		cout<<"***** YOU BOOKED Double Bed Room WITH AC *****"<<endl;
	}
	else
	{
		cout<<"INVALID ROOM"<<endl;
	}
  }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    cin.ignore();
    cin.get();
    fin.close();
}
void Hotel::edit()//edit function is use to modify or delete any record
 {
 	system("cls");
	start();
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Record";
    cout << "\n 2. Delete Customer Record";
    cout << "\n Enter your choice: ";
    cin >> choice;
    cout << "\n Enter room no: ";
    cin >> r;
    switch (choice) {
        case 1: modify(r);
            break;
       case 2:
       	delete_rec(r);
       	break;
        default:
		 cout << "\n Wrong Choice.....!!";
    }
    cout << "\n Press any key to continue....!!!";
    cin.ignore();
    cin.get();
}
void Hotel::modify(int r) {
	system("cls");
	start();
    double pos;
    int flag = 0;
    fstream file("Record.txt", ios::in | ios::out | ios::binary);
    while (file.read((char*)this, sizeof(Hotel))) {
        pos = file.tellg();//file.tellg() is a function that returns the current position of the file pointer
        if (room_no == r) {
            cout << "\n Enter New Details";
            cout << "\n -----------------";
            cin.ignore();
            cout << "\n Name: ";
            cin.getline(name, 30);
            cout << " Address: ";
            cin.getline(address, 50);
            cout << " Phone no: ";
            cin.getline(phone, 15);
            cout << " Days: ";
            cin >> days;
            price = days * 900;
            file.seekg(pos - sizeof(Hotel));// file.seekg move file pointer to the new position
            //pos is the current file position which was previsously stored using file.tellg()
            file.write((char*)this, sizeof(Hotel));
            cout << "\n Record is modified....!!";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry Room no : "<< r <<" is  not found ...!!";
    file.close();
}
void Hotel::delete_rec(int r) {
	system("cls");
	start();
    int flag = 0;
    char ch;
    ifstream fin("Record.txt", ios::in | ios::binary);
    ofstream fout("temp.txt", ios::out | ios::binary);
    while (fin.read((char*)this, sizeof(Hotel))) {
        if (room_no == r) {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone No: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total price : " << price;
            cout << "\n\n Do you want to delete this record (y/n): ";
            cin >> ch;
            if (ch == 'n') {
                fout.write((char*)this, sizeof(Hotel));
            }
            flag = 1;
        } else {
            fout.write((char*)this, sizeof(Hotel));
        }
    }
    fin.close();
    fout.close();
    if (flag == 0)
        cout << "\n Sorry room no. not found or vacant...!!";
    else {
        remove("Record.txt");
        rename("temp.txt", "Record.txt");
    }
}
class User:public Hotel
{
	private:
    string username;
    string password;
public:
    User() = default;
    User(string uname, string pass) : username(uname), password(pass) {}

    static bool login(const string& uname, const string& pass) {
        ifstream infile("Record.txt");
        if (!infile.is_open()) {
            cout << "Error opening file 'Record.txt'." << endl;
            return false;
        }

        string u, p;
        while (infile >> u >> p) {
            if (u == uname && p == pass) {
                infile.close();
                return true;
            }
        }
        infile.close();
        return false;
    }	
     void registerUser() {
        ofstream outfile("users.txt", ios::app);
        if (!outfile.is_open()) {
            cerr << "Error opening file 'users.txt'." << endl;
            return;
        }
        outfile << username << " " << password << endl;
        outfile.close();
    }
};
void Hotel::displaying()
{
	string chk;
	double pay=0.0;
		my_intro();
	system("cls");
	start();
	cout<<"ARE YOU OWNER OR CUSTOMER (OWNER / CUSTOMER) =>  ";
	cin>>chk;
	if(chk=="customer"||chk=="CUSTOMER"||chk=="Customer")
	{
		char user[20],pas[20];
		cout<<"ENTER USER NAME : ";
		cin>>user;
		cout<<"ENTER PASSWORD : ";
		cin>>pas;
		User u;
		u.login(user,pas);
 int room,food,food1;
 
 	
		 cout << "\n\t\t\t---Food Order Service---\n\n";
    cout << "What is your room number: \n";
    cin >> room;
    ifstream fin("Record.txt", ios::in | ios::binary); 
        ofstream fout("Record.txt", ios::app | ios::binary);
     while (fin.read((char*)this, sizeof(Hotel))) {
      if(room_no==room)
 {
   cout <<setw(60)<< "***** Food Menu *****\n\n";
    cout <<setw(5)<< " => DESI \n\n";
    cout <<setw(60)<< "Chicken Karahi with Roghni Naan (RS 1200) \n";
    cout <<setw(60)<< "White Handi with Roghni Naan (RS 1400)\n\n";
    cout <<setw(8)<< "=> FAST FOOD \n\n";
    cout <<setw(60)<< "Pizza with bottle (RS 1000)\n";
    cout <<setw(60)<< "Burger+fries (RS 700)\n";
    cout <<setw(60)<< "White Sauce Pasta (RS 500)\n\n";
    cout <<setw(6)<< "=> CHINESE \n\n";
    cout <<setw(60)<< "Egg fried rice with Manchurian (RS 800)\n";
    cout <<setw(60)<< "Eggs fried rice with Chowmien (RS 850)\n";
    cout << "\t\t\t\nPress 1 for Desi,2 for Fastfood,3 for Chinese.\n";
        cin >> food;
    switch (food)
    {
    case 1:
    {
    	system("cls");
    	start();
        cout << "\t\t\tDesi\n";
        cout << "\tSelect the dish from the following:\n\n";
        cout << "1.Chicken Karahi with Roghni Naan (RS 1200) \n";
        cout << "2.White Handi with Roghni Naan (RS 1400) \n";
        cout << "press 1 for 1st option,press 2 for 2nd option:";
        cin >> food1;
        if (food1 == 1)
        {
            cout << "\t\t\t\n\nSend Chicken Karahi with Roghni Naan to room number " << room << "\n";
            pay+=1200;
        }
        else if (food1 == 2)
        {
            cout << "\t\t\t\n\nSend White Handi with Roghni Naan to room number " << room << "\n";
            pay+=1400;
        }
        else
        {
            cout << " \n Invalid Input Entered.\n\n";
        }
        break;
    }
    case 2:
    {
    	system("cls");
    	start();
        cout << "\t\tFastfood\n\n";
        cout << "\tSelect the dish from the following:\n\n";
        cout << "1.Pizza+bottle (RS 1000)\n";
        cout << "2.Burger+fries (RS 700)\n";
        cout << "3.White Sauce Pasta  (RS 500)\n";
        cout << "\n\npress 1 for 1st option,press 2 for 2nd option,press 3 for 3rd option:";
        cin >> food1;
        if (food1 == 1)
        {
            cout << "\t\t\t\n\nsend Pizza to room number " << room << "\n";
            pay+=1000;
        }
        else if (food1 == 2)
        {
            cout << "\t\t\t\n\nsend Burger+fries to room number " << room << "\n";
            pay+=700;
            break;
        }
        else if (food1 == 3)
        {
            cout << "\t\t\t\n\nsend White sauce Pasta to room number " << room << "\n";
            pay+=500;
        }
        else
        {
            cout << "\n\nInvalid Input Entered.\n";
        }
        break;
    }
    case 3:
    {
    	system("cls");
    	start();
        cout << "\t\tChinese\n\n";
        cout << "1.Egg fried rice with Manchurian (PRICE 800)\n";
        cout << "2.Eggs fried rice with Chowmien (PRICE 850)\n";
        cout << "\n\npress 1 for 1st option,press 2 for 2nd option:";
        cin >> food1;
        if (food1 == 1)
        {
            cout << "\t\t\t\n\nsend Egg fried rice with Manchurian to room number" << room << "\n";
            pay+=800;
        }
        else if (food1 == 2)
        {
            cout << "\t\t\t\n\nsend Eggs fried rice with Chowmien to room number " << room << "\n";
            pay+=850;
        }
        else
        {
            cout << "\n Invalid Input entered. \n\n";
        }
        break;
    }
    default:
    {
        cout << "\n Invalid input Entered. \n\n";
        break;
    }
    }
   
} 

}
cout<<"YOUR FOOD CHARGES IS : "<<pay<<endl;
 cout<<"PLEASE PAY THIS PAYENMENT  : "<<pay<<endl;
 
  fout.write((char*)this, sizeof(Hotel));
	
	}

	else if(chk=="OWNER"||chk=="Owner"||chk=="owner"){
		fstream f("Recrd.txt",ios::in | ios::out) ;
	string username, password;
	    int count = 0;
	  while (count<3) {
        cout << "\n\t\t\t\t  LOGIN ";
        cout << "\n\t\t\t\t --------- ";
        cout << "\n\t\t\t\t  Username: ";
        cin >> username;
        cout << "\n\t\t\t\t  Password: ";
        cin >> password;
        if (username != "admin" || password != "123") {
            cout << "\n\t\t\t\t  Invalid Login. Try Again.";
            count++;
        }
        else
        {
    cout << "\n\t\t\t\t  Login Successful! Press any key to continue...";
    cin.ignore();
    cin.get();
    Hotel h;
    h.main_menu();
}
    }
    	}
    	else
    	cout<<"..................... INVALID ARGUMENT ENTER !!!!!!!!!!!"<<endl;
		}
void display()
{
	Hotel h;
	h.displaying();
}
int main()
{
display();
}