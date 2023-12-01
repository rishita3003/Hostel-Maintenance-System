#include"header.h"

int hostel::h1(int roll){
    return (roll%table_size);
}

int hostel::h2(int roll){
    return ((table_size-1)-roll%(table_size-1));
}

int hostel::doublee(int roll,int hostel,string stud_name){
    int temp=h1(roll);
    int count=0;
    while(roommates[hostel][temp].size()==2){
            temp=(temp+h2(roll))%table_size; //if i==1 always then linear probing, a special case of double hashing
            count++;
    }

    info stud;
    stud.roll_no=roll;
    stud.name=stud_name;
    roommates[hostel][temp].pb(stud);

    details[stud_name]=roll;
    int roomNumber=(temp+table_size)%table_size;

    //storeAllocation(roll,stud_name,roomNumber);
    return roomNumber;
}

bool hostel::search(int roll,int hostel){
    int temp=h1(roll);
    int count=0;
    int start=h1(roll);

    while(count<table_size){
        for(int i=0;i<roommates[hostel][temp].size();i++){
            if(roommates[hostel][temp][i].roll_no==roll){
                return true;
            }
        }
        temp=(temp+h2(roll))%table_size; //if i==1 always then linear probing, a special case of double hashing
        if (temp==start){
            return false;
        }
        count++;
        }
        return false;
}

int hostel::wait(int slot,int roll){
        v[slot].push(roll);
        int count;
        while(!v[slot].empty()){
            count++;
            v[slot].pop();
        }
        return (count-1)/2;
}

bool hostel::check_slot(int slot,int roll){
    if(v[slot].size()<=1){
        v[slot].push(roll);
        return true;
    }
    return false;
}

void hostel::stud_list(){
    cout<<"The list of the students registered is as follows: "<<endl;
    int i=1;
    for(auto x:details){
        cout<<i<<" "<<x.first<<" "<<x.second<<endl;
        i++;
    }
    return;
}

//schedule display of queries
void hostel::displayRoommates() {
    for (int host = 0; host < num_hostel; ++host) {
        cout << "Hostel " << host << "-\n";
        for (int room = 0; room < table_size; ++room) {
            cout << "  Room " << room << ":\n";
            for (const auto& student : roommates[host][room]) {
                cout << "    Roll No: " << student.roll_no << " | Name: " << student.name << "\n";
            }
        }
    }
}


			/***   			EXAMPLE RUN 			***/
							

/*---------------------------------------------- Hostel Maintenance System ----------------------------------------------- 
Hostel Numbers are as follows: 
Dhansiri: 0
Subansiri: 1
Disang: 2
Umiam: 3
Manas: 4
Lohit: 5
Barak: 6
Kameng: 7
Kapili: 8
Siang: 9

-------------------------------------------------------Query Form-------------------------------------------------------
Enter 1 for Room Allocation. 
Enter 2 for reparation requests.
1
Enter your name: saptarshi
Enter your Roll Number: 220150019
Enter your pre alloted hostel number: 2
Your room number is: 11

The list of the students registered is as follows: 
1 Arushi Kumar 220150032
2 Chekuri Muni Siva Keerthan 220150001
3 Dhruv Khichi 220150002
4 Goli Poojitha 220150003
5 Himanshu Singhal 220150004
6 Ishan Chandra Gupta 220150034
7 Karan Kumawat 220150005
8 Karnati Ravi Teja 220150006
9 Madamanchi Chandana 220150007
10 Mayukh Maithy 220150033
11 Mohit Yadav 220150008
12 Mulla Meharaj 220150009
13 Patel Heet Niraj 220150010
14 Prakhar Punj 220150011
15 Prince Tholia 220150012
16 Priyansh Awasthi 220150013
17 Raparla Sushmitha 220150014
18 Raunit Patel 220150015
19 Rishab Sonthalia 220150035
20 Rishita Agarwal 220150016
21 Sahil Kumar 220150017
22 Sahil Raj 220150018
23 Shinde Onkar Harishchandra 220150021
24 Shivansh Pal 220150022
25 Sirigudi Midhush 220150024
26 Soumya Savarn 220150031
27 Takkellapati Nagendra 220150025
28 Ujwal Fandulal Kirsan 220150026
29 Uoga Venkata Sai Charan Boddapati 220150030
30 Vanama Pranav 220150027
31 Varakala Rajasree 220150028
32 Vishal 220150029
33 saptarshi 220150019
Hostel 0-
  Room 0:
  Room 1:
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
    Roll No: 220150014 | Name: Raparla Sushmitha
  Room 7:
    Roll No: 220150028 | Name: Varakala Rajasree
  Room 8:
    Roll No: 220150016 | Name: Rishita Agarwal
    Roll No: 220150003 | Name: Goli Poojitha
  Room 9:
  Room 10:
  Room 11:
  Room 12:
    Roll No: 220150007 | Name: Madamanchi Chandana
Hostel 1-
  Room 0:
  Room 1:
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
    Roll No: 220150001 | Name: Chekuri Muni Siva Keerthan
  Room 7:
  Room 8:
  Room 9:
  Room 10:
  Room 11:
  Room 12:
Hostel 2-
  Room 0:
  Room 1:
    Roll No: 220150009 | Name: Mulla Meharaj
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
  Room 7:
  Room 8:
  Room 9:
  Room 10:
  Room 11:
    Roll No: 220150032 | Name: Arushi Kumar
    Roll No: 220150019 | Name: saptarshi
  Room 12:
Hostel 3-
  Room 0:
    Roll No: 220150021 | Name: Shinde Onkar Harishchandra
  Room 1:
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
  Room 7:
    Roll No: 220150015 | Name: Raunit Patel
  Room 8:
  Room 9:
  Room 10:
  Room 11:
    Roll No: 220150006 | Name: Karnati Ravi Teja
  Room 12:
Hostel 4-
  Room 0:
  Room 1:
    Roll No: 220150022 | Name: Shivansh Pal
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
  Room 7:
  Room 8:
  Room 9:
  Room 10:
  Room 11:
  Room 12:
Hostel 5-
  Room 0:
  Room 1:
  Room 2:
    Roll No: 220150010 | Name: Patel Heet Niraj
  Room 3:
    Roll No: 220150024 | Name: Sirigudi Midhush
  Room 4:
  Room 5:
    Roll No: 220150013 | Name: Priyansh Awasthi
  Room 6:
  Room 7:
    Roll No: 220150002 | Name: Dhruv Khichi
  Room 8:
  Room 9:
    Roll No: 220150004 | Name: Himanshu Singhal
  Room 10:
    Roll No: 220150005 | Name: Karan Kumawat
  Room 11:
  Room 12:
Hostel 6-
  Room 0:
  Room 1:
  Room 2:
  Room 3:
  Room 4:
    Roll No: 220150025 | Name: Takkellapati Nagendra
  Room 5:
  Room 6:
    Roll No: 220150027 | Name: Vanama Pranav
  Room 7:
  Room 8:
    Roll No: 220150029 | Name: Vishal
  Room 9:
    Roll No: 220150030 | Name: Uoga Venkata Sai Charan Boddapati
  Room 10:
  Room 11:
  Room 12:
Hostel 7-
  Room 0:
  Room 1:
  Room 2:
  Room 3:
    Roll No: 220150011 | Name: Prakhar Punj
  Room 4:
  Room 5:
    Roll No: 220150026 | Name: Ujwal Fandulal Kirsan
  Room 6:
  Room 7:
  Room 8:
  Room 9:
  Room 10:
    Roll No: 220150018 | Name: Sahil Raj
  Room 11:
  Room 12:
Hostel 8-
  Room 0:
    Roll No: 220150008 | Name: Mohit Yadav
  Room 1:
  Room 2:
  Room 3:
  Room 4:
    Roll No: 220150012 | Name: Prince Tholia
  Room 5:
  Room 6:
  Room 7:
  Room 8:
  Room 9:
    Roll No: 220150017 | Name: Sahil Kumar
  Room 10:
    Roll No: 220150031 | Name: Soumya Savarn
  Room 11:
  Room 12:
    Roll No: 220150033 | Name: Mayukh Maithy
Hostel 9-
  Room 0:
    Roll No: 220150034 | Name: Ishan Chandra Gupta
  Room 1:
    Roll No: 220150035 | Name: Rishab Sonthalia
  Room 2:
  Room 3:
  Room 4:
  Room 5:
  Room 6:
  Room 7:
  Room 8:
  Room 9:
  Room 10:
  Room 11:
  Room 12:
  
*/

/*

---------------------------------------------- Hostel Maintenance System ----------------------------------------------- 
Hostel Numbers are as follows: 
Dhansiri: 0
Subansiri: 1
Disang: 2
Umiam: 3
Manas: 4
Lohit: 5
Barak: 6
Kameng: 7
Kapili: 8
Siang: 9

-------------------------------------------------------Query Form-------------------------------------------------------
Enter 1 for Room Allocation. 
Enter 2 for reparation requests.
2
Enter your Roll No.: 220150016
Enter your pre alloted hostel no.: 0
Enter 'a' for LAN/WiFi.
Enter 'b' for furniture damage/replacement.
Enter 'c' for Electric devices replace or repairment. 
Enter 'd' for Washing machine problems. 
d

This is a common service for all the hostels.
The following are the time slots available for the required person to visit and address your query. Please select a time slot.(Time slots maybe occupied, so might be asked to choose another): 

WEEKDAYS-
SLOT 1-8.30 am-10.30 am
SLOT 2-2.30 pm-4.30 pm
SLOT 3-6.30 pm-8.30 pm
WEEKENDS-
SLOT 4-11.30 am-1.30 pm
SLOT 5-3.30 pm-5.30 pm
1
Sorry, but the selected slot is fully occupied.
Please select some other slot or Enter the queue for the same slot.
Type 0 to enter in a queue of the same slot.0
You will be recieving the services after 1weeks.

Your query has been recorded.
The repaiman will contact you soon and will visit you on the slot allotted to you.
Thank You.

*/






