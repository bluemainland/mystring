//find insert replace 
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
	 MyString& fromSTLstring(const std::string& str);
	const char& at(int index)const;
	char& at(int index);
	vector<char>::iterator begin();
	const char *c_str();
	size_t capacity() const;
	void clear();

    int copy(char* _Ptr, int _Count,int _Off = 0) const;
	const char *data( );
	bool empty( ) const;
	vector<char>::iterator end( );
	vector<char>::iterator erase(vector<char>::iterator _First,vector<char>::iterator _Last);
	vector<char>::iterator erase(vector<char>::iterator _It);
	MyString& erase(int _Pos = 0,int _Count = -1);
	int find(char _Ch, int _Off = 0) const;
	int find(const char* _Ptr,int _Off = 0) const;
	int find(const MyString& _Str,int _Off = 0) const;
	int find_first_not_of(char _Ch,int _Off = 0) const;
	int find_first_not_of(const char* _Ptr,int _Off = 0) const;
	int find_first_not_of(const char* _Ptr,int _Off,int _Count) const;
	int find_first_not_of(const MyString& _Str,int _Off = 0) const;
	int find_first_of(const char* _Ptr,int _Off = 0) const;
	int find_first_of(const char* _Ptr,int _Off,int _Count) const;
	int find_first_of(const MyString& _Str,int _Off = 0) const;
	int find_last_not_of(char _Ch,int _Off = -1) const;
	int find_last_not_of(const char* _Ptr,int _Off = -1) const;
	int find_last_not_of(const char* _Ptr,int _Off,int _Count) const;
	int find_last_not_of(const MyString& _Str,int _Off = -1) const;
	int find_last_of(char _Ch,int _Off = -1) const;
	int find_last_of(const char* _Ptr,int _Off = -1) const;
	int find_last_of(const char* _Ptr,int _Off,int _Count) const;
	int find_last_of(const MyString& _Str,int _Off = -1) const;
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
    MyString& replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const MyString _Str);
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
MyString& MyString::fromSTLstring(const std::string& str)
{
    length=str.size();
    p_str=(char *)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++)
    {
        p_str[i]=str[i];
    }
}

const char& MyString::at(int index)const
{
	return p_str[index-1];
}
char& MyString::at(int index)
{
	return p_str[index-1];
}
vector<char>::iterator MyString::begin()
{
	return static_cast<vector<char>::iterator>(p_str);
}
const char* MyString::c_str()
{
	const char* p;
	p=p_str;
	return p;
}
size_t MyString::capacity() const
{
	size_t a;
	a=length*sizeof(char);
	return a;
}
int MyString::copy(char* _Ptr, int _Count,int _Off) const
{
	if(_Count+_Off>length)
	return 0;
	else
	{
		memset(_Ptr,0,sizeof(0));
		for(int i=0;i<_Count;i++)
		_Ptr[i]=p_str[i+_Off];
		return 1;
	}
}
const char* MyString::data()
{
	char *a=new char[length];
	 for(int i=0;i<length;i++)
	 a[i]=p_str[i];
	 return a;
}
bool MyString::empty()const
{
	if(length==0)
	return true;
	return false;
}
vector<char>::iterator MyString::end()
{
	return begin()+length;
}
vector<char>::iterator MyString::erase(vector<char>::iterator _First,vector<char>::iterator _Last)
{
	vector<char> tem;
	for(int i=0;i<length;i++)
	tem.push_back(p_str[i]);
	vector<char>::iterator iter=tem.begin();
	while(iter!=tem.end())
	{
		if(*iter==*_First&&*iter!=*_Last)
		iter=tem.erase(iter);
		else
		++iter;
	}
	return iter;
}
MyString& MyString::erase(int _Pos,int _Count)
{
	for(int i=_Pos;i<length-_Count;i++)
	p_str[i]=p_str[i+_Count];
	length=length-_Count;
}
int MyString::find(char _Ch, int _Off)const
{
	size_t a=SIZE_MAX;
	for(size_t i=_Off;i<length;i++)
	{
		if(p_str[i]==_Ch)
		{
			a=SIZE_MAX;
			break;
		}
	}
	return a;
}
int MyString::find(const char* _Ptr,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t len=strlen(_Ptr);
	for(size_t i=_Off;i<length;i++)
	{
		if(p_str[i]==_Ptr[0])
		{
			size_t m=i;
			size_t n=0;
			bool check=true;
			for(;m<length,n<len;m++,n++)
			{
				if(p_str[m]!=_Ptr[n])
				{
					check=false;
					break;
				}
			}
			if(check)
			{
				flag=i;
				break;
			}
		}
	}
	return flag;
}
int MyString::find(const MyString& _Str,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t len=_Str.length;
	for(size_t i=_Off;i<length;i++)
	{
		if(p_str[i]==_Str.p_str[0])
		{
			size_t m=i;
			size_t n=0;
			bool check=true;
			for(;m<length,n<_Str.length;m++,n++)
			{
				if(p_str[m]!=_Str.p_str[n])
				{
					check=false;
					break;
				}
			}
			if(check)
			{
				flag=i;
				break;
			}
		}
	}
	return flag;
}
int MyString::find_first_not_of(char _Ch,int _Off)const
{
	size_t flag=SIZE_MAX;
	for(size_t i=_Off;i<length;i++)
	{
		if(p_str[i]!=_Ch)
		{
			flag=i;
			break;
		}
	}
	return flag;
}
int MyString::find_first_not_of(const char* _Ptr,int _Off)const
{
	size_t len=strlen(_Ptr);
	size_t flag=SIZE_MAX;
	size_t i,j;
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<len;j++)
		{
			if(p_str[i]==_Ptr[j])
			break;
		}
		if(j==len)
		break;
	}
	if(i==length)
	return flag;
	return i;
}
int MyString::find_first_not_of(const char* _Ptr,int _Off,int _Count)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<_Count;j++)
		{
			if(p_str[i]==_Ptr[j])
			break;
		}
		if(j==_Count)
		{
			break;
		}
	}
	if(i==length)
	return flag;
	return i;
}
int MyString::find_first_not_of(const MyString& _Str,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<_Str.length;j++)
		{
			if(p_str[i]==_Str.p_str[j])
			break;
		}
		if(j==_Str.length)
		{
			break;
		}
	}
	if(i==length)
	return flag;
	return i;
}
int MyString::find_first_of(const char* _Ptr,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	size_t len=strlen(_Ptr);
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<len;j++)
		{
			if(p_str[i]==_Ptr[j])
			{
				return i;
			}
		}
	}
	return flag;
}
int MyString::find_first_of(const char* _Ptr,int _Off,int _Count)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<_Count;j++)
		{
			if(p_str[i]==_Ptr[j])
			return i;
		}
	}
	return flag;
}
int MyString::find_first_of(const MyString& _Str,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	for(i=_Off;i<length;i++)
	{
		for(j=0;j<_Str.length;j++)
		{
			if(p_str[i]==_Str.p_str[j])
			return i;
		}
	}
	return flag;
}
int MyString::find_last_not_of(char _Ch,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			if(p_str[i]!=_Ch)
			{
				flag=i;
				break;
			}
		}
		return flag;
	}
}
int MyString::find_last_not_of(const char* _Ptr,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	size_t len=strlen(_Ptr);
	if(_Off<0)
	return flag;
	else{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			for(j=0;j<len;j++)
			{
				if(p_str[i]==_Ptr[j])
				break;
			}
			if(j==len)
			break;
		}
		if(i==-1)
		return flag;
		else
		return i;
	}
}
int MyString::find_last_not_of(const char* _Ptr,int _Off,int _Count)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
	for(i=_Off;i>=0;i--)
	{

		for(j=0;j<_Count;j++)
		{
			if(p_str[i]==_Ptr[j])
			break;
		}
		if(j==_Count)
		break;
	}
	if(i==-1)
	return flag;
	else
	return i;
    }
}
int MyString::find_last_not_of(const MyString& _Str,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			for(j=0;j<_Str.length;j++)
			{
				if(p_str[i]==_Str.p_str[j])
				break;
			}
			if(j==_Str.length)
			break;
		}
		if(i==-1)
		return flag;
		else
		return i;
	}
}
int MyString::find_last_of(char _Ch,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			if(p_str[i]==_Ch)
			break;
				}
		return i;
	}
}
int MyString::find_last_of(const char* _Ptr,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	size_t len=strlen(_Ptr);
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			for(j=0;j<len;j++)
			{
				if(p_str[i]==_Ptr[j])
				return i;
			}
			}
		return flag;
	}
}
int MyString::find_last_of(const char* _Ptr,int _Off,int _Count)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	size_t len=strlen(_Ptr);
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			for(j=0;j<_Count;j++)
			{
				if(p_str[i]==_Ptr[j])
				return i;
			}
				}
		return flag;
	}
}
int MyString::find_last_of(const MyString& _Str,int _Off)const
{
	size_t flag=SIZE_MAX;
	size_t i,j;
	if(_Off<0)
	return flag;
	else
	{
		int  a=length;
		_Off=min(_Off,a);
		for(i=_Off;i>=0;i--)
		{
			for(j=0;j<_Str.length;j++)
			{
				if(p_str[i]==_Str.p_str[j])
				return i;
			}
				}
			return flag;
		}
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
MyString& MyString::replace(int _Pos1, int _Num1,const char* _Ptr)
{
    size_t len = strlen(_Ptr);
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    erase(_Pos1,_Num1);
    insert(_Pos1,_Ptr);
    length = length - _Num1 + len;
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const MyString& _Str)
{
    size_t len = _Str.length;
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    erase(_Pos1,_Num1);
    insert(_Pos1,_Str);
    length = length - _Num1 + len;
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const char* _Ptr,int _Num2)
{
    size_t len = _Num2;
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    erase(_Pos1,_Num1);
    insert(_Pos1,_Ptr,_Num2);
    length = length - _Num1 + len;
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,const MyString& _Str,int _Pos2,int _Num2)
{
    size_t len = _Num2;
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    erase(_Pos1,_Num1);
    insert(_Pos1,_Str,_Pos2,_Num2);
    length = length - _Num1 + len;
    return *this;
}
MyString& MyString::replace(int _Pos1,int _Num1,int _Count,char _Ch)
{
    size_t len = _Count;
    p_str = (char*)realloc(p_str,sizeof(char)*(length+len+DEFAULT));
    erase(_Pos1,_Num1);
    insert(_Pos1,_Count,_Ch);
    length = length - _Num1 + len;
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
    length = length - _Count + len;
    return *this;
}
MyString& MyString::replace(vector<char>::iterator _First0,vector<char>::iterator _Last0,const MyString _Str)
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
    length = length - _Count + len;
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
    length = length - _Count + len;
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
    length = length - _Count + len;
}



int main()
{
	MyString s;
	string ss;
	cin >> ss;
	s.fromSTLstring(ss);
    vector<char>::iterator a;
    a=s.begin();
    vector<char>::iterator b;
    b=s.end();
    vector<char>::iterator c=s.erase(a,b);
    s.replace(2,2,5,'c');
    s.show();
//	s.show();
//	s1.fromSTLstring(s2);
/*	vector<char>::iterator a;
	a=s.begin();
	vector<char>::iterator b;
	b=a+3;
	vector<char>::iterator c;
	c=s.erase(a,b);
	cout<<*c<<endl;*/
/*	const char *p;
	p=s.c_str();
	cout<<p<<endl;*/
/*	s.erase(0,2);
	s.show();*/
/*	char a;
	cin>>a;
	int x;
	x=s.find(a,0);
	cout<<x;*/
	//char y[10];
	//cin>>y;
	//char *z=y;
	//int k=s.find_last_not_of(z,0);
	//cout<<k;
	return 0;
}
