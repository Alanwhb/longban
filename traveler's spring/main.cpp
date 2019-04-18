

#include <iostream>
#include "file_module.h"
#include "user.h"

using namespace std;



int main(int argc, const char * argv[]) {
    
    cout<<"the system is booting, please wait for a moent..........\n";
	bool r;
    r=read_file();//this is in file_module.cpp and all file related function and class is in there t
	if (!r) {
		goto Shut_down;
	}
    
    cout<<"system has booted!Welcome to trip adviser!\n";
    
    for(int i=0;i!=-1;){
        cout<<"\n\nWhat can I do for you?\n";
        cout<<"1.Go for a trip.\n2.Look up for a path\n3.Add a path\n-1.Turn of the system\n";
        cin>>i;
        switch(i){
            case 1:{
                User u;
                 //user functions insert in here
                break;
            }
                
            case 2:
                search();
                break;
                
            case 3:
                cout<<"coming soon!";
                break;
                
            case -1:
                cout<<"Have a nice day!\n\n";
        }
    //here is user's initialization
    }
	Shut_down:
    return 0;
}

