#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<unordered_map>
#include<map>
#include<fstream>
using namespace std;
#define ll long long
#define pb push_back
const ll num=1e9+7;

typedef struct information{
    int roll_no;
    string name;
}info;

class hostel{
public:
int slots_avail;
vector<vector<info>> *roommates;
vector<queue<int>> v;
map<string,int> details;

int num_hostel;
int last_three;
int table_size;

hostel(int host,int table,int slots){
    num_hostel=host;
    roommates=new vector<vector<info>>[host];
    //10
    last_three=0;
    table_size=table;
    slots_avail=slots;
    //6
    v.resize(slots_avail+1);

    //17
    for(int i=0;i<host;i++){
            roommates[i].resize(table_size);
    }
}

int h1(int roll);
int h2(int roll);
int doublee(int roll,int hostel,string stud_name);
bool search(int roll,int hostel);
int wait(int slot,int roll);
bool check_slot(int slot,int roll);
void stud_list();
void displayRoommates();

};
