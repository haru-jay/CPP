#include <iostream>
#include <string.h>

using std::cout;

class MyString
{
	private:
		char	*string_content;
		int		string_len;
		mutable int num;
	
	public:
		MyString();
		~MyString();
		explicit MyString(const char* user_input);
		MyString(const MyString& user_input);
		MyString& StringAssign(const char* str);
		MyString& StringAssign(const MyString& str);
		MyString& StringInsert(int loc, char c);
		MyString& StringInsert(int loc, const char *str);
		MyString& StringInsert(int loc, const MyString& str);
		int StringLen(void);
		int compare(const MyString& str);
		void StringPrint(void);

		bool operator==(const MyString& str);
		// char *ChangeString(const char *user_input);
};

MyString::MyString(): string_content(NULL), string_len(0) {};

MyString::~MyString()
{
	delete[] string_content;
}

MyString::MyString(const char *user_input)
{
	string_len = strlen(user_input);
	string_content = new char[string_len];
	// strcpy(string_content, user_input);
	for (int i = 0; i != string_len; i++)
		string_content[i] = user_input[i];
}

MyString::MyString(const MyString &user_input)
{
	string_len = user_input.string_len;
	string_content = new char[string_len];
	for (int i = 0; i != string_len; i++)
		string_content[i] = user_input.string_content[i];
}

int MyString::StringLen(void)
{
	return string_len;
}

void MyString::StringPrint(void)
{
	for(int i = 0 ; i < string_len ; i++)
		std::cout << string_content[i];
}

MyString& MyString::StringAssign(const char *str)
{
	int str_length = strlen(str);
	if (string_len == str_length)
		for(int i = 0 ; i<string_len ; i++)
			string_content[i] = str[i];
	else
	{
		char *new_content = new char[str_length];
		for(int i = 0 ; i<str_length ; i++)
			new_content[i] = str[i];
		delete[] string_content;
		string_content = new_content;
		string_len = str_length;  
	}
	return *this;
}

MyString& MyString::StringAssign(const MyString& str)
{
	int str_length = strlen(str.string_content);
	if (string_len == str.string_len)
		for(int i = 0 ; i<string_len ; i++)
			string_content[i] = str.string_content[i];
	else
	{
		char *new_content = new char[str_length];
		for(int i = 0 ; i<str_length ; i++)
			new_content[i] = str.string_content[i];
		delete[] string_content;
		string_content = new_content;
		string_len = str_length;
	}
	return *this;
}

MyString& MyString::StringInsert(int loc, char c)
{
	MyString temp(&c);
	return StringInsert(loc, temp);
}

MyString& MyString::StringInsert(int loc, const char *str)
{
	MyString temp(str);
	return StringInsert(loc, temp);
}

MyString& MyString::StringInsert(int loc, const MyString& str)
{
	if (loc > string_len || loc < 0)
		return *this;
	int total_length = str.string_len + string_len;
	char *new_str = new char[total_length];
	int i = 0;
	for(; i < loc ; i++)
		new_str[i] = string_content[i];
	for(int j = 0 ; j < str.string_len ; j++)
		new_str[i + j] = str.string_content[j];
	for(; i < string_len ; i++)
		new_str[i + str.string_len] = string_content[i];
	delete[] string_content;
	string_content = new_str;
	string_len = total_length;
	return *this;
}
int MyString::compare(const MyString& str)
{
// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
// 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
// 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.

	for (int i = 0; i < std::min(string_len, str.string_len); i++)
	{
		if (string_content[i] > str.string_content[i])
			return 1;

		else if (string_content[i] < str.string_content[i])
			return -1;
	}

  // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
  // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

  if (string_len == str.string_len) return 0;

  // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
  else if (string_len > str.string_len)
    return 1;

  return -1;
}

bool MyString::operator==(const MyString& str)
{
	return !compare(str);
}


int main()
{
	MyString *list[10];
	list[0] = new MyString("0 : Hello\n");
	list[1] = new MyString("1 : world\n");

	// cout << list[0] << std::endl;
	// cout << list[1] << std::endl;
	list[0]->StringPrint();
	list[1]->StringPrint();

	list[2] = new MyString(*list[0]);
	list[2]->StringPrint();

	list[2]->StringAssign("2 : Good ");
	list[2]->StringInsert(9, "Bye\n");
	list[2]->StringPrint();
	std::cout << list[0]->StringLen() << std::endl;
	// std::cout << std::endl;
	// for(int i = 0; list[i] != NULL ; i++)
	// 	delete[] list[i];
	delete list[0];
	delete list[1];
	delete list[2];

	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");

  if (str1 == str2)
    std::cout << "str1 와 str2 같다." << std::endl;
  else
    std::cout << "st1 와 str2 는 다르다." << std::endl;

  if (str2 == str3)
    std::cout << "str2 와 str3 는 같다." << std::endl;
  else
    std::cout << "st2 와 str3 는 다르다" << std::endl;
}
