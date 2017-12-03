#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int INI_MAX = 0x7fffffff;
const int INI_MIN = 0x80000000;
const int npos = 0xffffffff;

class MyString{
   private:
       char *p_str;
       size_t length;


   public:
       MyString();
       ~MyString();
       std::string toSTLstring();
       MyString& fromSTLstring(const std::string& str);
       MyString& append(const char*ptr);
       MyString& append(const char *ptr,int size);
       MyString& append(const char *ptr,int offset,int size);
       MyString& append(const MyString& other);
       MyString& append(int count,char c);
       MyString& append(char c);
       //assgin

       MyString& assign(const char *ptr);
       MyString& assign(const char *ptr,int count);
       MyString& assign(const char *ptr,int off,int count);
       MyString& assign(const MyString & other);
       MyString& assign(int count,char c);






       void show()
       {
           for(int i=0;i<length;i++)
            cout<<p_str[i];
           cout<<endl;
       }





};

MyString::MyString():p_str(NULL),length(0){}

MyString::~MyString()
{
    delete[] p_str;
    length=0;
}

std::string MyString::toSTLstring()
{
    string ss;
    for(int i=0;i<length;i++)
    ss+=p_str[i];
    return ss;
}

MyString& MyString::fromSTLstring(const std::string& str)
{
    length=str.size();
    p_str=(char *)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++)
    {
        p_str[i]=str[i];
    }
}

MyString& MyString::append(const char *ptr)
{
    int len=strlen(ptr);
   // cout<<len<<endl;
    p_str=(char *)realloc(p_str,sizeof(char)*(length+len));
    for(int i=0;i<len;i++)
        p_str[i+length]=ptr[i];
    length+=len;
   // cout<<1<<endl;
    //cout<<length<<endl;
}

MyString& MyString::append(const char *ptr,int size)
{
     p_str=(char *)realloc(p_str,sizeof(char)*(length+size));
    for(int i=0;i<size;i++)
        p_str[i+length]=ptr[i];
    length+=size;
}

MyString& MyString::append(const char *ptr,int offset,int size)
{
    offset--;
    p_str=(char *)realloc(p_str,sizeof(char)*(length+size));

    for(int i=offset;i<offset+size;i++)
        p_str[i-offset+length]=ptr[i];
    length+=size;
}

MyString& MyString::append(const MyString& other)
{
    int len=other.length;
    p_str=(char *)realloc(p_str,sizeof(char)*(length+len));
    for(int i=0;i<len;i++)
        p_str[i+length]=other.p_str[i];
    length+=len;
  //  cout<<length<<endl;
}

MyString& MyString::append(int count,char c)
{
    p_str=(char *)realloc(p_str,sizeof(char)*(length+count));
    for(int i=0;i<count;i++)
        p_str[i+length]=c;
    length+=count;
}

MyString& MyString::append(char c)
{
    int count=1;
     p_str=(char *)realloc(p_str,sizeof(char)*(length+count));
    for(int i=0;i<count;i++)
        p_str[i+length]=c;
    length+=count;
}
//assign
MyString& MyString::assign(const char *ptr)
{
   // int len=
}
       MyString& assign(const char *ptr,int count);
       MyString& assign(const char *ptr,int off,int count);
       MyString& assign(const MyString & other);
       MyString& assign(int count,char c);
int main()
{
    MyString s;
    string ss("abcd"),get;

    s.fromSTLstring(ss);

    get=s.toSTLstring();
    for(int i=0;i<get.size();i++)
        cout<<get[i];
    cout<<endl;

    s.show();

    char a[]="ef\0";
    s.append(a);
    s.show();

    s.append("gh",2);
    s.show();

    s.append("eijk",2,2);
    s.show();


    s.append(s);
    s.show();


    s.append(10,'l');
    s.show();

    s.append('m');
    s.show();
    return 0;
}
