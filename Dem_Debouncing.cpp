#include <iostream>
#include <string.h>
using namespace std;
int buffer=0;
int Dem_Buffer=0;
class SW_Component{
  public:
  string type_port;
  string type_interface;
  int data=0;
  void set_Sw_Components(){
      cout<<"give me the elmenet of your SW"<<endl;
      cin>>type_port;
      cin>>type_interface;
      //cin>>data;
  }
  void check_SW(){
     string chec_type_port[3]={"P-Port","R-Port","RP-Port"};
     string chec_type_interface[6]={"Sender/Receiver","Client/Server","Mode-Switch","Parameter","Trigge", "NV Data"};
     int check1,check2;
     for(int i=0;i<6;i++){
        if (i<3 &&type_port==chec_type_port[i]){
           check1=1;
            
        }
        if (i<6 &&type_interface==chec_type_interface[6]){
             check2=1;
        }
        }
    if(check1*check2){
       cout<<"your SW is completed"<<endl; 
     }
    }
    void send_Data(int a){
        data=a;
    }
    void Display_sw(){
        cout<<"the elmenets of SW-Components is:"<<endl;
        cout<<type_port<<endl;
        cout<<type_interface<<endl;
        cout<<data<<endl;
    }
int check(){
 enum error_state{PREfailed,PREpassed};
 error_state error;
 if (type_port=="P-Port" && type_interface=="Sender/Receiver"){
   if(data<5){
     // error is came 
        return (PREfailed);
   }
   else {
     //not existe error
     return (PREpassed); 
   }
  }
  else {
      cout<<"verfiey your transsmission"<<endl;
}
}
// RTE_function 
friend int Read(SW_Component p);
friend void write(SW_Component p);
};
int  Read(SW_Component p)
{
    if (p.type_port=="P-Port" && p.type_interface=="Sender/Receiver")
    {
        return p.data;
    }
}
void write(SW_Component * n){
  if (n->type_port=="R-Port" && n->type_interface=="Sender/Receiver")
  {
  
         n->data+=buffer;
         cout<<"the transmission is done "<<endl;
  }
  else {
  	cout<<"error"<<endl;
  }
        
}
void Dem_Debounce_Couneter(int Dem_var){
static signed int counter=0;
static signed int threshold_failed=8;
static signed int threshold_passed=-8;
  if(Dem_var<5){
      counter+=2;
      if(counter==threshold_failed){
          cout<<"this error is failed"<<endl;
          cout<<"send [snapshot_data & extended_data]"<<endl;
      }
      
  }
  else{
    counter-=2; 
       if(counter==threshold_passed){
          cout<<"this error is passed"<<endl;
      }
  }
}
int main()
{
SW_Component sw_m;
sw_m.set_Sw_Components();
for(int i=0;i<4;i++){
sw_m.send_Data(i);
if(sw_m.check()==1){
    cout<<"no error"<<endl;
}
else {
cout<<"chek"<<endl;
Dem_Buffer=Read(sw_m);
cout<<Dem_Buffer<<endl;
Dem_Debounce_Couneter(Dem_Buffer);
}
}
return 0;
}
