//even  parity

#include <iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    cout<<"We are depicting even parity error detection"<<endl;
    vector<string>initial;
    vector<string>final;
    vector<string>receiver;
    cout<<"Enter the number of packets of bits"<<endl;
    int n;
    cin>>n;
    string s2;
    for(int j=0;j<n;j++)
    {
        cout<<"Enter the string for "<<j<<" th packet"<<endl;
        cin>>s2;
        int length=s2.length();
        initial.push_back(s2);
    
        
        int count=0;
        for(int k=0;k<length;k++)
        {
            if(s2[k]=='1')
            {
                count++;
            }
        }
        if((count%2)==1)
        {
            string temp="1";
            s2.append(temp);
            final.push_back(s2);
        }
        else
        {
            string temp="0";
            s2.append(temp);
            final.push_back(s2);
        }
    }
    cout<<"THE MESSAGE ENTERED IN THE RECEIVER END, PLEASE ENTER"<<endl;
    for(int k=0;k<final.size();k++)
    {
        string received;
        cin>>received;
        receiver.push_back(received);
        
        
    }
    
    cout<<" THE ORIGINAL MESSAGE IS"<<endl;
    for(int j=0;j<initial.size();j++)
    {
        cout<<initial[j]<<" ";
    }
    cout<<endl;
    cout<<"THE RECEIVED MESSAGE IN RECEIVER END IS"<<endl;
    for(int j=0;j<initial.size();j++)
    {
        cout<<receiver[j]<<" ";
    }
    cout<<endl;
    cout<<"THE EXPECTED MESSAGE IN RECEIVER END AFTER ADDING even PARITY 1 is"<<endl;
    for(int j=0;j<initial.size();j++)
    {
        cout<<final[j]<<" ";
    }
    
    cout<<endl;
    cout<<"CHECKING OUT THE ERROR"<<endl;
    for(int j=0;j<initial.size();j++)
    {
        string s=receiver[j];
        string sx=final[j];
        int length=s.length();
        int count=0;
        for(int k=0;k<length;k++)
        {
            if(s[k]=='1')
            {
                count++;
            }
        }
        if((count)%2==0)
        {
            cout<<"message correct for  packet"<<j+1<<endl;
        }
        else
        {
              for(int m=0;m<length;m++)
              {
                  if(s[m]!=sx[m])
                  {
                      cout<<"packet "<<j+1<<" has error in bit "<<m+1<<endl;
                      break;
                  }
              }
        
               
        }
            
    }
    return 0;
        
        
}
    
    
    
   


