//字符串追加 填充 比较 size swap
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

       //append字符串追加
       MyString& append(const char*ptr);
       MyString& append(const char *ptr,int size);
       MyString& append(const char *ptr,int offset,int size);
       MyString& append(const MyString& other);
       MyString& append(int count,char c);
       MyString& append(char c);

       //assgin字符串填充
       MyString& assign(const char *ptr);
       MyString& assign(const char *ptr,int count);
       MyString& assign(const char *ptr,int off,int count);
       MyString& assign(const MyString & other);
       MyString& assign(int count,char c);

       void clear();

       //compare 字符串比较
       int compare(const MyString &str);
       int compare(int _Posl,int _Numl,const MyString &str);
       int compare(const char* _str);
       int compare(int _Posl,int _Numl,const char *_Ptr);

       //size
       size_t size()const;

       //swap
       void swap(MyString& _Str);

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
    p_str=(char *)realloc(p_str,sizeof(char)*(length+len));
    for(int i=0;i<len;i++)
        p_str[i+length]=ptr[i];
    length+=len;
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
}

MyString& MyString::append(int count,char c){
    p_str=(char *)realloc(p_str,sizeof(char)*(length+count));
    for(int i=0;i<count;i++)
        p_str[i+length]=c;
    length+=count;
}

MyString& MyString::append(char c){
    int count=1;
     p_str=(char *)realloc(p_str,sizeof(char)*(length+count));
    for(int i=0;i<count;i++)
        p_str[i+length]=c;
    length+=count;
}
//assign
MyString& MyString::assign(const char *ptr){
    int len=strlen(ptr);
    if(len>length){
        p_str=(char *)realloc(p_str,sizeof(char)*len);
        length=len;
    }
    for(int i=0;i<len;i++)
    p_str[i]=ptr[i];
}

MyString& MyString::assign(const char *ptr,int count){
    if(count>length){
         p_str=(char *)realloc(p_str,sizeof(char)*count);
         length=count;
    }
    for(int i=0;i<count;i++)
        p_str[i]=ptr[i];
}

MyString& MyString::assign(const char *ptr,int off,int count){
   int beg=off-count;//count一定要小于off
   for(int i=beg;i<=off;i++)
      p_str[i-beg]=ptr[i];
}

MyString& MyString::assign(const MyString & other){
     if(length<other.length){
        p_str=(char *)realloc(p_str,sizeof(char)*(length));
        length=other.length;
     }

    for(int i=0;i<length;i++)
        p_str[i]=other.p_str[i];
}

MyString& MyString::assign(int count,char c){
    free(p_str);
    length=count;
    p_str=(char *)malloc(sizeof(char)*(count));
    for(int i=0;i<length;i++)
        p_str[i]=c;
//        cout<<length<<endl;
//        cout<<count<<endl;
//        cout<<c<<endl;
}

 void MyString::clear(){
     ////free(p_str);
     delete[] p_str;
    length=0;
}

int MyString::compare(const MyString &str)
{
    char *sh;
    sh=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        sh[i]=p_str[i];
    sh[length]='\0';

    char *ch;
    ch=(char *)malloc(sizeof(char)*(str.length+1));
    for(int i=0;i<str.length;i++)
        ch[i]=str.p_str[i];
        ch[str.length]='\0';

   // puts(sh);
   //puts(ch);
     int ans =strcmp(sh,ch);
     free(sh);
     free(ch);
     return ans;
}

int MyString::compare(int _Posl,int _Numl,const MyString &str)
{
    char *sh;
    sh=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        sh[i]=p_str[i];
    sh[length]='\0';

    char *ch;
    ch=(char *)malloc(sizeof(char)*(_Numl+1));
    for(int i=_Posl;i<_Posl+_Numl;i++)
        ch[i-_Posl]=str.p_str[i];
        ch[_Posl+_Numl]='\0';
      //  puts(sh);
      //  puts(ch);
    int ans=strcmp(sh,ch);
    free(sh);
    free(ch);
    return ans;
}

int MyString::compare(const char* _str)
{
     char *sh;
    sh=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        sh[i]=p_str[i];
    sh[length]='\0';
    int ans=strcmp(sh,_str);
    free(sh);
    return ans;
}

int MyString::compare(int _Posl,int _Numl,const char *_Ptr)
{
    char *sh;
    sh=(char *)malloc(sizeof(char)*(length+1));
    for(int i=0;i<length;i++)
        sh[i]=p_str[i];
    sh[length]='\0';

    char *ch;
    ch=(char *)malloc(sizeof(char)*(_Numl+1));
    for(int i=0;i<_Numl;i++)
        ch[i]=_Ptr[i];
    ch[_Numl]='\0';
    int ans=strcmp(sh,ch);
    free(sh);
    free(ch);
    return ans;
}


size_t MyString::size()const{
 return length;

}

void MyString::swap(MyString& _Str){
   int len;
   len=length;
   length=_Str.length;
   _Str.length=len;

   char *ch;
   ch=p_str;
   p_str=_Str.p_str;
   _Str.p_str=ch;

}

int main()
{
    MyString s;
    string ss("abcd"),get;
    cout<<endl<<"MyString& fromSTLstring(const std::string& str);"<<endl<<endl;
    s.fromSTLstring(ss);
    s.show();
    cout<<endl;

    cout<<endl<<"std::string toSTLstring();"<<endl<<endl;
    get=s.toSTLstring();
    for(int i=0;i<get.size();i++)
        cout<<get[i];
    cout<<endl;
    cout<<endl;

    cout<<endl<<"append"<<endl<<endl;
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

    cout<<endl;

    cout<<endl<<"assign"<<endl<<endl;
    char b[]="12345\0";
    s.assign(b);
    s.show();

    char c[]="123456789012345678901234567890123456\0";
    s.assign(c,36);
    s.show();

    char d[]="abcdefghigklmn\0";

    s.assign(d,10,10);
    s.show();

    MyString sss;
    sss.assign(s);
    sss.show();

    s.assign(50,'l');
    s.show();
    cout<<endl;

    cout<<endl<<"compare"<<endl;
    cout<<endl<<"int compare(const MyString &str);"<<endl;
    s.show();
    sss.show();
    cout<<s.compare(sss)<<endl;

    cout<<endl<<"int compare(int _Posl,int _Numl,const MyString &str);"<<endl;

    cout<<s.compare(0,4,sss)<<endl;

    cout<<endl<<"int compare(const char* _str);"<<endl;

    char e[]="aaaaa\0";
    s.clear();
    s.assign(5,'a');
    s.show();
    cout<<s.compare(e)<<endl;

    cout<<endl<<"int compare(int _Posl,int _Numl,const char *_Ptr);"<<endl;
    char f[]="aaaaaaaaaa\0";
   // s.show();
    cout<<s.compare(0,5,f)<<endl;

    cout<<endl<<"size"<<endl<<endl;
    s.show();
    cout<<s.size()<<endl;
    cout<<endl;

    cout<<endl<<"swap"<<endl<<endl;
    s.show();
    sss.show();
    swap(s,sss);
    s.show();
    sss.show();
    cout<<endl;


    return 0;
}
