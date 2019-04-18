
#include "file_module.h"

void change_word_into_lowercase(char *a,int number){//change input into lower case
    for(int c=0;c<number;c++){
        if(a[c]<='Z'&&a[c]>='A'){
            a[c]=a[c]-'A'+'a';
        }
    }
}

char *change_word_into_lowercase1(char *a,int number){//change input into lower case
    char *b;
    b=new char(pathname);
    for(int c=0;c<number;c++){
        if(a[c]<='Z'&&a[c]>='A'){
            b[c]=a[c]-'A'+'a';
        }
        else{
            b[c]=a[c];
        }
    }
    return b;
}


void print_city(city c){//mapping city cype to it's name output
    switch(c){
        case beijing:
            cout<<"Beijing";
            break;
        case shanghai:
            cout<<"Shanghai";
            break;
        case guangzhou:
            cout<<"Guangzhou";
            break;
        case shenzhen:
            cout<<"Shenzhen";
            break;
        case shantou:
            cout<<"Shantou";
            break;
        case tianjing:
            cout<<"Tianjing";
            break;
        case hangzhou:
            cout<<"Hangzhou";
            break;
        case nanning:
            cout<<"nanning";
            break;
        case chongqing:
            cout<<"Chongqing";
            break;
        case xiamen:
            cout<<"Xiamen";
            break;
    }
}

int scan_city(){//mapping input to city type
    char city_name[cityname];
Recity:
    cin>>city_name;
    change_word_into_lowercase(city_name,cityname);
    if(!strcmp(city_name,"beijing")){
        return 0;
    }
    if(!strcmp(city_name,"shanghai")){
        return 1;
    }
    
    if(!strcmp(city_name,"guangzhou")){
        return 2;
    }
    
    if(!strcmp(city_name,"shenzhen")){
        return 3;
    }
    
    if(!strcmp(city_name,"shantou")){
        return 4;
    }
    
    if(!strcmp(city_name,"tianjin")){
        return 5;
    }
    
    if(!strcmp(city_name,"hangzhou")){
        return 6;
    }
    
    if(!strcmp(city_name,"nanning")){
        return 7;
    }
    
    if(!strcmp(city_name,"chongqing")){
        return 8;
    }
    if(!strcmp(city_name,"xiamen")){
        return 9;
    }
    cout<<"There is such a city on our list. Now we have:\n";
    for(int a=0;a<citynumber;a++){
        print_city((city)a);
        cout<<"\n";
    }
    
    cout<<"on our list. please choose another city from this list:";
    goto Recity;
    return -1;
}

void print_transportation(transportation a){//mapping transportation name to ouput it's name
    switch(a){
        case airplane:
            cout<<"Airplane";
            break;
        case train:
            cout<<"Train";
            break;
        case bus:
            cout<<"Bus";
            break;
    }
}




bool compare_time(path &a,path &b){
    return (a.get_stt()<b.get_stt());
}




vector<vector<vector<path>>> p(10,vector<vector<path>>(10,vector<path>()));


bool read_file() {
	fstream file;
	file.open("file.txt", ios::in | ios::out);//
	if (!file.is_open()) {
		cout << "the file can not be opened.\n";
		return 0;
	}
	else {
		while (!file.eof()) {
			path a(file);
			p[(int)a.get_depa()][(int)a.get_dest()].push_back(a);
		}
	}
	file.close();
    for(int i=0;i<10;i++) 
        for(int j=0;j<10;j++){
            // int s=(p[i][j].size()/sizeof(path));
            sort(p[i][j].begin(),p[i][j].end(),compare_time);
            //                                        for(int k=0;k<s;k++){//if you want to print all the imformation, disable the "//"
            //                                            p[i][j][k].print_path();
            //                                        }
        }
    return 1;
}


void search(){
    Search_again:
    cout<<"what do you want to serch?\n1.All paths from city A to city B.\n2.A specifically one.\n";
    int input;
    cin>>input;
    switch(input){
        case 1:{
            cout<<"please input:\ndepature:";
            int i,j;
            i=scan_city();
            cout<<"destination:";
            j=scan_city();
            int s=p[i][j].size();
            for(int k=0;k<s;k++){
                p[i][j][k].print_path();
            }
            break;
        }
        case 2:
            cout<<"please input filght number/train name/car name:";
            char search_name[pathname],*pname;
            cin>>search_name;
            change_word_into_lowercase(search_name, pathname);
            int count=0;
            for(int i=0;i<10;i++)
                for(int j=0;j<10;j++){
                    int s=p[i][j].size();
                    for(int k=0;k<s;k++){//if you want to print all the imformation, disable the "//"
                        pname=change_word_into_lowercase1(p[i][j][k].get_name(), pathname);
                        if(!strcmp(search_name,pname)){
                            p[i][j][k].print_path();
                            count++;
                        }
                    }
                }
            if(count==0){
                cout<<"There is no such a filght number/train name or car name,";
            }
            
            break;
    }
    
Reyn:
    cout<<"do you want to search again?(y for yse, n for no)";
    char yn;
    cin>>yn;
    if(yn=='y'){
        goto Search_again;
    }
    if(yn=='n'){
        return;
    }
    else{
        cout<<"illegal inout! please input y or n!\n";
        goto Reyn;
    }
}

void fastest(vector<junjie1>& junjie, vector<bool> is_min, int city, int begin, int cities)
{
	path cur_min;
	for (int i = 0; i < cities; ++i)
	{
		if (is_min[i]) {
			junjie[i].time_min = 0;
		}
		else
		{
			int ways = p[city][i].size();
			cur_min = p[city][i][0];
			for (int j = 1; j < ways; ++j) {
				if (p[city][i][j].time_need(begin) < cur_min.time_need(begin)) {
					cur_min = p[city][i][j];
				}
			}
			junjie[i].time_min = cur_min.time_need(begin);
			junjie[i].path0 = cur_min;
		}
	}
}

void cheapest(vector<junjie2>& junjie, vector<bool> is_min, int city, int cities)
{
    path cur_min;
    for (int i = 0; i < cities; ++i) {
        if (is_min[i]){
            junjie[i].price_min = 0;
        }
    	else
        {
            int ways = p[city][i].size();
            cur_min = p[city][i][0];
            for (int j = 1; j < ways; ++j) {
                if (p[city][i][j].get_price() < cur_min.get_price()){
					cur_min = p[city][i][j];
                }
            }
			junjie[i].price_min = cur_min.get_price();
			junjie[i].path0 = cur_min;
        }
    }
};
