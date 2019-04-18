
#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

bool read_file();
enum city {beijing , shanghai, guangzhou, shenzhen, shantou, tianjing, hangzhou, nanning, chongqing, xiamen};
//if you want to add a city, add it here.The city name mustn't longer than 10 char unless length of cityname in the front of file_module.cpp
enum transportation {airplane,train,bus};
//enum city {beijing , shanghai, guangzhou, shenzhen, shantou, tianjing, hangzhou, nanning, chongqing, xiamen};
const int citynumber=10;
const int cityname=10;
const int pathname=10;

void print_city(city c);
void print_transportation(transportation a);

class path{
private:
    char name[pathname];
    city depa=beijing,dest=shanghai;
    int stt=0,edt=0;
    float price=0;
    transportation tran;
    
public:
    int get_time(fstream &file){//read a time from the form of xx:xx to minutes started from 00:00 dorectly from file
        int hour,minute;
        file>>hour;
        file.seekg(1,ios::cur);
        file>>minute;
        return (hour*60+minute);
    }
    
    city get_depa(){//return depature
        return depa;
    }
    
    city get_dest(){//return destination
        return dest;
    }
    
    int get_stt(){
        return stt;
    }
    
    path(const path &copied){// copy constructure
        depa=copied.depa;
        dest=copied.dest;
        stt=copied.stt;
        edt=copied.edt;
        tran=copied.tran;
        price=copied.price;
        for(int i=0;i<pathname;i++){
            name[i]=copied.name[i];
        }
    }
    
    path(fstream &file){
        int i;
        file>>i;
        tran=(transportation)i;
        //        char c;
        //        c=file.get();
        //        for(int a=0;a<10&&c!=' ';a++){
        //            name[a]=c;
        //            c=file.get();
        //        }
        file>>name;
        file>>i;
        depa=(city)i;
        file>>i;
        dest=(city)i;
        stt=get_time(file);
        edt=get_time(file);
        
        if(edt<=stt){
            edt=edt+1440;
        }
        file>>price;
    }
    
    char *get_name(){
        return name;
    }
    
	//
    path(){}
    float get_price(){
        return price;
    }
	int temporary_lishi() {	// lishi: the time that this path takes
		if (stt <= edt)
			return edt - stt;
		else
			return edt - stt + 1440;
	}
	int time_need(int begin) {	//"https://blog.csdn.net/wj1066/article/details/82632294"
		if (begin <= stt)
			return stt - begin + temporary_lishi();
		else
			return stt - begin + 1440 + temporary_lishi();
	}
	int get_edt() {
		return edt;
	}
	//
    
    void print_time(int time){
        int hour=time/60;
        int minute=time%60;
        if(hour<10){
            cout<<"0";
        }
        cout<<hour;
        cout<<":";
        if(minute<10){
            cout<<"0";
        }
        cout<<minute;
    }
    
    void print_path(){
        cout<<"===================This is the begin of this path imformation===================\n";
        cout<<"==          transportation: ";
        print_transportation(tran);
        cout<<"\n==          ";
        cout<<"path name: "<<name<<"\n==          ";
        cout<<"departure: ";
        print_city(depa);
        cout<<"    destination: ";
        print_city(dest);
        cout<<"\n==          ";
        cout<<"start time:  ";
        print_time(stt);
        cout<<"    ";
        if(edt<1440){
            cout<<"end time:  ";
            print_time(edt);
            cout<<"\n==          ";
        }
        else{
            int nedt=edt-1440;
            cout<<"end time: ";
            print_time(nedt);
            cout<<"\n==          ";
        }
        cout<<"time used: "<<edt-stt<<"min\n==          ";
        cout<<"price: ¥"<<price<<"\n";
        cout<<"====================This is the end of this path imformation====================\n\n";
    }
};

typedef struct Junjie1{
    int time_min;
    path path0;
}junjie1;

typedef struct Junjie2{
    float price_min;
    path path0;
}junjie2;
int scan_city();
void search();
void fastest(vector<junjie1>& junjie, vector<bool> is_min, int city, int begin, int cities = 10);
void cheapest(vector<junjie2>& junjie, vector<bool> is_min, int city, int cities = 10);



#endif /* Header_h */
