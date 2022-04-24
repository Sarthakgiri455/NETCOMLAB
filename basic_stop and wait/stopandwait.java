

#include <iostream>
#include<vector>

using namespace std;


int receiver(int i)
{
    cout<<"is frame "<< i  <<" received? 1 for Y 0 for NO  ";
    
    int x;
    cin>>x;
    cout<<endl;
    
    if(x==1)
    {
        return 1;
        
    }
    return 0;
}
void send(vector<int>v1)
{
    int received=0;
    
    for(int j=0;j<v1.size();j++)
    {
        int res= receiver(j+1);
        while(!res)
        {
           
               cout<<"Acknowledgement for packet "<<j+1<<" not received yet"<<endl;
               cout<<endl;
               res= receiver(j+1);
       }
       cout<<"THanks for Acknowledgement of packet "<<j+1;
       cout<<endl;
       
           
    }
}


int main()
{
    cout<<"Number of frames??"<<endl;
    int x;
    cin>>x;
    vector<int>frames;
    for(int i=0;i<x;i++)
    {
        frames.push_back(i+1);
    }
    send(frames);
    

    return 0;
}
