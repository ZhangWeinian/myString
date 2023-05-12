#pragma once
#ifndef __MYSTRING__
#define __MYSTRING__

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class myString
{
private:
	char* data;
	size_t len;

public:
	myString(const char* str)
	{
		if (str == nullptr)
		{
			len = 0;
			data = new char[1];
			*data = '\0';
		}
		else
		{
			len = strlen(str);

			data = new char[len + 1];

			if (data == nullptr)
			{
				cerr << "myString(const char* str) 内存分配失败！" << endl;
				exit(EXIT_FAILURE);
			}

			else
			{
				strcpy(data, str);
			}
		}
	}

	myString(const myString& str)
	{
		len = str.size();
		data = new char[len];

		if (data == nullptr)
		{
			cerr << "myString(const myString& str) 内存分配失败！" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			strcpy(data, str.data);
		}
	}

	myString(void)
	{
		len = 0;
		data = new char[1];
		*data = '\0';
	}

	~myString(void)
	{
		delete[] data;
	}

	size_t size(void) const
	{
		return len;
	}

	char* get_c_str(void) const
	{
		return data;
	}

	char* write_c_str(void)
	{
		return data;
	}

	myString& operator=(const myString& str)
	{
		if (this == &str)
		{
			return *this;
		}

		delete[] data;
		len = str.size();

		data = new char[len + 1];
		if (data == nullptr)
		{
			cerr << "myString& operator=(const myString& str) 内存分配失败！" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			strcpy(data, str.data);

			return *this;
		}
	}

	myString& operator=(const char* str)
	{
		if (str == this->get_c_str())
		{
			return *this;
		}

		delete[] data;
		len = strlen(str);

		data = new char[len + 1];
		if (data == nullptr)
		{
			cerr << "myString& operator=(const char* str) 内存分配失败！" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			strcpy(data, str);

			return *this;
		}
	}

	myString& operator+=(const myString& str)
	{
		this->len = this->size() + str.size();

		char* str0 { new char[len + 1] };
		strcpy(str0, this->get_c_str());
		strcat(str0, str.get_c_str());

		delete[] data;
		this->data = str0;
		str0 = nullptr;

		return *this;
	}
};

inline myString operator+(const myString& str1, const myString& str2)
{
	const size_t len = str1.size() + str2.size();
	char* str = new char[len + 1];
	strcpy(str, str1.get_c_str());
	strcat(str, str2.get_c_str());

	myString ans(str);
	delete[] str;

	return ans;
}

inline myString operator+(const char* str1, const myString& str2)
{
	const size_t len = strlen(str1) + str2.size();
	char* str = new char[len + 1];
	strcpy(str, str1);
	strcat(str, str2.get_c_str());

	myString ans(str);
	delete[] str;

	return ans;
}

inline myString operator+(const myString& str1, const char* str2)
{
	const size_t len = str1.size() + strlen(str2);
	char* str = new char[len + 1];
	strcpy(str, str1.get_c_str());
	strcat(str, str2);

	myString ans(str);
	delete[] str;

	return ans;
}

inline myString operator+(const char& str1, const myString& str2)
{
	const size_t len = strlen(&str1) + str2.size();
	char* str = new char[len + 1];
	strcpy(str, &str1);
	strcat(str, str2.get_c_str());

	myString ans(str);
	delete[] str;

	return ans;
}

inline myString operator+(const myString& str1, const char& str2)
{
	const size_t len = str1.size() + strlen(&str2);
	char* str = new char[len + 1];
	strcpy(str, str1.get_c_str());
	strcat(str, &str2);

	myString ans(str);
	delete[] str;

	return ans;
}

inline ostream& operator<<(ostream& _output, const myString& str)
{
	return _output << str.get_c_str();
}

inline istream& operator>>(istream& _input, myString& str)
{
	return _input;
}

inline bool operator<(const myString& str1, const myString& str2)
{
	return strcmp(str1.get_c_str(), str2.get_c_str()) < 0 ? true : false;
}

inline bool operator<=(const myString& str1, const myString& str2)
{
	return strcmp(str1.get_c_str(), str2.get_c_str()) <= 0 ? true : false;
}

inline bool operator>(const myString& str1, const myString& str2)
{
	return strcmp(str1.get_c_str(), str2.get_c_str()) > 0 ? true : false;
}

inline bool operator>=(const myString& str1, const myString& str2)
{
	return strcmp(str1.get_c_str(), str2.get_c_str()) >= 0 ? true : false;
}

inline bool operator==(const myString& str1, const myString& str2)
{
	return strcmp(str1.get_c_str(), str2.get_c_str()) == 0 ? true : false;
}

#endif
