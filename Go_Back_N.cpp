#include<bits/stdc++.h>
using namespace std;

int main(){

    int window_size;
    cout<<"Enter window size"<<endl;
    cin>>window_size;

    int frames;
    cout<<"Enter total no of frames"<<endl;
    cin>>frames;

    int no_of_transmissions=0;
    int resent=0;

    for(int i=1;i<=frames;){
        for(int j=1;j<=(window_size-resent);j++){
            if(i<=frames){
                cout<<"The Frame "<<i<<" is transmitted"<<endl;
                no_of_transmissions++;
                i++;
            }
        }

        int miss;
        cout<<"Enter the frames number that is not received (0 if all are received)"<<endl;
        cin>>miss;

        resent=0;

        if(miss!=0){
            
            for(int j=miss;j<i;){
                cout<<"The Frame "<<j<<" is transmitted"<<endl;
                j++;
                no_of_transmissions++;
                resent++;
            }
        }
    }

    cout<<"No of transmissions : "<<no_of_transmissions<<endl;

    return 0;
}