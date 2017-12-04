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
    if(count>length){
        p_str=(char *)realloc(p_str,sizeof(char)*(count));
        length=count;
    }
    for(int i=0;i<length;i++)
        p_str[i]=c;
}

 void MyString::clear(){
     ////free(p_str);
     delete[] p_str;
    length=0;
}

int MyString::compare(const MyString &str)
{
     return strcmp(p_str,str.p_str);
}

int MyString::compare(int _Posl,int _Numl,const MyString &str)
{
    char *ch;
    ch=(char *)malloc(sizeof(char)*_Numl);
    for(int i=_Posl;i<_Posl+_Numl;i++)
        ch[i-_Posl]=str.p_str[i];
    //for(int i=0;i<_Numl;i++)
   // cout<<ch[i];    cout<<endl;
    return strcmp(p_str,ch);
}

int MyString::compare(const char* _str)
{
    return strcmp(p_str,_str);
}

int MyString::compare(int _Posl,int _Numl,const char *_Ptr)
{
    char *ch;
    ch=(char *)malloc(sizeof(char)*_Numl);

    for(int i=0;i<_Numl;i++){
         ch[i]=_Ptr[_Posl];
        // cout<<ch[i];
    }
    //cout<<endl;
    return strcmp(p_str,ch);
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

    cout<<"compare"<<endl;
    sss.clear();
    s.show();
    sss.show();
    cout<<s.compare(sss)<<endl;


    cout<<"flag"<<endl;
    s.clear();
    char e[]="abcd\0";
    cout<<strlen(e)<<endl;
    MyString st,str;
    st.append(e);
    str.append(e);
    st.show();
    str.show();
    cout<<st.compare(0,1,str)<<endl;


    //int compare(const char* _str);

    cout<<st.compare(e)<<endl;


    cout<<"compare"<<endl;
   //    int compare(int _Posl,int _Numl,const char *_Ptr);
    cout<<st.compare(0,4,e)<<endl;



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
