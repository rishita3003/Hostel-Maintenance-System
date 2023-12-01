#include"header.h"

int main(){
    ios::sync_with_stdio(false);
    cout<<"---------------------------------------------- Hostel Maintenance System ----------------------------------------------- "<<endl;
    cout<<"Hostel Numbers are as follows: "<<endl;
    cout<<"Dhansiri: 0\nSubansiri: 1\nDisang: 2\nUmiam: 3\nManas: 4\nLohit: 5\nBarak: 6\nKameng: 7\nKapili: 8\nSiang: 9"<<endl;

    cout<<endl;
    cout<<"-------------------------------------------------------Query Form-------------------------------------------------------"<<endl;

     hostel query(10,13,6); //hostels, table size, slots available

    query.doublee(220150015,3,"Raunit Patel");
    query.doublee(220150016,0,"Rishita Agarwal");
    query.doublee(220150032,2,"Arushi Kumar");
    query.doublee(220150001,1,"Chekuri Muni Siva Keerthan");
    query.doublee(220150002,5,"Dhruv Khichi");
    query.doublee(220150003,0,"Goli Poojitha");
    query.doublee(220150004,5,"Himanshu Singhal");
    query.doublee(220150005,5,"Karan Kumawat");
    query.doublee(220150006,3,"Karnati Ravi Teja");
    query.doublee(220150007,0,"Madamanchi Chandana");
    query.doublee(220150008,8,"Mohit Yadav");
    query.doublee(220150009,2,"Mulla Meharaj");
    query.doublee(220150010,5,"Patel Heet Niraj");
    query.doublee(220150011,7,"Prakhar Punj");
    query.doublee(220150012,8,"Prince Tholia");
    query.doublee(220150013,5,"Priyansh Awasthi");
    query.doublee(220150014,0,"Raparla Sushmitha");
    query.doublee(220150017,8,"Sahil Kumar");
    query.doublee(220150018,7,"Sahil Raj");
    query.doublee(220150022,4,"Shivansh Pal");
    query.doublee(220150021,3,"Shinde Onkar Harishchandra");
    query.doublee(220150024,5,"Sirigudi Midhush");
    query.doublee(220150025,6,"Takkellapati Nagendra");
    query.doublee(220150026,7,"Ujwal Fandulal Kirsan");
    query.doublee(220150027,6,"Vanama Pranav");
    query.doublee(220150029,6,"Vishal");
    query.doublee(220150030,6,"Uoga Venkata Sai Charan Boddapati");
    query.doublee(220150031,8,"Soumya Savarn");
    query.doublee(220150033,8,"Mayukh Maithy");
    query.doublee(220150034,9,"Ishan Chandra Gupta");
    query.doublee(220150035,9,"Rishab Sonthalia");
    query.doublee(220150028,0,"Varakala Rajasree");
    
    query.check_slot(1,220150016);
    query.check_slot(2,220150015);
    query.check_slot(3,220150023);
    query.check_slot(2,220150020);
    query.check_slot(1,220150029);
    query.check_slot(4,220150033);
    query.check_slot(5,220150030);
    query.check_slot(5,220150018);

    while(true){
    int x;
    cout<<"Enter 1 for Room Allocation. \nEnter 2 for reparation requests.\n";
    cin>>x;

    /*// Load previously allocated rooms from the file
    ifstream infile("room_allocation.txt");
    if (infile.is_open()) {
        int roll;
        string name;
        while (infile >> roll >> name) {
            info student;
            student.roll_no = roll;
            student.name = name;
            query.doublee(roll, 0, name);  // Assuming hostel 0 for demonstration
        }
        infile.close();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }*/
    int flag=0;
    switch(x){

        case 1:{
        string name;
        int roll;
        int hostel;
        cout<<"Enter your name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter your Roll Number: ";
        cin>>roll;
        cout<<"Enter your pre alloted hostel number: ";
        cin>>hostel;
        cout<<"Your room number is: "<<query.doublee(roll,hostel,name)<<endl;
        flag=1;
        /*
        Enter your name: Saptarshi Mukherjee
        Enter your Roll Number: 220150019
        Enter your pre alloted hostel number: 2
        Your room number is: 9 */
        break;
        }

        case 2:{
            flag=1;
        while(true){
        int roll;
        cout<<"Enter your Roll No.: ";
        cin>>roll;
        int hostel;
        cout<<"Enter your pre alloted hostel no.: ";
        cin>>hostel;
        cin.ignore();
        if(query.search(roll,hostel)){
        char y;
        cout<<"Enter 'a' for LAN/WiFi.\nEnter 'b' for furniture damage/replacement.\nEnter 'c' for Electric devices replace or repairment. \nEnter 'd' for Washing machine problems. "<<endl;
        cin>>y;
        while(y!='a' && y!='b' && y!='c' && y!='d'){
            cout<<"Please enter a valid query."<<endl;
            char z;
            cin>>z;
            y=z;
        }
        cout<<endl;
        cout<<"This is a common service for all the hostels."<<endl;
        cout<<"The following are the time slots available for the required person to visit and address your query. Please select a time slot.(Time slots maybe occupied, so might be asked to choose another): "<<endl;
        cout<<endl;
        //2 people can select the same time slot -> 2 repairman available
        //slot x is chosen to enter the person in the queue of a particular slot..repairman can reach them after a week or next
        cout<<"WEEKDAYS-\nSLOT 1-8.30 am-10.30 am\nSLOT 2-2.30 pm-4.30 pm\nSLOT 3-6.30 pm-8.30 pm\nWEEKENDS-\nSLOT 4-11.30 am-1.30 pm\nSLOT 5-3.30 pm-5.30 pm\n";
        int slot;
        cin>>slot;
        while(!query.check_slot(slot,roll)){
            cout<<"Sorry, but the selected slot is fully occupied."<<endl;
            cout<<"Please select some other slot or Enter the queue for the same slot.\nType 0 to enter in a queue of the same slot.";
            int extra;
            cin>>extra;
            if(extra==0){
                cout<<"You will be recieving the services after "<<query.wait(slot,roll)<<" weeks."<<endl;
                break;
            }
            slot=extra;
        }
        cout<<endl;
        cout<<"Your query has been recorded.\nThe repairman will contact you soon and will visit you on the slot allotted to you.\nThank You."<<endl;
        break;
        }

        else{
        cout<<endl;
            cout<<"Roll no. not found. Re-enter your details."<<endl;
        }
        }
        break;
    }

        default:{
        cout<<endl;
        cout<<"Please enter a valid query."<<endl;
        break;
        }
    }
    if(x==1){
    cout<<endl;
    query.stud_list();
    query.displayRoommates();
    }
    if(flag==1){
        break;
    }
    }
}
