#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include<stdint.h>
using namespace std;
#define DEFAULT 5
class MyString{
private:
	char *p_str;
	size_t length;
public:
	void show();
	MyString();
	~MyString();
	MyString(const MyString &str);
	string toSTLstring();
	MyString& fromSTLstring(const string& str);
	vector<char>::iterator begin();
	vector<char>::iterator end( );
	MyString& erase(int _Pos = 0,int _Count = -1);
	//insert操作
    MyString& insert(int P0, const char* Ptr);
    MyString& insert(int P0, const char* Ptr, int _Count);
    MyString& insert(int P0, const MyString& Str);
    MyString& insert(int P0, const MyString& Str, int _Off, int _Count);
    MyString& insert(int P0, int _Count, char _Ch);
    size_t thelength() const;
    size_t max_size() const;
    void push_back(char _Ch);
    //replace操作
    MyString& replace(int _Pos1,int _Num1,const char* _Ptr);
    MyString& replace(int _Pos1,int _Num1,const MyString& _Str);
    MyString& replace(int _Pos1,int _Num1,const char* _Ptr,int _Num2);
    MyString& replace(int _Pos1,int _Num1,const MyString& _Str,int _Pos2,int _Num2);
    MyString& replace(int _Pos1,int _Num1,int _Count,char _Ch);
    MyString& replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const char* _Ptr);
    MyString& replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const MyString& _Str);
    MyString& replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const char* _Ptr,int _Num2);
    MyString& replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,int _Num2,char _Ch);
};
void MyString::show()
{
	for(int i=0;i<length;i++)
	cout<<p_str[i];
	cout<<endl;
}
MyString::MyString()
{
	p_str = NULL;
	length = 0;
}
MyString::~MyString()
{
	delete[] p_str;
	length = 0;
}
string MyString::toSTLstring()
{
	string x;
	x = p_str;
	return x;
}
MyString& MyString::fromSTLstring(const std::string& str)
{
	length = str.size();
	p_str = (char *)malloc(sizeof(char)*length);
	for (int i = 0; i<length; i++)
	{
		p_str[i] = str[i];
	}
	return *this;
}
vector<char>::iterator MyString::begin()
{
    return static_cast<vector<char>::iterator>(p_str);
}
vector<char>::iterator MyString::end()
{
	return begin()+length;
}
MyString& MyString::erase(int _Pos,int _Count)
{
	for(int i=_Pos;i<length-_Count;i++)
	p_str[i]=p_str[i+_Count];
	length=length-_Count;
    return *this;
}
//insert操作
MyString& MyString::insert(int _P0, const char* _Ptr)
{
    size_t len = strlen(_Ptr);
    p_str=(char *)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    for(int i = length-1; i>=_P0; i--)
        p_str[i+len] = p_str[i];
    int t = _P0;
    for(int i = 0; i<len; i++)
        p_str[t++] = _Ptr[i];
    length += len;
    return *this;
}
MyString& MyString::insert(int _P0, const char* _Ptr, int _Count)
{
    p_str = (char *)realloc(p_str,sizeof(char)*(length+_Count+DEFAULT));
    for(int i = length-1; i>=_P0; i--)
        p_str[i+_Count] = p_str[i];
    int t = _P0;
    for(int i = 0; i<_Count; i++)
        p_str[t++] = _Ptr[i];
    length += _Count;
    return *this;
}
MyString& MyString::insert(int _P0, const MyString& _Str)
{
    size_t len = _Str.length;
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    for(int i = length-1; i>=_P0; i--)
        p_str[i+len] = p_str[i];
    int t = _P0;
    for(int i = 0; i<len; i++)
        p_str[t++] = _Str.p_str[i];
    length += len;
    return *this;
}
MyString& MyString::insert(int _P0, const MyString& _Str, int _Off, int _Count)
{
    p_str = (char*)realloc(p_str,sizeof(char)*(length+_Count+DEFAULT));
    for(int i = length-1; i>=_P0; i--)
        p_str[i+_Count] = p_str[i];
    int t = _P0;
    for(int i = _Off; i<_Off+_Count; i++)
        p_str[t++] = _Str.p_str[i];
    length += _Count;
    return *this;
}
MyString& MyString::insert(int _P0, int _Count, char _Ch)
{
    p_str = (char*)realloc(p_str, sizeof(char)*(length+_Count+DEFAULT));
    for(int i = length-1; i>=_P0; i--)
        p_str[i+_Count] = p_str[i];
    int t = _P0;
    for(int i = 0; i<_Count; i++)
        p_str[t++] = _Ch;
    length += _Count;
    return *this;
}
size_t MyString::thelength() const
{
    return length;
}
size_t MyString::max_size() const
{
    return strlen(p_str);
}
void MyString::push_back(char _Ch)
{
    p_str = (char*)realloc(p_str,sizeof(char)*(length+DEFAULT));
    p_str[length] = _Ch;
    length++;
}

//replace操作
MyString& MyString::replace(int _Pos1, int _Num1,const char* _Ptr)
{
    size_t len = strlen(_Ptr);
    erase(_Pos1,_Num1);
    insert(_Pos1,_Ptr);
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const MyString& _Str)
{
    size_t len = _Str.length;
    erase(_Pos1,_Num1);
    insert(_Pos1,_Str);
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const char* _Ptr,int _Num2)
{
    size_t len = _Num2;
    erase(_Pos1,_Num1);
    insert(_Pos1,_Ptr,_Num2);
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const MyString& _Str,int _Pos2,int _Num2)
{
    size_t len = _Num2;
    erase(_Pos1,_Num1);
    insert(_Pos1,_Str,_Pos2,_Num2);
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,int _Count,char _Ch)
{
    size_t len = _Count;
    erase(_Pos1,_Num1);
    insert(_Pos1,_Count,_Ch);
    return *this;
}
MyString& MyString::replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const char* _Ptr)
{
    vector<char>::iterator iter = begin();
    size_t _Pos1 = 0;
    size_t len = strlen(_Ptr);

    while(iter != _First0)
    {
        iter++;
        _Pos1++;
    }
    int _Count = 1;
    while(iter != _Last0)
    {
        iter++;
        _Count++;
    }
    erase(_Pos1,_Count);
    insert(_Pos1,_Ptr);
    return *this;
}
MyString& MyString::replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const MyString& _Str)
{
    vector<char>::iterator iter = begin();
    size_t len = _Str.length;
    size_t _Pos1 = 0;
    while(iter != _First0)
    {
        iter++;
        _Pos1++;
    }
    int _Count = 1;
    while(iter != _Last0)
    {
        iter++;
        _Count++;
    }
    erase(_Pos1,_Count);
    insert(_Pos1,_Str);
    return *this;
}
MyString& MyString::replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const char* _Ptr,int _Num2)
{
    vector<char>::iterator iter = begin();
    size_t len = _Num2;
    size_t _Pos1 = 0;
    while(iter != _First0)
    {
        iter++;
        _Pos1++;
    }
    int _Count = 1;
    while(iter != _Last0)
    {
        iter++;
        _Count++;
    }
    erase(_Pos1,_Count);
    insert(_Pos1,_Ptr,_Num2);
    return *this;
}
MyString& MyString::replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,int _Num2,char _Ch)
{
    vector<char>::iterator iter = begin();
    size_t len = _Num2;
    size_t _Pos1 = 0;
    while(iter != _First0)
    {
        iter++;
        _Pos1++;
    }
    int _Count = 1;
    while(iter != _Last0)
    {
        iter++;
        _Count++;
    }
    erase(_Pos1,_Count);
    insert(_Pos1,_Num2,_Ch);
    return *this;
}
int main()
{
	MyString s;
    MyString s1;
	string ss;
	cin >> ss;
	s.fromSTLstring(ss);
    cin>>ss;
    s1.fromSTLstring(ss);
    s.insert(2,"helloworld");
    s.show();
    s.insert(2,"hello",3);
    s.show();
    s.insert(4,s1);
    s.show();
    s.insert(2,3,'C');
    s.show();
    s.replace(2,3,"yesiam");
    s.show();
    s.replace(2,3,s1);
    s.show();
    s.replace(2,3,"imfine",2);
    s.show();
    s.replace(2,3,s1,2,2);
    s.show();
    s.replace(2,3,2,'C');
    s.show();
    vector<char>::iterator a = s.begin();
    vector<char>::iterator b = s.end();
    s.replace(a+1,b-3,"hellooy");
    s.show();
    a = s.begin();
    b = s.end();
    s.replace(a+1,b-3,s1);
    s.show();
    a = s.begin();
    b = s.end();
    s.replace(a+2,b-3,"hueieeoco",3);
    s.show();
    a = s.begin();
    b = s.end();
    s.replace(a+3,b-3,3,'C');
    s.show();
	return 0;
}
