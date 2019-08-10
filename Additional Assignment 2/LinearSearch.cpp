#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

int main()
{
    int t,n,key,num;
    bool flag=false;
    std::ifstream file("input.txt");
    std::string str;
    std::getline(file,str);
    std::stringstream stream1(str);
    stream1>>t;
    for(int i=0;i<t;i++)
    {
        flag=false;
        std::getline(file,str);
        std::stringstream stream2(str);
        stream2>>n;
        stream2>>key;
        std::getline(file,str);
        std::stringstream stream3(str);
        for(int j=0;j<n;j++)
        {
            //std::cout<<num<<std::endl;
            stream3>>num;
            if(num==key)
            {
                std::cout<<1<<std::endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            std::cout<<-1<<std::endl;
        }
    }
}
