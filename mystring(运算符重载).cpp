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
       //operator+ 字符串和运算符
		MyString operator+(const char* carray);
		MyString operator+(const MyString& str);
		MyString operator+(const char c);
		//operator+= 字符串追加运算符
		MyString& operator+=(char c);
		MyString& operator+=(const char* pstr);
		MyString& operator+=(const MyString& str);
		//operator= 字符串追赋值运算符
		void operator=(const MyString& str);
		void operator=(const char* pstr);
		void operator=(const char c);
		//operator[] 取字符串中的特定
		char operator[](int index) const;
		//operator!= 字符串比较运算符
		bool operator!=(const char* carray);
		bool operator!=(const MyString& str);
		//operator== 字符串比较运算符
		bool operator==(const char* carray);
		bool operator==(const MyString& str);
		//operator< 字符串比较运算符
		bool operator<(const char* carray);
		bool operator<(const MyString& str);
		//operator<= 字符串比较运算符
		bool operator<=(const char* carray);
		bool operator<=(const MyString& str);
		//operator> 字符串比较运算符
		bool operator>(const char* carray);
		bool operator>(const MyString& str);
		//operator>= 字符串比较运算符
		bool operator>=(const char* carray);
		bool operator>=(const MyString& str);
		//operator>> 字符串输入运算符
		friend std::istream& operator>> ( std::istream& is, MyString& dt );
		//operator<< 字符串输出运算符
		friend std::ostream& operator<< ( std::ostream& os, MyString& dt );

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

MyString MyString::operator+(const char* carray){
	MyString ms;
	ms.length = length+strlen(carray);
	ms.p_str = (char*)malloc((length+strlen(carray))*sizeof(char));
	for(int i=0;i<length;i++) ms.p_str[i] = p_str[i];
	for(int i=0;i<strlen(carray);i++) ms.p_str[i+length] = carray[i];
	return ms;
}
MyString MyString::operator+(const MyString& str){
	MyString ms;
	ms.length = length+str.length;
	ms.p_str = (char*)malloc((length+str.length)*sizeof(char));
	for(int i=0;i<length;i++) ms.p_str[i] = p_str[i];
	for(int i=0;i<str.length;i++) ms.p_str[i+length] = str.p_str[i];
	return ms;
}
MyString MyString::operator+(const char c){
	MyString ms;
	ms.length = length+1;
	ms.p_str = (char*)malloc((length+1)*sizeof(char));
	for(int i=0;i<length;i++) ms.p_str[i] = p_str[i];
	ms.p_str[length] = c;
	return ms;
}
MyString& MyString::operator+=(char c){
	length += 1;
	p_str = (char*)realloc(p_str,length*sizeof(char));
	p_str[length-1] = c;
	return *this;
}
MyString& MyString::operator+=(const char* pstr){
	int t = length;
	length += strlen(pstr);
	p_str = (char*)realloc(p_str,length*sizeof(char));
	for(int i=t;i<length;i++) p_str[i] = pstr[i];
	return *this;
}
MyString& MyString::operator+=(const MyString& str){
	int t = length;
	length += str.length;
	p_str = (char*)realloc(p_str,length*sizeof(char));
	for(int i=t;i<length;i++) p_str[i] = str.p_str[i];
	return *this;
}
void MyString::operator = (const MyString& str){
	p_str = (char*)malloc(str.length*sizeof(char));
	memset(p_str,0,sizeof(p_str));
	length = str.length;
	for(int i=0;i<length;i++) p_str[i] = str.p_str[i];
}
void MyString::operator = (const char* pstr){
	p_str = (char*)malloc(strlen(pstr)*sizeof(char));
	memset(p_str,0,sizeof(p_str));
	length = strlen(pstr);
	for(int i=0;i<length;i++) p_str[i] = pstr[i];
}
void MyString::operator = (const char c){
	p_str = (char*)malloc(sizeof(char));
	memset(p_str,0,sizeof(p_str));
	length = 1;
	p_str[0] = c;
	//return *this;
}
char MyString::operator[](int index) const{
	return p_str[index];
}
bool MyString::operator!=(const char* carray){
	int t = strcmp(p_str,carray);
	if(t==0) return 0;
	else return 1;
}
bool MyString::operator!=(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t==0) return 0;
	else return 1;
}
bool MyString::operator==(const char* carray){
	int t = strcmp(p_str,carray);
	if(t==0) return 1;
	else return 0;
}
bool MyString::operator==(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t==0) return 1;
	else return 0;
}
bool MyString::operator<(const char* carray){
	int t = strcmp(p_str,carray);
	if(t<0) return 1;
	else return 0;
}
bool MyString::operator<(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t<0) return 1;
	else return 0;
}
bool MyString::operator<=(const char* carray){
	int t = strcmp(p_str,carray);
	if(t<=0) return 1;
	else return 0;
}
bool MyString::operator<=(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t<=0) return 1;
	else return 0;
}
bool MyString::operator>(const char* carray){
	int t = strcmp(p_str,carray);
	if(t>0) return 1;
	else return 0;
}
bool MyString::operator>(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t>0) return 1;
	else return 0;
}
bool MyString::operator>=(const char* carray){
	int t = strcmp(p_str,carray);
	if(t>=0) return 1;
	else return 0;
}
bool MyString::operator>=(const MyString& str){
	int t = strcmp(p_str,str.p_str);
	if(t>=0) return 1;
	else return 0;
}
std::istream& operator>> ( std::istream& is, MyString& dt ){
	const int N = 1e5;
	char ch;
	char *tt;
	dt.length = N;
	tt = (char*)malloc(N*sizeof(char));
	is>>tt;
	dt.length = strlen(tt);
	dt.p_str = (char*)malloc(dt.length*sizeof(char));
	strcpy(dt.p_str,tt);
	free(tt);
	return is;
}
std::ostream& operator<< ( std::ostream& os, MyString& dt ){
	for(int i=0;i<dt.length;i++) os<<dt.p_str[i];
	return os;
}


int main()
{
    MyString s;
    cout<<"operator:"<<endl;
    cout<<s<<endl;

    MyString p,q;
	cin>>p>>q;
	cout<<p<<endl;
	cout<<q<<endl;
    MyString ans;
    ans = p+q;
	cout<<ans<<endl;

    MyString cc,aa,bb,dd;
	aa = "as",bb = "ew";
	cc = aa + bb;
	dd = "aa";
	cout<<(cc>dd)<<" "<<(cc<dd)<<endl;
    cout<<cc<<endl;
    return 0;
}


/*	do{
		is>>ch;
		if(i>=dt.length){
			dt.length += N;
			tt = (char*)realloc(tt,dt.length*sizeof(char));
		}
		tt[i++] = ch;
		//cout<<tt[i-1]<<endl;
	}while(ch!='\n'&&isspace(ch));
	dt.length = i;

//*/
