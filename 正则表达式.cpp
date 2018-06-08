#include<iostream>
using namespace std;
#include<regex>
int main()
{
    string s="";
    cout<<"input : "<<endl;
    cin>>s;
    regex REGEX("^-?[1-9]+(\.\d+)?(e-?\d+)?$");//构建正则表达式的对象
    if(regex_match(s,REGEX))
     cout<<"true"<<endl;
    else
      cout<<""<<endl;
}
