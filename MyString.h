#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();

	// 복사 생성자
	CMyString(const CMyString& rhs);

	// 변환 생성자(const char* 에 대한 변환)                     
	explicit CMyString(const char* pszParam);

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData = nullptr;
	// 저장된 문자열의 길이
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// 멤버 읽기만 수행하므로 메서드를 상수화
	const char* GetString() const;
	void Release();

	// 연산자 재정의
	CMyString& operator=(const CMyString& rhs);

	// char* 로의 변환
	operator char* (void) const
	{
		return m_pszData;
	}

};

