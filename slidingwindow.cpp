#include <iostream>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;
void resend(queue<int>&v2, int a)
{
    cout<<"Resending all the elements inside the buffer because did not receive acknowledgement for frame "<<a <<endl;
    queue<int>q3=v2;
    cout<<"THEY ARE: ";
    while(!q3.empty())
    {
        cout<<q3.front()<<" ";
        q3.pop();
    }
}
void acknowledgementcheck(queue<int>&v1, int success)
{
    string x;
    queue<int>frame;
    for(int j=1;j<=success;j++)
    {
        frame.push(j);
    }
    while(success>=0)
    {
        int a= v1.front();
        int b=v1.back();
        int mn=b;
        int xy=a;
        cout<<"is frame "<<xy<<" acknowledged dear receiver? Y/N"<<endl;
        cin>>x;
        if(x=="Y"|| x=="y")
        {
            mn+=1;
            v1.pop();
            if(mn<=frame.back())
            {
                v1.push(mn);
            }
            
            
            xy++;
            
            success--;
            if((success==0))
            {
                break;
            }
        }
        else
        {
            resend(v1, a);
        }
    }
    
    
    
}
int main()
{
    queue<int>slidingwindow;
    int window;
    vector<string>frames;
    vector<string>receiver_buffer;
    cout<<"Enter the window size"<<endl;
    cin>>window;
    cout<<"number of frames"<<endl;
    int n_of_frames;
    cin>>n_of_frames;
    
    cout<<"number of bits inside a frame  "<<endl;
    int bits_number;
    cin>>bits_number;
    vector<string>bitscollection;
    
    for(int j=0;j<n_of_frames;j++)
    {
        
        string bits;
        
        cout<<"Enter the bits for frame "<<j+1;
        cin>>bits;
        bitscollection.push_back(bits);
    }
    for(int j=0;j<n_of_frames;j++)
    {
        stringstream ss;
        ss<<j+1;
        string s;
        ss>>s;
        string z= "frame number "+s;
        frames.push_back(z);
    }
    while(receiver_buffer.size()<window)
    {
        
        for(int j=0;j<window;j++)
        {
            slidingwindow.push(j+1);
            
        }
        cout<<"waiting for acknowledgement"<<endl;
        acknowledgementcheck(slidingwindow, n_of_frames);
        
        
    }
    
    
    

    return 0;
}
