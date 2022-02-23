#include <iostream>
#include<string>
#include<vector>
using namespace std;
string calculation(string checksum2, string q)
{
    string x=checksum2;
    string y=q;
    int l=q.length();
    string checksum="";
    for(int j=0;j<checksum2.length();j++)
    {
        checksum+="0";
    }
    int carry=0;
    for(int j=0;j<x.length();j++){
        char temp=x[l-j-1];
        char temp2=y[l-j-1];
        int x1=temp-'0';
        int y2=temp2-'0';
        int sum=x1+y2+carry;
        if(sum>1)
        {
            carry=1;
        }
        else
        {
            carry=0;
        }
        
        sum=sum%2;
        checksum[l-j-1]=sum+'0';
    }
    if(carry!=0)
    {
        for(int j=0;j<x.length();j++){
           char temp=checksum[l-j-1];
        
           int x1=temp-'0';
        
           int sum=x1+carry;
           if(sum>1)
           {
               carry=1;
           }
           else
           {
               carry=0;
            
           }
        
           sum=sum%2;
           checksum[l-j-1]=sum+'0';
           if(carry==0)
           {
               break;
           }
       }
    }
    return checksum;
    
}
void calculatereceiver(vector<string>v1)
{
    int l=v1[0].length();
    string checksum="";
    for(int k=0;k<l;k++)
    {
        checksum=checksum+"0";
    }
    string checksumtemp=checksum;
    int carry=0;
    string x=v1[0];
    string y=v1[1];
    for(int j=0;j<x.length();j++){
        char temp=x[l-j-1];
        char temp2=y[l-j-1];
        int x1=temp-'0';
        int y2=temp2-'0';
        int sum=x1+y2+carry;
        if(sum>1)
        {
            carry=1;
        }
        else
        {
            carry=0;
        }
        
        sum=sum%2;
        checksum[l-j-1]=sum+'0';
    }
    if(carry!=0)
    {
        for(int j=0;j<x.length();j++){
           char temp=checksum[l-j-1];
        
           int x1=temp-'0';
        
           int sum=x1+carry;
           if(sum>1)
           {
               carry=1;
           }
           else
           {
               carry=0;
            
           }
        
           sum=sum%2;
           checksum[l-j-1]=sum+'0';
           if(carry==0)
           {
               break;
           }
       }
    }
    cout<<"check sum for step "<<1 <<" "<<checksum<<endl;
    for(int k=2;k<v1.size();k++)
    {
        string checksum2=calculation(checksum, v1[k]);
        cout<<"checksum step "<<k<<" "<<checksum2<<endl;
        checksum=checksum2;
    }
    if(checksumtemp!=checksum)
    {
        cout<<"THERE IS ERROR IN THE MESSAGE"<<endl;;
        
        
    }
    else{
        cout<<"CORRECT MESSAGE"<<endl;
    }
    
    
}



void receiverend(vector<string>v2, string message)
{
    cout<<"Dear receiver, could you please type the bits you received, so that we verify error or errrorless message"<<endl;
    int l= message.length()/v2.size();
    string s;
    cin>>s;
    string s1;
    vector<string>v1;
    for(int z=1;z<=s.length();z++)
    {
        s1=s1+message[z-1];
        if((z%l)==0)
        {
            v1.push_back(s1);
            s1="";
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"*****RECEIVER END*****"<<endl;
    
    calculatereceiver(v1);
}
    


string append(string ans, vector<string>v1)
{
    string tempo=ans;
    for(int k=0;k<v1.size();k++)
    {
        tempo=tempo+v1[k];
    }
    return tempo;
    
}
string onescomplement(string x)
{
    string tempo=x;
    for(int k=0;k<x.length();k++)
    {
        if(tempo[k]=='0')
        {
            tempo[k]='1';
        }
        else
        {
            tempo[k]='0';
        }
    }
    return tempo;
}

void calculate(vector<string>v1)
{
    int l=v1[0].length();
    string checksum="";
    for(int k=0;k<l;k++)
    {
        checksum=checksum+"0";
    }
    int carry=0;
    string x=v1[0];
    string y=v1[1];
    for(int j=0;j<x.length();j++){
        char temp=x[l-j-1];
        char temp2=y[l-j-1];
        int x1=temp-'0';
        int y2=temp2-'0';
        int sum=x1+y2+carry;
        if(sum>1)
        {
            carry=1;
        }
        else
        {
            carry=0;
        }
        
        sum=sum%2;
        checksum[l-j-1]=sum+'0';
    }
    if(carry!=0)
    {
        for(int j=0;j<x.length();j++){
           char temp=checksum[l-j-1];
        
           int x1=temp-'0';
        
           int sum=x1+carry;
           if(sum>1)
           {
               carry=1;
           }
           else
           {
               carry=0;
            
           }
        
           sum=sum%2;
           checksum[l-j-1]=sum+'0';
           if(carry==0)
           {
               break;
           }
       }
    }
    cout<<"check sum for step "<<1 <<" "<<checksum<<endl;
    for(int k=2;k<v1.size();k++)
    {
        string checksum2=calculation(checksum, v1[k]);
        cout<<"checksum step "<<k<<" "<<checksum2<<endl;
        checksum=checksum2;
    }
    
    string ans=onescomplement(checksum);
    cout<<"Final check sum after one's complement is :  "<<ans<<endl;
    string ans2=append(ans, v1);
    cout<<"Final Message after checksum appending becomes "<<ans2<<endl;
    
}



int main()
{
    int n_of_bits;
    cout<<"Number of bits in a message ?"<<endl;
    cin>>n_of_bits;
    int n_of_groups;
    cout<<"number of groups of message ?"<<endl;
    cin>>n_of_groups;
    string message;
    cout<<"enter message"<<endl;
    cin>>message;
    vector<string>v1;
    if(message.length()%n_of_groups)
    {
        cout<<"Message size not enough, thus appending the necessary ("<<message.length()%n_of_groups<<" ) number of zeros"<<endl;
        for(int z=0;z<message.length()%n_of_groups;z++)
        {
            message="0"+message;
        }
        cout<<"Final message to be transmitted is "<<message<<endl;
    }
    else
    {
        cout<<"Message can be equally divided to desired number of blocks no need to append anything"<<endl;
        cout<<"Final message to be transmitted is "<<message<<endl;
    }
    int x= message.length()/n_of_groups;
    string s1="";
    for(int z=1;z<=message.length();z++)
    {
        s1=s1+message[z-1];
        if((z%x)==0)
        {
            v1.push_back(s1);
            s1="";
        }
        
    }
    cout<<endl;
    cout<<"groups of message "<<endl;
    for(int z=0;z<v1.size();z++)
    {
        cout<<v1[z]<<" ";
    }
    cout<<endl;
    calculate(v1);
    receiverend(v1, message);
}
